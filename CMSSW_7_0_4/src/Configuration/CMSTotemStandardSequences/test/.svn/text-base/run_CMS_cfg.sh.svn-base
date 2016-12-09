#!/bin/sh

# Exit immediately if a simple command exits with a non-zero status.
set -e
# Log all commands to stdout.
set -x

# Absolute path to CMSTotemStandardSequences directory.
BASE_DIR=$(dirname $( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd ))

# Create '$BASE_DIR/python/step0_CMS_cfg.py' generator configuration file.
sh "$BASE_DIR/drivers/create_step0_CMS_cfg.sh"

# Run generator configuration which stores results in '$BASE_DIR/data/step0_CMS.root' output file.
cmsRun "$BASE_DIR/python/step0_CMS_cfg.py"

# Create '$BASE_DIR/python/step1_CMS_cfg.py' simulation configuration file.
sh "$BASE_DIR/drivers/create_step1_CMS_cfg.sh"

# Run CMS simulation configuration which reads '$BASE_DIR/data/step0_CMS.root' input file and stores result in '$BASE_DIR/data/step1_CMS.root' output file.
cmsRun "$BASE_DIR/python/step1_CMS_cfg.py"
