//
//  baselineWORKLOAD
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include<time.h>


int main(int argc, const char * argv[]) {
    long long inputNum = atoll(argv[1]);
    long long Sum=0;
    
    clock_t Start, Stop;
    Start = clock();
    for(int i=1; i<inputNum; i++){
        
        Sum += i;
        
    }
    Stop = clock();
    printf("Sum: %lld \n",Sum);
    double timer = (double)(Stop - Start)/CLOCKS_PER_SEC;
    printf("Time Elapsed: %0.13f", timer);
    
}
