#!/bin/bash

echo "Building..."
make clean
make


echo "Running workloads..."

N_1=100000000
N_2=1000000000
N_3=10000000000

NT_1=2
NT_2=4
NT_3=8


echo "Starting sequential Workloads..."
echo "----------------------------------------------------------------------------------------------------------------------"
./SeqWL $N_1
./SeqWL $N_2
./SeqWL $N_3
echo "----------------------------------------------------------------------------------------------------------------------"
echo "Sequential Workloads complete."

echo "Starting Multithreaded Workloads..."
echo "----------------------------------------------------------------------------------------------------------------------"
./Mthreads $N_1 $NT_1
./Mthreads $N_1 $NT_2
./Mthreads $N_1 $NT_3
./Mthreads $N_2 $NT_1
./Mthreads $N_2 $NT_2
./Mthreads $N_2 $NT_3
./Mthreads $N_3 $NT_1
./Mthreads $N_3 $NT_2
./Mthreads $N_3 $NT_3
echo "----------------------------------------------------------------------------------------------------------------------"

echo "Multithreaded Workloads complete."

echo "Starting Multitasking Workloads..."
echo "----------------------------------------------------------------------------------------------------------------------"
./Mtasks $N_1 $NT_1
./Mtasks $N_1 $NT_2
./Mtasks $N_1 $NT_3
./Mtasks $N_2 $NT_1
./Mtasks $N_2 $NT_2
./Mtasks $N_2 $NT_3
./Mtasks $N_3 $NT_1
./Mtasks $N_3 $NT_2
./Mtasks $N_3 $NT_3
echo "----------------------------------------------------------------------------------------------------------------------"
echo "Multitasking Workloads complete."


echo "All workloads complete."


