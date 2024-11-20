.text
.globl teste
teste:
    pushq       %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movq    %rdi, -8(%rbp)
    movq    %rsi, -16(%rbp)
    movq    %rdx, -24(%rbp)
    movq    $0x4444229128A24490, %rax
    movq    $0x4444229128A24490, %r10
    movl    (%r10), %edi
    movl    (%r10), %esi
    movl    (%r10), %edx
    movq    (%r10), %rdi
    movq    -8(%rbp), %rdi
    movq    -8(%rbp), %rsi
    movq    -8(%rbp), %rdi
    movq    (%r10), %rsi
    movq    (%r10), %rdx
    movl    (%r10), %r10d
    movl    %r10d, %edi
    movl    %r10d, %esi
    movl    %r10d, %edx
    call    *%rax
    movl    $0, %edi 
    movl    $0, %esi 
    movl    $0, %edx
    movq    $0x4444229128A24490, %rdi 
    movq    $0x4444229128A24490, %rsi 
    movq    $0x4444229128A24490, %rdx
    leave
    ret




