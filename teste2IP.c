#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cria_func.h"

typedef int (*func_ptr_0_P) ();
typedef int (*func_ptr_1_P_I) (int x);
typedef int (*func_ptr_1_P_P) ();
typedef int (*func_ptr_2_P_I) (int x, int y);
typedef int (*func_ptr_2_P_P) ();

int teste2I(int x, int y)
{
    fprintf(stderr, "entrei na funcao\n");
    fprintf(stderr, "x: %d, y: %d\n", x, y);
    return x * y;
}

/*
Usaremos para:

int - int -> div(int, int)
int - pointer -> strchr(const char *s, int c)
pointer - pointer -> strcmp(const char *s1, const char *s2)
*/

int main(void)
{
    //INT - INT
    //printf("\n INT - INT : ");

    /* //FIX - FIX
    DescParam params_F_F[2];
    unsigned char codigo[500];
    func_ptr_0_P teste_F_F;

    params_F_F[0].tipo_val = INT_PAR;
    params_F_F[0].orig_val = FIX;
    params_F_F[0].valor.v_int = 15;


    params_F_F[1].tipo_val = INT_PAR; 
    params_F_F[1].orig_val = FIX;
    params_F_F[1].valor.v_int = 3;


    cria_func(teste2I, params_F_F, 2, codigo);
    teste_F_F = (func_ptr_0_P) codigo;
    int resultado = teste_F_F();
    printf("\nFIX - FIX : ");

    if( resultado == 45)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE\n");

    }

    //FIX - IND

    DescParam params_F_I[2];
    unsigned char codigo_F_I[500];
    func_ptr_0_P teste_F_I;

    params_F_I[0].tipo_val = INT_PAR;
    params_F_I[0].orig_val = FIX;
    params_F_I[0].valor.v_int = 15;

    int valor = 3;
    params_F_I[1].tipo_val = INT_PAR; 
    params_F_I[1].orig_val = IND;
    params_F_I[1].valor.v_ptr = &valor;


    cria_func(teste2I, params_F_I, 2, codigo_F_I);
    teste_F_I = (func_ptr_0_P) codigo_F_I;
    int resultado_F_I = teste_F_I();
    printf("\nFIX - IND : ");
    if( resultado_F_I == 45)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE\n");

    } 

    //FIX - PARAM

    DescParam params_F_P[2];
    unsigned char codigo_F_P[500];
    func_ptr_0_P teste_F_P;

    params_F_P[0].tipo_val = INT_PAR;
    params_F_P[0].orig_val = FIX;
    params_F_P[0].valor.v_int = 15;

    params_F_P[1].tipo_val = INT_PAR; 
    params_F_P[1].orig_val = PARAM;


    cria_func(teste2I, params_F_P, 2, codigo_F_P);
    teste_F_P = (func_ptr_0_P) codigo_F_P;
    int resultado_F_P = teste_F_P(3);
    printf("\nFIX - PARAM : ");
    if( resultado_F_P == 45)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE -- %d\n", resultado_F_P);

    }
    */
    /*
    //IND - FIX
    DescParam params_I_F[2];
    unsigned char codigo_I_F[500];
    func_ptr_0_P teste_I_F;

    int valor_I_F = 15;
    params_I_F[0].tipo_val = INT_PAR;
    params_I_F[0].orig_val = IND;
    params_I_F[0].valor.v_ptr = &valor_I_F;


    params_I_F[1].tipo_val = INT_PAR; 
    params_I_F[1].orig_val = FIX;
    params_I_F[1].valor.v_int = 3;


    cria_func(teste2I, params_I_F, 2, codigo_I_F);
    teste_I_F = (func_ptr_0_P) codigo_I_F;
    int resultado = teste_I_F();
    printf("\nIND - FIX : ");

    if( resultado == 45)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE\n");

    }

    //IND - IND

    DescParam params_I_I[2];
    unsigned char codigo_I_I[500];
    func_ptr_0_P teste_I_I;

    int valor_I_I_1 = 15;
    params_I_I[0].tipo_val = INT_PAR;
    params_I_I[0].orig_val = IND;
    params_I_I[0].valor.v_ptr = &valor_I_I_1;

    int valor_I_I_2 = 3;
    params_I_I[1].tipo_val = INT_PAR; 
    params_I_I[1].orig_val = IND;
    params_I_I[1].valor.v_ptr = &valor_I_I_2;


    cria_func(teste2I, params_I_I, 2, codigo_I_I);
    teste_I_I = (func_ptr_0_P) codigo_I_I;
    int resultado_F_I = teste_I_I();
    printf("\n IND - IND : ");
    if( resultado_F_I == 45)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE\n");

    } 

    //IND - PARAM

    DescParam params_I_P[2];
    unsigned char codigo_I_P[500];
    func_ptr_0_P teste_I_P;

    int valor_I_P = 15;
    params_I_P[0].tipo_val = INT_PAR;
    params_I_P[0].orig_val = IND;
    params_I_P[0].valor.v_ptr = &valor_I_P;

    params_I_P[1].tipo_val = INT_PAR; 
    params_I_P[1].orig_val = PARAM;


    cria_func(teste2I, params_I_P, 2, codigo_I_P);
    teste_I_P = (func_ptr_0_P) codigo_I_P;
    int resultado_I_P = teste_I_P(3);
    printf("\nIND - PARAM : ");
    if( resultado_I_P == 45)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE -- %d\n", resultado_I_P);

    }
   

    //PARAM - FIX
    DescParam params_P_F[2];
    unsigned char codigo_P_F[500];
    func_ptr_1_P_I teste_P_F;

    params_P_F[0].tipo_val = INT_PAR;
    params_P_F[0].orig_val = PARAM;

    params_P_F[1].tipo_val = INT_PAR; 
    params_P_F[1].orig_val = FIX;
    params_P_F[1].valor.v_int = 3;


    cria_func(teste2I, params_P_F, 2, codigo_P_F);
    teste_P_F = (func_ptr_1_P_I) codigo_P_F;
    int resultado_P_F = teste_P_F(15);
    printf("\nPARAM - FIX : ");

    if( resultado_P_F == 45)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE\n");

    }

    //PARAM - IND

    DescParam params_P_I[2];
    unsigned char codigo_P_I[500];
    func_ptr_1_P_I teste_P_I;

    params_P_I[0].tipo_val = INT_PAR;
    params_P_I[0].orig_val = PARAM;

    int valor_I_I = 3;
    params_P_I[1].tipo_val = INT_PAR; 
    params_P_I[1].orig_val = IND;
    params_P_I[1].valor.v_ptr = &valor_I_I;


    cria_func(teste2I, params_P_I, 2, codigo_P_I);
    teste_P_I = (func_ptr_1_P_I) codigo_P_I;
    int resultado_P_I = teste_P_I(15);
    printf("\nPARAM - PARAM : ");
    if( resultado_P_I == 45)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE\n");

    } 

    //PARAM - PARAM

    DescParam params_P_P[2];
    unsigned char codigo_P_P[500];
    func_ptr_2_P_I teste_P_P;

    params_P_P[0].tipo_val = INT_PAR;
    params_P_P[0].orig_val = PARAM;

    params_P_P[1].tipo_val = INT_PAR; 
    params_P_P[1].orig_val = PARAM;

    cria_func(teste2I, params_P_P, 2, codigo_P_P);
    teste_P_P = (func_ptr_2_P_I) codigo_P_P;
    int resultado_P_P = teste_P_P(15,3);
    printf("\nPARAM - PARAM : ");
    if( resultado_P_P == 45)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE -- %d\n", resultado_P_P);

    }
    */

}