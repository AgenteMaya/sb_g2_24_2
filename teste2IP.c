#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cria_func.h"

//#define TESTES_INT
#define TESTES_PTR

typedef int (*func_ptr_0_P) ();
typedef int (*func_ptr_1_P_I) (int x);
typedef int (*func_ptr_1_P_P) (void* x);
typedef int (*func_ptr_2_P_I) (int x, int y);
typedef int (*func_ptr_2_P_P) (void* x, void* y);

int teste2I(int x, int y)
{
    fprintf(stderr, "entrei na funcao\n");
    fprintf(stderr, "x: %d, y: %d\n", x, y);
    return x * y;
}

int compara2P(char* x, char* y)
{
    fprintf(stderr, "entrei na funcao\n");
    
    fprintf(stderr, "y: %s\n",y);
    fprintf(stderr, "x: %s\n",x);
    return strcmp(x, y);
}

int somaVNum(int*x, int qtd)
{
    int soma = 0;
    for(int i = 0; i < qtd; i++)
    {
        soma+= x[i];
    }
    return soma;
}

void printvVChar(char** palavra, int n)
{
    for(int i = 0; i < n; i++)
    {
        fprintf(stderr, "%s \n", palavra[i]);
    }
    fprintf(stderr, "\n");
}

/*
Usaremos para:

int - int -> div(int, int)
int - pointer -> strchr(const char *s, int c)
pointer - pointer -> strcmp(const char *s1, const char *s2)
*/

