/* Maria Eduarda da Fonseca Gonçalves Santos 2212985 3WA */
/* Mayara Ramos Damazio 2210833 3WC */

#include <stdio.h>

#include "cria_func.h"
#define DEBUG

unsigned contaParam(DescParam params[], int n)
{
    unsigned qtd_params = 0;
    for (int i = 0; i < n; i++)
    {
        if (params[i].orig_val == PARAM)
        {
            qtd_params++;
        }
    }
    return qtd_params;    
}

void organizaByteL(unsigned char movl[], int* valor)
{
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] Entrei na colocaByteL\n", __LINE__);
        fprintf(stderr, "\n[DEBUG - %d] valor : %d\n", __LINE__, *valor);
        fprintf(stderr, "\n[DEBUG - %d] movl[%d] - %hhx \n", __LINE__, 0, movl[0]);        
    #endif
    unsigned ind = 1;
    for (int i = 0; i < 4; i++)
    {
        #ifdef DEBUG
            fprintf(stderr, "\n[DEBUG - %d] movl[%d] - %hhx \n", __LINE__, ind, movl[ind]);
        #endif
        movl[ind++] = (*valor >> i * 8) & 0xff;
        #ifdef DEBUG
            fprintf(stderr, "\n[DEBUG - %d] codigo[%d] - %hhx --- %hhx\n", __LINE__, ind -1,  movl[ind-1], (*valor >> i * 8) & 0xff);
        #endif
    }
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] Vou sair da organizaByteL \n", __LINE__);
    #endif
}

void organizaByteQ(unsigned char movq[], void** valor)
{
    unsigned long p1 = (unsigned long) *valor;
    unsigned ind = 2;

    for (int i = 0; i < 8; i++)
    {
        movq[ind++] = (p1 >> i * 8) & 0xff;
    }
}

/* 
void decideOrganizaByte (unsigned char mov[], void** valor, unsigned tipo)
{
    if (!tipo) // INTEIRO
    {
        organizaByteL(mov, (int*) valor);
    }
    else{
        void* pointer = *valor;
        organizaByteQ(mov, pointer);
    }
} */

unsigned colocaByte(unsigned char codigo[], unsigned char outroCodigo[], unsigned posInicio, unsigned qtdElementos)
{
    for ( unsigned i = 0; i < qtdElementos; i++)
    {
        codigo[posInicio++] = outroCodigo[i];
    }
    return posInicio;
}

int busca_leave(char codigo[])/*busca a posição o comando leave c9*/
{
    int i = 0;
    while (codigo[i])
    {
        if(codigo[i] == 0xc9)
            return i;
        i++;
    }
    return -1;
} 

