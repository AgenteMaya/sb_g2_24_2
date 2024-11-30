#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) ();

int id(int* x){
  return *x;
}

int main (void) {
  DescParam params[2];
  func_ptr f_id;
  int i;
  unsigned char codigo[500];
  int fixo[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
  int* ptr = &fixo[0];
  int** ptr2 = &ptr;

  params[0].tipo_val = PTR_PAR;
  params[0].orig_val = IND;
  params[0].valor.v_ptr = ptr2;
  cria_func (id, params, 1, codigo);
  f_id = (func_ptr) codigo;

  /* for (; *ptr; ptr++) {
     printf("%d\n", id(ptr));
   } */
  for (; *ptr; ptr++) {
    
    printf("%d\n", f_id());
  
  }

  return 0;
}