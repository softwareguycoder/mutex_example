#include "stdafx.h"
#include "mutex_example.h"

#include "my_thread_3.h"

#define MY_THREAD_FUNCTION_3_DONE "my_thread_function_3: Done."
#define MY_THREAD_FUNCTION_3_RESULTS "my_thread_function_3:\n\tThread ID: %d\tStatic: %d\tGlobal: %d"

#define MY_THREAD_FUNCTION_3_ERROR_VARGP_NULL "my_thread_function_3: Must pass the address of an int in vargp."

#define LONG_MAX  0xFFFFFFFF

///////////////////////////////////////////////////////////////////////////////
// my_thread_function_3: Thread that changes global variables and uses args

void *my_thread_function_3(void *vargp)
{
	log_info("In my_thread_function_3");

	/* Check to ensure that the argument, vargp, is not a NULL pointer.
	 * If it is, then stop the function and report an error. */
	if (vargp == NULL) {
		log_error(MY_THREAD_FUNCTION_3_ERROR_VARGP_NULL);
		log_info(MY_THREAD_FUNCTION_3_DONE);
		return NULL;
	}

	counter+=1;

	log_info("Beginning job #%d...", counter);

	/* This for loop is just here to make this thread last a long time */
	for(unsigned long i = 0; i < LONG_MAX; i++);

	log_info("Job #%d is done.", counter);

	log_info(MY_THREAD_FUNCTION_3_DONE);

	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
