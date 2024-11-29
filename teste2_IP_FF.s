.text
.globl foo
foo:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movq    %rdi, -8(%rbp)
    movq    %rsi, -16(%rbp)
    movq    %rdx, -24(%rbp)
    movl    $15, %edi
    movl    $3, %esi
    movq    $0x4444229128A24490, %rax
    call    *%rax
    leave
    ret
