/*
 * _XBRTIME_COLLECTIVES_C_
 *
 * Copyright (C) 2017-2019  Tactical Computing Laboratories, LLC
 * All Rights Reserved
 * contact@tactcomplabs.com
 *
 * This file is a part of the XBGAS-RUNTIME package.  For license
 * information, see the LICENSE file in the top level directory
 * of the distribution.
 *
 */

 #include "xbrtime.h"

 #define XBGAS_BROADCAST(_type, _typename)                                                                  \
 void xbrtime_##_typename##_broadcast(_type *dest, const _type *src, size_t nelems, int stride, int root)   \
 {                                                                                                          \
     int i, numpes, my_rpe, my_vpe, numpes_log, mask, two_i, r_partner, v_partner;                          \
     numpes = xbrtime_num_pes();                                                                            \
     my_rpe = xbrtime_mype();                                                                               \
     my_vpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root));                              \
     numpes_log = (int) ceil((log(numpes)/log(2)));  /* Number of commmuication stages */                   \
     mask = (int) (pow(2,numpes_log) - 1);                                                                  \
                                                                                                            \
     /* Perform communication if PE active at stage i and has valid partner */                              \
     for(i = numpes_log-1; i >= 0; i--)                                                                     \
     {                                                                                                      \
         two_i = (int) pow(2,i);                                                                            \
         mask = mask ^ two_i;                                                                               \
         if(((my_vpe & mask) == 0) && ((my_vpe & two_i) == 0))                                              \
         {                                                                                                  \
             v_partner = (my_vpe ^ two_i) % numpes;                                                         \
             r_partner = (v_partner + root) % numpes;                                                       \
             if(my_vpe < v_partner)                                                                         \
             {                                                                                              \
                 xbrtime_##_typename##_put(dest, src, nelems, stride, r_partner);                           \
             }                                                                                              \
         }                                                                                                  \
         temp_barrier();                                                                                    \
    }                                                                                                       \
 }

    XBGAS_BROADCAST(float, float)
    XBGAS_BROADCAST(double, double)
    XBGAS_BROADCAST(char, char)
    XBGAS_BROADCAST(unsigned char, uchar)
    XBGAS_BROADCAST(signed char, schar)
    XBGAS_BROADCAST(unsigned short, ushort)
    XBGAS_BROADCAST(short, short)
    XBGAS_BROADCAST(unsigned int, uint)
    XBGAS_BROADCAST(int, int)
    XBGAS_BROADCAST(unsigned long, ulong)
    XBGAS_BROADCAST(long, long)
    XBGAS_BROADCAST(unsigned long long, ulonglong)
    XBGAS_BROADCAST(long long, longlong)
    XBGAS_BROADCAST(uint8_t, uint8)
    XBGAS_BROADCAST(int8_t, int8)
    XBGAS_BROADCAST(uint16_t, uint16)
    XBGAS_BROADCAST(int16_t, int16)
    XBGAS_BROADCAST(uint32_t, uint32)
    XBGAS_BROADCAST(int32_t, int32)
    XBGAS_BROADCAST(uint64_t, uint64)
    XBGAS_BROADCAST(int64_t, int64)
    XBGAS_BROADCAST(size_t, size)
    XBGAS_BROADCAST(ptrdiff_t, ptrdiff)
//  XBGAS_BROADCAST(long double, longdouble)

