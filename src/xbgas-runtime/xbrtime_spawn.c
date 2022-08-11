/*
 * _XBRTIME_SPAWN_C_
 *
 */

#include "xbrtime.h"

// ---------------------------------- MACROS
#define DEBUG 1  

/* ------------------------------------------------- GLOBALS */
// Handles for each thread thread                                               
extern pthread_t thread_handles[NUM_THREADS];

// Args struct for each thread                                                  
extern args thread_args[NUM_THREADS];    

/* ------------------------------------------------- FUNCTION */
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
