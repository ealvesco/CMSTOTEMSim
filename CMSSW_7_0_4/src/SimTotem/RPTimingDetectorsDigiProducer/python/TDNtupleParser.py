import ROOT
import os
import random
import sys
import argparse

parser = argparse.ArgumentParser(description='Merge multiple ntuples into one with probability.')
parser.add_argument('config_file', metavar='config_file', type=str, nargs=1,
                    help='Config file with sources data and output file path')
args = parser.parse_args()

# Load proper classes into ROOT
ROOT.gROOT.ProcessLine('.include /afs/cern.ch/cms/slc6_amd64_gcc481/external/fastjet/3.0.3/include')
ROOT.gROOT.ProcessLine('.include ' + os.environ['CMSSW_BASE'] + '/src')
ROOT.gROOT.ProcessLine(
    '.L ' + os.environ['CMSSW_BASE'] + '/src/TotemAnalysis/TotemNtuplizer/interface/RPTimingDetectorsNtuplizerHit.h+g')
ROOT.gROOT.ProcessLine('.L /afs/cern.ch/cms/slc6_amd64_gcc481/external/fastjet/3.0.3/lib/libfastjet.so')
ROOT.gROOT.ProcessLine(
    '.L ' + os.environ['CMSSW_BASE'] + '/src/TotemAnalysis/TotemNtuplizer/interface/RPRootTrackInfo.h+g')

# ID: arm | station | roman pot | plane
hit_source_types = ["geant", "reco"]
ids = {
    "geant": ['%d%d%d%d' % (arm, 2, pot, plane) for arm in range(0, 2) for pot in range(0, 2) for plane in range(0, 4)],
    "reco": ["%03d" % det_id for det_id in [20, 21, 120, 121]]
}
ids["filtered"] = ids["reco"]
ids["tracking_pot_220_far"] = ids["reco"]
ids["tracking_pot_210_far"] = ids["reco"]
tree_name = 'TotemNtuple'
# each track needs its own data struct which will be created dynamically
vertical_rp_ids = [0, 1, 4, 5]  # id without arm and station
track_info = {}
reco_id_to_geant_id = {
    "020": "0200",
    "021": "0210",
    "120": "1200",
    "121": "1210",
}
allowed_error = 0.2  # mm

tracking_pot_maps = {
    "tracking_pot_220_far": {
        "020": "24",
        "021": "25",
        "120": "124",
        "121": "125"
    },
    "tracking_pot_210_far": {
        "020": "4",
        "021": "5",
        "120": "104",
        "121": "105"
    }
}


def get_branch_name(detector_id, type):
    if type == "geant":
        return 'rp_timing_detector_%s_hits' % detector_id
    elif type == "reco":
        return 'rp_timing_detector_%s_reco_hits' % detector_id
    elif type == "filtered":
        return 'rp_timing_detector_%s_filtered_hits' % detector_id
    elif type == "tracking_pot_220_far":
        return 'rp_timing_detector_%s_tracking_pot_%03.d' % (detector_id, int(tracking_pot_maps[type][detector_id]))
    elif type == "tracking_pot_210_far":
        return 'rp_timing_detector_%s_tracking_pot_%03.d' % (detector_id, int(tracking_pot_maps[type][detector_id]))


def load_ntuple(file_path):
    tree_path = '/'.join([file_path, tree_name])
    tchain = ROOT.TChain('TotemNtuple', '')
    tchain.Add(tree_path)
    return tchain


def check_track_presence(source, det_id, event_id):
    if det_id not in track_info:
        track_info[det_id] = ROOT.RPRootDumpTrackInfo()
    source.SetBranchAddress("track_rp_%s." % det_id, track_info[det_id])
    source.GetEvent(event_id)
    return bool(track_info[det_id].valid)


def get_track_xy_if_present(source, det_id, event_id):
    if det_id not in track_info:
        track_info[det_id] = ROOT.RPRootDumpTrackInfo()
    source.SetBranchAddress("track_rp_%s." % det_id, track_info[det_id])
    source.GetEvent(event_id)
    if not bool(track_info[det_id].valid):
        return None, None
    return track_info[det_id].x, track_info[det_id].y


def compare_floats(f1, f2):
    return abs(f1 - f2) <= allowed_error


def compare_hits(hit1, hit2):
    return compare_floats(float(hit1.position.x), float(hit2.position.x)) and \
           compare_floats(float(hit1.position.y), float(hit2.position.y))


