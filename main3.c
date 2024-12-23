#include <stdio.h>
#include "cria_func.h"
//#include <stddef.h>
#include <string.h>
typedef int (*func_ptr) (void* candidata, size_t n);

char fixa[] = "quero saber se a outra string é um prefixo dessa";

#define DEBUG

int main (void) {
  DescParam params[3];
  func_ptr mesmo_prefixo;
  char s[] = "quero saber tudo";
  int tam;
  unsigned char codigo[500];

  params[0].tipo_val = PTR_PAR; /* o primeiro parâmetro de memcmp é um ponteiro para char */
  params[0].orig_val = FIX;     /* a nova função passa para memcmp o endereço da string "fixa" */
  params[0].valor.v_ptr = fixa;

  params[1].tipo_val = PTR_PAR; /* o segundo parâmetro de memcmp é também um ponteiro para char */
  params[1].orig_val = PARAM;   /* a nova função recebe esse ponteiro e repassa para memcmp */

  params[2].tipo_val = INT_PAR; /* o terceiro parâmetro de memcmp é um inteiro */
  params[2].orig_val = PARAM;   /* a nova função recebe esse inteiro e repassa para memcmp */

  cria_func (memcmp, params, 3, codigo);
  mesmo_prefixo = (func_ptr) codigo;

  tam = 12;
  printf ("'%s' tem mesmo prefixo-%d de '%s'? %s\n", s, tam, fixa, mesmo_prefixo (s, tam)?"NAO":"SIM");
  //printf ("'%s' tem mesmo prefixo-%d de '%s'? %s\n", s, tam, fixa, memcmp (s, fixa, tam)?"NAO":"SIM");

  tam = strlen(s);
  printf ("'%s' tem mesmo prefixo-%d de '%s'? %s\n", s, tam, fixa, mesmo_prefixo (s, tam)?"NAO":"SIM");
  //printf ("'%s' tem mesmo prefixo-%d de '%s'? %s\n", s, tam, fixa, memcmp (s, fixa, tam)?"NAO":"SIM");

  return 0;
}