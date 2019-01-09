// MUTEX_EXAMPLE.H: Header file for the functions declared in the main mutex_example.c file that we can
// expose to the rest of the program. Obviously, main() will not be exposed.
//

#ifndef __MUTEX_EXAMPLE_H__
#define __MUTEX_EXAMPLE_H__

#include "mutex.h"

// Variable is implemented in the mutex_example.c file
extern int g;

// Variable is implemented in the mutex_example.c file
extern int counter;

// Lock object for the global mutex
extern HMUTEX hGlobalMutex;

// Let us create a global array of thread IDs (for example #3)
extern pthread_t thread_ids[NUM_THREADS_FOR_EXAMPLE_3];

#endif	//__MUTEX_EXAMPLE_H__
