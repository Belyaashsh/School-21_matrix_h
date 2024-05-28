#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define MATRIX_FAILURE 1
#define CALCULATIONS_FAILURE 2

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int cols;
} matrix_t;

//создание матрицы
int s21_create_matrix(int rows, int cols, matrix_t *result);

//вывод матрицы в консоль
void s21_print_matrix(matrix_t *result);

//очитска и уничтожение матрицы
void s21_remove_matrix(matrix_t *A);

//сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);

//сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//вычитание матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//умножение матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//умножение матрицы на число
int s21_mult_number(matrix_t *A, double *num, matrix_t *result);

//траспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result);

//вычисление детерминанта (определителя) матрицы
int s21_determinant(matrix_t *A, matrix_t *result);

//вычисление матрицы алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);

//поиск обратной матрицы
int s21_inverse_matrix(matrix_t *A, matrix_t *result);


#endif // S21_MATRIX_H