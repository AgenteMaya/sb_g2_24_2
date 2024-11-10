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
    movq    $7071817044022531464, %rdi 
    movq    $7071817044022531464, %rsi 
    movq    $7071817044022531464, %rdx
    leave
    ret