#define XBGAS_REDUCT(_type, _typename, _funcname, _op)                                                            \
void xbrtime_##_typename##_reduct_##_funcname(_type *dest, const _type *src, size_t nelems, int stride, int root) \
{                                                                                                                 \
    int i, j, numpes, my_rpe, my_vpe, numpes_log, mask, two_i, r_partner, v_partner;                              \
    stride = ((stride == 0) ? 1 : stride);   /* Avoid memory allocation problem */                                \
    _type *temp = (_type*) malloc(nelems * (sizeof(_type) * stride));                                             \
    _type *accumulate = (_type*) xbrtime_malloc(nelems * (sizeof(_type) * stride));                               \
    numpes = xbrtime_num_pes();                                                                                   \
    my_rpe = xbrtime_mype();                                                                                      \
    my_vpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root));                                     \
    numpes_log = (int) ceil((log(numpes)/log(2)));  /* Number of commmuication stages */                          \
    mask = (int) (pow(2,numpes_log) - 1);                                                                         \
                                                                                                                  \
    /* Load accumulate buffer on each PE */                                                                       \
    for(i = 0; i < nelems; i++)                                                                                   \
    {                                                                                                             \
        accumulate[i*stride] = src[i*stride];                                                                     \
    }                                                                                                             \
                                                                                                                  \
    /* Ensure accumulate buffer is ready */                                                                       \
    temp_barrier();                                                                                               \
                                                                                                                  \
    /* Perform communication if PE active at stage i and has valid partner */                                     \
    for(i = 0; i < numpes_log; i++)                                                                               \
    {                                                                                                             \
        two_i = (int) pow(2,i);                                                                                   \
        mask = mask ^ two_i;                                                                                      \
        if(((my_vpe | mask) == mask) && ((my_vpe & two_i) == 0))                                                  \
        {                                                                                                         \
            v_partner = (my_vpe ^ two_i) % numpes;                                                                \
            r_partner = (v_partner + root) % numpes;                                                              \
            if(my_vpe < v_partner)                                                                                \
            {                                                                                                     \
                xbrtime_##_typename##_get(temp, accumulate, nelems, stride, r_partner);                           \
                for(j = 0; j < nelems; j++)                                                                       \
                {                                                                                                 \
                    accumulate[j*stride] = (_type) accumulate[j*stride] _op temp[j*stride];                       \
                }                                                                                                 \
            }                                                                                                     \
        }                                                                                                         \
        temp_barrier();                                                                                           \
    }                                                                                                             \
                                                                                                                  \
    /* Copy data to destination on root*/                                                                         \
    if(my_vpe == 0)                                                                                               \
    {                                                                                                             \
        for(i = 0; i < nelems; i++)                                                                               \
        {                                                                                                         \
            dest[i*stride] = accumulate[i*stride];                                                                \
        }                                                                                                         \
    }                                                                                                             \
    xbrtime_free(accumulate);                                                                                     \
    free(temp);                                                                                                   \
}

    /* Sum */
    XBGAS_REDUCT(float, float, sum, +)
    XBGAS_REDUCT(double, double, sum, +)
    XBGAS_REDUCT(char, char, sum, +)
    XBGAS_REDUCT(unsigned char, uchar, sum, +)
    XBGAS_REDUCT(signed char, schar, sum, +)
    XBGAS_REDUCT(unsigned short, ushort, sum, +)
    XBGAS_REDUCT(short, short, sum, +)
    XBGAS_REDUCT(unsigned int, uint, sum, +)
    XBGAS_REDUCT(int, int, sum, +)
    XBGAS_REDUCT(unsigned long, ulong, sum, +)
    XBGAS_REDUCT(long, long, sum, +)
    XBGAS_REDUCT(unsigned long long, ulonglong, sum, +)
    XBGAS_REDUCT(long long, longlong, sum, +)
    XBGAS_REDUCT(uint8_t, uint8, sum, +)
    XBGAS_REDUCT(int8_t, int8, sum, +)
    XBGAS_REDUCT(uint16_t, uint16, sum, +)
    XBGAS_REDUCT(int16_t, int16, sum, +)
    XBGAS_REDUCT(uint32_t, uint32, sum, +)
    XBGAS_REDUCT(int32_t, int32, sum, +)
    XBGAS_REDUCT(uint64_t, uint64, sum, +)
    XBGAS_REDUCT(int64_t, int64, sum, +)
    XBGAS_REDUCT(size_t, size, sum, +)
    XBGAS_REDUCT(ptrdiff_t, ptrdiff, sum, +)
    //  XBGAS_REDUCT(long double, longdouble, sum, +)

    /* Product */
    XBGAS_REDUCT(float, float, product, *)
    XBGAS_REDUCT(double, double, product, *)
    XBGAS_REDUCT(char, char, product, *)
    XBGAS_REDUCT(unsigned char, uchar, product, *)
    XBGAS_REDUCT(signed char, schar, product, *)
    XBGAS_REDUCT(unsigned short, ushort, product, *)
    XBGAS_REDUCT(short, short, product, *)
    XBGAS_REDUCT(unsigned int, uint, product, *)
    XBGAS_REDUCT(int, int, product, *)
    XBGAS_REDUCT(unsigned long, ulong, product, *)
    XBGAS_REDUCT(long, long, product, *)
    XBGAS_REDUCT(unsigned long long, ulonglong, product, *)
    XBGAS_REDUCT(long long, longlong, product, *)
    XBGAS_REDUCT(uint8_t, uint8, product, *)
    XBGAS_REDUCT(int8_t, int8, product, *)
    XBGAS_REDUCT(uint16_t, uint16, product, *)
    XBGAS_REDUCT(int16_t, int16, product, *)
    XBGAS_REDUCT(uint32_t, uint32, product, *)
    XBGAS_REDUCT(int32_t, int32, product, *)
    XBGAS_REDUCT(uint64_t, uint64, product, *)
    XBGAS_REDUCT(int64_t, int64, product, *)
    XBGAS_REDUCT(size_t, size, product, *)
    XBGAS_REDUCT(ptrdiff_t, ptrdiff, product, *)
    //  XBGAS_REDUCT(long double, longdouble, product, *)

    /* Binary AND */
    XBGAS_REDUCT(char, char, and, &)
    XBGAS_REDUCT(unsigned char, uchar, and, &)
    XBGAS_REDUCT(signed char, schar, and, &)
    XBGAS_REDUCT(unsigned short, ushort, and, &)
    XBGAS_REDUCT(short, short, and, &)
    XBGAS_REDUCT(unsigned int, uint, and, &)
    XBGAS_REDUCT(int, int, and, &)
    XBGAS_REDUCT(unsigned long, ulong, and, &)
    XBGAS_REDUCT(long, long, and, &)
    XBGAS_REDUCT(unsigned long long, ulonglong, and, &)
    XBGAS_REDUCT(long long, longlong, and, &)
    XBGAS_REDUCT(uint8_t, uint8, and, &)
    XBGAS_REDUCT(int8_t, int8, and, &)
    XBGAS_REDUCT(uint16_t, uint16, and, &)
    XBGAS_REDUCT(int16_t, int16, and, &)
    XBGAS_REDUCT(uint32_t, uint32, and, &)
    XBGAS_REDUCT(int32_t, int32, and, &)
    XBGAS_REDUCT(uint64_t, uint64, and, &)
    XBGAS_REDUCT(int64_t, int64, and, &)
    XBGAS_REDUCT(size_t, size, and, &)
    XBGAS_REDUCT(ptrdiff_t, ptrdiff, and, &)

    /* Binary OR */
    XBGAS_REDUCT(char, char, or, |)
    XBGAS_REDUCT(unsigned char, uchar, or, |)
    XBGAS_REDUCT(signed char, schar, or, |)
    XBGAS_REDUCT(unsigned short, ushort, or, |)
    XBGAS_REDUCT(short, short, or, |)
    XBGAS_REDUCT(unsigned int, uint, or, |)
    XBGAS_REDUCT(int, int, or, |)
    XBGAS_REDUCT(unsigned long, ulong, or, |)
    XBGAS_REDUCT(long, long, or, |)
    XBGAS_REDUCT(unsigned long long, ulonglong, or, |)
    XBGAS_REDUCT(long long, longlong, or, |)
    XBGAS_REDUCT(uint8_t, uint8, or, |)
    XBGAS_REDUCT(int8_t, int8, or, |)
    XBGAS_REDUCT(uint16_t, uint16, or, |)
    XBGAS_REDUCT(int16_t, int16, or, |)
    XBGAS_REDUCT(uint32_t, uint32, or, |)
    XBGAS_REDUCT(int32_t, int32, or, |)
    XBGAS_REDUCT(uint64_t, uint64, or, |)
    XBGAS_REDUCT(int64_t, int64, or, |)
    XBGAS_REDUCT(size_t, size, or, |)
    XBGAS_REDUCT(ptrdiff_t, ptrdiff, or, |)

    /* Binary XOR */
    XBGAS_REDUCT(char, char, xor, ^)
    XBGAS_REDUCT(unsigned char, uchar, xor, ^)
    XBGAS_REDUCT(signed char, schar, xor, ^)
    XBGAS_REDUCT(unsigned short, ushort, xor, ^)
    XBGAS_REDUCT(short, short, xor, ^)
    XBGAS_REDUCT(unsigned int, uint, xor, ^)
    XBGAS_REDUCT(int, int, xor, ^)
    XBGAS_REDUCT(unsigned long, ulong, xor, ^)
    XBGAS_REDUCT(long, long, xor, ^)
    XBGAS_REDUCT(unsigned long long, ulonglong, xor, ^)
    XBGAS_REDUCT(long long, longlong, xor, ^)
    XBGAS_REDUCT(uint8_t, uint8, xor, ^)
    XBGAS_REDUCT(int8_t, int8, xor, ^)
    XBGAS_REDUCT(uint16_t, uint16, xor, ^)
    XBGAS_REDUCT(int16_t, int16, xor, ^)
    XBGAS_REDUCT(uint32_t, uint32, xor, ^)
    XBGAS_REDUCT(int32_t, int32, xor, ^)
    XBGAS_REDUCT(uint64_t, uint64, xor, ^)
    XBGAS_REDUCT(int64_t, int64, xor, ^)
    XBGAS_REDUCT(size_t, size, xor, ^)
    XBGAS_REDUCT(ptrdiff_t, ptrdiff, xor, ^)

