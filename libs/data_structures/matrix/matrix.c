#include "matrix.h"
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);

    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; i++) {
        ms[i] = getMemMatrix(nRows, nCols);
    }

    return ms;
}

void freeMemMatrix(matrix *m) {
    if (m->values) {
        for (int i = 0; i < m->nRows; i++) {
            free(m->values[i]);
        }
        free(m->values);
        m->values = NULL;
    }
    m->nRows = 0;
    m->nCols = 0;
}


void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
    }
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &m->values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(&ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}


void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix *m, int i1, int i2) {
    assert(i1 < m->nRows);
    assert(i2 < m->nRows);
    assert(m->values != NULL);

    int *rows_1 = m->values[i1];

    m->values[i1] = m->values[i2];
    m->values[i2] = rows_1;
}

void swapColumns(matrix *m, int j1, int j2) {
    assert(j1 < m->nCols && j2 < m->nCols);

    for (int i = 0; i < m->nRows; i++) {
        int colm = m->values[i][j1];
        m->values[i][j1] = m->values[i][j2];
        m->values[i][j2] = colm;
    }
}

int getSum(const int *a, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum;
}

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int auxiliary_array[m.nRows];

    for (int i = 0; i < m.nRows; i++) {
        auxiliary_array[i] = getSum(m.values[i], INT_MAX); // ИСПРАВИТЬ
    }

    // ДОДЕЛАТЬ
}