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

/* unsigned char* organizaByte(unsigned char mov[], DescParam* params)
{
    unsigned size = sizeof(mov);
    unsigned ind = 0;
    if (size == 5)
    {
        ind = 1;
    }
        
    else
    {
        ind = 2;
        void* p1 = params->valor;
    }
        

    
    for (unsigned i = 0; i < size; i++)
    {
        mov[ind++] = ((vPonteiro) >>  i * 8) & 0xff;
    }
} */

void organizaByteL(unsigned char movl[], int* valor)
{
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] Entrei na organizaByteL\n", __LINE__);

        fprintf(stderr, "\n[DEBUG - %d] valor: %d\n", __LINE__,*valor);
    #endif
    unsigned ind = 1;
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] movl[%d] - %hhx \n", __LINE__, 0, movl[0]);
    #endif
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
}

void organizaByteQ(unsigned char movq[], void** valor)
{
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] Entrei na organizaByteQ\n", __LINE__);

        fprintf(stderr, "\n[DEBUG - %d] valor: %p\n", __LINE__, *valor);
    #endif
    unsigned long p1 = (unsigned long) *valor;
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] valor: %lx\n", __LINE__, *valor);
    #endif

    unsigned ind = 2;
     #ifdef DEBUG
            fprintf(stderr, "\n[DEBUG - %d] movl[%d] - %hhx \n", __LINE__, ind, movq[0]);
            fprintf(stderr, "\n[DEBUG - %d] movl[%d] - %hhx \n", __LINE__, ind, movq[1]);
    #endif
    for (int i = 0; i < 8; i++)
    {
        #ifdef DEBUG
            fprintf(stderr, "\n[DEBUG - %d] movl[%d] - %hhx \n", __LINE__, ind, movq[ind]);
        #endif
        movq[ind++] = (p1 >> i * 8) & 0xff;
        #ifdef DEBUG
            fprintf(stderr, "\n[DEBUG - %d] codigo[%d] - %hhx --- %hhx\n", __LINE__, ind -1,  movq[ind-1], (p1 >> i * 8) & 0xff);
        #endif
    }
}

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
}

unsigned colocaByte(unsigned char codigo[], unsigned char outroCodigo[], unsigned posInicio, unsigned qtdElementos)
{
    #ifdef DEBUG
        fprintf(stderr, "\nENTREI NA colocaByte\n", __LINE__);
    #endif
    for ( unsigned i = 0; i < qtdElementos; i++)
    {
        #ifdef DEBUG
            fprintf(stderr, "\n[DEBUG - %d] codigo[%d] - %hhx --- coutrocodigo[%d] - %hhx\n", __LINE__, posInicio, codigo[posInicio], i, outroCodigo[i]);
        #endif
        codigo[posInicio++] = outroCodigo[i];
        #ifdef DEBUG
                    fprintf(stderr, "\n[DEBUG - %d] codigo[%d] - %hhx --- coutrocodigo[%d] - %hhx\n", __LINE__, posInicio -1, codigo[posInicio -1 ], i, outroCodigo[i]);

        #endif
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
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] Entrei na cria func\n", __LINE__);
    #endif
    unsigned char posicao = 0;
    unsigned char inicio[] = {0x55, 0x48, 0x89, 0xe5};
    unsigned char final[] = {0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 ,0xff, 0xd0, 0xc9, 0xc3};
    unsigned char movl[][5] = {{0xbf, 0x00, 0x00, 0x00, 0x00}, {0xbe, 0x00, 0x00, 0x00, 0x00}, {0xba, 0x00, 0x00, 0x00, 0x00}};
    unsigned char movq[][10] = {{0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
#ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] Antes coloca byte\n", __LINE__);
    #endif
    posicao = colocaByte(codigo, inicio, posicao, sizeof(inicio));
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] Depois coloca byte\n", __LINE__);
    #endif
    unsigned qtdParams = contaParam(params, n);
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] qtd param geral: %d \n\n", __LINE__, n);

        fprintf(stderr, "\n[DEBUG - %d] qtd param param: %d \n\n", __LINE__, qtdParams);
    #endif

    for (unsigned i = 0; i < n; i++)
    {
        unsigned origem = params[i].orig_val;

        switch(origem)
        {
            case 0: //PARAM
                #ifdef DEBUG
                    fprintf(stderr, "\n[DEBUG - %d] Entrei no caso param param\n", __LINE__);
                #endif
                continue;
            case 1: //FIX
                #ifdef DEBUG
                    fprintf(stderr, "\n[DEBUG - %d] Entrei no caso param fix\n", __LINE__);
                #endif
                if (!params[i].tipo_val) // INTEIRO
                {
                    #ifdef DEBUG
                        fprintf(stderr, "\n[DEBUG - %d] tipo do valor: %d\n", __LINE__, params[i].tipo_val);
                        fprintf(stderr, "\n[DEBUG - %d] valor: %d\n", __LINE__, params[i].valor);
                    #endif
                    organizaByteL(movl[qtdParams], (int* ) &params[i].valor);
                }
                else
                {
                    #ifdef DEBUG
                        fprintf(stderr, "\n[DEBUG - %d] tipo do valor: %d\n", __LINE__, params[i].tipo_val);
                        fprintf(stderr, "\n[DEBUG - %d] valor: %p\n", __LINE__,params[i].valor);
                    #endif
                    organizaByteQ(movq[qtdParams], (void**) &params[i].valor);
                }
                break;
            case 2: //IND
                #ifdef DEBUG
                    fprintf(stderr, "\n[DEBUG - %d] Entrei no caso param ind\n", __LINE__);
                #endif
                if (!params[i].tipo_val) // INTEIRO
                {
                    decideOrganizaByte(movl[qtdParams], (void**) &params[i].valor, params[i].tipo_val);
                }
                else{
                    decideOrganizaByte(movq[qtdParams], (void**) &params[i].valor, params[i].tipo_val);
                }
                break;
        }
        #ifdef DEBUG
                fprintf(stderr, "\n[DEBUG - %d] SAI DO SWITCH\n", __LINE__);
        #endif
        if (!params[i].tipo_val) // INTEIRO
        {
            #ifdef DEBUG
                fprintf(stderr, "\n[DEBUG - %d] Vou entra no coloca byte- INTEIRO\n", __LINE__);
            #endif
            posicao = colocaByte(codigo, movl[qtdParams], posicao, sizeof(movl[i]));
        }
        else
        {
            #ifdef DEBUG
                fprintf(stderr, "\n[DEBUG - %d] Vou entra no coloca byte - PARAM\n", __LINE__);
            #endif
            posicao = colocaByte(codigo, movq[qtdParams], posicao, sizeof(movq[i]));
        }
        qtdParams++;
    }
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] PONTEIRO DA FUNCAO: %p\n", __LINE__, f);
    #endif
    organizaByteQ(final, &f);
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] Vou entra no ultima colocaByte\n", __LINE__);
    #endif
    posicao = colocaByte(codigo, final, posicao, sizeof(final));
    #ifdef DEBUG
        for (unsigned j = 0; j < 30; j++)
        {
            fprintf(stderr, "\n[DEBUG - %d] codigo[%u]: %hhx\n", __LINE__, j, codigo[j]);
        }
    #endif
    
}
