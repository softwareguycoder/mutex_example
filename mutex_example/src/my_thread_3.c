#include "stdafx.h"
#include "mutex_example.h"

#include "my_thread_3.h"

#define MY_THREAD_FUNCTION_3_DONE "my_thread_function_3: Done."
#define MY_THREAD_FUNCTION_3_RESULTS "my_thread_function_3:\n\tThread ID: %d\tStatic: %d\tGlobal: %d"

#define MY_THREAD_FUNCTION_3_ERROR_VARGP_NULL "my_thread_function_3: Must pass the address of an int in vargp."

///////////////////////////////////////////////////////////////////////////////
// my_thread_function_3: Thread that changes global variables and uses args

void *my_thread_function_3(void *vargp)
{
	log_info("In my_thread_function_3");

	log_info(MY_THREAD_FUNCTION_3_DONE);

	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
