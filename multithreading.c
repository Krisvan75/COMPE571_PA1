/*
Multithreading implementation of WORKLOAD
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include<time.h>
#include <pthread.h>

pthread_mutex_t mutex;
long long total_sum = 0;


void *Workload(void *args){
    int *thread_args = (int *)args;
    long long local_sum = 0;
    for(int i=thread_args[0]; i<thread_args[1]; i++){
        local_sum += i;
    }
    pthread_mutex_lock(&mutex);
    total_sum += local_sum;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}



int main(int argc, const char * argv[]) {
    long long inputNum = atoll(argv[1]);
    int numThreads = atoi(argv[2]);
    // Create an array of threads
    pthread_t threads[numThreads];
    clock_t Start, Stop;

    int thread_args[2][numThreads]; //Start index, stop index, and local sum for each thread
    int chunk = inputNum/numThreads;

    Start = clock();
    for(int i=0; i<numThreads; i++){
        thread_args[0][i] = i * chunk;
        thread_args[1][i] = (i+1) * chunk;

        pthread_create(&threads[i], NULL, Workload, (void *)&thread_args[i]);   
    }
    for(int i=0; i<numThreads; i++){
        pthread_join(threads[i], NULL);
    }
    Stop = clock();
    printf("Sum: %lld \n",total_sum);
    double timer = (double)(Stop - Start)/CLOCKS_PER_SEC;
    printf("Time Elapsed: %0.13f", timer);
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
    
}