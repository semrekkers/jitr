#include "jitr.h"

static void op_add_one_accum() {
    JITR_ASM(JITR_ADD(JITR_VAL(0x1), R_ACCUM));
}

static void op_pop_into_accum() {
    JITR_ASM(JITR_POP(R_ACCUM));
}

static void op_ret() {
    JITR_ASM(JITR_RET());
}

static void op_call() {
    JITR_ASM(
            JITR_INC(R_ACCUM)
            JITR_DEC(R_ACCUM)
            JITR_DEC(R_ACCUM)
            );
}

static char* jitr_getChunk(jitr_raw raw) {
    const char *end_bytes = JITR_MARK_SEQ;
    int last_index = sizeof(JITR_MARK_SEQ) + 1;

    int len = 0;
    char *cur = (char*)raw;
    char first = end_bytes[0];
    bool flag = false;
    int cmpindex = 0;
    for (; ; len++) {
        if (flag) {
            if (*cur == end_bytes[cmpindex++]) {
                if (cmpindex == last_index)
                    break;
            }
            else {
                if (*cur == first) {
                    cmpindex = 1;
                    continue;
                }
                flag = false;
            }
        }
        else {
            if (*cur == first) {
                cmpindex = 1;
                flag = true;
            }
        }
        cur++;
    }

    len -= (last_index - 2);
    char *native = (char*)malloc(len);
    memcpy(native, raw, len);
    return native;
}

int main() {
    char *native = jitr_getChunk(op_pop_into_accum);

    return 0;
}

