// STDAFX.H - Include file that is to be included everywhere else in the program, provides includes
// for widely-used system includ files and headers
//

#ifndef __STDAFX_H__
#define __STDAFX_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Exit codes
#define OK		0		// Code to return to the operating system to indicate successful program termination
#define ERROR	-1		// Code to return to the operating system to indicate an error condition

typedef enum { FALSE, TRUE } BOOL;

#endif //__STDAFX_H__
