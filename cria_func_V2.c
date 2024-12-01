/* Maria Eduarda da Fonseca Gonçalves Santos 2212985 3WA */
/* Mayara Ramos Damazio 2210833 3WC */

/**
 * @brief Gerador dinâmico de funções
 * @author Maria Eduarda da Fonseca Gonçalves Santos 2212985 3WA
 * @author Mayara Ramos Damazio 2210833 3WC
 * @version 2.0
 * @date 30/11/2024
 */

#include <stdio.h>
#include "cria_func.h"
//#define DEBUG
//#define DEBUG_GERAL

/**
 * Essa função recebe o endereço de um inteiro e coloca em um vetor de bytes os bytes que compõem esse inteiro
 * @param movl Vetor que recebe os bytes do inteiro
 * @param valor Endereço do inteiro que terá seu conteúdo copiado
 */
void organizaByteL(unsigned char movl[], int* valor)
{
    unsigned ind = 1; //Índice da posicao inicial que se coloca no vetor. A posição 0 é um byte especifico que não deve ser mudado
    for (int i = 0; i < 4; i++)
    {
        movl[ind++] = (*valor >> i * 8) & 0xff;
    }
}

/**
 * Essa função recebe o endereço de um ponteiro e coloca em um vetor de bytes os bytes que compoem esse ponteiro
 * @param movq Vetor que recebe os bytes do ponteiro
 * @param valor Endereço do ponteiro que tera seu conteudo copiado
 */
void organizaByteQ(unsigned char movq[], void** valor)
{
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] VALOR DE PTR: %p\n", __LINE__, valor);
        fprintf(stderr, "\n[DEBUG - %d] VALOR DE PTR[O]: %p\n", __LINE__, *valor);
    #endif
    unsigned long pointerAsLong = (unsigned long) valor;
    unsigned ind = 2; //indice da posição índice da posição inicial que se coloca no vetor. A posição 0 e um byte específico inicial que se coloca no vetor. A posição 0 e 1 são bytes específicos que não devem ser mudados 

    for (int i = 0; i < 8; i++)
    {
        movq[ind++] = (pointerAsLong >> i * 8) & 0xff;
    }

    #ifdef DEBUG_ANTIGO
        fprintf(stderr, "\n\n[DEBUG - %d] PRINT DO CODIGO INDL:\n\n", __LINE__);
        for (unsigned j = 0; j < 10; j++)
        {
            fprintf(stderr, "\n[DEBUG - %d] codigo[%u]: %hhx\n", __LINE__, j, movq[j]);
        }
    #endif
}

/* void organizaByteQI(unsigned char movq[], void** valor)
{
    #ifdef DEBUG
        fprintf(stderr, "\n[DEBUG - %d] VALOR DE PTR2: %p\n", __LINE__, valor);
        fprintf(stderr, "\n[DEBUG - %d] VALOR DE PTR: %p\n", __LINE__, *valor);
    #endif
    void* pointerAsLong = *valor;
    organizaByteQ(movq, *valor);
} */

/**
 * Essa função copia um byte de um vetor para outro vetor 
 * @param codigo Vetor que recebe os bytes copiados
 * @param outroCodigo Vetor que tem os bytes que serão copiados
 * @param posInicio É a posição, índice em que começa a colocar os bytes no vetor codigo
 * @param qtdElementos É a quantidade de elementos, bytes, que o vetor outroCodigo tem
 * @return Retorna a posicao em que o ultimo elemento do vetor está adicionado de 1, ou seja, o índice em que ocorrerá a próxima inserção
 */
unsigned colocaByte(unsigned char codigo[], unsigned char outroCodigo[], unsigned posInicio, unsigned qtdElementos)
{
    for ( unsigned i = 0; i < qtdElementos; i++)
    {
        //fprintf(stderr, "\n[DEBUG - %d] codigo[%u] :%hhx --- outrocodigo[%u] :%hhx\n", __LINE__, posInicio, codigo[posInicio], i, outroCodigo[i]);
        codigo[posInicio++] = outroCodigo[i];
        //fprintf(stderr, "\n[DEBUG - %d] codigo[%u] :%hhx --- outrocodigo[%u] :%hhx\n", __LINE__, posInicio -1, codigo[posInicio -1], i, outroCodigo[i]);
    }
    return posInicio;
}

/**
 * Essa função recebe as características dos parâmetros que outra função deve recebe e os amarra ou repassa de acordo com a origem dele e chama a funcao original
 * @param f É o endereço da função original
 * @param params É o vetor de estrutura do tipo Param em que cada Param tem as características de um parâmetro
 * @param n É a quantidade de elementos que há no vetor Param
 * @param codigo É o vetor de bytes em que devem ser colocados os bytes de linguagem de máquina que fazem parrte da nova função intermediária
 */
