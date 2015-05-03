#ifndef JITR_I386_H_
#define JITR_I386_H_

// jitr platform-specific integer types
typedef int jitr_int;
typedef unsigned int jitr_uint;

// jitr mark
const char JITR_MARK_SEQ[] = {0x90, 0x90};
#define JITR_MARK       "nop; nop\n\t"

// jitr args
#define JITR_ARG1       0x54FF3201
#define JITR_ARG2       0x54FF3202
const unsigned int JITR_ARG1_SEQ = JITR_ARG1;
const unsigned int JITR_ARG2_SEQ = JITR_ARG2;

// jitr registers
#define R_ACCUM         "%eax"
#define R_BASE          "%ebx"
#define R_COUNT         "%ecx"
#define R_DATA          "%edx"
#define R_INDEX         "%esi"
#define R_PTR           "%edi"

// jitr value
#define JITR_VAL(val)   "$"#val

// operations
#define JITR_MOVE(src, dest)        "mov "src", "dest"\n\t"
#define JITR_PUSH(src)              "push "src"\n\t"
#define JITR_POP(src)               "pop "src"\n\t"
#define JITR_ADDR(src, dest)        "lea "src", "dest"\n\t"
#define JITR_ADD(src, dest)         "add "src", "dest"\n\t"
#define JITR_SUB(src, dest)         "sub "src", "dest"\n\t"
#define JITR_INC(src)               "inc "src"\n\t"
#define JITR_DEC(src)               "dec "src"\n\t"
#define JITR_IMUL(src, dest)        "imul "src", "dest"\n\t"
#define JITR_IDIV(src, dest)        "idiv "src", "dest"\n\t"
#define JITR_AND(src, dest)         "and "src", "dest"\n\t"
#define JITR_OR(src, dest)          "or "src", "dest"\n\t"
#define JITR_XOR(src, dest)         "xor "src", "dest"\n\t"
#define JITR_NOT(src, dest)         "not "src", "dest"\n\t"
#define JITR_NEG(src, dest)         "neg "src", "dest"\n\t"
#define JITR_SHL(src, dest)         "shl "src", "dest"\n\t"
#define JITR_SHR(src, dest)         "shr "src", "dest"\n\t"
#define JITR_JMP(src)               "jmp "src"\n\t"
#define JITR_JE(src)                "je "src"\n\t"
#define JITR_JNE(src)               "jne "src"\n\t"
#define JITR_JZ(src)                "jz "src"\n\t"
#define JITR_JG(src)                "jg "src"\n\t"
#define JITR_JGE(src)               "jge "src"\n\t"
#define JITR_JL(src)                "jl "src"\n\t"
#define JITR_JLE(src)               "jle "src"\n\t"
#define JITR_CMP(src, dest)         "cmp "src", "dest"\n\t"
#define JITR_CALL(src)              "call "src"\n\t"
#define JITR_RET()                  "ret\n\t"

#endif // JITR_I386_H_

