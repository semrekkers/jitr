#ifndef JITR_H_
#define JITR_H_

#include <stdio.h>
#include <stdlib.h>

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



#ifdef __cplusplus
}
#endif

#endif // JITR_H_

