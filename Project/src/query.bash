#!/bin/bash

index="OMNIKDTREE"
dataset_train="../datasets/train_nasa.csv"
separator_train=","
dataset_test="../datasets/test_nasa.csv"
separator_test=","
distance_function="EUCLIDEAN"
pivot_type=("RANDOM" "GNAT" "CONVEX" "KMEDOIDS" "MAXSEPARETED" "MAXVARIANCE" "SELECTION" "PCA" "SSS")
sample_size=(1.0 1.0 1.0 0.2 1.0 0.3 0.3 0.01 0.03)
num_pivots=2
seed=($(shuf -i 0-500000 -n 9))
k_max=100
num_query=1000
num_per_leaf=360 #only omni,kdtree
path_save_results="../results/"

mkdir -p ../omni/omni_files/
mkdir -p ../kdtree/kdtree_files/
mkdir -p ../results/

make clean
cp query.cpp main.cpp
/usr/lib/qt5/bin/qmake -makefile ProjectJoao.pro
#Qt/6.1.0/gcc_64/bin/qmake -makefile ProjectJoao.pro 
make

for((i=0; i<9; i++));
do
    nohup ./ProjectJoao -INDEX ${index} -DATASET_TRAIN ${dataset_train} -DATASET_TRAIN_SEPARATOR ${separator_train} -DATASET_TEST ${dataset_test} -DATASET_TEST_SEPARATOR ${separator_test} -DISTANCE_FUNCTION ${distance_function} -PIVOT_TYPE ${pivot_type[$i]} -SAMPLE_SIZE_PIVOT ${sample_size[$i]} -NUM_PIVOTS ${num_pivots} -SEED ${seed[$i]} -K_MAX ${k_max} -PATH_SAVE_RESULTS ${path_save_results} -NUM_PER_LEAF ${num_per_leaf} &
done
