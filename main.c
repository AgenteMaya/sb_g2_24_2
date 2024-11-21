#include <stdio.h>
#include "cria_func.h"

#define DEBUG

typedef int (*func_ptr) ();

void oi(void)
{

}

int mult(int x, int y) {
  #ifdef DEBUG
    fprintf(stderr, "\n[DEBUG - %d] x - %x\n", __LINE__, x);
    fprintf(stderr, "\n[DEBUG - %d] y - %x\n", __LINE__, y);
  #endif
  return x * y;
}

 /*
 TESTE PARA 1 PARÂMETRO - INTEIRO - PARAM
 */
int main(void)
{
    DescParam params[2];
    func_ptr f_mult;
    int i;
    unsigned char codigo[500];

    params[1].tipo_val = INT_PAR; /* o primeiro parãmetro de mult é int */
    params[1].orig_val = PARAM;   /* a nova função repassa seu parämetro */

    params[0].tipo_val = INT_PAR; /* o segundo parâmetro de mult é int */
    params[0].orig_val = FIX;     /* a nova função passa para mult a constante 10 */
    params[0].valor.v_int = 10;

    cria_func (mult, params, 2, codigo);
    f_mult = (func_ptr) codigo;   

    for (i = 1; i <=10; i++) {
      fprintf(stderr, "\n[DEBUG - %d] endereço de i : %p\n", __LINE__, &i);      
      int resultado = f_mult(i);
      printf("%d\n", resultado); /* a nova função só recebe um argumento */
    }

    return 0;
}