// Mutex API

#include "stdafx.h"
#include "mutex.h"


/**
 * @brief Creates a mutex object, and returns a handle to it.  Returns INVALID_HANDLE_VALUE
   if an error occurred.
 */
HMUTEX CreateMutex()
{
	pthread_mutex_t* pMutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	if (pMutex == NULL)
	{	
		return INVALID_HANDLE_VALUE;
	}

	if (OK != pthread_mutex_init(pMutex))
	{
		return INVALID_HANDLE_VALUE;
	}

	return (HMUTEX)pMutex;	// a HMUTEX is a typedef of pthread_mutex_t*
}

/**
 * @brief Locks the mutex with the handle specified.  Does nothing if the handle
 * is INVALID_HANDLE_VALUE.
 * @param hMutex Handle of type HMUTEX (see stdafx.h) that refers to the mutex you want
 * to obtain a lock for.
 */
void LockMutex(HMUTEX hMutex)
{
	if (hMutex == INVALID_HANDLE_VALUE)
	{
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
void UnlockMutex(HMUTEX hMutex)
{
	if (hMutex == INVALID_HANDLE_VALUE)
	{
		return;
	}

	pthread_mutex_unlock(hMutex);
}

/**
 * @brief Releases resources associated with the specified mutex back to the operating system.
 */
void DestroyMutex(HMUTEX hMutex)
{
	if (INVALID_HANDLE_VALUE == hMutex)
	{	
		// If we have an invalid handle, then there is nothing to do.
		return;
	}

	// The HMUTEX handle type is just a typedef of pthread_mutex_t*
	// However, to work with the pthread functions, we need to view it
	// as such.
	pthread_mutex_t* pMutex = (pthread_mutex_t*)hMutex;

	pthread_mutex_destroy((pthread_mutex_t*)hMutex);

	free(pMutex);
	pMutex = NULL;
	hMutex = INVALID_HANDLE_VALUE;
}
