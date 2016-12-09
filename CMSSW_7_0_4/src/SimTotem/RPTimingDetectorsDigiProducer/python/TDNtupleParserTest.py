import ROOT
from copy import copy
import os

# Load proper classes into ROOT
compSuffix = '+g'
ROOT.gROOT.ProcessLine(
    '.L ' + os.environ['CMSSW_BASE'] +
    '/src/TotemAnalysis/TotemNtuplizer/interface/RPTimingDetectorsNtuplizerHit.h' + compSuffix
)
root_files_path = os.environ['CMSSW_BASE']

# format: file_path, probability of occurrence
sources_data = [
    root_files_path + '/source1_10000.root',
]
target_file_path = root_files_path + '/results.root'

# ID: arm | station | roman pot | plane
ids = ['%d%d%d%d' % (arm, 2, pot, plane) for arm in range(0, 2) for pot in range(0, 2) for plane in range(0, 4)]
tree_name = 'TotemNtuple'


def get_branch_name(det_id):
    return 'rp_timing_detector_%s_hits' % det_id


def load_ntuple(file_path):
    tree_path = '/'.join([file_path, tree_name])
    tchain = ROOT.TChain('TotemNtuple', '')
    tchain.Add(tree_path)
    return tchain


if __name__ == "__main__":
    elastic = 'TDElastic10Ntuple.root'
    test = 'test.root'

    sources = []
    for name in sources_data:
        sources.append(load_ntuple(name))

    target = load_ntuple(target_file_path)

    sources_data = []
    for _ in sources[0]:
        dict = {}
        for id in ids:
            dict[id] = []
        sources_data.append(dict)

    for source in sources:
        for i, event in enumerate(source):
            for det_id in ids:
                hits = getattr(event, get_branch_name(det_id))
                for hit in hits:
                    sources_data[i][det_id].append(hit.electrode_id)

    target_data = []
    for _ in sources[0]:
        dict = {}
        for id in ids:
            dict[id] = []
        target_data.append(dict)

    for i, event in enumerate(target):
        for det_id in ids:
            hits = getattr(event, get_branch_name(det_id))
            for hit in hits:
                target_data[i][det_id].append(hit.electrode_id)

    for dict1, dict2 in zip(sources_data, target_data):
        for id in ids:
            dict1[id].sort()
            dict2[id].sort()
            if dict1[id] != dict2[id]:
                print id
                print 'Source:', dict1[id]
                print 'Target:', dict2[id]
                exit()

    print "All ok"
