// MUTEX_EXAMPLE.C: File containing the program entry point and code that is central to the execution of global
// application functionality
//

#include "stdafx.h"
#include "mutex_example.h"

#include "threading_examples.h"

// Let us create a global variable to change it in threads
int g = 0;

// Let us create a global counter
int counter = 0;

// Let us create a global array of thread IDs (for example #3)
pthread_t thread_ids[NUM_THREADS_FOR_EXAMPLE_3];

// Let us create a global for the mutex lock object
//pthread_mutex_t lock;
HMUTEX hGlobalMutex;	// global mutex handle

///////////////////////////////////////////////////////////////////////////////
// main function - entry point

int main(int argc, char* argv[]) {
	log_debug("In main");

	log_info("main: Seeding the random number generator...");

	unsigned int nResult = (unsigned int) time(NULL);

	srand(nResult);

	log_info("main: Random number generator seeded with value %u.", nResult);

	log_info("main: Attempting to initialize global mutex object...");

	// Initialize the mutex lock object ( allocate a new one
	// in memory if necessary ) and then attempt to get a handle
	// to it.

	hGlobalMutex = CreateMutex();

	log_info(
			"main: Checking whether mutex handle was allocated and initialized successfully...");

	if (INVALID_HANDLE_VALUE == hGlobalMutex) {
		log_error("Failed to initialize mutex.");

		log_info("main: Done.");

		return ERROR;
	}

	log_info(
			"main: Global mutex handle allocated and initialized successfully.");

	log_info("main: Calling thread_example_1...");

	thread_example_1();

	log_info("main: Called thread_example_1.");

	log_info("main: Calling thread_example_2...");

	thread_example_2();

	log_info("main: Called thread_example_2.");

	log_info("main: Calling thread_example_3...");

	thread_example_3();

	log_info("main: Called thread_example_3.");

	log_info(
			"main: Attempting to release resources consumed by the global mutex object back to the operating system...");

	// Done with the mutex object, so destroy and de-allocate it.
	DestroyMutex(hGlobalMutex);

	log_info("main: Global mutex resources have been released.");

	log_info("main: result = %d", OK);

	log_info("main: Done.");

	return OK;
}

///////////////////////////////////////////////////////////////////////////////";
