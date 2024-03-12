#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *values;
    int nRows;
    int nCols;
} matrix;

matrix mulMatrices(matrix m1, matrix m2) {
    matrix result;
    result.nRows = m1.nRows;
    result.nCols = m2.nCols;
    result.values = (int *)malloc(result.nRows * result.nCols * sizeof(int));

    for (int i = 0; i < result.nRows; i++) {
        for (int j = 0; j < result.nCols; j++) {
            result.values[i * result.nCols + j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                result.values[i * result.nCols + j] += m1.values[i * m1.nCols + k] * m2.values[k * m2.nCols + j];
            }
        }
    }

    return result;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (m->nRows != m->nCols) {
        printf("Input matrix is not square, cannot find square matrix.\n");
        return;
    }

    for (int i = 0; i < m->nRows; i++) {
        for (int j = i + 1; j < m->nCols; j++) {
            if (m->values[i * m->nCols + j] != m->values[j * m->nCols + i]) {
                printf("Input matrix is not symmetric, cannot find square matrix.\n");
                return;
            }
        }
    }

    matrix squared = mulMatrices(*m, *m);

    free(m->values);
    m->values = squared.values;
    m->nRows = squared.nRows;
    m->nCols = squared.nCols;
}

int main() {
    // Пример использования функций
    matrix testMatrix = { .values = (int[]){1, 2, 2, 1}, .nRows = 2, .nCols = 2 };

    printf("Original matrix:\n");
    for (int i = 0; i < testMatrix.nRows; i++) {
        for (int j = 0; j < testMatrix.nCols; j++) {
            printf("%d ", testMatrix.values[i * testMatrix.nCols + j]);
        }
        printf("\n");
    }

    getSquareOfMatrixIfSymmetric(&testMatrix);

    printf("\nSquared matrix:\n");
    for (int i = 0; i < testMatrix.nRows; i++) {
        for (int j = 0; j < testMatrix.nCols; j++) {
            printf("%d ", testMatrix.values[i * testMatrix.nCols + j]);
        }
        printf("\n");
    }

    free(testMatrix.values);
    return 0;
}
