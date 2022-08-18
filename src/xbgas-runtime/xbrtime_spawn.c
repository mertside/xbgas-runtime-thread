/*
 * _XBRTIME_SPAWN_C_
 *
 */

#include "xbrtime.h"
// #include <stdio.h>                                                              
// #include <stdlib.h>                                                             
// #include <stdint.h>                                                             
// #include <string.h>                                                             
// #include <pthread.h>                                                            
// #include <stdbool.h> 

// ---------------------------------- MACROS
#define DEBUG 1  

// ------------------------------------------------------------------- STRUCTS  
typedef struct args{                                                            
  uint64_t thread_id;                                                           
  volatile uint64_t trampoline_memory;                                          
} args;

// ---------------------------------------------------------- GLOBAL VARIABLES 
// Handles for each thread thread                                               
extern pthread_t thread_handles[NUM_THREADS];

// Args struct for each thread                                                  
extern args thread_args[NUM_THREADS];    

// ------------------------------------------------------------ SPAWN FUNCTION 
void __xbrtime_spawn(void *jmpAddr){  
 
  // Get the number of threads from the environment
  int numOfThreads = atoi(getenv("NUM_OF_THREADS")); 

  // tell each thread to jump to a specific function                            
  // -- all threads jump to XXX                                              
  for( i=0; i<numOfThreads; i++ ){                                             
    thread_args[i].trampoline_memory = (uint64_t) &jmpAddr;                       
#if DEBUG                                                                       
    fprintf(stdout, "    Thread %lu trampoline set to %p\n",                    
            thread_args[i].thread_id,(void *)thread_args[i].trampoline_memory); 
#endif                                                                          
  } 

}
/* ================================== EOF ================================== */
