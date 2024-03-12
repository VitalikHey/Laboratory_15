#include "../matrix/matrix.h"
#include <malloc.h>
#include <assert.h>
#include "test_matrix.h"

void testGetMemMatrix() {
    matrix mat = getMemMatrix(3, 3);

    assert(mat.values != 0);

    freeMemMatrix(&mat);
}

void testGetMemArrayOfMatrices() {
    int nMatrices = 3;
    int nRows = 2;
    int nCols = 2;

    matrix *array_matrix = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    for (int i = 0; i < nMatrices; i++) {
        assert(array_matrix[i].values != NULL);
    }

    freeMemMatrices(array_matrix, nMatrices);
}

void testFreeMemMatrix() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3
    );

    freeMemMatrix(&test_matrix);

    assert(test_matrix.values == NULL);
}

void testFreeMemMatrices() {
    int nMatrices = 3;
    matrix ms[nMatrices];
    matrix *array_matrix = getMemArrayOfMatrices(nMatrices, ms->nRows, ms->nCols);

    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
        assert(ms[i].values == NULL);
    }
}

void testSwapRows() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3
    );

    swapRows(test_matrix, 0, 1);

    assert(test_matrix.values[0][0] == 4);
    assert(test_matrix.values[0][1] == 5);
    assert(test_matrix.values[0][2] == 6);
    assert(test_matrix.values[1][0] == 1);
    assert(test_matrix.values[1][1] == 2);
    assert(test_matrix.values[1][0] == 3);
}

void testSwapColumns() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3
    );

    swapColumns(test_matrix, 0, 1);

    assert(test_matrix.values[0][0] == 2);
    assert(test_matrix.values[0][1] == 1);
    assert(test_matrix.values[1][0] == 5);
    assert(test_matrix.values[1][1] == 4);
    assert(test_matrix.values[0][2] == 8);
    assert(test_matrix.values[1][2] == 7);
}

int sumCriteria(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void testInsertionSortRowsMatrixByRowCriteria() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    insertionSortRowsMatrixByRowCriteria(test_matrix, sumCriteria);

    assert(test_matrix.values[0][0] == 3);
    assert(test_matrix.values[0][1] == 4);
    assert(test_matrix.values[1][0] == 1);
    assert(test_matrix.values[1][1] == 2);

    for (int i = 0; i < test_matrix.nRows; i++) {
        free(test_matrix.values[i]);
    }
    free(test_matrix.values);
}

void testSelectionSortColsMatrixByColCriteria() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    selectionSortColsMatrixByColCriteria(test_matrix, sumCriteria);

    assert(test_matrix.values[0][0] == 2);
    assert(test_matrix.values[0][1] == 1);
    assert(test_matrix.values[1][0] == 4);
    assert(test_matrix.values[1][1] == 3);

    for (int i = 0; i < test_matrix.nRows; i++) {
        free(test_matrix.values[i]);
    }
    free(test_matrix.values);
}

void testAreTwoMatricesEqual() {
    matrix first_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 2, 1,
            },
            3, 2
    );

    matrix second_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 2, 1,
            },
            3, 2
    );

    assert(areTwoMatricesEqual(&first_matrix, &second_matrix) == true);

    freeMemMatrix(&first_matrix);
    freeMemMatrix(&second_matrix);
}

void testIsSquareMatrix() {
    matrix test_matrix = getMemMatrix(3, 3);

    assert(isSquareMatrix(&test_matrix) == true);
}

void testIsEMatrix() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            },
            3, 3
    );

    assert(isEMatrix(&test_matrix) == true);

    freeMemMatrix(&test_matrix);
}

void testIsSymmetricMatrix() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 4, 5,
                    3, 5, 7,
            },
            3, 3
    );

    assert(isSymmetricMatrix(&test_matrix) == true);

    freeMemMatrix(&test_matrix);
}

void testTransposeSquareMatrix() {
    matrix first_test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 2, 1,
            },
            2, 3
    );

    matrix second_test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 2, 1,
            },
            2, 3
    );

    transposeMatrix(&first_test_matrix);
    transposeMatrix(&first_test_matrix);

    assert(first_test_matrix.values == second_test_matrix.values);

    freeMemMatrix(&first_test_matrix);
    freeMemMatrix(&second_test_matrix);
}

void testGetMinValuePos() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    4, 4, 4,
                    1, 3, 2,
            },
            2, 3
    );
    position pos = {1, 2};

    assert(getMinValuePos(test_matrix).rowIndex == pos.rowIndex);
    assert(getMinValuePos(test_matrix).colIndex == pos.colIndex);

    freeMemMatrix(&test_matrix);
}

void testGetMaxValuePos() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    4, 4, 4,
                    5, 3, 2,
            },
            2, 3
    );
    position pos = {1, 2};

    assert(getMaxValuePos(test_matrix).rowIndex == pos.rowIndex);
    assert(getMaxValuePos(test_matrix).colIndex == pos.colIndex);

    freeMemMatrix(&test_matrix);
}

