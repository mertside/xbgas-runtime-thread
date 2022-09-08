/*
 * _XBRTIME_CTOR_C_
 *
 * Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
 * All Rights Reserved
 * contact@tactcomplabs.com
 *
 * This file is a part of the XBGAS-RUNTIME package.  For license
 * information, see the LICENSE file in the top level directory
 * of the distribution.
 *
 */

#include "xbrtime.h"
#include "threadpool.h"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// -------------------------------------------------------------------- MACROS
//#define INIT_ADDR 0xBB00000000000000ull
#define END_ADDR 0xAA00000000000000ull

#define DEBUG 1
#define MAX_NUM_OF_THREADS 16

// ---------------------------------------------------------- GLOBAL VARIABLES
volatile uint64_t *barrier;

// ------------------------------------------------------- FUNCTION PROTOTYPES
void __xbrtime_ctor_reg_reset();

// ------------------------------------------------------ CONSTRUCTOR FUNCTION
__attribute__((constructor)) void __xbrtime_ctor(){
  
  /* initialize the unnecessary registers */
  __xbrtime_ctor_reg_reset();
	// As max PE = 1024, at most 10 rounds are needed in the synchronizatino  
  barrier = malloc(sizeof(uint64_t)*2*10);	
  //printf("CTOR: Init\n");
	//int init = 0;
  //*((uint64_t *)INIT_ADDR) = init;
	//if(init || *((uint64_t *)INIT_ADDR))
	//init = 0;	

  //  ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   numOfThreads
  int i = 0;
  int numOfThreads = MAX_NUM_OF_THREADS;

  // Can take number of threads as args
  if(argc > 1){
    numOfThreads = atoi(argv[1]);
  } else {
    // Get number of threads from the environment
    char *str = getenv("NUM_OF_THREADS");
    // Is the environment variable set appropriately?
    if(str == NULL || atoi(str) <= 0 || atoi(str) > MAX_NUM_OF_THREADS){
      if(str == NULL) {
        // NOT found!
        fprintf(stderr, "\nNUM_OF_THREADS not set; set environment first!\n");
      } else {
        // NOT a reasonable number!
        fprintf(stderr, "\nNUM_OF_THREADS should be between %d and %d\n",
                1, MAX_NUM_OF_THREADS);
      }
      // Set MAX number of threads as an environment variable
      const char *envName = "NUM_OF_THREADS";
      char envValue[10] = "";
      sprintf(envValue, "%d", numOfThreads);
      setenv(envName, envValue, 1);
    }
    numOfThreads = atoi(getenv("NUM_OF_THREADS"));
    //free(str);
  }

#if DEBUG
  fprintf(stdout, "\nNumber of threads: %d\n", numOfThreads);
  fflush(stdout);
#endif

  // ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...
  
  // Create a thread pool
  tpool_work_queue_t *pool;
  pool = tpool_create(numOfThreads);

}

// ------------------------------------------------------- DESTRUCTOR FUNCTION
__attribute__((destructor)) void __xbrtime_dtor(){
  
  // Will return when there is no work
  tpool_wait(pool);

  // Discard pending, clean queue, order stop, wait, destroy
  tpool_destroy(pool); 

  // ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...
 
  /* free_barrier */
	uint64_t end = 0;
	*((uint64_t *)END_ADDR) = end;
	//if(end || *((uint64_t *)END_ADDR))
	//end = 1;
  free ((void*)barrier); 	
  //printf("DTOR: Free\n");

}

/* ================================== EOF ================================== */
