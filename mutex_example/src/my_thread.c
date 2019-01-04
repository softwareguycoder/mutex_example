#include "stdafx.h"
#include "mutex_example.h"

#include "my_thread.h"

///////////////////////////////////////////////////////////////////////////////
// my_thread_function: Defines the operations for the thread

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *my_thread_function(void *vargp)
{
    sleep(1);
    log_info("Printing a message from my_thread...Hello, world!");
    log_info("Yay the thread works!");
    return NULL;
}

///////////////////////////////////////////////////////////////////////////////
