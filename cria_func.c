/* Maria Eduarda da Fonseca Gonçalves Santos 2212985 3WA */
/* Mayara Ramos Damazio 2210833 3WC */

#include "cria_func.h"

unsigned organizaByte(unsigned char movl, params[i].valor)
{

}

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
        if(codigo[i] == 'c9')
            return i;
        i++;
    }

    return -1;
} 

void cria_func (void* f, DescParam params[], int n, unsigned char codigo[])
{
    unsigned char posicao = 0;
    unsigned char inicio[] = {0x55, 0x48, 0x89, 0xe5};
    unsigned char final[] = {0xc9, 0xc3};
    unsigned char* movl[] = {{0xbf, 0x00, 0x00, 0x00, 0x00}, {0xbe, 0x00, 0x00, 0x00, 0x00}, {0xba, 0x00, 0x00, 0x00, 0x00}};
    unsigned char* movq[] = {{0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x48, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x48, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    
    posicao = colocaByte(params, inicio, posicao, sizeof(inicio));
    
    for (unsigned i = 0; i < n; i++)
    {
        unsigned origem = params[i].orig_val;
        switch(origem)
        {
            case 0: //PARAM
               break;
            case 1: //FIX
                 if (!params[i].tipo_val) // INTEIRO
                {
                    organizaByte(movl[i], params[i].valor);
                }
                else{
                    organizaByte(movq[i], params[i].valor);

                }
                
            case 2: //IND

        }
    }
    posicao = colocaByte(params, final, posicao, sizeof(inicio));

}
