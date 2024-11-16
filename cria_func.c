/* Maria Eduarda da Fonseca Gonçalves Santos 2212985 3WA */
/* Mayara Ramos Damazio 2210833 3WC */

#include "cria_func.h"


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
    unsigned ind = 1;
    for (int i = 0; i < 4; i++)
    {
        movl[ind++] = (*valor >> i * 8) & 0xff;
    }
}

void organizaByteQ(unsigned char movq[], void** valor)
{
    unsigned long p1 = *valor;

    unsigned ind = 2;
    for (int i = 0; i < 4; i++)
    {
        movq[ind++] = (p1 >> i * 8) & 0xff;
    }
}

void decideOrganizaByte (unsigned mov[], void** valor, unsigned tipo)
{
    if (!tipo) // INTEIRO
    {
        int* pointer = *valor;
        organizaByteL(mov, *pointer);
    }
    else{
        void* pointer = *valor;
        organizaByteQ(mov, pointer);
    }
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
    unsigned qtd_params = contaParam(params, n);

    

    for (unsigned i = qtd_params; i < n; i++)
    {
        unsigned origem = params[i].orig_val;
        switch(origem)
        {
            case 0: //PARAM
                continue;
            case 1: //FIX
                if (!params[i].tipo_val) // INTEIRO
                {
                    organizaByteL(movl[i], &params[i].valor);
                }
                else{
                    organizaByteQ(movq[i], &params[i].valor);
                }
                break;
            case 2: //IND
                if (!params[i].tipo_val) // INTEIRO
                {
                    decideOrganizaByte(movl[i], &params[i].valor, params[i].tipo_val);
                }
                else{
                    decideOrganizaByte(movq[i], &params[i].valor, params[i].tipo_val);
                }
        }
    }
    posicao = colocaByte(params, final, posicao, sizeof(inicio));

}
