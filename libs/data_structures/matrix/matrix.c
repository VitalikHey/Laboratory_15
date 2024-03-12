#include "matrix.h"
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>

int getMax(int *array, int lengthArray) {
    int maxNum = array[0];
    for (int ind = 1; ind < lengthArray; ind++) {
        if (array[ind] > maxNum) {
            maxNum = array[ind];
        }
    }

    return maxNum;
}


int getMin(int array[], int lengthArray){
    int minNum = array[0];
    for (int ind = 1; ind < lengthArray; ind++){
        if (array[ind] < minNum){
            minNum = array[ind];
        }
    }

    return minNum;
}


matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);

    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }

    return (matrix) {values, nRows, nCols};
}

void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
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

void swapRows(matrix m, int i1, int i2) {
    assert(i1 < m.nRows);
    assert(i2 < m.nRows);
    assert(m.values != NULL);

    int *rows_1 = m.values[i1];

    m.values[i1] = m.values[i2];
    m.values[i2] = rows_1;
}

void swapColumns(matrix m, int j1, int j2){
    if (j1 >= m.nCols || j2 >= m.nCols){
        fprintf(stderr, "Index Error");
        exit(1);
    }

    for (int indRow = 0; indRow < m.nRows; indRow++){
        int temp = m.values[indRow][j1];
        m.values[indRow][j1] = m.values[indRow][j2];
        m.values[indRow][j2] = temp;
    }
}

int getSum(const int *a, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum;
}

int partition(int array[], const int start, const int end, matrix m,
              void (*predicateSwap)(matrix, int, int)) {
    int pivot = array[end];
    int pivotIndex = start;
    for (int ind = start; ind < end; ind++) {
        if (array[ind] <= pivot) {
            swap(&array[ind], &array[pivotIndex]);
            predicateSwap(m, ind, pivotIndex);
            pivotIndex++;
        }
    }

    swap(&array[pivotIndex], &array[end]);
    predicateSwap(m, pivotIndex, end);

    return pivotIndex;
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int nRows = m.nRows;
    int rowSums[nRows];

    for (int i = 0; i < nRows; i++) {
        rowSums[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 1; i < nRows; i++) {
        int currentSum = rowSums[i];
        int *currentRow = m.values[i];
        int j = i - 1;

        while (j >= 0 && rowSums[j] > currentSum) {
            rowSums[j + 1] = rowSums[j];
            m.values[j + 1] = m.values[j];
            j--;
        }
        rowSums[j + 1] = currentSum;
        m.values[j + 1] = currentRow;
    }
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*predicate)(int*, int)){
    int arrayResults[m.nCols];

    for (int indCol = 0; indCol < m.nCols; indCol++){
        int column[m.nRows];
        for (int indRow = 0; indRow < m.nRows; indRow++){
            column[indRow] = m.values[indRow][indCol];
        }

        arrayResults[indCol] = predicate(column, m.nRows);
    }

    quickSort(arrayResults, 0, m.nCols - 1, m, swapColumns);
}

void quickSort(int array[], const int start, const int end, matrix m,
               void (*predicateSwap)(matrix, int, int)) {
    if (start >= end) {
        return;
    }

    int pivot = partition(array, start, end, m, predicateSwap);
    quickSort(array, start, pivot - 1, m, predicateSwap);
    quickSort(array, pivot + 1, end, m, predicateSwap);
}

bool isSquareMatrix(matrix *m) {
    return m->nRows == m->nCols;
}

bool isUnique(const int array[], int lengthArray) {
    for (int indNum = 0; indNum < lengthArray - 1; indNum++) {
        for (int indCheck = indNum + 1; indCheck < lengthArray; indCheck++) {
            if (array[indNum] == array[indCheck]) {
                return false;
            }
        }
    }

    return true;
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    if (m1->nRows != m2->nRows || m1->nCols != m2->nCols) {
        return false;
    }

    if (memcmp(m1->values, m2->values, m1->nRows * m1->nCols * sizeof(int)) == 0) {
        return true;
    } else {
        return false;
    }
}


bool isEMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            if (j != i && m->values[i][j] != 0) {
                return false;
            } else if (m->values[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool isSymmetricMatrix(matrix *m) {
    if (m->nRows != m->nCols) {
        return false; // Матрица не квадратная, не может быть симметричной
    }

    for (int i = 0; i < m->nRows; i++) {
        for (int j = i + 1; j < m->nCols; j++) {
            if (m->values[i][j] != m->values[j][i]) {
                return false; // Найдено несовпадение симметричных элементов
            }
        }
    }

    return true; // Все пары симметричных элементов совпадают
}

void transposeSquareMatrix(matrix *m) {
    assert(m->nRows == m->nCols);

    for (int i = 0; i < m->nRows; i++) {
        for (int j = i + 1; j < m->nCols; j++) {
            int temp = m->values[i][j];
            m->values[i][j] = m->values[j][i];
            m->values[j][i] = temp;
        }
    }
}

void transposeMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = i + 1; j < m->nCols; j++) {
            int temp = m->values[i][j];
            m->values[i][j] = m->values[j][i];
            m->values[j][i] = temp;
        }
    }
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices,
                                     int nRows, int nCols){
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}


position getMinValuePos(matrix m) {
    position min_element_position;
    int min_element = INT_MAX;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < min_element) {
                min_element = m.values[i][j];
                min_element_position.rowIndex = i;
                min_element_position.colIndex = j;
            }
        }
    }
    return min_element_position;
}


position getMaxValuePos(matrix m) {
    position max_element_position;
    int max_element = INT_MIN;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > max_element) {
                max_element = m.values[i][j];
                max_element_position.rowIndex = i;
                max_element_position.colIndex = j;
            }
        }
    }
    return max_element_position;
}

