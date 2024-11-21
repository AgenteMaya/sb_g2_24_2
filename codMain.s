.text
.globl f_mult
f_mult:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movq    %rdi, -8(%rbp)
    movq    %rsi, -16(%rbp)
    movq    %rdx, -24(%rbp)
    movl    $10, %edi
    movl    -8(%rbp), %esi
    movq    mult, %rax
    call    *%rax
    leave
    ret
    