void cria_func (void* f, DescParam params[], int n, unsigned char codigo[])
{
   /*  #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] Entrei na cria func\n", __LINE__);
    #endif */
    unsigned char posicao = 0;
    unsigned char inicio[] = {0x55,
                              0x48, 0x89, 0xe5,
                              0x48, 0x83, 0xec, 0x20,
                              0x48, 0x89, 0x7d, 0xf8,
                              0x48, 0x89, 0x75, 0xf0,
                              0x48, 0x89, 0x55, 0xe8
                             };
    unsigned char final[] = {0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 ,0xff, 0xd0, 0xc9, 0xc3};
    unsigned char movl[][5] = {{0xbf, 0x00, 0x00, 0x00, 0x00}, {0xbe, 0x00, 0x00, 0x00, 0x00}, {0xba, 0x00, 0x00, 0x00, 0x00}};
    unsigned char movq[][10] = {{0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
    unsigned char vInd[] = {0x49, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    unsigned char movsIndsL [][3] = {{0x41, 0x8b, 0x3a}, {0x41, 0x8b, 0x32}, {0x41, 0x8b, 0x12}};
    unsigned char movsIndsQ [][3] = {{0x49, 0x8b, 0x3a}, {0x49, 0x8b, 0x32}, {0x49, 0x8b, 0x12}};
    unsigned char paramsL[][3][3] = {{{0x8b, 0x7d, 0xf8}, {0x8b, 0x75, 0xf8}, {0x8b, 0x55, 0xf8}},{{0x8b, 0x7d, 0xf0}, {0x8b, 0x75, 0xf0}, {0x8b, 0x55, 0xf0}}, {{0x8b, 0x7d, 0xe8}, {0x8b, 0x75, 0xe8}, {0x8b, 0x55, 0xe8}}};
    unsigned char paramsQ [][3][4]= {{{0x48, 0x8b, 0x7d, 0xf8}, {0x48, 0x8b, 0x75, 0xf8}, {0x48, 0x8b, 0x55, 0xf8}}, {{0x48, 0x8b, 0x7d, 0xf0}, {0x48, 0x8b, 0x75, 0xf0}, {0x48, 0x8b, 0x55, 0xf0}}, {{0x48, 0x8b, 0x7d, 0xe8}, {0x48, 0x8b, 0x75, 0xe8}, {0x48, 0x8b, 0x55, 0xe8}}};


    unsigned qtdParam = 0;

    posicao = colocaByte(codigo, inicio, posicao, sizeof(inicio));
  
    //unsigned qtdParams = contaParam(params, n);
   
    for (unsigned i = 0; i < n; i++)
    {
        #ifdef DEBUG
            fprintf(stderr, "\n[DEBUG - %d] i : %u --- n : %d\n", __LINE__, i, n);
        #endif
        unsigned origem = params[i].orig_val;

        switch(origem)
        {
            case 0: //PARAM
                #ifdef DEBUG
                    fprintf(stderr, "\n[DEBUG - %d] Entrei no caso param param\n", __LINE__);
                #endif
                if (!params[i].tipo_val) // INTEIRO
                {
                    posicao = colocaByte(codigo, paramsL[qtdParam][i], posicao, sizeof(paramsL[qtdParam][i]));
                }
                else
                {
                    posicao = colocaByte(codigo, paramsQ[qtdParam][i], posicao, sizeof(paramsQ[qtdParam][i]));
                }
                qtdParam++;
                break;
            case 1: //FIX
                #ifdef DEBUG
                    fprintf(stderr, "\n[DEBUG - %d] Entrei no caso param fix\n", __LINE__);
                #endif
                if (!params[i].tipo_val) // INTEIRO
                {
                    #ifdef DEBUG
                        fprintf(stderr, "\n[DEBUG - %d] Vou entrar na organiza byte pelo fix\n", __LINE__);
                    #endif
                    organizaByteL(movl[i], (int* ) &params[i].valor);
                    posicao = colocaByte(codigo, movl[i], posicao, sizeof(movl[i]));
                }
                else
                {
                    organizaByteQ(movq[i], (void**) &params[i].valor);
                    posicao = colocaByte(codigo, movq[i], posicao, sizeof(movq[i]));
                }
                break;
            case 2: //IND
                #ifdef DEBUG
                    fprintf(stderr, "\n[DEBUG - %d] Entrei no caso param ind\n", __LINE__);
                #endif
                organizaByteQ(vInd, (void**) &params[i].valor);
                posicao = colocaByte(codigo, vInd, posicao, sizeof(vInd));
                if (!params[i].tipo_val) // INTEIRO
                {
                    posicao = colocaByte(codigo, movsIndsL[i], posicao, sizeof(movsIndsL[i]));    
                }
                else{
                    posicao = colocaByte(codigo, movsIndsQ[i], posicao, sizeof(movsIndsQ[i]));    
                } 
                break;
        }
        #ifdef DEBUG
                fprintf(stderr, "\n[DEBUG - %d] SAI DO SWITCH\n", __LINE__);
        #endif
       
        //qtdParams++;
    }
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] PONTEIRO DA FUNCAO: %p\n", __LINE__, f);
    #endif
    organizaByteQ(final, &f);

    posicao = colocaByte(codigo, final, posicao, sizeof(final));

    #ifdef DEBUG
        fprintf(stderr, "\n\n[DEBUG - %d] PRINT DO CODIGO FINAL:\n\n", __LINE__);
        for (unsigned j = 0; j < 60; j++)
        {
            fprintf(stderr, "\n[DEBUG - %d] codigo[%u]: %hhx\n", __LINE__, j, codigo[j]);
        }
    #endif
    
}
