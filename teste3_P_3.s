.text
.globl nova
nova:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movq    %rdi, -8(%rbp)
    movq    %rsi, -16(%rbp)
    movq    %rdx, -24(%rbp)
    movq    $0x24044044042821, %r10
    movq    %r10, %rdi
    movq    %r10, %rsi
    movq    %r10, %rdx
    movq    mult, %rax
    call    *%rax
    leave
    ret
