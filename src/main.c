#include "s21_matrix.h"

int main(){
  matrix_t res = {0};
  s21_create_matrix(4, 2, &res);
  s21_print_matrix(&res);
  s21_remove_matrix(&res);
  return 0;
}