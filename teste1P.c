#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cria_func.h"

typedef int (*func_ptr) (char* x);
typedef int (*func_ptr2) ();

unsigned teste1P(char* x)
{
    fprintf(stderr, "Entrei na funcao\n");
    fprintf(stderr, "%p\n", x);
    unsigned i = 0;
    while (x[i] != '\0')
    {
        fprintf(stderr, "x[%u] -- %c -- %hhx", i, x[i], x[i]);
        i++;
    }
    return i;
}

int main(void)
{
    DescParam params[1];
    unsigned char codigo[500];

    func_ptr mesmo_prefixo;

    //TESTE 1 - INTEIRO
    params[0].tipo_val = PTR_PAR; /* o primeiro parâmetro de memcmp é um ponteiro para char */
    params[0].orig_val = PARAM; 

    cria_func (strlen, params, 1, codigo);
    mesmo_prefixo = (func_ptr) codigo;

    int tamanho = mesmo_prefixo("Arcane acabou");
    printf("%d", tamanho);
    if ( 13 == tamanho)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf(" NÃO PASSOU NO TESTE\n");

    }

    unsigned char codigo2[500];

    func_ptr2 mesmo_prefixo2;

    //TESTE 1 - INTEIRO
    params[0].tipo_val = PTR_PAR; /* o primeiro parâmetro de memcmp é um ponteiro para char */
    params[0].orig_val = FIX; 
    params[0].valor.v_ptr = "Arcane acabou";


    cria_func (strlen, params, 1, codigo2);
    mesmo_prefixo2 = (func_ptr2) codigo2;
    tamanho = mesmo_prefixo2();
    printf("%d", tamanho);
    if ( 13 == tamanho)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf(" NÃO PASSOU NO TESTE\n");

    }

    unsigned char codigo3[500];
    char ind[] = "Arcane acabou";
    char* p = ind;
    char** pp = &p;
    //TESTE 1 - INTEIRO
    params[0].tipo_val = PTR_PAR; /* o primeiro parâmetro de memcmp é um ponteiro para char */
    params[0].orig_val = IND; 
    params[0].valor.v_ptr = pp;


    //cria_func (teste1P, params, 1, codigo3);
    cria_func (strlen, params, 1, codigo3);

    /* for(unsigned i = 0; i < 50; i++)
    {
        printf("codigo[%u] - %hhx\n", i, codigo3[i]);
    } */

    mesmo_prefixo2 = (func_ptr2) codigo3;

    if ( 13 == mesmo_prefixo2())
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf(" NÃO PASSOU NO TESTE\n");

    }

    return 0;
}