///////////////////////////////////////////////////////////////////////////////
// threading_examples.c: Driver functions that run the threading examples

#include "stdafx.h"
#include "mutex_example.h"

#include "threading_examples.h"

///////////////////////////////////////////////////////////////////////////////
// thread_example_1: Driver function for the trivial example of working with a
// simple and synchronous thread

void thread_example_1(void) {
	log_debug("In  thread_example_1");

	// Multithreading trial - code from
	// <https://www.geeksforgeeks.org/multithreading-c-2/>

	pthread_t thread_id;

	log_info("thread_example_1: Attempting to create thread...");

	int nResult = pthread_create(&thread_id, NULL, my_thread_function_1, NULL);
	if (OK != nResult) {
		log_error("thread_example_1: Failed to create thread. %s",
				strerror(nResult));

		log_info("thread_example_1: Done.");

		return;
	}

	log_info("thread_example_1: Created thread with ID %lu.", thread_id);

	log_info("thread_example_1: Attempting to join thread with ID %lu...",
			thread_id);

	nResult = pthread_join(thread_id, NULL);
	if (OK != nResult) {
		log_error("thread_example_1: Failed to join thread with ID %lu. %s",
				thread_id, strerror(nResult));

		log_info("thread_example_1: Done.");

		return;
	}

	log_info("thread_example_1: Thread with ID %lu terminated successfully.",
			thread_id);

	log_info("thread_example_1: Done.");
}

///////////////////////////////////////////////////////////////////////////////
// thread_example_2: Example of calling a thread, passing args, and changing
// global variables
//

void thread_example_2(void) {
	log_debug("In  thread_example_2");

	// Multithreading trial - code from
	// <https://www.geeksforgeeks.org/multithreading-c-2/>

	// Let us create three threads
	const int NUM_THREADS = 3;

	log_info("thread_example_2: Attempting to create %d threads...",
			NUM_THREADS);

	pthread_t tid;

	for (int i = 0; i < NUM_THREADS; i++) {
		int nCurrentThread = i + 1;

		log_info("thread_example_2: Attempting to create thread #%d",
				nCurrentThread);

		int nResult = pthread_create(&tid, NULL, my_thread_function_2,
				(void*) &tid);
		if (OK != nResult) {
			log_error("thread_example_2: Failed to create thread #%d. %s",
					nCurrentThread, strerror(nResult));

			log_info("thread_example_2: Done.");

			return;
		}

		log_info("thread_example_2: Created thread #%d with thread ID %lu.",
				nCurrentThread, tid);

		log_info("thread_example_2: Attempting to join thread #%d...",
				nCurrentThread);

		nResult = pthread_join(tid, NULL);
		if (OK != nResult) {
			log_error("thread_example_2: Failed to join thread #%d. %s",
					nCurrentThread, strerror(nResult));

			log_info("thread_example_2: Done.");
		}

		tid = (unsigned long int) rand();// RANDOMIZE the thread ID before creating the next thread

		log_info("thread_example_2: Thread #%d has terminated.",
				nCurrentThread);
	}

	log_info("thread_example_2: Done.");
}

///////////////////////////////////////////////////////////////////////////////
// thread_example_3: Example of calling a thread, passing args, and changing
// global variables
//

void thread_example_3(void) {
	log_debug("In  thread_example_3");

	log_info("thread_example_3: Attempting to create %d threads...",
	NUM_THREADS_FOR_EXAMPLE_3);

	// First, create NUM_THREADS_FOR_EXAMPLE_3 new threads and put their IDs into
	// the globally-declared array
	for (int i = 0; i < NUM_THREADS_FOR_EXAMPLE_3; i++) {
		int nCurrentThread = i + 1;
		log_info("thread_example_3: Attempting to create thread #%d...",
				nCurrentThread);

		int nResult = pthread_create(&(thread_ids[i]), NULL,
				my_thread_function_3, NULL);
		if (OK != nResult) {// nonzero result from pthread_create means error
			log_error("thread_example_3: Failed to create thread #%d. %s",
					nCurrentThread, strerror(nResult));

			log_info("thread_example_3: Done.");

			/* Stop here as something went wrong. */
			return;
		}

		log_info(
				"thread_example_3: Thread #%d has been created.  Thread ID is %lu.",
				nCurrentThread, thread_ids[i]);
	}

	log_info(
			"thread_example_3: Finished creating threads.  Launching each thread...");

	for (int i = 0; i < NUM_THREADS_FOR_EXAMPLE_3; i++) {
		int nCurrentThread = i + 1;
		log_info("thread_example_3: Attempting to launch thread #%d...",
				nCurrentThread);

		int nResult = pthread_join(thread_ids[i], NULL);
		if (OK != nResult) {
			log_error("thread_example_3: Failed to launch thread #%d. %s",
					nCurrentThread, strerror(nResult));

			log_info("thread_example_3: Done.");

			return;
		}

		log_info("thread_example_3: Launched thread #%d.", nCurrentThread);
	}

	log_info("thread_example_3: Done.");
}
