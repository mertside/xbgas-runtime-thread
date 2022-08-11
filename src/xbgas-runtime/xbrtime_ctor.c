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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
// #include <stdbool.h>                                                         
                                                                                
// -------------------------------------------------------------------- MACROS
//#define INIT_ADDR 0xBB00000000000000ull
#define END_ADDR 0xAA00000000000000ull

#define DEBUG 1                                                                 
#define MAX_NUM_OF_THREADS 16                                                   
                                                                                
// ------------------------------------------------------------------- STRUCTS 
typedef struct args{                                                            
  uint64_t thread_id;                                                           
  volatile uint64_t trampoline_memory;                                          
} args;                                                                         
                                                                                
typedef enum {false, true} bool;                                                
                                                                                
// ---------------------------------------------------------- GLOBAL VARIABLES                         
// Handles for each thread thread                                               
pthread_t thread_handles[MAX_NUM_OF_THREADS];                                   
                                                                                
// Args struct for each thread                                                  
args thread_args[MAX_NUM_OF_THREADS];  
                                                                                
// Indicates whether threads are done                                           
volatile bool done = false;    

// --------------------------------------------------------- SPINWAIT FUNCTION
void *spinWait( void *arg ){                                                    
                                                                                
  args *thread_args = (args*)(arg);                                             
  uint64_t my_id = thread_args->thread_id;                                      
  volatile uint64_t *my_trampoline = &(thread_args->trampoline_memory);         
                                                                                
  // Loop to spinWait (...sleep;jump;sleep...)                                  
  while(!done){                                                                 
    // Function pointer for redirection                                         
    void (*Func)() = NULL;                                                      
                                                                                
    // Do nothing until trampoline address is set                               
    while((*my_trampoline) == 0x00ull){                                         
      sleep(1);                                                                 
    }                                                                           
                                                                                
    // Someone loaded an address into the trampoline                            
#if DEBUG                                                                       
    fprintf(stdout, "\t[*] Thread %lu: Trampoline at address %p set to %p!\n",  
           my_id, (void *) my_trampoline, (void *) *my_trampoline);             
#endif                                                                          
                                                                                
    // Check condition to end spinWait loop                                     
    if((*my_trampoline) == 0xdeadbeef){                                         
#if DEBUG                                                                       
      fprintf(stdout, "\t[*] Thread %lu: My work is done!\n", my_id);           
#endif                                                                          
      // Break out of the loop                                                  
      done = true; // break;                                                    
    } else {                                                                    
      // Cast the address to a function pointer                                 
      Func = (void (*)(void *))(*my_trampoline);                                
                                                                                
      // Jump to the user-defined function                                      
      (*Func)();                                                                
                                                                                
      // Reset the trampoline address                                           
      *my_trampoline = 0x00ull; // thread_args->trampoline_memory = 0x00ull;    
                                                                                
#if DEBUG                                                                       
      fprintf(stdout, "\t[*] Thread %lu: Trampoline at address %p REset %p!\n", 
             my_id, (void *) my_trampoline, (void *) *my_trampoline);           
#endif                                                                          
                                                                                
    }                                                                           
  } // END of infinite while                                                    
                                                                                
  fflush(stdout);                                                               
  // This thread's work is done                                                 
  pthread_exit(NULL);                                                           
}  

// ------------------------------------------------------- FUNCTION PROTOTYPES
void __xbrtime_ctor_reg_reset();

// ------------------------------------------------------ CONSTRUCTOR FUNCTION
__attribute__((constructor)) void __xbrtime_ctor(){
  /* initialize the unnecessary registers */
  __xbrtime_ctor_reg_reset();
	// As max PE = 1024, at most 10 rounds are needed in the synchronization  
  barrier = malloc(sizeof(uint64_t)*2*10);	
  //printf("CTOR: Init\n");
	//int init = 0;
  //*((uint64_t *)INIT_ADDR) = init;
	//if(init || *((uint64_t *)INIT_ADDR))
	//  init = 0;	

  int i = 0;                                                                    
  int numOfThreads = MAX_NUM_OF_THREADS;   
                                                                               
  // Get number of threads from the environment                                 
  char *str = getenv("NUM_OF_THREADS");                                       
  if(str == NULL){                                                            
    fprintf(stderr, "\nNUM_OF_THREADS not set; set environment first!\n");    
  } else {                                                                    
    numOfThreads = atoi(str);                                                 
    if(numOfThreads <= 0 || numOfThreads > MAX_NUM_OF_THREADS){               
      fprintf(stderr, "\nNUM_OF_THREADS should be between %d and %d\n",       
              1, MAX_NUM_OF_THREADS);                                         
      numOfThreads = MAX_NUM_OF_THREADS;                                      
    }                                                                         
  }                                                                                 
 
#if DEBUG                                                                       
  fprintf(stdout, "\nNumber of threads: %d\n", numOfThreads);                   
  fflush(stdout);                                                               
#endif 
 
  // initialize thread args                                                     
  for( i=0; i<numOfThreads; i++ ){                                              
    thread_args[i].thread_id = i;                                               
    thread_args[i].trampoline_memory = 0x00ull;                                 
  }  

#if DEBUG                                                                       
  printf("\nAddresses of trampolines: \n");                                     
  for(i = 0; i< numOfThreads; i++){                                             
    printf("Thread %lu: %p\t", thread_args[i].thread_id,                        
           &(thread_args[i].trampoline_memory));                                
  }                                                                             
  printf("\n");                                                                 
  printf("\nValues of trampolines: \n");                                        
  for(i = 0; i< numOfThreads; i++){                                             
    printf("Thread %lu: %p\t", thread_args[i].thread_id,                        
           thread_args[i].trampoline_memory);                                   
  }                                                                             
  printf("\n");                                                                 
#endif     

  //sleep(2);                                                                   
  //printf("\n");                                                               
                                                                                
  // create the threads                                                         
  for( i=0; i<numOfThreads; i++ ){                                              
    pthread_create(&thread_handles[i], NULL, spinWait, &thread_args[i]);        
  }                                                                             
                                                                                
  //sleep(2);                                                                   
  //printf("\n");

}

// ------------------------------------------------------- DESTRUCTOR FUNCTION
__attribute__((destructor)) void __xbrtime_dtor(){

  sleep(2);                                                                   
  //printf("\n");
  
  // -- all threads end spinWait                                                
  for(i=0; i<numOfThreads; i++){                                                
    // Pass a specific address to end spinWait                                  
    thread_args[i].trampoline_memory = (uint64_t) 0xdeadbeef;                   
    // Jump to a specific function to end spinWait                              
    // thread_args[i].trampoline_memory = (uint64_t) &endSpinWait;              
#if DEBUG                                                                       
  fprintf(stdout, "    Thread %lu trampoline set to %p for completion\n",       
          thread_args[i].thread_id, (void *) thread_args[i].trampoline_memory); 
#endif                                                                          
  }                                                                             
                                                                                
  //sleep(2);                                                                   
  //printf("\n");                                                               
                                                                                
  // close the threads                                                          
  for(i=0; i<numOfThreads; i++){                                                
    pthread_join(thread_handles[i], NULL);                                      
  }  

  /* free_barrier */
	uint64_t end = 0;
	*((uint64_t *)END_ADDR) = end;
	//if(end || *((uint64_t *)END_ADDR))
	//  end = 1;
  free ((void*)barrier); 	
  //printf("DTOR: Free\n");

}
/* ================================== EOF ================================== */
