#include "jitr.h"

void jitr_scan(jitr_code *code, jitr_source source) {
    jitr_uchar *cur = (jitr_uchar*)source;
    unsigned int cmpi;
    bool flag = false;
    jitr_uchar first = JITR_MARK_SEQ[0];
    unsigned int lasti = sizeof(JITR_MARK_SEQ) - 1;
    unsigned int i = 0;

    bool final = false;
    unsigned int starti;
    unsigned int endi;

    for (;; cur++, i++) {
        if (flag) {
            if (*cur == JITR_MARK_SEQ[cmpi]) {
                if (cmpi == lasti) {
                    if (final) {
                        endi = i;
                        break;
                    }
                    starti = i + 1;
                    final = true;
                    flag = false;
                }
                cmpi++;
            }
            else if (*cur == first) {
                cmpi = 1;
            }
            else {
                flag = false;
            }
        }
        else {
            if (*cur == first) {
                cmpi = 1;
                flag = true;
            }
        }
    }

    code->length = (endi - lasti) - starti; 
    code->native = (jitr_native)malloc(code->length);
    memcpy(code->native, source, code->length);
    code->arg1 = NULL;
    code->arg2 = NULL;
    code->index = NULL;
}

jitr_native jitr_parse(jitr_code *code, jitr_uchar val, int skip) {
    jitr_uchar *cur = code->native;
    for (unsigned int i = 0; i < code->length; cur++, i++) {
        if (*cur == val) {
            if (skip == 0) {
                return cur;
            }
            skip--;
        }
    }
    return NULL;
}

jitr_uint* jitr_parseInt(jitr_code *code, jitr_uint val, int skip) {
    jitr_uchar *cur = code->native;
    jitr_uchar *cmp = (jitr_uchar*)&val;
    jitr_uchar first = cmp[0];
    bool flag = false;
    unsigned int cmpi;
    unsigned int lasti = sizeof(val) - 1;
    jitr_uchar *res;

    for (unsigned int i = 0; i < code->length; cur++, i++) {
        if (flag) {
            if (*cur == cmp[cmpi]) {
                if (cmpi == lasti) {
                    if (skip == 0) {
                        return (jitr_uint*)res;
                    }
                    skip--;
                }
                cmpi++;
            }
            else if (*cur == first) {
                cmpi = 1;
                res = cur;
            }
            else {
                flag = false;
            }
        }
        else {
            if (*cur == first) {
                flag = true;
                cmpi = 1;
                res = cur;
            }
        }
    }
    return NULL;
}

void jitr_code_destroy(jitr_code *code) {
    free(code->native);
}

void jitr_code_copy(jitr_code *code, jitr_code *dest) {
    dest->native = (jitr_native)malloc(code->length);
    dest->length = code->length;
    memcpy(dest->native, code->native, code->length);

    // recalculate pointers
    jitr_uint diff;
    if (code->arg1 != NULL) {
        diff = ((jitr_uint)code->arg1) - ((jitr_uint)code->native);
        dest->arg1 = (jitr_uint*)((jitr_uint)dest->native) + diff;
    }
    if (code->arg2 != NULL) {
        diff = ((jitr_uint)code->arg2) - ((jitr_uint)code->native);
        dest->arg2 = (jitr_uint*)((jitr_uint)dest->native) + diff;
    }
    if (code->index != NULL) {
        diff = ((jitr_uint)code->index) - ((jitr_uint)code->native);
        dest->index = (jitr_uchar*)((jitr_uint)dest->native) + diff;
    }
}

