.text
.globl teste
teste:
    pushq       %rbp
    movq    %rsp, %rbp
    movq    $0, %rax
    call    *%rax
    movl    $0, %edi 
    movl    $0, %esi 
    movl    $0, %edx
    movq    $0, %rdi 
    movq    $0, %rsi 
    movq    $0, %rdx
    leave
    ret




