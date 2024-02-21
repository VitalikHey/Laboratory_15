#ifndef LABORATORY_15_TEST_MATRIX_H
#define LABORATORY_15_TEST_MATRIX_H

#include <stdio.h>
#include <stdbool.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix testGetMemMatrix(int nRows, int nCols);

matrix *testGetMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void testFreeMemMatrix(matrix *m);

void testFreeMemMatrices(matrix *ms, int nMatrices);

void testInputMatrix(matrix *m);

void testInputMatrices(matrix *ms, int nMatrices);

void testOutputMatrix(matrix m);

void testOutputMatrices(matrix *ms, int nMatrices);

void testSwapRows(matrix *m, int i1, int i2);

void testSwapColumns(matrix *m, int j1, int j2);

void testInsertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int));

int testGetSum(const int *a, int n);

void testSelectionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int*, int));

bool testIsSquareMatrix(matrix *m);

bool testAreTwoMatricesEqual(matrix *m1, matrix *m2);

bool testIsEMatrix(matrix *m);

bool testIsSymmetricMatrix(matrix *m);

void testTransposeSquareMatrix(matrix *m);

void testTransposeMatrix(matrix *m);

position testGetMinValuePos(matrix m);

position testGetMaxValuePos(matrix m);

matrix testCreateMatrixFromArray(const int *a, int nRows,
                             int nCols);


#endif //LABORATORY_15_TEST_MATRIX_H
