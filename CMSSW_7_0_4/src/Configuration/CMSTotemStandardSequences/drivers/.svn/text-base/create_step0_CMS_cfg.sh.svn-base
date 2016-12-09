#!/bin/sh

# Absolute path to CMSTotemStandardSequences directory.
BASE_DIR=$(dirname $( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd ))

cmsDriver.py MinBias_13TeV_cfi.py \
             --fileout file:"$BASE_DIR/data/step0_CMS.root" \
             --mc \
             --eventcontent RAWSIM \
             --customise SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1 \
             --datatier GEN-SIM \
             --conditions POSTLS170_V5::All \
             --step GEN \
             --magField 38T_PostLS1 \
             --geometry Extended2015 \
             --no_exec \
             --number 100 \
             --python_filename "$BASE_DIR/python/step0_CMS_cfg.py"
