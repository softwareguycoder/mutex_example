// MUTEX_EXAMPLE.H: Header file for the functions declared in the main mutex_example.c file that we can
// expose to the rest of the program. Obviously, main() will not be exposed.
//

#ifndef __MUTEX_EXAMPLE_H__
#define __MUTEX_EXAMPLE_H__

// Variable is implemented in the mutex_example.c file
extern int g;

// Variable is implemented in the mutex_example.c file
extern int counter;

void thread_example_1(void);
void thread_example_2(void);
void thread_example_3(void);

#endif	//__MUTEX_EXAMPLE_H__