int main(void)
{
    #ifdef TESTES_INT
    {
        //INT - INT
        //fprintf(stderr, "\n INT - INT : ");

        //FIX - FIX
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
        int resultado_F_F = teste_F_F();
        fprintf(stderr, "\nFIX - FIX : ");

        if( resultado_F_F == 45)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

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
        fprintf(stderr, "\nFIX - IND : ");
        if( resultado_F_I == 45)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        } 

        //FIX - PARAM

        DescParam params_F_P[2];
        unsigned char codigo_F_P[500];
        func_ptr_1_P_I teste_F_P;

        params_F_P[0].tipo_val = INT_PAR;
        params_F_P[0].orig_val = FIX;
        params_F_P[0].valor.v_int = 15;

        params_F_P[1].tipo_val = INT_PAR; 
        params_F_P[1].orig_val = PARAM;


        cria_func(teste2I, params_F_P, 2, codigo_F_P);
        teste_F_P = (func_ptr_1_P_I) codigo_F_P;
        int resultado_F_P = teste_F_P(3);
        fprintf(stderr, "\nFIX - PARAM : ");
        if( resultado_F_P == 45)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_F_P);

        }
       
        
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
        int resultado_I_F = teste_I_F();
        fprintf(stderr, "\nIND - FIX : ");

        if( resultado_I_F == 45)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

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
        int resultado_I_I = teste_I_I();
        fprintf(stderr, "\n IND - IND : ");
        if( resultado_I_I == 45)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

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
        fprintf(stderr, "\nIND - PARAM : ");
        if( resultado_I_P == 45)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_I_P);

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
        fprintf(stderr, "\nPARAM - FIX : ");

        if( resultado_P_F == 45)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

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
        fprintf(stderr, "\nPARAM - IND : ");
        if( resultado_P_I == 45)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

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
        fprintf(stderr, "\nPARAM - PARAM : ");
        if( resultado_P_P == 45)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_P_P);

        }
       
    }
    #endif

    #ifdef TESTES_PTR
    {
        //PTR - PTR
        fprintf(stderr, "\n PTR - PTR : ");

        //FIX - FIX
        DescParam params_F_F[2];
        unsigned char codigo[500];
        func_ptr_0_P teste_F_F;

        params_F_F[0].tipo_val = PTR_PAR;
        params_F_F[0].orig_val = FIX;
        params_F_F[0].valor.v_ptr = "arcane";


        params_F_F[1].tipo_val = PTR_PAR; 
        params_F_F[1].orig_val = FIX;
        params_F_F[1].valor.v_ptr = "ARCANE";


        cria_func(compara2P, params_F_F, 2, codigo);
        teste_F_F = (func_ptr_0_P) codigo;
        int resultado_F_F = teste_F_F();
        fprintf(stderr, "\nFIX - FIX : ");

        if(resultado_F_F)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        }

        //FIX - IND

        DescParam params_F_I[2];
        unsigned char codigo_F_I[500];
        func_ptr_0_P teste_F_I;

        params_F_I[0].tipo_val = PTR_PAR;
        params_F_I[0].orig_val = FIX;
        params_F_I[0].valor.v_ptr = "arcane";

        char valor_F_I[] = "ARCANE";
        char* ptr_F_I = valor_F_I;
        char** ptr2_F_I = &ptr_F_I;
        params_F_I[1].tipo_val = PTR_PAR; 
        params_F_I[1].orig_val = IND;
        params_F_I[1].valor.v_ptr = ptr2_F_I;


        cria_func(compara2P, params_F_I, 2, codigo_F_I);
        teste_F_I = (func_ptr_0_P) codigo_F_I;
        int resultado_F_I = teste_F_I();
        fprintf(stderr, "\nFIX - IND : ");
        if(resultado_F_I )
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        } 

        //FIX - PARAM

        DescParam params_F_P[2];
        unsigned char codigo_F_P[500];
        func_ptr_1_P_P teste_F_P;

        params_F_P[0].tipo_val = PTR_PAR;
        params_F_P[0].orig_val = FIX;
        params_F_P[0].valor.v_ptr = "arcane";

        params_F_P[1].tipo_val = PTR_PAR; 
        params_F_P[1].orig_val = PARAM;


        cria_func(compara2P, params_F_P, 2, codigo_F_P);
        teste_F_P = (func_ptr_1_P_P) codigo_F_P;
        int resultado_F_P = teste_F_P("ARCANE");
        fprintf(stderr, "\nFIX - PARAM : ");
        if(resultado_F_P)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_F_P);

        }
        
    
        //IND - FIX
        DescParam params_I_F[2];
        unsigned char codigo_I_F[500];
        func_ptr_0_P teste_I_F;

        char valor_I_F[] = "arcane";
        char* ptr_I_F = valor_I_F;
        char** ptr2_I_F = &ptr_I_F;
        params_I_F[0].tipo_val = PTR_PAR;
        params_I_F[0].orig_val = IND;
        params_I_F[0].valor.v_ptr = ptr2_I_F;


        params_I_F[1].tipo_val = PTR_PAR; 
        params_I_F[1].orig_val = FIX;
        params_I_F[1].valor.v_ptr = "ARCANE";


        cria_func(compara2P, params_I_F, 2, codigo_I_F);
        teste_I_F = (func_ptr_0_P) codigo_I_F;
        int resultado_I_F = teste_I_F();
        fprintf(stderr, "\nIND - FIX : ");

        if(resultado_I_F)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        }

        //IND - IND

        DescParam params_I_I[2];
        unsigned char codigo_I_I[500];
        func_ptr_0_P teste_I_I;

        char valor_I_I_1[] = "Arcane";
        char* ptr_I_I_1 = valor_I_I_1;
        char** ptr2_I_I_1 = &ptr_I_I_1;
        params_I_I[0].tipo_val = PTR_PAR;
        params_I_I[0].orig_val = IND;
        params_I_I[0].valor.v_ptr = ptr2_I_I_1;

        char valor_I_I_2[] = "ARCANE";
         char* ptr_I_I_2 = valor_I_I_2;
        char** ptr2_I_I_2 = &ptr_I_I_2;
        params_I_I[1].tipo_val = PTR_PAR; 
        params_I_I[1].orig_val = IND;
        params_I_I[1].valor.v_ptr = ptr2_I_I_2;


        cria_func(compara2P, params_I_I, 2, codigo_I_I);
        teste_I_I = (func_ptr_0_P) codigo_I_I;
        int resultado_I_I = teste_I_I();
        fprintf(stderr, "\n IND - IND : ");
        if(resultado_I_I)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        } 

        //IND - PARAM

        DescParam params_I_P[2];
        unsigned char codigo_I_P[500];
        func_ptr_1_P_P teste_I_P;

        char valor_I_P[] = "arcane";
        char* ptr_I_P = valor_I_P;
        char** ptr2_I_P = &ptr_I_P;
        params_I_P[0].tipo_val = PTR_PAR;
        params_I_P[0].orig_val = IND;
        params_I_P[0].valor.v_ptr = ptr2_I_P;

        params_I_P[1].tipo_val = PTR_PAR; 
        params_I_P[1].orig_val = PARAM;


        cria_func(compara2P, params_I_P, 2, codigo_I_P);
        teste_I_P = (func_ptr_1_P_P) codigo_I_P;
        int resultado_I_P = teste_I_P("ARCANE");
        fprintf(stderr, "\nIND - PARAM : ");
        if(resultado_I_P)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_I_P);

        }
    

        //PARAM - FIX
        DescParam params_P_F[2];
        unsigned char codigo_P_F[500];
        func_ptr_1_P_P teste_P_F;

        params_P_F[0].tipo_val = PTR_PAR;
        params_P_F[0].orig_val = PARAM;

        params_P_F[1].tipo_val = PTR_PAR; 
        params_P_F[1].orig_val = FIX;
        params_P_F[1].valor.v_ptr = "ARCANE";


        cria_func(compara2P, params_P_F, 2, codigo_P_F);
        teste_P_F = (func_ptr_1_P_P) codigo_P_F;
        int resultado_P_F = teste_P_F("arcane");
        fprintf(stderr, "\nPARAM - FIX : ");

        if(resultado_P_F)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        }

        //PARAM - IND

        DescParam params_P_I[2];
        unsigned char codigo_P_I[500];
        func_ptr_1_P_P teste_P_I;

        params_P_I[0].tipo_val = PTR_PAR;
        params_P_I[0].orig_val = PARAM;

        char valor_P_I[]= "ARCANE";
        char* ptr_P_I = valor_P_I;
        char** ptr2_P_I = &ptr_P_I;
        params_P_I[1].tipo_val = PTR_PAR; 
        params_P_I[1].orig_val = IND;
        params_P_I[1].valor.v_ptr = ptr2_P_I;


        cria_func(compara2P, params_P_I, 2, codigo_P_I);
        teste_P_I = (func_ptr_1_P_P) codigo_P_I;
        int resultado_P_I = teste_P_I("arcane");
        fprintf(stderr, "\nPARAM - IND : ");
        if(resultado_P_I)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        } 

        //PARAM - PARAM

        DescParam params_P_P[2];
        unsigned char codigo_P_P[500];
        func_ptr_2_P_P teste_P_P;

        params_P_P[0].tipo_val = PTR_PAR;
        params_P_P[0].orig_val = PARAM;

        params_P_P[1].tipo_val = PTR_PAR; 
        params_P_P[1].orig_val = PARAM;

        cria_func(compara2P, params_P_P, 2, codigo_P_P);
        teste_P_P = (func_ptr_2_P_P) codigo_P_P;
        int resultado_P_P = teste_P_P("arcane", "ARCANE");
        fprintf(stderr, "\nPARAM - PARAM : ");
        if(resultado_P_P)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_P_P);

        }
   }

   {
        fprintf(stderr, "\n INT - PTR : ");

        //FIX - FIX
        DescParam params_F_F[2];
        unsigned char codigo[500];
        func_ptr_0_P teste_F_F;

        params_F_F[0].tipo_val = INT_PAR;
        params_F_F[0].orig_val = FIX;
        params_F_F[0].valor.v_int = 'C';


        params_F_F[1].tipo_val = PTR_PAR; 
        params_F_F[1].orig_val = FIX;
        params_F_F[1].valor.v_ptr = "ARCANE";


        cria_func(printvVChar, params_F_F, 2, codigo);
        teste_F_F = (func_ptr_0_P) codigo;
        int resultado_F_F = teste_F_F();
        fprintf(stderr, "\nFIX - FIX : ");

        if(resultado_F_F)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        }

        //FIX - IND

        DescParam params_F_I[2];
        unsigned char codigo_F_I[500];
        func_ptr_0_P teste_F_I;

        params_F_I[0].tipo_val = PTR_PAR;
        params_F_I[0].orig_val = FIX;
        params_F_I[0].valor.v_ptr = "arcane";

        char valor_F_I[] = "ARCANE";
        char* ptr_F_I = valor_F_I;
        char** ptr2_F_I = &ptr_F_I;
        params_F_I[1].tipo_val = PTR_PAR; 
        params_F_I[1].orig_val = IND;
        params_F_I[1].valor.v_ptr = ptr2_F_I;


        cria_func(compara2P, params_F_I, 2, codigo_F_I);
        teste_F_I = (func_ptr_0_P) codigo_F_I;
        int resultado_F_I = teste_F_I();
        fprintf(stderr, "\nFIX - IND : ");
        if(resultado_F_I)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        } 

        //FIX - PARAM

        DescParam params_F_P[2];
        unsigned char codigo_F_P[500];
        func_ptr_1_P_P teste_F_P;

        params_F_P[0].tipo_val = PTR_PAR;
        params_F_P[0].orig_val = FIX;
        params_F_P[0].valor.v_ptr = "arcane";

        params_F_P[1].tipo_val = PTR_PAR; 
        params_F_P[1].orig_val = PARAM;


        cria_func(compara2P, params_F_P, 2, codigo_F_P);
        teste_F_P = (func_ptr_1_P_P) codigo_F_P;
        int resultado_F_P = teste_F_P("ARCANE");
        fprintf(stderr, "\nFIX - PARAM : ");
        if(resultado_F_P)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_F_P);

        }
        
    
        //IND - FIX
        DescParam params_I_F[2];
        unsigned char codigo_I_F[500];
        func_ptr_0_P teste_I_F;

        char valor_I_F[] = "arcane";
        char* ptr_I_F = valor_I_F;
        char** ptr2_I_F = &ptr_I_F;
        params_I_F[0].tipo_val = PTR_PAR;
        params_I_F[0].orig_val = IND;
        params_I_F[0].valor.v_ptr = ptr2_I_F;


        params_I_F[1].tipo_val = PTR_PAR; 
        params_I_F[1].orig_val = FIX;
        params_I_F[1].valor.v_ptr = "ARCANE";


        cria_func(compara2P, params_I_F, 2, codigo_I_F);
        teste_I_F = (func_ptr_0_P) codigo_I_F;
        int resultado_I_F = teste_I_F();
        fprintf(stderr, "\nIND - FIX : ");

        if(resultado_I_F)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        }

        //IND - IND

        DescParam params_I_I[2];
        unsigned char codigo_I_I[500];
        func_ptr_0_P teste_I_I;

        char valor_I_I_1[] = "Arcane";
        char* ptr_I_I_1 = valor_I_I_1;
        char** ptr2_I_I_1 = &ptr_I_I_1;
        params_I_I[0].tipo_val = PTR_PAR;
        params_I_I[0].orig_val = IND;
        params_I_I[0].valor.v_ptr = ptr2_I_I_1;

        char valor_I_I_2[] = "ARCANE";
        char* ptr_I_I_2 = valor_I_I_2;
        char** ptr2_I_I_2 = &ptr_I_I_2;
        params_I_I[1].tipo_val = PTR_PAR; 
        params_I_I[1].orig_val = IND;
        params_I_I[1].valor.v_ptr = ptr2_I_I_2;


        cria_func(compara2P, params_I_I, 2, codigo_I_I);
        teste_I_I = (func_ptr_0_P) codigo_I_I;
        int resultado_I_I = teste_I_I();
        fprintf(stderr, "\n IND - IND : ");
        if(resultado_I_I)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        } 

        //IND - PARAM

        DescParam params_I_P[2];
        unsigned char codigo_I_P[500];
        func_ptr_1_P_P teste_I_P;

        char valor_I_P[] = "arcane";
        char* ptr_I_P = valor_I_P;
        char** ptr2_I_P = &ptr_I_P;
        params_I_P[0].tipo_val = PTR_PAR;
        params_I_P[0].orig_val = IND;
        params_I_P[0].valor.v_ptr = ptr2_I_P;

        params_I_P[1].tipo_val = PTR_PAR; 
        params_I_P[1].orig_val = PARAM;


        cria_func(compara2P, params_I_P, 2, codigo_I_P);
        teste_I_P = (func_ptr_1_P_P) codigo_I_P;
        int resultado_I_P = teste_I_P("ARCANE");
        fprintf(stderr, "\nIND - PARAM : ");
        if(resultado_I_P)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_I_P);

        }
    

        //PARAM - FIX
        DescParam params_P_F[2];
        unsigned char codigo_P_F[500];
        func_ptr_1_P_P teste_P_F;

        params_P_F[0].tipo_val = PTR_PAR;
        params_P_F[0].orig_val = PARAM;

        params_P_F[1].tipo_val = PTR_PAR; 
        params_P_F[1].orig_val = FIX;
        params_P_F[1].valor.v_ptr = "ARCANE";


        cria_func(compara2P, params_P_F, 2, codigo_P_F);
        teste_P_F = (func_ptr_1_P_P) codigo_P_F;
        int resultado_P_F = teste_P_F("arcane");
        fprintf(stderr, "\nPARAM - FIX : ");

        if(resultado_P_F)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        }

        //PARAM - IND

        DescParam params_P_I[2];
        unsigned char codigo_P_I[500];
        func_ptr_1_P_P teste_P_I;

        params_P_I[0].tipo_val = PTR_PAR;
        params_P_I[0].orig_val = PARAM;

        char valor_I_I[]= "ARCANE";
        char* ptr_I_I = valor_I_I;
        char** ptr2_I_I = &ptr_I_I;
        params_P_I[1].tipo_val = PTR_PAR; 
        params_P_I[1].orig_val = IND;
        params_P_I[1].valor.v_ptr = ptr2_I_I;


        cria_func(compara2P, params_P_I, 2, codigo_P_I);
        teste_P_I = (func_ptr_1_P_P) codigo_P_I;
        int resultado_P_I = teste_P_I("arcane");
        fprintf(stderr, "\nPARAM - PARAM : ");
        if(resultado_P_I)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE\n");

        } 

        //PARAM - PARAM

        DescParam params_P_P[2];
        unsigned char codigo_P_P[500];
        func_ptr_2_P_P teste_P_P;

        params_P_P[0].tipo_val = PTR_PAR;
        params_P_P[0].orig_val = PARAM;

        params_P_P[1].tipo_val = PTR_PAR; 
        params_P_P[1].orig_val = PARAM;

        cria_func(compara2P, params_P_P, 2, codigo_P_P);
        teste_P_P = (func_ptr_2_P_P) codigo_P_P;
        int resultado_P_P = teste_P_P("arcane", "ARCANE");
        fprintf(stderr, "\nPARAM - PARAM : ");
        if(resultado_P_P)
        {
            fprintf(stderr, "PASSOU NO TESTE\n");
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_P_P);

        }
    }
    #endif 
    /* {
        //PARAM - PARAM

        DescParam params_P_P[2];
        unsigned char codigo_P_P[500];
        func_ptr_1_P_I teste_P_P;
        int vNums [] = {1,2,3,4};
        int** vvNums = &vNums;
        params_P_P[0].tipo_val = PTR_PAR;
        params_P_P[0].orig_val = IND;
        params_P_P[0].valor.v_ptr = vvNums;

        params_P_P[1].tipo_val = INT_PAR; 
        params_P_P[1].orig_val = PARAM;

        cria_func(somaVNum, params_P_P, 2, codigo_P_P);
        teste_P_P = (func_ptr_1_P_P) codigo_P_P;
        int resultado_P_P = teste_P_P(4);
        fprintf(stderr, "\nPARAM - PARAM : ");
        if(resultado_P_P)
        {
            fprintf(stderr, "PASSOU NO TESTE --%d\n", resultado_P_P);
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_P_P);

        }
    }

    {
        //PARAM - PARAM

        DescParam params_P_P[2];
        unsigned char codigo_P_P[500];
        func_ptr_1_P_I teste_P_P;
        char* vNums[] = {"Arcane", "e", "muito", "bom"};
        char** p = vNums;
        char*** pp = &p;
        params_P_P[0].tipo_val = PTR_PAR;
        params_P_P[0].orig_val = IND;
        params_P_P[0].valor.v_ptr = pp;

        params_P_P[1].tipo_val = INT_PAR; 
        params_P_P[1].orig_val = PARAM;

        fprintf(stderr, "%p\n", &vNums);
        fprintf(stderr, "%p\n", vNums);

        printvVChar(vNums, 4);
        cria_func(printvVChar, params_P_P, 2, codigo_P_P);
        teste_P_P = (func_ptr_1_P_I) codigo_P_P;
        int resultado_P_P = teste_P_P(4);
        fprintf(stderr, "\nPARAM - PARAM : ");
        if(resultado_P_P)
        {
            fprintf(stderr, "PASSOU NO TESTE --%d\n", resultado_P_P);
        }
        else{
            fprintf(stderr, "NÃO PASSOU NO TESTE -- %d\n", resultado_P_P);

        }
    } */
    return 0;
} 