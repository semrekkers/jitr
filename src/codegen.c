#include "operations.h"

void jitr_batch_init(jitr_batch *batch) {
    batch->native = (jitr_native)malloc(32);
    batch->cap = 32;
    batch->length = 0;
}

void jitr_batch_destroy(jitr_batch *batch) {
    free(batch->native);
}

void jitr_batch_call(jitr_batch *batch, void *func) {
    jitr_code call_op;
    jitr_scan(&call_op, &op_call);
    jitr_uint *funcptr = jitr_parseInt(&call_op, 0x00FF00FF, 0);
    *funcptr = (jitr_uint)func;
}

void jitr_batch_prepare(jitr_batch *batch);
void jitr_batch_finalize(jitr_batch *batch);

jitr_func jitr_compile(jitr_batch *batch);

