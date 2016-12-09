Description
===========

This document presents steps which should be undertaken in order to convert
generated CMS configuration into TOTEM configuration.

Conversion steps
================

1. Create 'python/step0_CMS_cfg.py' generator configuration file.

        $ sh drivers/create_step0_CMS_cfg.sh

2. Run generator configuration which stores results in 'data/step0_CMS.root'
   output file.
        
        $ cmsRun python/step0_CMS_cfg.py

3. Create 'python/step1_CMS_cfg.py' simulation configuration file.
        
        $ sh drivers/create_step1_CMS_cfg.sh

4. Run first step of TOTEM simulation configuration which reads 'data/step0_CMS.root'
   input file, executes Geant 4 simulation and stores result in 'data/step1_TOTEM.root'
   output file.

        $ cmsRun python/step1_TOTEM_cfg.py

5. Run second step of TOTEM simulation configuration which reads 'data/step1_CMS.root'
   input file, reconstructs proton tracks and creates both raw output file
   'data/step2_TOTEM.root' and ntuple file 'data/step2_TOTEM.ntuple.root'.

        $ cmsRun python/step2_TOTEM_cfg.py

6. Browse simulation results using ROOT (remember to connect via ssh with -X or
   -Y option).

        $ root -l
        root [0] TBrowser T

Tests
=====

In the 'test' directory you may find two scripts: 'run_CMS_cfg.sh' and 'run_TOTEM_cfg.sh'.
The first one runs CMS simulation configuration along with generation of necessary files.
The second one executes all the steps described in the 'Conversion steps' section.

Useful commands
===============

edmConfigDump cfg.py - fully expands python configuration file