/* For use with min/max reduction below */
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define XBGAS_REDUCT_MM(_type, _typename, _funcname, _op)                                                         \
void xbrtime_##_typename##_reduct_##_funcname(_type *dest, const _type *src, size_t nelems, int stride, int root) \
{                                                                                                                 \
    int i, j, numpes,my_rpe, my_vpe, numpes_log, mask, two_i, r_partner, v_partner;                               \
    stride = ((stride == 0) ? 1 : stride);   /* Avoid memory allocation problem */                                \
    _type *temp = (_type*) malloc(nelems * (sizeof(_type) * stride));                                             \
    _type *accumulate = (_type*) xbrtime_malloc(nelems * (sizeof(_type) * stride));                               \
    numpes = xbrtime_num_pes();                                                                                   \
    my_rpe = xbrtime_mype();                                                                                      \
    my_vpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root));                                     \
    numpes_log = (int) ceil((log(numpes)/log(2)));   /* Number of commmuication stages */                         \
    mask = (int) (pow(2,numpes_log) - 1);                                                                         \
                                                                                                                  \
    /* Load accumulate buffer on each PE */                                                                       \
    for(i = 0; i < nelems; i++)                                                                                   \
    {                                                                                                             \
        accumulate[i*stride] = src[i*stride];                                                                     \
    }                                                                                                             \
                                                                                                                  \
    /* Ensure accumulate buffer is ready */                                                                       \
    temp_barrier();                                                                                               \
                                                                                                                  \
    /* Perform communication if PE active at stage i and has valid partner */                                     \
    for(i = 0; i < numpes_log; i++)                                                                               \
    {                                                                                                             \
        two_i = (int) pow(2,i);                                                                                   \
        mask = mask ^ two_i;                                                                                      \
        if(((my_vpe | mask) == mask) && ((my_vpe & two_i) == 0))                                                  \
        {                                                                                                         \
            v_partner = (my_vpe ^ two_i) % numpes;                                                                \
            r_partner = (v_partner + root) % numpes;                                                              \
            if(my_vpe < v_partner)                                                                                \
            {                                                                                                     \
                xbrtime_##_typename##_get(temp, accumulate, nelems, stride, r_partner);                           \
                for(j = 0; j < nelems; j++)                                                                       \
                {                                                                                                 \
                    accumulate[j*stride] = (_type) _op(accumulate[j*stride], temp[j*stride]);                     \
                }                                                                                                 \
            }                                                                                                     \
        }                                                                                                         \
        temp_barrier();                                                                                           \
    }                                                                                                             \
                                                                                                                  \
    /* Copy data to destination on root*/                                                                         \
    if(my_vpe == 0)                                                                                               \
    {                                                                                                             \
        for(i = 0; i < nelems; i++)                                                                               \
        {                                                                                                         \
            dest[i*stride] = accumulate[i*stride];                                                                \
        }                                                                                                         \
    }                                                                                                             \
    xbrtime_free(accumulate);                                                                                     \
    free(temp);                                                                                                   \
}
    /* Max */
    XBGAS_REDUCT_MM(float, float, max, MAX)
    XBGAS_REDUCT_MM(double, double, max, MAX)
    XBGAS_REDUCT_MM(char, char, max, MAX)
    XBGAS_REDUCT_MM(unsigned char, uchar, max, MAX)
    XBGAS_REDUCT_MM(signed char, schar, max, MAX)
    XBGAS_REDUCT_MM(unsigned short, ushort, max, MAX)
    XBGAS_REDUCT_MM(short, short, max, MAX)
    XBGAS_REDUCT_MM(unsigned int, uint, max, MAX)
    XBGAS_REDUCT_MM(int, int, max, MAX)
    XBGAS_REDUCT_MM(unsigned long, ulong, max, MAX)
    XBGAS_REDUCT_MM(long, long, max, MAX)
    XBGAS_REDUCT_MM(unsigned long long, ulonglong, max, MAX)
    XBGAS_REDUCT_MM(long long, longlong, max, MAX)
    XBGAS_REDUCT_MM(uint8_t, uint8, max, MAX)
    XBGAS_REDUCT_MM(int8_t, int8, max, MAX)
    XBGAS_REDUCT_MM(uint16_t, uint16, max, MAX)
    XBGAS_REDUCT_MM(int16_t, int16, max, MAX)
    XBGAS_REDUCT_MM(uint32_t, uint32, max, MAX)
    XBGAS_REDUCT_MM(int32_t, int32, max, MAX)
    XBGAS_REDUCT_MM(uint64_t, uint64, max, MAX)
    XBGAS_REDUCT_MM(int64_t, int64, max, MAX)
    XBGAS_REDUCT_MM(size_t, size, max, MAX)
    XBGAS_REDUCT_MM(ptrdiff_t, ptrdiff, max, MAX)
    //  XBGAS_REDUCT_MM(long double, longdouble, max, MAX)

    /* Min */
    XBGAS_REDUCT_MM(float, float, min, MIN)
    XBGAS_REDUCT_MM(double, double, min, MIN)
    XBGAS_REDUCT_MM(char, char, min, MIN)
    XBGAS_REDUCT_MM(unsigned char, uchar, min, MIN)
    XBGAS_REDUCT_MM(signed char, schar, min, MIN)
    XBGAS_REDUCT_MM(unsigned short, ushort, min, MIN)
    XBGAS_REDUCT_MM(short, short, min, MIN)
    XBGAS_REDUCT_MM(unsigned int, uint, min, MIN)
    XBGAS_REDUCT_MM(int, int, min, MIN)
    XBGAS_REDUCT_MM(unsigned long, ulong, min, MIN)
    XBGAS_REDUCT_MM(long, long, min, MIN)
    XBGAS_REDUCT_MM(unsigned long long, ulonglong, min, MIN)
    XBGAS_REDUCT_MM(long long, longlong, min, MIN)
    XBGAS_REDUCT_MM(uint8_t, uint8, min, MIN)
    XBGAS_REDUCT_MM(int8_t, int8, min, MIN)
    XBGAS_REDUCT_MM(uint16_t, uint16, min, MIN)
    XBGAS_REDUCT_MM(int16_t, int16, min, MIN)
    XBGAS_REDUCT_MM(uint32_t, uint32, min, MIN)
    XBGAS_REDUCT_MM(int32_t, int32, min, MIN)
    XBGAS_REDUCT_MM(uint64_t, uint64, min, MIN)
    XBGAS_REDUCT_MM(int64_t, int64, min, MIN)
    XBGAS_REDUCT_MM(size_t, size, min, MIN)
    XBGAS_REDUCT_MM(ptrdiff_t, ptrdiff, min, MIN)
    //  XBGAS_REDUCT_MM(long double, longdouble, min, MIN)

