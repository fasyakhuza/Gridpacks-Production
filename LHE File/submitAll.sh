#!/bin/bash

dir=$1
echo "Running on the gridpacks in directory " $dir
for file in $(ls $dir/*xz) 
do
    echo $file
    bsub -q2nd $PWD/runJob3.sh $PWD $file
done
