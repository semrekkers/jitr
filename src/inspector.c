#include "jitr.h"

static jitr_code jitr_getPrototype(jitr_asm native_asm) {
    char *cur = (char*)native_asm;
    unsigned int cmpindex;
    bool flag = false;
    char first = JITR_MARK_SEQ[0];
    unsigned int lastindex = sizeof(JITR_MARK_SEQ);
    unsigned int i = 0;

    bool finalize = false;
    unsigned int start;
    unsigned int end;

    for (; ; cur++, i++) {
        if (flag) {
            if (*cur == JITR_MARK_SEQ[cmpindex]) {
                if (cmpindex == lastindex) {
                    if (finalize) {
                        end = i;
                        break;
                    }
                    else {
                        start = i;
                        finalize = true;
                    }
                }
                else {
                    if (*cur == first) {
                        cmpindex = 1;
                        continue;
                    }
                    flag = false;
                }
                cmpindex++;
            }
        }
        else {
            if (*cur == first) {
                cmpindex = 1;
                flag = true;
            }
        }
    }

    jitr_code code;
    code.length = (end - start) + 1;
    code.code = (char*)malloc(code.length);
    memcpy(code.code, native_asm, code.length);
    return code;
}

static void jitr_resolveIndex(jitr_code *code, char val, int skip) {
    char *cur = code->code;
    for (unsigned int i = 0; i < code->length; cur++, i++) {
        if (*cur == val) {
            if (skip == 0) {
                code->index = (unsigned char*)cur;
                break;
            }
            skip--;
        }
    }
}