#define XBGAS_SCATTER(_type, _typename)                                                                                             \
void xbrtime_##_typename##_scatter(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root)            \
{                                                                                                                                   \
    int i, j, counter, numpes, my_rpe, my_vpe, numpes_log, mask, temp_rpe, two_i, r_partner, v_partner, iter_msg_size, r_i;         \
    _type *temp = (_type *) xbrtime_malloc(nelems * sizeof(_type));  /* Buffer space for messages */                                \
    numpes = xbrtime_num_pes();                                                                                                     \
    my_rpe = xbrtime_mype();                                                                                                        \
    my_vpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root));                                                       \
    numpes_log = (int) ceil((log(numpes)/log(2)));  /* Number of commmuication stages */                                            \
    mask = (int) (pow(2,numpes_log) - 1);                                                                                           \
    int adj_disp[numpes];                                                                                                           \
                                                                                                                                    \
    /* Calculate adj_disp by vpe */                                                                                                 \
    counter = 0;                                                                                                                    \
    for(i = 0; i < numpes; i++)                                                                                                     \
    {                                                                                                                               \
        r_i = (i + root) % numpes;                                                                                                  \
        adj_disp[i] = counter;                                                                                                      \
        counter = counter + pe_msg_sz[r_i];                                                                                         \
    }                                                                                                                               \
                                                                                                                                    \
    /* Load temp buffer on root by vpe */                                                                                           \
    counter = 0;                                                                                                                    \
    if(my_vpe == 0)                                                                                                                 \
    {                                                                                                                               \
        for(i = 0; i < numpes; i++)                                                                                                 \
        {                                                                                                                           \
            temp_rpe = (i+root) % numpes;                                                                                           \
            for(j = 0; j < pe_msg_sz[temp_rpe]; j++)                                                                                \
            {                                                                                                                       \
                temp[counter++] = src[(pe_disp[temp_rpe]+j)];                                                                       \
            }                                                                                                                       \
        }                                                                                                                           \
    }                                                                                                                               \
                                                                                                                                    \
    /* Ensure all PEs are ready for communication */                                                                                \
    temp_barrier();                                                                                                                 \
                                                                                                                                    \
    /* Perform communication if PE active at stage i and has valid partner */                                                       \
    for(i = numpes_log-1; i >= 0; i--)                                                                                              \
    {                                                                                                                               \
        two_i = (int) pow(2,i);                                                                                                     \
        mask = mask ^ two_i;                                                                                                        \
        if(((my_vpe & mask) == 0) && ((my_vpe & two_i) == 0))                                                                       \
        {                                                                                                                           \
            v_partner = (my_vpe ^ two_i) % numpes;                                                                                  \
            r_partner = (v_partner + root) % numpes;                                                                                \
            if(my_vpe < v_partner)                                                                                                  \
            {                                                                                                                       \
                /* Calculate message length for stage i*/                                                                           \
                iter_msg_size = 0;                                                                                                  \
                for(j = v_partner; ((j < (v_partner + two_i)) && (j < numpes)); j++)                                                \
                {                                                                                                                   \
                    temp_rpe = (j+root) % numpes;                                                                                   \
                    iter_msg_size = iter_msg_size + pe_msg_sz[temp_rpe];                                                            \
                }                                                                                                                   \
                xbrtime_##_typename##_put(&temp[(adj_disp[v_partner])], &temp[(adj_disp[v_partner])], iter_msg_size, 1, r_partner); \
            }                                                                                                                       \
        }                                                                                                                           \
        temp_barrier();                                                                                                             \
   }                                                                                                                                \
                                                                                                                                    \
   /* Copy data to destination */                                                                                                   \
   for(i = 0; i < pe_msg_sz[my_rpe]; i++)                                                                                           \
   {                                                                                                                                \
       dest[i] = temp[(adj_disp[my_vpe])+i];                                                                                        \
   }                                                                                                                                \
   xbrtime_free(temp);                                                                                                              \
}

    XBGAS_SCATTER(float, float)
    XBGAS_SCATTER(double, double)
    XBGAS_SCATTER(char, char)
    XBGAS_SCATTER(unsigned char, uchar)
    XBGAS_SCATTER(signed char, schar)
    XBGAS_SCATTER(unsigned short, ushort)
    XBGAS_SCATTER(short, short)
    XBGAS_SCATTER(unsigned int, uint)
    XBGAS_SCATTER(int, int)
    XBGAS_SCATTER(unsigned long, ulong)
    XBGAS_SCATTER(long, long)
    XBGAS_SCATTER(unsigned long long, ulonglong)
    XBGAS_SCATTER(long long, longlong)
    XBGAS_SCATTER(uint8_t, uint8)
    XBGAS_SCATTER(int8_t, int8)
    XBGAS_SCATTER(uint16_t, uint16)
    XBGAS_SCATTER(int16_t, int16)
    XBGAS_SCATTER(uint32_t, uint32)
    XBGAS_SCATTER(int32_t, int32)
    XBGAS_SCATTER(uint64_t, uint64)
    XBGAS_SCATTER(int64_t, int64)
    XBGAS_SCATTER(size_t, size)
    XBGAS_SCATTER(ptrdiff_t, ptrdiff)
    //  XBGAS_SCATTER(long double, longdouble)

