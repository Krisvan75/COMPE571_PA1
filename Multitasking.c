/*
Multitasking implementation of WORKLOAD
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int argc, const char *argv[]){
    long long N = atoll(argv[1]);
    int numProcesses = atoi(argv[2]);
    
    
    long long chunk = N/numProcesses;
    int pipes[numProcesses][2];
    pid_t PIDs[numProcesses];
    clock_t Start, Stop;
    Start = clock();

    for(int i=0;i<numProcesses;i++){
        pipe(pipes[i]);
        PIDs[i] = fork();
        if(PIDs[i] == 0){
            long long start = i*chunk;
            long long end = (i==numProcesses-1) ? N : (i+1)*chunk;
            long long local_sum = 0;
            for(long long j=start; j<end; j++){
                local_sum += j;
            }
            write(pipes[i][1], &local_sum, sizeof(local_sum));
            close(pipes[i][1]);
            exit(0);
        }
    }
    long long total_sum = 0;
    for(int i=0; i<numProcesses; i++){
        long long local_sum;
        read(pipes[i][0], &local_sum, sizeof(local_sum));
        close(pipes[i][0]);
        total_sum += local_sum;
    }
    Stop = clock();
    double timer = (double)(Stop - Start)/CLOCKS_PER_SEC;
    printf("Sum: %lld\n", total_sum);
    printf("Time Elapsed: %0.13f\n", timer);
    return 0;
}