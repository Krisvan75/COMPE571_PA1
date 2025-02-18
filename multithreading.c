/*
Multithreading implementation of WORKLOAD
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

long long total_sum = 0;


void* Workload(void *args){
    long long *thread_args = (long long *)args;
    long long local_sum = 0;
    for(long long i=thread_args[0]; i<thread_args[1]; i++){
        local_sum += i;
    }
    thread_args[2] = local_sum;


}



int main(int argc, const char * argv[]) {
    unsigned long long inputNum = atoll(argv[1]);
    int numThreads = atoi(argv[2]);
    // Create an array of threads
    pthread_t threads[numThreads];
    clock_t Start, Stop;

    unsigned long long thread_args[numThreads][3]; //Start index, stop index, and local sum for each thread
    unsigned long long chunk = inputNum/numThreads;


    Start = clock();
    for(int i=0; i<numThreads; i++){
        thread_args[i][0] = i * chunk;
        thread_args[i][1] = (i==numThreads-1) ? inputNum : (i+1) * chunk;
        pthread_create(&threads[i], NULL, Workload, (void *)&thread_args[i]);   
    }
    for(int i=0; i<numThreads; i++){
        pthread_join(threads[i], NULL);
        total_sum += thread_args[i][2];
    }
    Stop = clock();
    printf("Sum: %lld \n",total_sum);
    double timer = (double)(Stop - Start)/CLOCKS_PER_SEC;
    printf("Time Elapsed: %0.13f", timer);
    
    return 0;
    
}