#define XBGAS_GATHER(_type, _typename)                                                                                                \
void xbrtime_##_typename##_gather(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root)               \
{                                                                                                                                     \
    int i, j, counter, numpes, my_rpe, my_vpe, numpes_log, mask, temp_rpe, two_i, r_partner, v_partner, iter_msg_size, r_i, zero_idx; \
    _type *temp = (_type*) xbrtime_malloc(nelems * sizeof(_type));   /* Buffer space for messages */                                  \
    numpes = xbrtime_num_pes();                                                                                                       \
    my_rpe = xbrtime_mype();                                                                                                          \
    my_vpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root));                                                         \
    numpes_log = (int) ceil((log(numpes)/log(2)));                                                                                    \
    mask = (int) (pow(2,numpes_log) - 1);                                                                                             \
    int adj_disp[numpes];                                                                                                             \
                                                                                                                                      \
    /* Calculate adj_disp by vpe */                                                                                                   \
    counter = 0;                                                                                                                      \
    for(i = 0; i < numpes; i++)                                                                                                       \
    {                                                                                                                                 \
        r_i = (i + root) % numpes;                                                                                                    \
        adj_disp[i] = counter;                                                                                                        \
        counter = counter + pe_msg_sz[r_i];                                                                                           \
    }                                                                                                                                 \
                                                                                                                                      \
    /* Load temp values for each pe by vpe */                                                                                         \
    for(i = 0; i < pe_msg_sz[my_rpe]; i++)                                                                                            \
    {                                                                                                                                 \
        temp[(adj_disp[my_vpe])+i] = src[i];                                                                                          \
    }                                                                                                                                 \
                                                                                                                                      \
    /* Ensure all PEs are ready for communication */                                                                                  \
    temp_barrier();                                                                                                                   \
                                                                                                                                      \
    /* Perform communication if PE active at stage i and has valid partner */                                                         \
    for(i = 0; i < numpes_log; i++)                                                                                                   \
    {                                                                                                                                 \
        two_i = (int) pow(2,i);                                                                                                       \
        mask = mask ^ two_i;                                                                                                          \
        if(((my_vpe | mask) == mask) && ((my_vpe & two_i) == 0))                                                                      \
        {                                                                                                                             \
            v_partner = (my_vpe ^ two_i) % numpes;                                                                                    \
            r_partner = (v_partner + root) % numpes;                                                                                  \
            if(my_vpe < v_partner)                                                                                                    \
            {                                                                                                                         \
                /* Calculate message length for stage i */                                                                            \
                iter_msg_size = 0;                                                                                                    \
                for(j = v_partner; ((j < (v_partner + two_i)) && (j < numpes)); j++)                                                  \
                {                                                                                                                     \
                    temp_rpe = (j+root) % numpes;                                                                                     \
                    iter_msg_size = iter_msg_size + pe_msg_sz[temp_rpe];                                                              \
                }                                                                                                                     \
                xbrtime_##_typename##_get(&temp[(adj_disp[v_partner])], &temp[(adj_disp[v_partner])], iter_msg_size, 1, r_partner);   \
            }                                                                                                                         \
        }                                                                                                                             \
        temp_barrier();                                                                                                               \
   }                                                                                                                                  \
                                                                                                                                      \
   /* Copy data ordered by rpe to destination on root*/                                                                               \
   if(my_vpe == 0)                                                                                                                    \
   {                                                                                                                                  \
       zero_idx = numpes - root;                                                                                                      \
       for(i = 0; i < nelems; i++)                                                                                                    \
       {                                                                                                                              \
           dest[i] = temp[((adj_disp[zero_idx])+i)%nelems];                                                                           \
       }                                                                                                                              \
   }                                                                                                                                  \
   xbrtime_free(temp);                                                                                                                \
}

    XBGAS_GATHER(float, float)
    XBGAS_GATHER(double, double)
    XBGAS_GATHER(char, char)
    XBGAS_GATHER(unsigned char, uchar)
    XBGAS_GATHER(signed char, schar)
    XBGAS_GATHER(unsigned short, ushort)
    XBGAS_GATHER(short, short)
    XBGAS_GATHER(unsigned int, uint)
    XBGAS_GATHER(int, int)
    XBGAS_GATHER(unsigned long, ulong)
    XBGAS_GATHER(long, long)
    XBGAS_GATHER(unsigned long long, ulonglong)
    XBGAS_GATHER(long long, longlong)
    XBGAS_GATHER(uint8_t, uint8)
    XBGAS_GATHER(int8_t, int8)
    XBGAS_GATHER(uint16_t, uint16)
    XBGAS_GATHER(int16_t, int16)
    XBGAS_GATHER(uint32_t, uint32)
    XBGAS_GATHER(int32_t, int32)
    XBGAS_GATHER(uint64_t, uint64)
    XBGAS_GATHER(int64_t, int64)
    XBGAS_GATHER(size_t, size)
    XBGAS_GATHER(ptrdiff_t, ptrdiff)
    //  XBGAS_GATHER(long double, longdouble)

