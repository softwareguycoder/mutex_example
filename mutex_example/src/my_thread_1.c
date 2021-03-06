#include "stdafx.h"
#include "mutex_example.h"

#include "my_thread_1.h"

///////////////////////////////////////////////////////////////////////////////
// my_thread_function: Defines the operations for the thread

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *my_thread_function_1(void *vargp) {
	log_debug("In my_thread_function_1");

	sleep(1);

	log_info("my_thread_function_1: Hello, world!");
	log_info("my_thread_function_1: Yay the thread works!");
	log_info("my_thread_function_1: Done.");

	return NULL;
}

///////////////////////////////////////////////////////////////////////////////