void cria_func (void* f, DescParam params[], int n, unsigned char codigo[])
{
    unsigned char posicao = 0; //Contador que guarda a proxima posicao a ser colocar no vetor codigo

    /**Vetor que contem os bytes iniciais que são comuns para todas as funções que serão criadas */
    unsigned char inicio[] = {
                                0x55,                       //pushq %rbp
                                0x48, 0x89, 0xe5,           //movq  %rsp, %rbp
                                0x48, 0x83, 0xec, 0x20,     //subq  $32, %rsp
                                0x48, 0x89, 0x7d, 0xf8,     //movq  %rdi, -8(%rbp)
                                0x48, 0x89, 0x75, 0xf0,     //movq  %rsi, -16(%rbp)
                                0x48, 0x89, 0x55, 0xe8      //movq  %rdi, -24(%rbp)
                             };

    /**Vetor que contem os bytes finais que são comuns para todas as funções que serão criadas */
    unsigned char final[] = {
                                0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     //movq  f, %r10
                                0xff, 0xd0,     //call *%rax   
                                0xc9,           //leave
                                0xc3            //ret
                            };

    /**Vetor de vetores que contem as opções de movl para registradores usados no modo FIX para inteiros*/                        
    unsigned char movl[][5] = {
                                {0xbf, 0x00, 0x00, 0x00, 0x00},     //movl  $  , %edi
                                {0xbe, 0x00, 0x00, 0x00, 0x00},     //movl  $  , %esi
                                {0xba, 0x00, 0x00, 0x00, 0x00}      //movl  $  , %edx
                              };

    /**Vetor de vetores que contem as opções de movQ para registradores usados no modo FIX para ponteiros*/                        
    unsigned char movq[][10] = {
                                {0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},     //movq  $  , %rdi
                                {0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},     //movq  $  , %rsi
                                {0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}      //movq  $  , %rdx
                               };

    /**Vetor que contem os bytes de um ponteiro para o registrador r10 */
    unsigned char vInd[] = {0x49, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};     //movq  $  , %r10

    /**Vetor de vetores que contem as opções de mover o conteúdo que r10 aponta para registradores. É usado no modo IND para inteiros*/
    unsigned char movsIndsL [][3] = {
                                        {0x41, 0x8b, 0x3a},     //movl  (%r10),%edi
                                        {0x41, 0x8b, 0x32},     //movl  (%r10),%esi
                                        {0x41, 0x8b, 0x12}      //movl  (%r10),%edx
                                    };
    /**Vetor de vetores que contem as opções de mover o conteúdo de r10 para registradores. É usado no modo IND para ponteiros*/
    unsigned char movsIndsQ [][3] = {
                                        {0x49, 0x8b, 0x3a},     //movq  (%r10),%rdi
                                        {0x49, 0x8b, 0x32},     //movq  (%r10),%rsi
                                        {0x49, 0x8b, 0x12}      //movq  (%r10),%rdx
                                    };
    /**Vetor tridimensional que contem movls de posições do rbp para os registradores de parâmetros. É usado no modo PARAM para inteiro */
    unsigned char paramsL[][3][3] = {
                                        {
                                            {0x8b, 0x7d, 0xf8},     //movl  -8(%rbp),%edi
                                            {0x8b, 0x75, 0xf8},     //movl  -8(%rbp),%esi
                                            {0x8b, 0x55, 0xf8}      //movl  -8(%rbp),%edx
                                        },
                                        {
                                            {0x8b, 0x7d, 0xf0},     //movl  -16(%rbp),%edi
                                            {0x8b, 0x75, 0xf0},     //movl  -16(%rbp),%esi
                                            {0x8b, 0x55, 0xf0}      //movl  -16(%rbp),%edx
                                        }, 
                                        {
                                            {0x8b, 0x7d, 0xe8},     //movl  -24(%rbp),%edi
                                            {0x8b, 0x75, 0xe8},     //movl  -24(%rbp),%esi
                                            {0x8b, 0x55, 0xe8}      //movl  -24(%rbp),%edx
                                        }
                                    };
    /**Vetor tridimensional que contem movqs de posições do rbp para os registradores de parâmetros. É usado no modo PARAM para ponteiros*/
    unsigned char paramsQ [][3][4]= {
                                        {
                                            {0x48, 0x8b, 0x7d, 0xf8},     //movq  -8(%rbp),%rdi
                                            {0x48, 0x8b, 0x75, 0xf8},     //movq  -8(%rbp),%rsi
                                            {0x48, 0x8b, 0x55, 0xf8}      //movq  -8(%rbp),%rdx
                                        }, 
                                        {
                                            {0x48, 0x8b, 0x7d, 0xf0},     //movq  -16(%rbp),%rdi
                                            {0x48, 0x8b, 0x75, 0xf0},     //movq  -16(%rbp),%rsi
                                            {0x48, 0x8b, 0x55, 0xf0}      //movq  -16(%rbp),%rdx
                                        }, 
                                        {
                                            {0x48, 0x8b, 0x7d, 0xe8},     //movq  -24(%rbp),%rdi
                                            {0x48, 0x8b, 0x75, 0xe8},     //movq  -24(%rbp),%rsi
                                            {0x48, 0x8b, 0x55, 0xe8}      //movq  -24(%rbp),%rdx
                                        }
                                    };


    unsigned qtdParam = 0;  //Contador de parâmetros do tipo param

    posicao = colocaByte(codigo, inicio, posicao, sizeof(inicio));
   
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
                    fprintf(stderr, "\n[DEBUG - %d] Entrei no caso param param - %d\n", __LINE__, params[i].tipo_val);
                #endif
                if (!params[i].tipo_val) // INTEIRO
                {
                    #ifdef DEBUG
                        fprintf(stderr, "\n[DEBUG - %d] Entrei no caso inteiro - %d\n", __LINE__, params[i].tipo_val);
                    #endif
                    posicao = colocaByte(codigo, paramsL[qtdParam][i], posicao, sizeof(paramsL[qtdParam][i]));
                }
                else
                {
                    #ifdef DEBUG
                        fprintf(stderr, "\n[DEBUG - %d] Entrei no caso ponteiro\n", __LINE__);
                    #endif                    
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
                        fprintf(stderr, "\n[DEBUG - %d] Entrei no caso inteiro\n", __LINE__);
                    #endif
                    organizaByteL(movl[i], (int* ) &params[i].valor.v_int);
                    posicao = colocaByte(codigo, movl[i], posicao, sizeof(movl[i]));
                }
                else
                {
                    #ifdef DEBUG
                        fprintf(stderr, "\n[DEBUG - %d] Entrei no caso ponteiro\n", __LINE__);
                    #endif
                    organizaByteQ(movq[i], params[i].valor.v_ptr);
                    posicao = colocaByte(codigo, movq[i], posicao, sizeof(movq[i]));
                }
                break;
            case 2: //IND
                #ifdef DEBUG
                    fprintf(stderr, "\n[DEBUG - %d] Entrei no caso param ind\n", __LINE__);
                    /* fprintf(stderr, "\n[DEBUG - %d] %p\n", __LINE__, &params[i].valor);
                    fprintf(stderr, "\n[DEBUG - %d] %p\n", __LINE__, params[i].valor);
                    fprintf(stderr, "\n[DEBUG - %d] %p\n", __LINE__, params[i].valor.v_ptr); */
                    fprintf(stderr, "\n[DEBUG - %d] ENDEREÇO PTR2: %p\n", __LINE__, params[i].valor.v_ptr);
                #endif
                
                if (!params[i].tipo_val) // INTEIRO
                {
                    #ifdef DEBUG
                        fprintf(stderr, "\n[DEBUG - %d] Entrei no caso inteiro\n", __LINE__);
                    #endif
                    organizaByteQ(vInd, params[i].valor.v_ptr);
                    posicao = colocaByte(codigo, vInd, posicao, sizeof(vInd));
                    posicao = colocaByte(codigo, movsIndsL[i], posicao, sizeof(movsIndsL[i]));    
                }
                else{
                    #ifdef DEBUG
                        fprintf(stderr, "\n[DEBUG - %d] Entrei no caso ponteiro\n", __LINE__);

                    #endif
                    organizaByteQ(vInd, params[i].valor.v_ptr);
                    posicao = colocaByte(codigo, vInd, posicao, sizeof(vInd));
                    posicao = colocaByte(codigo, movsIndsQ[i], posicao, sizeof(movsIndsQ[i]));    
                } 
                break;
        }
    }
    fprintf(stderr, "\n[DEBUG - %d] ENDEREÇO DA FUNCAO: %p\n", __LINE__, f);
    organizaByteQ(final, f);

    posicao = colocaByte(codigo, final, posicao, sizeof(final));   

    #ifdef DEBUG_GERAL
        fprintf(stderr, "\n\n[DEBUG - %d] PRINT DO CODIGO FINAL:\n\n", __LINE__);
        for (unsigned j = 0; j < 60; j++)
        {
            fprintf(stderr, "\n[DEBUG - %d] codigo[%u]: %hhx\n", __LINE__, j, codigo[j]);
        }
    #endif
}