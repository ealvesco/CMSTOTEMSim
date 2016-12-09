#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''Script used by Jenkins continuous integration server in order to run 
simulations and validate the output with sw_tester tool.'''

__author__ = 'Krzysztof Trzepla'

import os
import subprocess

agent_username = os.getlogin()
agent_kerberos_keytab = '/etc/{0}.keytab'.format(agent_username)
agent_test_log = os.path.join(os.getenv('WORKSPACE'), 'test.log')
# Tool used to test root files format.
validator = '/afs/cern.ch/exp/totem/soft/sw_tester/sw_tester.py'
# Mapping from the test configuration to the output file which should be created
# due to the configuration run.
tests = {
'src/Configuration/TotemStandardSequences/test/RP/prodRPinelasticBeta90Energy6500GeV_cfg.py':
'prodRPinelasticBeta90Energy6500GeV.root',
'src/Configuration/TotemStandardSequences/test/RPT1T2/prodRPT1T2pythiaSDbeta90energy6500GeV_cfg.py':
'prodRPT1T2pythiaSDbeta90energy6500GeV.root',
'src/IOMC/FlatProtonLogKsiLogTGunMul/test/FlatProtonLogKsiLogTGunMulTest_cfg.py':
'FlatProtonLogKsiLogTGunMulTest.root',
'src/IOMC/MultiParticleEtaEMC2/test/MultiParticleEtaEMC2Test_cfg.py':
'MultiParticleEtaEMC2Test.root',
'src/IOMC/FlatProtonLogKsiLogTGun/test/FlatProtonLogKsiLogTGunTest_cfg.py':
'FlatProtonLogKsiLogTGunTest.root',
'src/IOMC/Elegent/test/ElegentTest_cfg.py':
'ElegentTest.root',
'src/IOMC/FlatThetaXYGun/test/FlatThetaXYGunTest_cfg.py':
'FlatThetaXYGunTest.root',
'src/IOMC/Phojet/test/PhojetTest_cfg.py':
'PhojetTest.root',
'src/IOMC/MultiParticleGuns/test/MultiParticleGunsTest_cfg.py':
'MultiParticleGunsTest.root',
'src/IOMC/SmearingGenerator/test/SmearingGeneratorTest_cfg.py':
'SmearingGeneratorTest.root',
}

def initialize_kerberos_keytab_cmd():
    '''Initializes Kerberos keytab for agent user.'''

    return [
    'echo Initializing Kerberos keytab for user {0}...'.format(agent_username),
    'kinit -kt {0} {1}'.format(agent_kerberos_keytab, agent_username)
    ]

def initialize_cms_environment_cmd():
    '''Initializes cms environment.'''

    return [
    'echo Initializing cms environment...',
    'cd {0}'.format(os.getenv('JOB_NAME')),
    'export SCRAM_ARCH=slc6_amd64_gcc481',
    'source /afs/cern.ch/cms/cmsset_default.sh',
    'eval `scramv1 runtime -sh`'
    ]

def run_and_validate_configs_cmd():
    '''Runs configuration and checks root file format.'''

    cmd = []

    for configuration, output in tests.items():
        cmd += [
            'echo Running configuration "{0}"'.format(configuration),
            'cmsRun {0}'.format(configuration),
            'cp {0} {1}'.format(output, os.getenv('WORKSPACE')),
            'echo Validating configuration "{0}"'.format(configuration),
            '{0} -e {1}'.format(validator, output)
        ]

    return cmd

def test_CMSSW_7_0_4():
    '''Test CMSSW 7_0_4 project by running selected simulations and 
    reconstructions and checking the output using sw_tester tool.'''

    cmd = ' &&\n'.join(
        initialize_kerberos_keytab_cmd() +
        initialize_cms_environment_cmd() +
        run_and_validate_configs_cmd()
        )

    process = subprocess.Popen(['bash'],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        shell=True)

    (stdout, stderr) = process.communicate(cmd)

    log_message = 'COMMAND:\n{0}\nSTDOUT:\n{1}\nSTDERR:\n{2}'.format(cmd, stdout, stderr)
    with open(agent_test_log, 'w') as log_file:
        log_file.write(log_message)
    print(log_message)

    exit(process.returncode)

if __name__ == '__main__':
    test_CMSSW_7_0_4()

