// MUTEX_EXAMPLE.C: File containing the program entry point and code that is central to the execution of global
// application functionality
//

#include "stdafx.h"
#include "mutex_example.h"

#include "my_thread.h"

///////////////////////////////////////////////////////////////////////////////
// thread_example_1: Trivial example of working with a simple thread

void thread_example_1(void)
{
	log_info("In thread_example_1");

	// Multithreading trial - code from
	// <https://www.geeksforgeeks.org/multithreading-c-2/>

	pthread_t thread_id;
	log_info("Before Thread");
	pthread_create(&thread_id, NULL, my_thread_function, NULL);
	pthread_join(thread_id, NULL);
	log_info("After Thread");

	log_info("thread_example1: Done.");
}

///////////////////////////////////////////////////////////////////////////////
// main function - entry point

int main(int argc, char* argv[])
{
	log_info("In main");

	log_info("main: Calling thread_example_1...");

	thread_example_1();

	log_info("main: Called thread_example_1.");

	log_info("main: result = %d", OK);

	log_info("main: Done.");

	return OK;
}

///////////////////////////////////////////////////////////////////////////////";
