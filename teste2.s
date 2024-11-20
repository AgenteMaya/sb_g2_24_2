.data 
sf: .string "%d\n"

.text
.globl teste2

teste2:
    pushq       %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movq    %rdi, -8(%rbp)
    movq    %rsi, -16(%rbp)
    movq    %rdx, -24(%rbp)
    movl    %edi, %esi
    movq    $sf, %rdi
    call    printf
    movq    -8(%rbp), %rdi
    movq    -8(%rbp), %rsi
    movq    -8(%rbp), %rdx
    movq    -16(%rbp), %rdi
    movq    -16(%rbp), %rsi
    movq    -16(%rbp), %rdx
    movq    -24(%rbp), %rdi
    movq    -24(%rbp), %rsi
    movq    -24(%rbp), %rdx
    movl    -8(%rbp), %edi
    movl    -8(%rbp), %esi
    movl    -8(%rbp), %edx
    movl    -16(%rbp), %edi
    movl    -16(%rbp), %esi
    movl    -16(%rbp), %edx
    movl    -24(%rbp), %edi
    movl    -24(%rbp), %esi
    movl    -24(%rbp), %edx
    leave
    ret
