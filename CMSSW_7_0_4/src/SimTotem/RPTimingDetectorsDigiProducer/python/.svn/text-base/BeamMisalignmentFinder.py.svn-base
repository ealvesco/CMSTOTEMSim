import ROOT
import os
import argparse
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy import exp

parser = argparse.ArgumentParser(description='Finds beam misaligned between given template and misaligned ntuple')
parser.add_argument('template_file', metavar='template_file', type=str, nargs=1,
                    help='File containing ntuple used as template to find misaligned')
parser.add_argument('misaligned_file', metavar='misaligned_file', type=str, nargs=1,
                    help='File containing misaligned ntuple')
args = parser.parse_args()

ROOT.gROOT.ProcessLine('.include ' + os.environ['CMSSW_BASE'] + '/src')
ROOT.gROOT.ProcessLine(
    '.L ' + os.environ['CMSSW_BASE'] + '/src/TotemAnalysis/TotemNtuplizer/interface/RPTimingDetectorsNtuplizerHit.h+g')
tree_name = 'TotemNtuple'
hit_source_types = ["reco", "filtered", "tracking_pot_210_far", "tracking_pot_220_far"]
ids = {
    "reco": ["%03d" % id for id in [20, 21, 120, 121]]
}
ids["filtered"] = ids["reco"]
ids["tracking_pot_220_far"] = ids["reco"]
ids["tracking_pot_210_far"] = ids["reco"]

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


def gauss(x, a, x0, sigma):
    return a*exp(-(x-x0)**2/(2*sigma**2))


def cut_zero_bins(histogram, bins):
    first = histogram.index(next(x for x in histogram if x != 0))
    last = (len(histogram) - 1) - histogram[::-1].index(
        next(x for x in histogram[::-1] if x != 0))

    hist_x = bins[first:last + 1]
    hist_y = histogram[first:last + 1]
    return hist_x, hist_y


def fit_gauss(x, y):
    gauss_params, pcov = curve_fit(gauss, x, y, p0=[1., 0., 1.])
    return gauss_params, np.sqrt(np.diag(pcov))


def find_misalignment(template_data, misaligned_data):
    sum = 0.0
    number = 0.0
    template_error = 0.0
    misaligned_error = 0.0
    for bin_width in list(np.arange(0.1, 1.1, 0.1))[::-1]:
        try:
            histogram_bins = np.arange(-20, 20, bin_width)
            template_histogram = list(np.histogram(template_data, bins=histogram_bins)[0])
            misaligned_histogram = list(np.histogram(misaligned_data, bins=histogram_bins)[0])

            template_x, template_y = cut_zero_bins(template_histogram, histogram_bins)
            misaligned_x, misaligned_y = cut_zero_bins(misaligned_histogram, histogram_bins)

            template_gauss_params, template_standard_deviation_error = fit_gauss(template_x, template_y)
            misaligned_gauss_params, misaligned_standard_deviation_error = fit_gauss(misaligned_x, misaligned_y)
            template_error += template_standard_deviation_error[1]
            misaligned_error += misaligned_standard_deviation_error[1]
            template_x0 = template_gauss_params[1]
            misaligned_x0 = misaligned_gauss_params[1]

            # plt.plot(misaligned_x, misaligned_y, 'b+:', label='data')
            # plt.plot(misaligned_x, gauss(misaligned_x, *misaligned_gauss_params), 'ro:', label='fit')
            # plt.legend()
            # plt.savefig("foo.png")

            sum += (misaligned_x0 - template_x0)
            number += 1
        except RuntimeError:
            # print "result not found for %.2f bins width" % bin_width
            pass
    if number > 0:
        return sum/number, template_error/number, misaligned_error/number

    raise Exception('Cannot find misalignment')


if __name__ == "__main__":
    template_file_name = args.template_file[0]
    misaligned_file_name = args.misaligned_file[0]

    template_ntuple = load_ntuple(template_file_name)
    misaligned_ntuple = load_ntuple(misaligned_file_name)

    # check sizes
    if template_ntuple.GetEntries() != misaligned_ntuple.GetEntries():
        print "Error, all sources must have te same number of events"
        exit(-1)

    sources_ntuples_types = ["template", "misaligned"]
    hits_histograms = {}
    for ntuple_type in sources_ntuples_types:
        hits_histograms[ntuple_type] = {}
        for hit_type in hit_source_types:
            hits_histograms[ntuple_type][hit_type] = {}
            for id in ids[hit_type]:
                hits_histograms[ntuple_type][hit_type][id] = []

    for source_name, source_ntuple in zip(sources_ntuples_types, [template_ntuple, misaligned_ntuple]):
        for event in source_ntuple:
            for type in hit_source_types:
                for id in ids[type]:
                    for hits_vector in getattr(event, get_branch_name(id, type)):
                        if type in ["reco", "filtered"]:
                            hits_histograms[source_name][type][id].append(hits_vector.position.x)
                        elif type in ["tracking_pot_210_far", "tracking_pot_220_far"]:
                            hits_histograms[source_name][type][id].append(hits_vector.x)

    sum = 0.0
    number = 0.0
    print "Calculated misalignment"
    for type in hit_source_types:
        for id in ids[type]:
            result, template_error, misaligned_error = \
                find_misalignment(hits_histograms["template"][type][id], hits_histograms["misaligned"][type][id])
            sum += result
            number += 1
            print '%s %.2fmm; standard deviation error: template: %.2f misaligned: %.2f' % (get_branch_name(id, type), result,
                                                                        template_error, misaligned_error)
    print 'Average %.2fmm' % (sum/number)
