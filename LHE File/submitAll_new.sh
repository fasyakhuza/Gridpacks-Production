#!/bin/bash

dir=$(find test3/ZpBaryonic_test/*xz)
echo "Running on the gridpacks in directory " $dir
for file in $dir
do
    echo $file
    bsub -q2nd $PWD/runJob3.sh $PWD "/afs/cern.ch/work/f/fkhuzaim/genproductions/bin/MadGraph5_aMCatNLO/"$file
done
