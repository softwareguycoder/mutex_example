// Mutex API

#include "stdafx.h"
#include "mutex.h"

/**
 * \brief Locks the mutex with the handle specified.  Does nothing if the handle
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
 * \brief Releases any existing locks on the mutex referred to by the handle specified. Does
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
