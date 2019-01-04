// MUTEX_EXAMPLE.C: File containing the program entry point and code that is central to the execution of global
// application functionality
//

#include "stdafx.h"
#include "mutex_example.h"

#include "my_thread.h"
#include "my_thread_2.h"

// Let us create a global variable to change it in threads
int g = 0;

///////////////////////////////////////////////////////////////////////////////
// thread_example_1: Trivial example of working with a simple thread

void thread_example_1(void)
{
	log_info("In thread_example_1");

	// Multithreading trial - code from
	// <https://www.geeksforgeeks.org/multithreading-c-2/>

	pthread_t thread_id;
	log_info("thread_example_1: Before Thread");
	pthread_create(&thread_id, NULL, my_thread_function, NULL);
	pthread_join(thread_id, NULL);
	log_info("thread_example_1: After Thread");

	log_info("thread_example1: Done.");
}

///////////////////////////////////////////////////////////////////////////////
// thread_example_2: Example of calling a thread, passing args, and changing
// global variables
//

void thread_example_2(void)
{
	log_info("In thread_example_2");

	// Multithreading trial - code from
	// <https://www.geeksforgeeks.org/multithreading-c-2/>

	// Let us create three threads
	const int NUM_THREADS = 3;

	pthread_t tid;

	for(int i = 0; i < NUM_THREADS; i++) {
		log_info("thread_example_2: Before Thread #%d", i+1);
		pthread_create(&tid, NULL, my_thread_function_2, (void*)&tid);
		pthread_join(tid, NULL);
		log_info("thread_example_2: After Thread #%d", i+1);
	}

	log_info("thread_example_2: Done.");
}

///////////////////////////////////////////////////////////////////////////////
// main function - entry point

int main(int argc, char* argv[])
{
	// Turn off all logging
	//toggle_debug(FALSE); // @suppress("Symbol is not resolved")

	log_info("In main");

	log_info("main: Calling thread_example_1...");

	thread_example_1();

	log_info("main: Called thread_example_1.");

	log_info("main: Calling thread_example_2...");

	thread_example_2();

	log_info("main: Called thread_example_2.");

	log_info("main: result = %d", OK);

	log_info("main: Done.");

	return OK;
}

///////////////////////////////////////////////////////////////////////////////";
