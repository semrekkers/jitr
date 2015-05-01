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

#define JITR_PTR_SIZE       (sizeof(void*))
#define JITR_ASM(s)         __asm__ __volatile__ (JITR_MARK s JITR_MARK)
typedef void(*jitr_raw)(void);

#ifdef __cplusplus
}
#endif

#endif // JITR_H_

