#!/bin/bash

dataset_name="../datasets/ulcer_SPP.csv"
dataset_separator=","
distance_function=("EUCLIDEAN" "COSINE" "BRAYCURTIS" "TANIMOTO" "MATUSITA")
sample_size=20000
seed=($(shuf -i 0-500000 -n 5))

make clean
cp mainIntrinsicDimensionality.cpp main.cpp
/usr/lib/qt5/bin/qmake -makefile ProjectJoao.pro
#Qt/6.1.0/gcc_64/bin/qmake -makefile ProjectJoao.pro 
make

for((i=0; i<5; i++));
do
    nohup ./ProjectJoao -DATASET_NAME ${dataset_name} -DATASET_SEPARATOR ${dataset_separator} -DISTANCE_FUNCTION ${distance_function[$i]} -SAMPLE_SIZE ${sample_size} -SEED ${seed[$i]} &
done
