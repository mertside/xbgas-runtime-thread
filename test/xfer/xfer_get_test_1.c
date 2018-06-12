/* _XFER_TEST_1_C_
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

#include <stdio.h>
#include <inttypes.h>
#include "xbrtime.h"

#define _XBGAS_ALLOC_SIZE_ 8

int main( int argc, char **argv ){
  int rtn = 0;
  uint64_t *ptr = NULL;
  uint64_t VALUE = 0x00ull;
  size_t sz = _XBGAS_ALLOC_SIZE_;

  printf( "Initializing xBGAS Runtime\n" );
  rtn = xbrtime_init();
  printf( "PE=%d; xBGAS is Initialized\n", xbrtime_mype() );

  printf( "PE=%d; Allocating %d bytes\n", xbrtime_mype(), (int)(sz) );
  ptr = (uint64_t *)(xbrtime_malloc( sz ));

  printf( "PE=%d; PTR = %p\n", xbrtime_mype(), ptr );
  ptr[0] = (uint64_t)(xbrtime_mype());

  if( xbrtime_mype() == 0 ){
    /* perform an operation */
    printf( "PE=%d; PERFORMING OPERATION\n", xbrtime_mype() );
    xbrtime_ulonglong_get((unsigned long long *)(&VALUE),
                          (unsigned long long *)(ptr),
                          1,
                          1,
                          1 );
  }else{
    printf( "PE=%d; DOING NOTHING\n", xbrtime_mype() );
  }

  printf( "PE=%d; VALUE=0x%"PRIu64"\n", xbrtime_mype(), VALUE);

  printf( "PE=%d; xBGAS is Closing\n", xbrtime_mype() );
  xbrtime_free( ptr );
  xbrtime_close();
  printf( "xBGAS is Closed\n" );

  return rtn;
}

/* EOF */