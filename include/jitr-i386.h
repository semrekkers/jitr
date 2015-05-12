#ifndef JITR_I386_H_
#define JITR_I386_H_

// jitr platform-specific types
typedef unsigned char jitr_uchar;
typedef int jitr_int;
typedef unsigned int jitr_uint;
typedef void *jitr_ptr;

// jitr mark
const jitr_uchar JITR_MARK_SEQ[] = {0x90, 0x90};
#define JITR_MARK       "nop; nop\n\t"

// jitr registers
#define JITR_R1         "%eax"
#define JITR_R2         "%ebx"
#define JITR_R3         "%ecx"
#define JITR_R4         "%edx"

// jitr stack and base pointer
#define JITR_STACK      "%esp"
#define JITR_BASE       "%ebp"

// jitr "mask" value
jitr_uint jitr_mask = 0x00FFFF32;

// jitr value
#define JITR_VAL(val)   "$"#val
#define JITR_DEREF(val) "("val")"

// operations
#define JITR_MOV(src, dest)         "mov "src", "dest"\n\t"
#define JITR_PUSH(src)              "push "src"\n\t"
#define JITR_POP(src)               "pop "src"\n\t"
#define JITR_LEA(src, dest)         "lea "src", "dest"\n\t"
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
#define JITR_CALL_REG(src)          "call *"src"\n\t"
#define JITR_RET()                  "ret\n\t"

#endif // JITR_I386_H_

