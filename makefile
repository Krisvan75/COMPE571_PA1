CFLAGS= -Wall

all: seqWL Mthreads Mtasks

seqWL: sequentialWORKLOAD.c 
	gcc $(CFLAGS) -o seqWL sequential.c

Mthreads: multithreading.c
	gcc $(CFLAGS) -o Mthreads multithreading.c

Mtasks: multitasking.c
	gcc $(CFLAGS) -o MTasks multitasking.c

clean:
	rm -f seqWL Mthreads Mtasks

.PHONY: all clean


