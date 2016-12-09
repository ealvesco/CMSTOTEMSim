#!/bin/env python

import sys,os,stat
import optparse
from subprocess import Popen,PIPE

def listFilesInEOS(eos_dir,type,prefix=""):
    lscmd ='/afs/cern.ch/project/eos/installation/0.3.84-aquamarine/bin/eos.select ls'
    lscmd = '%s %s' % (lscmd,eos_dir)

    print lscmd

    p1 = Popen(lscmd,shell=True,stdout=PIPE)
    p2 = Popen(['grep',type],stdin=p1.stdout,stdout=PIPE)
    p3 = Popen(['grep','.root'],stdin=p2.stdout,stdout=PIPE)
    files = [ "%s%s" % (prefix,val[:-1]) for val in p3.stdout]
    p3.stdout.close()

    return files

def generateFileDict(nFilesPerJob,totem_dir,cms_dir,totem_type,cms_type,totem_prefix,cms_prefix):
    from subprocess import call

    totemfiles = listFilesInEOS(totem_dir,totem_type)
    cmsfiles = listFilesInEOS(cms_dir,cms_type)

    print "##################################"
    print "Generate list from TOTEM and CMS n-tuples"
    print "Nr. of CMS files           : ", len(cmsfiles)
    print "Nr. of TOTEM files         : ", len(totemfiles)

    totemGroups = []
    while len(totemfiles):
        totemGroups.append( totemfiles[:nFilesPerJob])
        totemfiles = totemfiles[nFilesPerJob:]

    print "Nr. of TOTEM file groupings: ", len(totemGroups)
    print "##################################"

    print "List of TOTEM files:"
    print "---"
    for group in totemGroups:
        for fileName in group: print fileName 
        print "---"

    print "List of CMS files:"
    for fileName in cmsfiles: print fileName
   
    f={}
    print "List of combinations:"
    for indexCMS in range(len(cmsfiles)):
	for indexTOTEM in range(len(totemGroups)):
            mergeName = "%s_%s" % ( totemGroups[indexTOTEM][0].rstrip(".root"),cmsfiles[indexCMS].rstrip(".root") )
            print mergeName 
 
            cmsFilePath = cms_prefix + cms_dir + "/" + cmsfiles[indexCMS] 
            fileListTOTEM = [ totem_prefix + totem_dir + "/" + item for item in totemGroups[indexTOTEM] ]

            f[mergeName] = (cmsFilePath,fileListTOTEM)
    
    print "Nr. of CMS-TOTEM combinations:", len(f)
    print "####################################"
    return f

# Find pairs of TOTEM and CMS files
def findCMSTOTEM(nFilesPerJob,totem_dir,cms_dir,totem_type,cms_type,totem_prefix,cms_prefix):
    #from subprocess import call
    files_ = generateFileDict(nFilesPerJob,totem_dir,cms_dir,totem_type,cms_type,totem_prefix,cms_prefix)
    return files_

# Changes the rights for file (for scripts)
def chmod(f):
    os.chmod(f, stat.S_IRWXU | stat.S_IRGRP | stat.S_IROTH)

