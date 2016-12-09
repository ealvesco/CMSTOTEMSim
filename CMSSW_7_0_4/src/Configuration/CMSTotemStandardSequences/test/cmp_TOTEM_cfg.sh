#!/bin/sh

# This script compares ROOT files produced by second step of TOTEM simulation '$BASE_DIR/python/step2_TOTEM_cfg.py' and original TOTEM simulation '$BASE_DIR/test/TOTEM_cfg.py' using '$BASE_DIR/test/printer.py' tool.
# Both simulations takes as an input '$BASE_DIR/data/step0_CMS.root' file.

# Exit immediately if a simple command exits with a non-zero status.
set -e
# Log all commands to stdout.
set -x

# Absolute path to CMSTotemStandardSequences directory.
BASE_DIR=$(dirname $( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd ))

# Run TOTEM simulation from modified CMS configuration.
sh "$BASE_DIR/test/run_TOTEM_cfg.sh"

# Run original TOTEM simulation.
cmsRun "$BASE_DIR/test/TOTEM_cfg.py"

# Create 'fingerprint' of simulation outputs using '$BASE_DIR/test/printer.py' tool.
python "$BASE_DIR/test/printer.py" "$BASE_DIR/data/step2_TOTEM.root" > "$BASE_DIR/data/step2_TOTEM.printer.log"
python "$BASE_DIR/test/printer.py" "$BASE_DIR/data/orig_TOTEM.root" > "$BASE_DIR/data/orig_TOTEM.printer.log"

# Stop logging all commands to stdout.
set +x

# Compare fingerprints.
DIFF_OUTPUT=`diff "$BASE_DIR/data/step2_TOTEM.printer.log" "$BASE_DIR/data/orig_TOTEM.printer.log"` || EXIT_CODE=$?

if [ $EXIT_CODE ]
then
    echo -e "Fingerprints differ!\n"
    echo $DIFF_OUTPUT
else
    echo "Fingerprints are the same!"
fi

exit $EXIT_CODE
