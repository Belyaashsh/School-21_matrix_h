#include "s21_matrix.h"

int s21_create_matrix(int rows, int cols, matrix_t *result) {
  int ERR_CODE = OK;

  if (result != NULL){
    result->matrix = (double **)malloc(rows * sizeof(double *));

    for (int i = 0; i < rows; i++){
      result->matrix[i] = (double *)malloc(cols * sizeof(double));
    }

  } else {
    ERR_CODE = MATRIX_FAILURE;
  }
  result->rows = rows;
  result->cols = cols;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result->matrix[i][j] = 0;
    }
  }
  return ERR_CODE;
}

void s21_print_matrix(matrix_t *result){
  for (int i = 0; i < result->rows; i++) {

    for (int j = 0; j < result->cols; j++) {

      if (j != result->cols - 1 && i != result->rows) {
        printf("%f ", result->matrix[i][j]);

      } else if (j == result->cols - 1 && i != result->rows) {
        printf("%f\n", result->matrix[i][j]);

      } else if (j == result->cols - 1 && i == result->rows) {
        printf("%f", result->matrix[i][j]);

      }
    }
  }
}

void s21_remove_matrix(matrix_t *A){
  for (int i = 0; i < A->rows; i++){
    free(A->matrix[i]);
  }
  free(A->matrix);
}

// int s21_eq_matrix(matrix_t *A, matrix_t *B){}

// int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result){}

// int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result){}

// int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){}

// int s21_mult_number(matrix_t *A, double *num, matrix_t *result){}

// int s21_transpose(matrix_t *A, matrix_t *result){}

// int s21_determinant(matrix_t *A, matrix_t *result){}

// int s21_calc_complements(matrix_t *A, matrix_t *result){}

// int s21_inverse_matrix(matrix_t *A, matrix_t *result){}