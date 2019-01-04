#include "stdafx.h"
#include "mutex_example.h"

#include "my_thread_2.h"

#define MY_THREAD_FUNCTION_2_DONE "my_thread_function_2: Done."
#define MY_THREAD_FUNCTION_2_RESULTS "my_thread_function_2:\n\tThread ID: %d\tStatic: %d\tGlobal: %d"

#define MY_THREAD_FUNCTION_2_ERROR_VARGP_NULL "my_thread_function_2: Must pass the address of an int in vargp."

///////////////////////////////////////////////////////////////////////////////
// my_thread_function_2: Thread that changes global variables and uses args

void *my_thread_function_2(void *vargp)
{
	log_info("In my_thread_function_2");

	/* In this thread function, we are expecting args to be passed in.
	 * So, first we check whether vargp is NULL. If it is, then obviously,
	 * soemthing is wrong and needs to be fixed.
	 */

	if (vargp == NULL){
		log_error(MY_THREAD_FUNCTION_2_ERROR_VARGP_NULL);
		log_info(MY_THREAD_FUNCTION_2_DONE);
		return NULL;
	}

	// Argument passed should be the address of an int variable
	int* pId = (int*)vargp;

	// Let us introduce a static variable to see how it changes

	static int s = 0;

	// Change both the static and global variables
	++s; ++g;

	toggle_debug(TRUE); // @suppress("Symbol is not resolved")

	// Print the results
	log_info(MY_THREAD_FUNCTION_2_RESULTS, *pId, ++s, ++g);

	toggle_debug(FALSE); // @suppress("Symbol is not resolved")

	log_info(MY_THREAD_FUNCTION_2_DONE);

	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
