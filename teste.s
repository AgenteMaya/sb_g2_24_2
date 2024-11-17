.text
.globl teste
teste:
    pushq       %rbp
    movq    %rsp, %rbp
    movq    $0x4444229128A24490, %rax
    call    *%rax
    movl    $0, %edi 
    movl    $0, %esi 
    movl    $0, %edx
    movq    $0x4444229128A24490, %rdi 
    movq    $0x4444229128A24490, %rsi 
    movq    $0x4444229128A24490, %rdx
    leave
    ret




