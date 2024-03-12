#ifndef LABORATORY_15_TASKS_H
#define LABORATORY_15_TASKS_H

#include "../tasks_for_16_laboratory/tasks.h"
#include "../data_structures/matrix/matrix.h"
#include <limits.h>
#include <math.h>

// меняет местами строки с минимальным и максимальным числом
// в матрице(все уникальные)
void swapRowsWithMinimumAndMaximumNumber(matrix m);

// возвращает максимальное абсолютное значение среди элементов матрицы
int getMaxAbsValue(matrix m);

// Возвращает количество нулевых строк в матрице
int getCountZeroRows(matrix m);

// возвращает указатель на квадрат матрицы
void getSquareOfMatrix(matrix *m);

// возвращает 'истина', если произведение матриц m1 и m2
// дает единичную матрицу, иначе - 'ложь'
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

// Возвращает сумму максимальных элементов всех псевдодиагоналей данной матрицы
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

// Возвращает минимальное число в закаршенной области матрицы
int getMinInArea(matrix m, const int arrayLengthsShadedColumns[]);

// Возвращает количество уникальных сумм строк матрицы (суммы без повторения)
int getCountUniqueSum(matrix m);

// Сортирует матрицу по удалению точек от центра координат
void sortByDistances(matrix m);

// Возвращает количество особенных столбцов, в которых масимальный элемент
// больше суммы остальных элементов
int calculateCountSpecialLines(matrix m);

// Меняет предпоследнюю строку матрицы первым из столбцов,
// в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix *m);

// Возвращает число матриц, строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

// Выводит матрицы, имеющие наибольшее число нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

// Выводит матрицы, имеющие минимальную абсолютною норму
void printMatrixWithMinAbsNorm(matrix *ms, int nMatrix);

// Возвращает количество 'особых' элементов в матрице
int getCountSpecialElementsInMatrix(matrix m);

// Возвращает индекс вектора из матрицы,
// образующего с вектором vector максимальный угол
int getVectorIndexWithMaxAngle(matrix m, int vector[]);

// Возвращает скалярное произведение строки с наибольшим элементом матрицы
// на столбец с наименьшим элементом матрицы
long long getSpecialScalarProduct(matrix m);

#endif
