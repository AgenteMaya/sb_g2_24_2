#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cria_func.h"

typedef int (*func_ptr_0_P) ();
typedef int (*func_ptr_1_P_I) (int x);
typedef int (*func_ptr_1_P_P) (void* x);
typedef int (*func_ptr_2_P_I) (int x, int y);
typedef int (*func_ptr_2_P_P) (void* x, void* y);

int testa_3I(int x, int y, int z)
{
    fprintf(stderr, "entrei na funcao\n");
    fprintf(stderr, "x: %d, y: %d, z: %d\n", x, y, z);
    return x * y * z;
}

int main(void)
{
    
    //FIX - FIX - FIX

   /*  DescParam params_F_F_F[3];
    unsigned char codigo[500];
    func_ptr_0_P teste_F_F_F;

    params_F_F_F[0].tipo_val = INT_PAR;
    params_F_F_F[0].orig_val = FIX;
    params_F_F_F[0].valor.v_int = 15;


    params_F_F_F[1].tipo_val = INT_PAR; 
    params_F_F_F[1].orig_val = FIX;
    params_F_F_F[1].valor.v_int = 3;

    params_F_F_F[2].tipo_val = INT_PAR; 
    params_F_F_F[2].orig_val = FIX;
    params_F_F_F[2].valor.v_int = 2;

    cria_func(testa_3I, params_F_F_F, 3, codigo);
    teste_F_F_F = (func_ptr_0_P) codigo;
    int resultado = teste_F_F_F();
    printf("\nFIX - FIX - FIX: ");

    if( resultado == 90)
    {
    printf("PASSOU NO TESTE\n");
    }
    else{
    printf("NÃO PASSOU NO TESTE\n");

    } */

    //FIX - FIX - IND
    
    /* DescParam params_F_F_I[3];
    unsigned char codigo_F_F_I[500];
    func_ptr_0_P teste_F_F_I;

    params_F_F_I[0].tipo_val = INT_PAR;
    params_F_F_I[0].orig_val = FIX;
    params_F_F_I[0].valor.v_int = 15;

    params_F_F_I[1].tipo_val = INT_PAR;
    params_F_F_I[1].orig_val = FIX;
    params_F_F_I[1].valor.v_int = 3;

    int valor = 2;
    params_F_F_I[2].tipo_val = INT_PAR; 
    params_F_F_I[2].orig_val = IND;
    params_F_F_I[2].valor.v_ptr = &valor;


    cria_func(testa_3I, params_F_F_I, 3, codigo_F_F_I);
    teste_F_F_I = (func_ptr_0_P) codigo_F_F_I;
    int resultado_F_F_I = teste_F_F_I();
    printf("\nFIX - FIX - IND : ");
    
    if( resultado_F_F_I == 90)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE\n");

    }  */
    
    //FIX - FIX - PARAM

    DescParam params_F_F_P[3];
    unsigned char codigo_F_F_P[500];
    func_ptr_0_P teste_F_F_P;

    params_F_F_P[0].tipo_val = INT_PAR;
    params_F_F_P[0].orig_val = FIX;
    params_F_F_P[0].valor.v_int = 15;

    params_F_F_P[1].tipo_val = INT_PAR;
    params_F_F_P[1].orig_val = FIX;
    params_F_F_P[1].valor.v_int = 3;

    params_F_F_P[2].tipo_val = INT_PAR; 
    params_F_F_P[2].orig_val = PARAM;

    cria_func(testa_3I, params_F_F_P, 3, codigo_F_F_P);
    teste_F_F_P = (func_ptr_0_P) codigo_F_F_P;
    int resultado_F_F_I = teste_F_F_P(2);
    printf("\nFIX - FIX - PARAM : ");
    
    if( resultado_F_F_I == 90)
    {
        printf("PASSOU NO TESTE\n");
    }
    else{
        printf("NÃO PASSOU NO TESTE\n");

    } 

       
}