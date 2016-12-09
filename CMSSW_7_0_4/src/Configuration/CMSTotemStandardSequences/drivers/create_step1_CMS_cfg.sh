#!/bin/sh

# Absolute path to CMSTotemStandardSequences directory.
BASE_DIR=$(dirname $( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd ))

cmsDriver.py --filein file:"$BASE_DIR/data/step0_CMS.root" \
             --fileout file:"$BASE_DIR/data/step1_CMS.root" \
             --mc \
             --eventcontent RAWSIM \
             --customise Configuration/StandardSequences/SimWithCastor_cff.customise, \
                         SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1 \
             --datatier SIM \
             --conditions POSTLS170_V5::All \
             --step SIM \
             --magField 38T_PostLS1 \
             --geometry Extended2015 \
             --python_filename "$BASE_DIR/python/step1_CMS_cfg.py" \
             --no_exec \
             --number -1
