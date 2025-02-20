//
//  baselineWORKLOAD
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include<time.h>


int main(int argc, const char * argv[]) {
    unsigned long long N = atoll(argv[1]);
    unsigned __int128 Sum;
    
    clock_t Start, Stop;
    Sum=0;
    Start = clock();
    for(unsigned long long i=1; i<N; i++){
        Sum += i;
    }
    Stop = clock();
    //printf("Sum: %lld \n",Sum);
    double timer = (double)(Stop - Start)/CLOCKS_PER_SEC;
    printf("Sum of %llu integers\tTime taken to compute: %0.8f\n", N,timer);
}