/* A very simple and naive implementation until a better algorithm is found */
#define XBGAS_ALLTOALL(_type, _typename)                                                                                    \
void xbrtime_##_typename##_alltoall(_type *dest, const _type *src, int src_stride, int dest_stride, size_t nelems)          \
{                                                                                                                           \
    int i, my_rpe, numpes, total_elems;                                                                                     \
    my_rpe = xbrtime_mype();                                                                                                \
    numpes = xbrtime_num_pes();                                                                                             \
    total_elems = numpes * nelems; /* Total elements per PE */                                                              \
    _type *src_buff = (_type*) xbrtime_malloc(total_elems * sizeof(_type));                                                 \
    _type *dest_buff = (_type*) xbrtime_malloc(total_elems * sizeof(_type));                                                \
                                                                                                                            \
    /* Build src_buff */                                                                                                    \
    for(i = 0; i < total_elems; i++)                                                                                        \
    {                                                                                                                       \
        src_buff[i] = src[i * src_stride];                                                                                  \
    }                                                                                                                       \
                                                                                                                            \
    temp_barrier();                                                                                                         \
                                                                                                                            \
    /* Perform put to dest_buff of each PE */                                                                               \
    for(i = 0; i < numpes; i++)                                                                                             \
    {                                                                                                                       \
        xbrtime_##_typename##_put(&dest_buff[my_rpe*nelems], &src_buff[i*nelems], nelems, 1, i);                            \
    }                                                                                                                       \
                                                                                                                            \
    temp_barrier();                                                                                                         \
                                                                                                                            \
    /* Copy to dest with stride */                                                                                          \
    for(i = 0; i < total_elems; i++)                                                                                        \
    {                                                                                                                       \
        dest[i * dest_stride] = dest_buff[i];                                                                               \
    }                                                                                                                       \
                                                                                                                            \
    xbrtime_free(src_buff);                                                                                                 \
    xbrtime_free(dest_buff);                                                                                                \
}

    XBGAS_ALLTOALL(float, float)
    XBGAS_ALLTOALL(double, double)
    XBGAS_ALLTOALL(char, char)
    XBGAS_ALLTOALL(unsigned char, uchar)
    XBGAS_ALLTOALL(signed char, schar)
    XBGAS_ALLTOALL(unsigned short, ushort)
    XBGAS_ALLTOALL(short, short)
    XBGAS_ALLTOALL(unsigned int, uint)
    XBGAS_ALLTOALL(int, int)
    XBGAS_ALLTOALL(unsigned long, ulong)
    XBGAS_ALLTOALL(long, long)
    XBGAS_ALLTOALL(unsigned long long, ulonglong)
    XBGAS_ALLTOALL(long long, longlong)
    XBGAS_ALLTOALL(uint8_t, uint8)
    XBGAS_ALLTOALL(int8_t, int8)
    XBGAS_ALLTOALL(uint16_t, uint16)
    XBGAS_ALLTOALL(int16_t, int16)
    XBGAS_ALLTOALL(uint32_t, uint32)
    XBGAS_ALLTOALL(int32_t, int32)
    XBGAS_ALLTOALL(uint64_t, uint64)
    XBGAS_ALLTOALL(int64_t, int64)
    XBGAS_ALLTOALL(size_t, size)
    XBGAS_ALLTOALL(ptrdiff_t, ptrdiff)
    //  XBGAS_ALLTOALL(long double, longdouble)

#undef MAX
#undef MIN
#undef XBGAS_BROADCAST
#undef XBGAS_REDUCT
#undef XBGAS_REDUCT_MM
#undef XBGAS_SCATTER
#undef XBGAS_GATHER
#undef XBGAS_ALLTOALL

void temp_barrier()
{
	int init = 1;
	*((uint64_t *)INIT_ADDR) = init;
}
