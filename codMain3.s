.text
.globl mesmo_prefixo
mesmo_prefixo:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movq    %rdi, -8(%rbp)
    movq    %rsi, -16(%rbp)
    movq    %rdx, -24(%rbp)
    movq    $0x24044044042821, %rdi
    movq    -8(%rbp), %rsi
    movl    -16(%rbp), %edx
    movq    mult, %rax
    call    *%rax
    leave
    ret
