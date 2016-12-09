#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''Create a summary plot of a selected histograms for Roman Pot detector with 
given ID.'''

__author__ = 'Krzysztof Trzepla'

import ROOT
import argparse

parser = argparse.ArgumentParser(
    formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    description='Create a summary plot of a selected histograms for Roman Pot '
    'detector with given ID.'
    )

parser.add_argument(
    '-d', '--id',
    type=int,
    action='store',
    help='Roman Pot detector ID.',
    dest='id')

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
    default='RP_{0}_summary.pdf',
    help='Path to output summary plot file with extension.',
    dest='output')

if __name__ == '__main__':
    args = parser.parse_args()
    f = ROOT.TFile(args.input)
    t = f.Get('TotemNtuple')

    histograms = map(lambda h: h.format(args.id), [
		'trigger_data.input_status_bits',
		'digi_rp_{0}.numberOfPlanesOn',
		'digi_rp_{0}.centralStrip',
		'par_patterns_rp_{0}.u_no',
		'par_patterns_rp_{0}.v_no',
		'nonpar_patterns_rp_{0}.u_no',
		'nonpar_patterns_rp_{0}.v_no',
		'track_rp_{0}.y:track_rp_{0}.x',
		'track_rp_{0}.thx',
		'track_rp_{0}.thy'
        ])

    c = ROOT.TCanvas()
    c.SetTitle('RP {0} summary'.format(args.id))
    c.Divide(2, len(histograms) / 2 + len(histograms) % 2)

    for i, histogram in enumerate(histograms):
        c.cd(i + 1)
        t.Draw(histogram)

    c.SaveAs(args.output.format(args.id))


