#include "stdafx.h"
#include "mutex_example.h"

#include "my_thread_3.h"
#include "mutex.h"

#define MY_THREAD_FUNCTION_3_DONE "my_thread_function_3: Done."
#define MY_THREAD_FUNCTION_3_RESULTS "my_thread_function_3:\n\tThread ID: %d\tStatic: %d\tGlobal: %d"

#define MY_THREAD_FUNCTION_3_WARN_VARGP_NULL "my_thread_function_3: vargp has a NULL value."

#define LONG_MAX  0xFFFFFFFF

///////////////////////////////////////////////////////////////////////////////
// my_thread_function_3: Thread that changes global variables and uses args

void *my_thread_function_3(void *vargp)
{
	log_info("In my_thread_function_3");

	log_info("my_thread_function_3: Checking whether there are any args...");

	/* Check to ensure that the argument, vargp, is not a NULL pointer.
	 * If it is, then warn the user but do not stop the function. */
	if (vargp == NULL) {
		log_warning(MY_THREAD_FUNCTION_3_WARN_VARGP_NULL);
	}

	// Lock the mutex to prevent other threads from running the code below
	// at the same time we are.

	// NOTE: 'lock' is a global variable we've defined in mutex_example.h
	// and implemented in mutex_example.c

	log_info("my_thread_function_3: Attempting to get a mutually-exclusive lock on the global mutex...");

	LockMutex(hGlobalMutex);
	{
		log_info("my_thread_function_3: Obtained mutually-exclusive lock.");

		log_info("my_thread_function_3: Counter before job start = %d", counter);

		counter+=1;

		log_info("my_thread_function_3: Value of counter after increment = %d", counter);

		log_info("Beginning job #%d...", counter);

		log_info("my_thread_function_3: Doing work...");

		/* This for loop is just here to make this thread last a long time */
		for(unsigned long i = 0; i < LONG_MAX; i++);

		log_info("my_thread_function_3: Job #%d is done.", counter);

		log_info("my_thread_function_3: Releasing the mutually-exclusive lock...");
	}
	UnlockMutex(hGlobalMutex);

	log_info("my_thread_function_3: Mutually-exclusive lock released.");

	log_info(MY_THREAD_FUNCTION_3_DONE);

	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
