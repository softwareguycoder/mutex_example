// STDAFX.H - Include file that is to be included everywhere else in the program, provides includes
// for widely-used system includ files and headers
//

#ifndef __STDAFX_H__
#define __STDAFX_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Exit codes
#define OK		0		// Code to return to the operating system to indicate successful program termination
#define ERROR	-1		// Code to return to the operating system to indicate an error condition

#define INVALID_HANDLE_VALUE NULL

#define NUM_THREADS_FOR_EXAMPLE_3	2

// All handles are pointers, so define a constant
// INVALID_HANDLE_VALUE to be the same as NULL

// Bringing in libraries defined by us
#include <../../debug_core/debug_core/include/debug_core.h>

#endif //__STDAFX_H__
