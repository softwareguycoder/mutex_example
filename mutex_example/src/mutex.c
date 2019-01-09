// Mutex API

#include "stdafx.h"
#include "mutex.h"

/**
 * @brief Internal (i.e., will not be put in the mutex.h header file) method
 * for freeing malloc'd mutex handles.
 * @param hMutex The handle to be freed.
 */
void FreeMutex(HMUTEX hMutex) {
	log_info("In FreeMutex");

	log_info("FreeMutex: Checking whether the mutex handle passed is valid...");

	if (INVALID_HANDLE_VALUE == hMutex) {
		log_error(
				"The mutex handle passed has a NULL value; assuming it's already been deallocated.");

		log_info("FreeMutex: Done.");

		// If we have an invalid handle (i.e., NULL pointer), then there is nothing to do.
		return;
	}

	log_info(
			"FreeMutex: The mutex handle passed is valid.  Proceeding to free it...");

	// The HMUTEX handle type is just a typedef of pthread_mutex_t*
	// However, to work with the pthread functions, we need to view it
	// as such.
	pthread_mutex_t* pMutex = (pthread_mutex_t*) hMutex;

	free(pMutex);
	pMutex = NULL;
	hMutex = INVALID_HANDLE_VALUE;

	log_info("FreeMutex: The mutex handle passed has been freed.");

	log_info("FreeMutex: Done.");
}

/**
 * @brief Creates a mutex object, and returns a handle to it.  Returns INVALID_HANDLE_VALUE
 if an error occurred.
 */
HMUTEX CreateMutex() {
	pthread_mutex_t* pMutex = (pthread_mutex_t*) malloc(
			sizeof(pthread_mutex_t));
	if (pMutex == NULL) {
		return INVALID_HANDLE_VALUE;
	}

	// Call pthread_mutex_init.  This version of CreateMutex just passes a
	// mutex handle for the function to initialize with NULL for the attributes.
	if (OK != pthread_mutex_init(pMutex, NULL)) {
		// Cleanup the mutex handle if necessary
		if (pMutex != NULL) {
			FreeMutex((HMUTEX) pMutex);
		}

		return INVALID_HANDLE_VALUE;
	}

	return (HMUTEX) pMutex;	// a HMUTEX is a typedef of pthread_mutex_t*
}

/**
 * @brief Releases resources associated with the specified mutex back to the operating system.
 */
void DestroyMutex(HMUTEX hMutex) {
	if (INVALID_HANDLE_VALUE == hMutex) {
		// If we have an invalid handle (i.e., NULL pointer), then there is nothing to do.
		return;
	}

	pthread_mutex_destroy((pthread_mutex_t*) hMutex);

	FreeMutex(hMutex);
}

/**
 * @brief Locks the mutex with the handle specified.  Does nothing if the handle
 * is INVALID_HANDLE_VALUE.
 * @param hMutex Handle of type HMUTEX (see stdafx.h) that refers to the mutex you want
 * to obtain a lock for.
 */
void LockMutex(HMUTEX hMutex) {
	if (hMutex == INVALID_HANDLE_VALUE) {
		return;
	}

	pthread_mutex_lock(hMutex);
}

/**
 * @brief Releases any existing locks on the mutex referred to by the handle specified. Does
 * nothing if the handle is INVALID_HANDLE_VALUE.
 * @param hMutex Mutex handle of type HMUTEX (see stdafx.h) that refers to the mutex you want
 * to release the lock on.
 */
void UnlockMutex(HMUTEX hMutex) {
	if (hMutex == INVALID_HANDLE_VALUE) {
		return;
	}

	pthread_mutex_unlock(hMutex);
}