# Create a script that:
# - sets the gcc and root environment
# - runs orbit offset searching or merging
# - copies the output files from pool to output directory     
def createJobFile(cms, totemFiles, output, cmsRunNumber, orbitOffset, cmsFirstLumi, cmsLastLumi, outputEOS, cmsswPath):
    outdir = os.getcwd() + "/"
    output_label = output.split('/')[-1].rstrip("root").rstrip(".")
    stdOutName = output_label + "_out"
    fileName = output_label + "_job.sh"
    jobFile = open(fileName, "w")
    
    chmod(fileName)

    totemFilePaths = totemFiles
    cmsFilePath = cms

    output_local = output_label + ".root"
    #stdOutNamePath = outdir + stdOutName
    stdOutNamePath = stdOutName

    runJob = None
    if compiledProgramPath.split('/')[-1] == 'mergeNtuples':
	runJob = compiledProgramPath  + " " + totemFilePaths[0] + " " + cmsFilePath + " " + output_local + " " + str(cmsRunNumber)+ " " + str(orbitOffset) + " " + str(cmsFirstLumi)  + " " + str(cmsLastLumi) + " > " + stdOutNamePath + "\n"
    elif compiledProgramPath.split('/')[-1] == 'findOrbitOffset':
        output_local = "out_findOrbitOffset_" + output_local
        stdOutNamePath = outdir + "findOrbitOffset_" + stdOutName
	runJob = compiledProgramPath  + " " + totemFilePaths[0] + " " + cmsFilePath + " " + output_local + " " + str(cmsFirstLumi)  + " " + str(cmsLastLumi) + " > " + stdOutNamePath + "\n"
    elif compiledProgramPath.split('/')[-1] == 'mergeNtuplesNew':
        #mergeNtuples <CMS run number> <offset> <first CMS lumi> <last CMS lumi> <Output file name> <CMS data file> <TOTEM data file 1> [<TOTEM data file 2>,...]
	runJob = compiledProgramPath
        runJob += " " + str(cmsRunNumber)
        runJob += " " + str(orbitOffset)
        runJob += " " + str(cmsFirstLumi) + " " + str(cmsLastLumi)
        runJob += " " + output_local
        runJob += " " + cmsFilePath
        for filePath in totemFilePaths: runJob += " " + filePath
        runJob += " > " + stdOutNamePath + "\n"
    else:
	runJob = compiledProgramPath + " " + totemFilePaths[0] + " " + cmsFilePath + " " + output_local + " > " + stdOutNamePath + "\n"

    jobFile.write( "#!/bin/bash\n" )
    jobFile.write( "WORK=$PWD" + "\n" )

    # Environment initialized explicitely
    #jobFile.write( "source /cvmfs/cms.cern.ch/slc6_amd64_gcc491/external/gcc/4.9.1-cms/etc/profile.d/init.sh\n" )
    #jobFile.write( "source /cvmfs/cms.cern.ch/slc6_amd64_gcc491/external/xrootd/4.0.4-odfocd/etc/profile.d/init.sh\n" )
    #jobFile.write( "source %s/bin/thisroot.sh\n" % os.environ['ROOTSYS'] )

    # Environment initialized using CMSSW SCRAM area
    jobFile.write( "source /cvmfs/cms.cern.ch/cmsset_default.sh\n" )
    jobFile.write( "cd " + cmsswPath + "\n" )
    jobFile.write( "eval `scramv1 runtime -sh`\n" )

    jobFile.write( "cd $WORK" + "\n" )
    jobFile.write(runJob)
    # Get return code from executable and append to log file 
    jobFile.write( "ret_code=$?\n" )
    jobFile.write( "echo \"EXECUTABLE RETURN CODE=\"$ret_code"  + " >> " + stdOutNamePath + "\n" )

    cp = ""
    rm = "rm"
    if outputEOS == True:
        cp = "xrdcp"
    else:
        cp = "cp"

    copyRootFile      = cp + " " + "$WORK/" + output_local + " " + output
    copyStdOutFileEOS = cp + " " + stdOutNamePath + " " + '/'.join( output.split('/')[:-1] ) + "/" + stdOutName
    copyStdOutFileLocal = "cp " + stdOutNamePath + " " + outdir

    # BASH
    jobFile.write( "if [ ! -f %s ]; then echo \"Output file not created\"; echo \"OUTPUT FILE NOT CREATED\" >> %s; %s; exit 1; fi\n" % (output_local,stdOutNamePath, copyStdOutFileLocal) )

    # Copy output file
    jobFile.write( copyRootFile + "\n" )
    # Get return code from executable and append to log file 
    jobFile.write( "ret_code=$?\n" )
    jobFile.write( "echo \"COPY COMMAND RETURN CODE=\"$ret_code"  + " >> " + stdOutNamePath + "\n" )
     
    # Copy STDOUT to local dir
    jobFile.write( copyStdOutFileLocal + "\n" )

    # Copy STDOUT to EOS (commented)
    jobFile.write("#" + copyStdOutFileEOS + "\n")

    # Clean-up of local area
    delRootFile = rm + " " + "$WORK/" + output_local
    jobFile.write( delRootFile + "\n" )
    jobFile.write( "rm " + stdOutNamePath + "\n" )
    jobFile.close()
    return fileName

