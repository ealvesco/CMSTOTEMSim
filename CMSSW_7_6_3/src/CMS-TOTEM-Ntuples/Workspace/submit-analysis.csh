#!/bin/csh

if ($#argv != 3) then
    echo "************** Argument Error: 5 arguments required **************"
    echo "   Usage:"
    echo "     ./submit-analysis.csh preAna taskName inputFiles.txt"
    echo "*************************************************************"
    exit 1
endif

set EXE_DIR = $PWD

#set cmd = "prelAna"
set cmd = $1
set name = $2
set files = $3
#
set n_lines_per_job = 100
# set queue = 1nh
set queue = 1nh
# 8nm (8 minutes) 1nh (1 hour) 8nh 1nd (1day) 1nw (1 week)

echo $files

set submit_dir = $PWD/submit-$name
set output_dir = $submit_dir

if( ! ( -e $submit_dir ) ) then
    mkdir $submit_dir
endif

cp $files $submit_dir/
cd $submit_dir

###########################
#
split -a 3 -l $n_lines_per_job -d $files files_

set jobs=`ls files_*` 
echo $jobs

set njobs=`ls files_* | wc -l` 
echo "will create $njobs jobs"

set i = 1
foreach job ( $jobs )

echo "Producing job number $i..."

echo "Writing $output_dir/${name}_${i}.csh"
cat > $output_dir/${name}_${i}.csh <<EOF
#!/bin/tcsh

set WORK_DIR_NODE = \$PWD 
echo "Working in directory \$WORK_DIR_NODE"

cd $CMSSW_BASE/src
cmsenv
rehash
cd \$WORK_DIR_NODE

$EXE_DIR/$cmd $output_dir/$job $output_dir/output_${name}_${i}.root -1 >&! $output_dir/out_${name}_${i}.txt

EOF
#$output_dir/output_${name}_${i}.root $file >&! $output_dir/out_${name}_${i}.txt
	
chmod +x $output_dir/${name}_${i}.csh
#cd $submit_dir
bsub -q $queue ${name}_${i}.csh  -o /afs/cern.ch/work/k/kshcheli/private/tan/CMSSW_7_4_15/src/CMS-TOTEM-Ntuples/Workspace/go/nn%J 

@ i++
end

cd ../
