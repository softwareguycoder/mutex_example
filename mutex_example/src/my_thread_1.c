#include <my_thread_1.h>
#include "stdafx.h"
#include "mutex_example.h"


///////////////////////////////////////////////////////////////////////////////
// my_thread_function: Defines the operations for the thread

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *my_thread_function(void *vargp)
{
	log_info("In my_thread_function");

    sleep(1);

    log_info("my_thread_function: Hello, world!");
    log_info("my_thread_function: Yay the thread works!");

    log_info("my_thread_function: Done.");

    return NULL;
}

///////////////////////////////////////////////////////////////////////////////
