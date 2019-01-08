/*
 * mutex.h
 *
 *  Created on: Jan 8, 2019
 *      Author: bhart
 */

#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "stdafx.h"

// API for mutex use

/**
 * \brief Locks the mutex with the handle specified.  Does nothing if the handle
 * is INVALID_HANDLE_VALUE.
 *
 * @param hMutex Handle of type HMUTEX (see stdafx.h) that refers to the mutex you want
 * to obtain a lock for.
 */
void LockMutex(HMUTEX hMutex);

/**
 * \brief Releases any existing locks on the mutex referred to by the handle specified. Does
 * nothing if the handle is INVALID_HANDLE_VALUE.
 * @param hMutex Mutex handle of type HMUTEX (see stdafx.h) that refers to the mutex you want
 * to release the lock on.
 */
void UnlockMutex(HMUTEX hMutex);


#endif /* __MUTEX_H__ */
