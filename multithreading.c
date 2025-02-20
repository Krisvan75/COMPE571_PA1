/*
Multithreading implementation of WORKLOAD
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

unsigned __int128 total_sum = 0;


void *Workload(void *args){
    unsigned __int128 *thread_args = (unsigned __int128*)args;
    unsigned __int128 local_sum = 0;
    for(unsigned __int128 i=thread_args[0]; i<thread_args[1]; i++){
        local_sum += i;
    }
    thread_args[2] = local_sum;

    return NULL;

}



int main(int argc, const char * argv[]) {
    unsigned long long N = atoll(argv[1]);
    int numThreads = atoi(argv[2]);
    // Create an array of threads
    pthread_t threads[numThreads];
    clock_t Start, Stop;

    unsigned __int128 thread_args[numThreads][3]; //Start index, stop index, and local sum for each thread
    unsigned long long Nrange = N/numThreads;


    Start = clock();
    for(int i=0; i<numThreads; i++){
        thread_args[i][0] = (unsigned __int128) i * Nrange;
        thread_args[i][1] = (unsigned __int128)(i==numThreads-1) ? N : (i+1) * Nrange;
        pthread_create(&threads[i], NULL, Workload, (void *)&thread_args[i]);   
    }
    for(int i=0; i<numThreads; i++){
        pthread_join(threads[i], NULL);
        total_sum += thread_args[i][2];
    }
    Stop = clock();
    //printf("Sum: %lld \n",total_sum);
    double timer = (double)(Stop - Start)/CLOCKS_PER_SEC;
    printf("Sum of %llu integers with %d threads\tTime taken to compute: %0.8f\n", N,numThreads,timer);
    
    return 0;
    
}