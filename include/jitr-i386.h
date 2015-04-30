#ifndef JITR_I386_H_
#define JITR_I386_H_

// jitr sequence terminator
#define JITR_END        "nop; nop\n\t"          // asm
#define JITR_END_SEQ    0x9090                  // native

// jitr registers
#define JITR_RTMP       "%eax"
#define JITR_RBASE      "%ebx"
#define JITR_RRET       "%ecx"
#define JITR_RPTR       "%edx"
#define JITR_RARG1      "%esi"
#define JITR_RARG2      "%edi"

// operations
#define JITR_MOVE(src, dest)        "mov "src", "dest"\n\t"
#define JITR_PUSH(val)              "push "val"\n\t"
#define JITR_POP(val)               "pop "val"\n\t"
#define JITR_ADDR(src, dest)        "lea "src", "dest"\n\t"
#define JITR_ADD(src, dest)         "add "src", "dest"\n\t"
#define JITR_SUB(src, dest)         "sub "src", "dest"\n\t"
#define JITR_INC(src)               "inc "src"\n\t"
#define JITR_DEC(src)               "dec "src"\n\t"

#endif // JITR_I386_H_

