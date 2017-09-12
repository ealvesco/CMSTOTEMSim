# CMSTOTEMSim

$git clone -b CMSTOTEM-v01 https://github.com/elizamelo/CMSTOTEMSim.git
$scram p -n CMSSW_704test CMSSW_7_0_4
$cd CMSSW_704test/src
$cmsenv
$cd ..
$mv src src_save
$cp -r ../CMSTOTEMSim/CMSSW_7_0_4/src .
$scram build -j 15