if __name__ == '__main__':

    parser = optparse.OptionParser(usage="usage: %prog [options]")
    parser.add_option("--totemDir", dest="totemDir", help="TOTEM directory")
    parser.add_option("--totemFileType", dest="totemFileType", default=".root", metavar="TYPE", help="Select files matching TYPE")
    parser.add_option("--cmsDir", dest="cmsDir", help="CMS directory")
    parser.add_option("--cmsFileType", dest="cmsFileType", default=".root", metavar="TYPE", help="Select files matching TYPE")
    parser.add_option("--outputDir", dest="outputDir", help="Output directory")
    parser.add_option("--submitDir", dest="submitDir", default="submit", help="Local directory where LSF jobs are defined")
    parser.add_option("--queue", dest="queue", default="1nw", help="LSF queue name")
    parser.add_option("--cmsRunNumber", dest="cmsRunNumber", type="int", help="CMS Run number")
    parser.add_option("--orbitOffset", dest="orbitOffset", type="int", help="Orbit offset")
    parser.add_option("--cmsFirstLumi", dest="cmsFirstLumi", type="int", default = "-1", help="First CMS lumi section")
    parser.add_option("--cmsLastLumi", dest="cmsLastLumi", type="int", default = "-1", help="Last CMS lumi section")
    parser.add_option("--nFilesPerJob", dest="nFilesPerJob", type="int", default = "1", help="Number of TOTEM files per job")

    (input, args) = parser.parse_args()

    allowedTypes = ('mergeNtuples','findOrbitOffset','mergeNtuplesNew')
    input.programType = 'mergeNtuples'
    if len(args) > 0: 
        if args[0] not in allowedTypes: parser.error('[ERROR] Option "%s" not allowed' % args[0])
        input.programType = args[0]

    requiredFields = ('totemDir','cmsDir','outputDir','cmsRunNumber','orbitOffset')
    for val in requiredFields:
        if not getattr(input,val):
            parser.error('[ERROR] Option "%s" needs to be set' % val) 

    requiredEnv = ('CMSSW_BASE','CMSTOTEM_BASE')
    #requiredEnv = ('CMSTOTEM_BASE','ROOTSYS')
    for val in requiredEnv:
        if not os.environ.has_key(val):
            parser.error('[ERROR] Environment variable "%s" needs to be set' % val) 
    
    if input.programType != 'mergeNtuplesNew': input.nFilesPerJob = 1

    cmssw_dir = "%s/src/" % os.environ['CMSSW_BASE']
    # Path to the compiled program
    #compiledProgramPath = "%s/Merge/mergeNtuples" % os.environ['CMSTOTEM_BASE']   
    compiledProgramPath = "%s/Merge/%s" % ( os.environ['CMSTOTEM_BASE'] , input.programType )  

    # Directory where totem ntuples are stored, please put "root://eostotem/directoryName" if it is on EOS
    #totemDirectory = "root://eostotem/" + totemDir 

    # Directory where cms ntuples are stored, "root://eoscms/directoryName" if it's on EOS
    #cmsDirectory = "root://eoscms/" + cmsDir

    totemFilePrefix = "root://eostotem/"
    #cmsFilePrefix = "root://eoscms/"
    cmsFilePrefix = "root://eostotem/"

    # The map contains the runs that are going to be merged
    # key - merged file name
    # value - (cmsNtuple, (totemNtuple 1,totemNtuple 2,...))
    files = findCMSTOTEM(input.nFilesPerJob,input.totemDir,input.cmsDir,input.totemFileType,input.cmsFileType,totemFilePrefix,cmsFilePrefix)

    # If the output directory is on CASTOR set outputCastor = True
    # If the output directory is on EOS set outputEOS = True
    #outputCastor = False
    outputEOS = True

    # Location where merged #files will be stored
    #outputDirectory = "root://eoscms/"
    outputFilePrefix = "root://eostotem/" 
    outputDirectory = "root://eostotem/" + input.outputDir

    # LXBATCH queue
    queueName = input.queue

    # Create directory for files
    #directory = "submit"
    directory = input.submitDir
    if not os.path.exists(directory):
	os.makedirs(directory)
    os.chdir(directory)

    submitFileName = "submit.sh"
    submitFile = open( submitFileName , "w" )  
    chmod(submitFileName)

    pbash = "#!/bin/bash" + "\n"
    localarea = os.getcwd()+"/"                                                                                              
    cdpath ="cd " + localarea + "\n"
    submitFile.write(pbash)
    submitFile.write(cdpath)

    # Create scripts for every pair of ntuples and then create one script that will submit the jobs on lxbatch
    for output, inputFiles in files.iteritems():
	cms        = inputFiles[0]
	totemFiles = inputFiles[1]

	jobFileName = createJobFile(cms, totemFiles, outputDirectory + "/" + output + ".root", input.cmsRunNumber, input.orbitOffset, input.cmsFirstLumi, input.cmsLastLumi, outputEOS, cmssw_dir)

	jobName = jobFileName.rstrip(".sh")

	submitJobFile = "bsub -J " + jobName + " -R \"swp>2000&&pool>40000\" -q " + queueName + " " + jobFileName + "\n"
	submitFile.write(submitJobFile)
    
    submitFile.close()