if __name__ == "__main__":
    print "Parse config file"

    path, full_filename = os.path.split(args.config_file[0])
    config_file, _ = os.path.splitext(full_filename)

    sys.path.insert(0, path)
    config = __import__(config_file)

    sources_data = config.sources_data
    target_file_path = config.target_file_path
    beam_x_misalignment = config.beam_x_misalignment
    beam_y_misalignment = config.beam_y_misalignment

    print "Load source ntuples"
    # tchain, probability, name
    sources = []
    # name => [count, probability]
    occurrences_count = {}
    for name, probability in sources_data:
        print name
        sources.append((load_ntuple(name), probability, name))
        occurrences_count[name] = [0., probability]

    # Check sizes
    size = sources[0][0].GetEntries()  # each source must have the same events number
    real_size = size
    for source, _, _ in sources:
        if source.GetEntries() != size:
            print "Error, all sources must have te same number of events"
            exit(-1)

    # Create new ntuple to save selected events
    print "Create new ntuple to save selected events"
    print target_file_path
    target_file = ROOT.TFile.Open(target_file_path, "RECREATE")
    target_tree = ROOT.TTree("TotemNtuple", "TotemNtuple")

    # Create branches in target ntuple
    branches_data = {}
    print "Create branches in target ntuple"
    for type in hit_source_types + ["filtered", "tracking_pot_210_far", "tracking_pot_220_far"]:
        branches_data[type] = {}
        for det_id in ids[type]:
            if type in hit_source_types + ["filtered"]:
                branches_data[type][det_id] = ROOT.vector('RPTimingDetectorsNtuplizerHit')()
            elif type in ["tracking_pot_210_far", "tracking_pot_220_far"]:
                branches_data[type][det_id] = ROOT.vector('Point')()
            target_tree.Branch(get_branch_name(det_id, type), branches_data[type][det_id])

    # Copy data to from sources to target ntuple

    # each branch needs its own temporary vector, using one vector ends up with copy of one branch in all others
    hits_vectors = {}
    for type in hit_source_types:
        hits_vectors[type] = {}
        for det_id in ids[type]:
            hits_vectors[type][det_id] = ROOT.vector('RPTimingDetectorsNtuplizerHit')()

    print "Copy data to target ntuple"
    # for each event in sources ntuples
    for i in xrange(0, size):
        # clear vectors before adding new hits
        for type in hit_source_types + ["filtered", "tracking_pot_210_far", "tracking_pot_220_far"]:
            for det_id in ids[type]:
                branches_data[type][det_id].clear()

        current_event_sources = []
        # for each source file
        for source, probability, name in sources:

            # decide whether use this source in event
            if not random.random() < probability:
                continue

            current_event_sources.append((source, name))

        # check tracks presence
        left, right = False, False

        for source, _ in current_event_sources:
            station = 2
            for rp_id in vertical_rp_ids:
                # left -  0
                left |= check_track_presence(source, str(10 * station + rp_id), i)
                # right - 1
                right |= check_track_presence(source, str(100 + 10 * station + rp_id), i)

        # reject events without tracks on both sides
        if not (left and right):
            real_size -= 1
            continue

        for source, name in current_event_sources:
            occurrences_count[name][0] += 1.  # register occurrence
            for type in hit_source_types:
                # for each timing detector branch
                for det_id in ids[type]:
                    # extract TDHists vector for current event
                    source.SetBranchAddress(get_branch_name(det_id, type), hits_vectors[type][det_id])
                    source.GetEvent(i)
                    # copy hits to target ntuple
                    for hit in hits_vectors[type][det_id]:
                        branches_data[type][det_id].push_back(hit)

            # filtered hits
            for det_id in ids["filtered"]:
                for reco_hit in hits_vectors["reco"][det_id]:
                    if next((True for geant_hit in hits_vectors["geant"][reco_id_to_geant_id[det_id]]
                             if compare_hits(geant_hit, reco_hit)), False):
                        branches_data["filtered"][det_id].push_back(reco_hit)

        # hits in corresponding tracking detector
        type = "reco"
        timing_detector_on = dict((id, False) for id in ids[type])
        for det_id in ids[type]:
            for source, _ in current_event_sources:
                # extract TDHists vector for current event
                source.SetBranchAddress(get_branch_name(det_id, type), hits_vectors[type][det_id])
                source.GetEvent(i)
                timing_detector_on[det_id] |= (not hits_vectors[type][det_id].empty())
        for det_id in ids[type]:
            if timing_detector_on[det_id]:
                for source, _ in current_event_sources:
                    for far_pot_type in ["tracking_pot_210_far", "tracking_pot_220_far"]:
                        # extract x,y from track data
                        x, y = get_track_xy_if_present(source, tracking_pot_maps[far_pot_type][det_id], i)
                        if x is not None and y is not None:
                            branches_data[far_pot_type][det_id].push_back(ROOT.Point(
                                x + beam_x_misalignment,
                                y + beam_y_misalignment
                            ))

        # save event data
        target_tree.Fill()

    # Save data to target ntuple
    print "Save data to target ntuple"
    target_file.cd()
    target_tree.Write()

    print "Statistics"
    print "name | real | expected"
    for name, value in occurrences_count.iteritems():
        print "%s\t%.2f%%\t%.2f%%" % (name, value[0] * 100. / real_size, value[1] * 100)
