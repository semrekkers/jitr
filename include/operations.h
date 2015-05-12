#ifndef JITR_OPERATIONS_H_
#define JITR_OPERATIONS_H_

#include "jitr.h"

#ifdef __cplusplus
extern "C" {
#endif

jitr_code *jitr_cache_before = NULL;
jitr_code *jitr_cache_after = NULL;
jitr_code *jitr_cache_beforeCall = NULL;
jitr_code *jitr_cache_call = NULL;
jitr_code *jitr_cache_afterCall = NULL;
jitr_code *jitr_cache_pushR1 = NULL;
jitr_code *jitr_cache_pushR2 = NULL;
jitr_code *jitr_cache_popR1 = NULL;
jitr_code *jitr_cache_popR2 = NULL;

static void jitr_op_before() {
    JITR_ASM (
        // save base pointer
        JITR_PUSH(JITR_BASE)
        // set base pointer
        JITR_MOV(JITR_STACK, JITR_BASE)
        // save callee-saved registers
        JITR_PUSH(JITR_R2)
    );
}

static void jitr_op_after() {
    JITR_ASM (
        // restore callee-saved registers
        JITR_POP(JITR_R2)
        // deallocate local variables
        JITR_MOV(JITR_BASE, JITR_STACK)
        // restore base pointer
        JITR_POP(JITR_BASE)
        // return
        JITR_RET()
    );
}

static void jitr_op_beforeCall() {
    JITR_ASM (
        // save caller-saved registers
        JITR_PUSH(JITR_R3)
        JITR_PUSH(JITR_R4)
    );
}

static void jitr_op_call() {
    JITR_ASM (
        // call function at address in R2
        JITR_CALL_REG(JITR_R2)
    );
}

static void jitr_op_afterCall() {
    JITR_ASM (
        // restore caller-saved registers
        JITR_POP(JITR_R4)
        JITR_POP(JITR_R3)
    );
}

static void jitr_op_pushR1() {
    JITR_ASM (
        JITR_PUSH(JITR_R1)
    );
}

static void jitr_op_pushR2() {
    JITR_ASM (
        JITR_PUSH(JITR_R2)
    );
}

static void jitr_op_popR1() {
    JITR_ASM (
        JITR_POP(JITR_R1)
    );
}

static void jitr_op_popR2() {
    JITR_ASM (
        JITR_POP(JITR_R2)
    );
}

static void jitr_op_loadR1() {
    JITR_ASM (
        // copy variable at address to R1
        // address of jitr_mask is used as placeholder for later replacement
        JITR_MOV(JITR_DEREF("jitr_mask"), JITR_R1)
    );
}

static void jitr_op_loadR2() {
    JITR_ASM (
        // copy variable at address to R2
        JITR_MOV(JITR_DEREF("JITR_MASK"), JITR_R2)
    );
}

static void jitr_op_storeR1() {
    JITR_ASM (
        // copy contents of R1 to variable at address
        // address of jitr_mask is used as placeholder for later replacement
        JITR_MOV(JITR_R1, JITR_DEREF("JITR_MASK"))
    );
}

static void jitr_op_storeR2() {
    JITR_ASM (
        // copy contents of R1 to variable at address
        // address of jitr_mask is used as placeholder for later replacement
        JITR_MOV(JITR_R2, JITR_DEREF("JITR_MASK"))
    );
}

static void jitr_op_inc() {
    JITR_ASM (
        JITR_INC(JITR_R1)
    );
}

#ifdef __cplusplus
}
#endif

#endif // JITR_OPERATIONS_H_

