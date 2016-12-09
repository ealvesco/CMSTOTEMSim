#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''Create a summary plot of a selected histograms for T2 detector.'''

__author__ = 'Krzysztof Trzepla'

import ROOT
import argparse

parser = argparse.ArgumentParser(
    formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    description='Create a summary plot of a selected histograms for T2 detector.'
    )

parser.add_argument(
    '-i', '--input',
    type=str,
    action='store',
    help='Path to input ntuple file.',
    dest='input')

parser.add_argument(
    '-o', '--output',
    type=str,
    action='store',
    default='T2_summary.pdf',
    help='Path to output summary plot file with extension.',
    dest='output')

if __name__ == '__main__':
    args = parser.parse_args()
    f = ROOT.TFile(args.input)
    t = f.Get('TotemNtuple')

    histograms = [
        'branchT2EV.Pad_det',
        'branchT2EV.Strip_det',
        'branchT2EV.NumPadCluH0',
        'branchT2EV.NumPadCluH1',
        'branchT2EV.NumPadCluH2',
        'branchT2EV.NumPadCluH3',
        'branchT2EV.TrkEta2'
        ]

    c = ROOT.TCanvas()
    c.SetTitle('T2 summary')
    c.Divide(2, len(histograms) / 2 + len(histograms) % 2)

    for i, histogram in enumerate(histograms):
        c.cd(i + 1)
        t.Draw(histogram)

    # Example cut.
    cut = ROOT.TCut('branchT2EV.Pad_det > 10')
    c.cd(len(histograms) + 1)
    t.Draw(histograms[0], cut)

    c.SaveAs(args.output)

