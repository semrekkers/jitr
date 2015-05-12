#include <stdio.h>
#include <stdlib.h>

#include "jitr.h"
#include "operations.h"

static jitr_native native_code;
static unsigned int cur = 0;

typedef void (*func)(void);

static void append_code(jitr_code *code) {
    jitr_native back = native_code + cur;
    memcpy(back, code->native, code->length);
    cur += code->length;
}

int main() {
    native_code = (jitr_native)malloc(256);

    jitr_code workbench;
    jitr_uint *ptr;
    unsigned int val = 0x02;

    // prepare
    jitr_scan(&workbench, &jitr_op_before);
    append_code(&workbench);
    free(workbench.native);

    // first op (load var)
    jitr_scan(&workbench, &jitr_op_loadR1);
    ptr = jitr_parseInt(&workbench, JITR_AOF(jitr_mask), 0);
    *ptr = JITR_AOF(val);
    append_code(&workbench);
    free(workbench.native);

    // second op (calculate)
    jitr_scan(&workbench, &jitr_op_inc);
    append_code(&workbench);
    free(workbench.native);

    // third op (store result)
    jitr_scan(&workbench, &jitr_op_storeR1);
    ptr = jitr_parseInt(&workbench, JITR_AOF(jitr_mask), 0);
    *ptr = JITR_AOF(val);
    append_code(&workbench);
    free(workbench.native);

    // finalize 
    jitr_scan(&workbench, &jitr_op_after);
    append_code(&workbench);
    free(workbench.native);

    func jitr_result = (func)native_code;
    jitr_result();

    printf("Number out: %u\n", val);
    return 0;
}

