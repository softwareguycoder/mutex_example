#include "stdafx.h"
#include "mutex_example.h"

#include "my_thread_2.h"

#define MY_THREAD_FUNCTION_2_DONE "my_thread_function_2: Done."
#define MY_THREAD_FUNCTION_2_RESULTS "my_thread_function_2:\n\tThread ID: %lu\tStatic: %d\tGlobal: %d"

#define MY_THREAD_FUNCTION_2_ERROR_VARGP_NULL "my_thread_function_2: Must pass the address of an int in vargp."

///////////////////////////////////////////////////////////////////////////////
// my_thread_function_2: Thread that changes global variables and uses args

void *my_thread_function_2(void *vargp) {
	log_info("In my_thread_function_2");

	/* In this thread function, we are expecting args to be passed in.
	 * So, first we check whether vargp is NULL. If it is, then obviously,
	 * soemthing is wrong and needs to be fixed.
	 */

	log_info(
			"my_thread_function_2: Checking whether arguments have been passed...");


	if (vargp == NULL) {
		log_error(MY_THREAD_FUNCTION_2_ERROR_VARGP_NULL);

		log_info(MY_THREAD_FUNCTION_2_DONE);

		return NULL;
	}

	log_info(
			"my_thread_function_2: Arguments have been passed.  Assuming a pointer to an integer has been passed.");

	// Argument passed should be the address of an int variable
	int* pThreadID = (int*) vargp;

	if (NULL != pThreadID) {
		log_info("my_thread_function_2: Successfully unpacked arguments.");
	} else {
		log_error(
				"my_thread_function_2: Null value passed for required argument.  Stopping.");

		log_info("my_thread_function_2: Done.");

		return NULL;
	}

	log_info("my_thread_function_2: Doing work...");

	// Let us introduce a static variable to see how it changes

	static int s = 0;

	// Change both the static and global variables
	++s;
	++g;

	log_info("my_thread_function_2:: Work completed.");

	// Print the results
	log_info(MY_THREAD_FUNCTION_2_RESULTS, *pThreadID, ++s, ++g);

	//toggle_debug(FALSE); // @suppress("Symbol is not resolved")

	log_info(MY_THREAD_FUNCTION_2_DONE);

	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
