#ifndef JITR_H_
#define JITR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(__cplusplus) && defined(true) && defined(false))
typedef unsigned char bool;
#define true    (1)
#define false   (0)
#endif

#ifndef JITR_ARCH
#error JITR_ARCH must be defined
#endif

#if JITR_ARCH == i386
#include "jitr-i386.h"
#elif JITR_ARCH == amd64
// jitr-amd64.h
#elif JITR_ARCH == arm
// jitr-arm.h
#endif

#define JITR_PTR_SIZE       (sizeof(jitr_ptr))
#define JITR_ASM(s)         __asm__ __volatile__ (JITR_MARK s JITR_MARK)
#define JITR_AOF(val)       ((jitr_uint)&val)

typedef void (*jitr_source)(void);
typedef void* (*jitr_func)(int n, ...);
typedef jitr_uchar *jitr_native;

typedef struct {
    jitr_native native;
    unsigned int length;
    jitr_uint *arg1;
    jitr_uint *arg2;
    jitr_uchar *index;
} jitr_code;

typedef struct {
    jitr_native native;
    unsigned int length;
    unsigned int cap;
} jitr_batch;

void jitr_scan(jitr_code *code, jitr_source source);
jitr_native jitr_parse(jitr_code *code, jitr_uchar val, int skip);
jitr_uint* jitr_parseInt(jitr_code *code, jitr_uint val, int skip);

void jitr_code_destroy(jitr_code *code);
void jitr_code_copy(jitr_code *code, jitr_code *dest);

void jitr_batch_init(jitr_batch *batch);
void jitr_batch_destroy(jitr_batch *batch);

void jitr_batch_call(jitr_batch *batch, void *func);

void jitr_batch_prepare(jitr_batch *batch);
void jitr_batch_finalize(jitr_batch *batch);

jitr_func jitr_compile(jitr_batch *batch);

#ifdef __cplusplus
}
#endif

#endif // JITR_H_

