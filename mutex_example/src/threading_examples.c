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

	log_info("thread_example_1: Attempting to create thread...");

	HTHREAD hThread = CreateThread(my_thread_function_1);
	if (INVALID_HANDLE_VALUE == hThread) {
		log_error("thread_example_1: Failed to create thread.");

		log_info("thread_example_1: Done.");

		return;
	}

	log_info(
			"thread_example_1: Successfully created new thread with handle %lu.",
			hThread);

	log_info(
			"thread_example_1: Attempting to join the thread with handle %lu...",
			hThread);

	// Wait for the thread created above to terminate.
	WaitThread(hThread);

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

	HTHREAD hThread = INVALID_HANDLE_VALUE;

	for (int i = 0; i < NUM_THREADS; i++) {
		int nCurrentThread = i + 1;

		log_info("thread_example_2: Attempting to create thread #%d",
				nCurrentThread);

		/* Pass the ordinal number of which thread this is to the thread procedure
		 * itself by calling CreateThreadEx and filling in a reference to nCurrentThread
		 * using the pUserState parameter of CreateThreadEx.
		 */

		hThread = CreateThreadEx(my_thread_function_2, (void*)&nCurrentThread);
		if (INVALID_HANDLE_VALUE == hThread) {
			log_error("thread_example_2: Failed to create thread #%d.",
					nCurrentThread);

			log_info("thread_example_2: Done.");

			return;
		}

		log_info(
				"thread_example_2: Created thread #%d with thread handle at address %x.",
				nCurrentThread, hThread);

		log_info("thread_example_2: Attempting to join thread #%d...",
				nCurrentThread);

		int nResult = WaitThread(hThread);
		if (OK != nResult) {
			log_error("thread_example_2: Failed to join thread #%d. %s",
					nCurrentThread, strerror(nResult));

			log_info("thread_example_2: Done.");
		}

		// Even though it may seem superfluous, we call DestroyThread here
		// so that we have a guarantee that the thread handle has been invalidated
		// since we re-use it in a loop.
		DestroyThread(hThread);

		// RANDOMIZE the thread handle's address before creating the next thread!
		// Since this hThread will no longer have a value of INVALID_HANDLE_VALUE,
		// undefined behavior WILL RESULT from using this hThread to, e.g., call
		// WaitThreadEx etc.  So, don't do it! Only a CreateThread call can follow
		// this function call.
		hThread = (HTHREAD)((unsigned long int) rand());

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

	// First, create NUM_THREADS_FOR_EXAMPLE_3 new threads and put
	// their handles into the globally-declared array (in mutex_example.h)
	// that is accessed via the threadPool variable.
	for (int i = 0; i < NUM_THREADS_FOR_EXAMPLE_3; i++) {
		int nCurrentThread = i + 1; // Ordinal value that indicates the current thread
		log_info("thread_example_3: Attempting to create thread #%d...",
				nCurrentThread);

		// The threadPool is a globally-declared static array of HTHREADs.  Initialize
		// the ith thread handle with a call to CreateThread.
		threadPool[i] = CreateThread(my_thread_function_3);
		if (INVALID_HANDLE_VALUE == threadPool[i]) {
			log_error("thread_example_3: Failed to create thread #%d.",
					nCurrentThread);

			log_info("thread_example_3: Done.");

			/* Stop here, as something went wrong -- but, if any
			 * previous threads got successfully created, then clean
			 * them up -- we do this by waiting on each thread that has
			 * a valid handle to terminate, and then we free any resources
			 * consumed by that thread back to the operating system.  If
			 * a thread has already had its handle set to INVALID_HANDLE_VALUE
			 * then we can just skip it.
			 */
			if (i > 0) {// If we are past the first thread in the thread pool at this point...
				// If we are here, then threads have been created before this one.
				// Join with them so they terminate cleanly and then get their
				// resources released.
				for (int j = 0; j < i; j++) {
					if (INVALID_HANDLE_VALUE == threadPool[j]) {
						// if we are here, there is nothing to do since this thread
						// has, apparently, already terminated/been disposed of.
						continue;
					}

					// else, wait on the thread until it's done, and gets freed from
					// memory.  After the WaitThread function returns, threadPool[j]
					// will have the value INVALID_HANDLE_VALUE.
					WaitThread(threadPool[j]);
				}
			}

			/* Now that we are here, we can return from this function as we have done
			 * our chores. */
			log_info("thread_example_3: Done.");

			return;
		}

		/* If we are here, then the current thread got created successfully. */
		log_info(
				"thread_example_3: Thread #%d has been successfully created and has begun executing.",
				nCurrentThread);
	}

	log_info(
			"thread_example_3: Finished creating threads.  Waiting for each thread to terminate...");

	for (int i = 0; i < NUM_THREADS_FOR_EXAMPLE_3; i++) {
		int nCurrentThread = i + 1;

		// Skip a thread if its handle is set to an invalid value (say,
		// because it already terminated prior to us getting to this part
		// of the code)
		if (INVALID_HANDLE_VALUE == threadPool[i]) {
			continue;
		}

		log_info("thread_example_3: Waiting for thread #%d to terminate...",
				nCurrentThread);

		WaitThread(threadPool[i]);

		// By the time we are here, thread #nCurrentThread will have
		// terminated, and we can assume that the handle at threadPool[i]
		// already has the value INVALID_HANDLE_VALUE.
		log_info("thread_example_3: Thread #%d has terminated.",
				nCurrentThread);
	}

	log_info("thread_example_3: Done.");
}
