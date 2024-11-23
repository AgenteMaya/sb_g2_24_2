#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cria_func.h"

typedef int (*func_ptr) (int x);
typedef int (*func_ptr2) ();



int teste1I(int x)
{
    printf("%d", x);
    return x * 2;
}

unsigned teste1P(char* x)
{
    printf("%s", x);
    unsigned i = 0;
    while (x[i] != '\0')
    {
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
    params[0].tipo_val = INT_PAR; /* o primeiro parâmetro de memcmp é um ponteiro para char */
    params[0].orig_val = PARAM; 

    cria_func (abs, params, 1, codigo);
    mesmo_prefixo = (func_ptr) codigo;

    if ( 2 == mesmo_prefixo(-2))
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf(" NÃO PASSOU NO TESTE\n");

    }

    unsigned char codigo2[500];

    func_ptr2 mesmo_prefixo2;

    //TESTE 1 - INTEIRO
    params[0].tipo_val = INT_PAR; /* o primeiro parâmetro de memcmp é um ponteiro para char */
    params[0].orig_val = FIX; 
    params[0].valor.v_int = -2;


    cria_func (abs, params, 1, codigo2);
    mesmo_prefixo2 = (func_ptr2) codigo2;

    if ( 2 == mesmo_prefixo2())
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf(" NÃO PASSOU NO TESTE\n");

    }

    unsigned char codigo3[500];
    int ind = -2;

    //TESTE 1 - INTEIRO
    params[0].tipo_val = INT_PAR; /* o primeiro parâmetro de memcmp é um ponteiro para char */
    params[0].orig_val = IND; 
    params[0].valor.v_ptr = &ind;


    cria_func (abs, params, 1, codigo3);
    mesmo_prefixo2 = (func_ptr2) codigo3;

    if ( 2 == mesmo_prefixo2())
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf(" NÃO PASSOU NO TESTE\n");

    }

    return 0;
}