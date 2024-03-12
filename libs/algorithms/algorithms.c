#include <stdlib.h>
#include "algorithms.h"
#include <limits.h>
#include <math.h>

int compare(const void *firstNum, const void *secondNum) {
    return (*(int *) firstNum - *(int *) secondNum);
}

long long getScalarProduct(const int vector1[], const int vector2[], int length) {
    long long sumProducts = 0;
    for (int ind = 0; ind < length; ind++) {
        sumProducts += vector1[ind] * vector2[ind];
    }

    return sumProducts;
}

double getVectorLength(const int vector[], int length) {
    double lengthVector = 0;
    for (int ind = 0; ind < length; ind++) {
        lengthVector += vector[ind] * vector[ind];
    }

    return sqrt(lengthVector);
}


double getCosine(const int vector1[], const int vector2[],
                 int lengthArrays, double lengthVector2) {

    double numerator = (double) getScalarProduct(vector1, vector2, lengthArrays);
    double denominator = getVectorLength(vector1, lengthArrays) * lengthVector2;
    double cosine = numerator / denominator;

    return cosine;
}

void getLastArray(const int arrayOrigin[], int lastArray[], int lengthArrays) {
    lastArray[0] = INT_MIN;
    int maxNum = lastArray[0];
    for (int ind = 1; ind < lengthArrays; ind++) {
        if (arrayOrigin[ind - 1] > maxNum) {
            maxNum = arrayOrigin[ind - 1];
        }

        lastArray[ind] = maxNum;
    }
}

void getNextArray(const int arrayOrigin[], int nextArray[], int lengthArrays) {
    nextArray[lengthArrays - 1] = INT_MAX;
    int minNum = nextArray[lengthArrays - 1];
    for (int ind = lengthArrays - 2; ind > -1; ind--) {
        if (arrayOrigin[ind + 1] < minNum) {
            minNum = arrayOrigin[ind + 1];
        }

        nextArray[ind] = minNum;
    }
}

int getCountSpecialElementsInRow(int array[], int lengthArray) {
    int lastArray[lengthArray];
    int nextArray[lengthArray];
    getLastArray(array, lastArray, lengthArray);
    getNextArray(array, nextArray, lengthArray);

    int countSpecialElements = 0;
    for (int ind = 0; ind < lengthArray; ind++) {
        if (array[ind] < nextArray[ind] && array[ind] > lastArray[ind]) {
            countSpecialElements++;
        }
    }

    return countSpecialElements;
}

int getMaxAbsValue(matrix m) {
    int maxAbsValue = abs(m.values[0][0]);
    for (int indRow = 0; indRow < m.nRows; indRow++) {
        for (int indCol = 0; indCol < m.nCols; indCol++) {
            if (abs(m.values[indRow][indCol]) > maxAbsValue) {
                maxAbsValue = abs(m.values[indRow][indCol]);
            }
        }
    }

    return maxAbsValue;
}

bool isNonDescendingRows(matrix m) {
    if (m.nRows == 0) {
        return false;
    }

    for (int indRow = 0; indRow < m.nRows; indRow++) {
        for (int indCol = 0; indCol < m.nCols - 1; indCol++) {
            if (m.values[indRow][indCol] > m.values[indRow][indCol + 1]) {
                return false;
            }
        }
    }

    return true;
}

int getCountZeroRows(matrix m) {
    int countZeroRows = 0;
    for (int indRow = 0; indRow < m.nRows; indRow++) {
        bool isZero = true;
        for (int indCol = 0; indCol < m.nCols; indCol++) {
            if (m.values[indRow][indCol] != 0) {
                isZero = false;
                break;
            }
        }

        if (isZero) {
            countZeroRows++;
        }
    }

    return countZeroRows;
}

int getColMinNum(matrix m) {
    int minNum = m.values[0][0];
    int colMinNum = 0;
    for (int indCol = 0; indCol < m.nCols; indCol++) {
        for (int indRow = 0; indRow < m.nRows; indRow++) {
            if (m.values[indRow][indCol] < minNum) {
                minNum = m.values[indRow][indCol];
                colMinNum = indCol;
            }
        }
    }

    return colMinNum;
}

int getDistance(const int array[], int lengthArray) {
    int sum = 0;
    for (int ind = 0; ind < lengthArray; ind++) {
        sum += array[ind] * array[ind];
    }

    return sum;
}

long long sumMaxNumsInDiagonals(matrix m, bool isRow) {
    long long sum = 0;
    for (int indStart = 1; indStart < (isRow ? m.nRows : m.nCols); indStart++) {
        int maxNum = m.values[isRow ? indStart : 0][isRow ? 0 : indStart];
        for (int indCol = (isRow ? 1 : indStart + 1), indRow = (isRow ? indStart + 1 : 1);
             indCol < m.nCols && indRow < m.nRows; indCol++, indRow++) {
            if (m.values[indRow][indCol] > maxNum) {
                maxNum = m.values[indRow][indCol];
            }
        }

        sum += maxNum;
    }

    return sum;
}

void swapRowsWithMinimumAndMaximumNumber(matrix m) {
    position minNum = getMinValuePos(m);
    position maxNum = getMaxValuePos(m);
    swapRows(m, minNum.rowIndex, maxNum.rowIndex);
}

void getSquareOfMatrix(matrix *m) {
    matrix squareMatrix = getMemMatrix(m->nRows, m->nCols);

    for (int indRow = 0; indRow < m->nRows; indRow++) {
        for (int indCol = 0; indCol < m->nCols; indCol++) {
            squareMatrix.values[indRow][indCol] = 0;
            for (int indColMul = 0; indColMul < m->nCols; indColMul++) {
                squareMatrix.values[indRow][indCol] +=
                        m->values[indRow][indColMul] * m->values[indColMul][indCol];
            }
        }
    }

    freeMemMatrix(m);
    *m = squareMatrix;
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    for (int indRow = 0; indRow < m1.nRows; indRow++) {
        for (int indCol = 0; indCol < m1.nCols; indCol++) {
            int sum = 0;
            for (int indColMul = 0; indColMul < m1.nCols; indColMul++) {
                sum += m1.values[indRow][indColMul] * m2.values[indColMul][indCol];
            }

            if (sum != (indRow == indCol))
                return false;
        }
    }

    return true;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;
    sum += sumMaxNumsInDiagonals(m, false);
    sum += sumMaxNumsInDiagonals(m, true);

    return sum;
}

int getMinInArea(matrix m, const int arrayLengthsShadedColumns[]) {
    int minNum = INT_MAX;
    int indCol = 0;
    int indRow = 0;
    while (indCol < m.nCols) {
        if (arrayLengthsShadedColumns[indCol] == indRow) {
            indRow = 0;
            indCol++;
        } else {
            if (m.values[indRow][indCol] < minNum) {
                minNum = m.values[indRow][indCol];
            }

            indRow++;
        }
    }

    return minNum;
}

int getCountUniqueSum(matrix m) {
    int countUniqueElements = 0;
    if (m.nRows > 0) {
        int arraySum[m.nRows];
        for (int indRow = 0; indRow < m.nRows; indRow++) {
            arraySum[indRow] = getSum(m.values[indRow], m.nCols);
        }

        qsort(arraySum, m.nRows, sizeof(int), compare);
        countUniqueElements++;
        int lastNum = arraySum[0];
        for (int ind = 1; ind < m.nRows; ind++) {
            if (arraySum[ind] != lastNum) {
                countUniqueElements++;
                lastNum = arraySum[ind];
            }
        }
    }

    return countUniqueElements;
}

void sortByDistances(matrix m) {
    int arrayDistance[m.nRows];
    for (int ind = 0; ind < m.nRows; ind++) {
        arrayDistance[ind] = getDistance(m.values[ind], m.nCols);
    }

    quickSort(arrayDistance, 0, m.nRows - 1, m, swapRows);
}

int calculateCountSpecialLines(matrix m) {
    int countSpecialLines = 0;
    for (int indCol = 0; indCol < m.nCols; indCol++) {
        int sum = m.values[0][indCol];
        int maxNum = m.values[0][indCol];
        for (int indRow = 1; indRow < m.nRows; indRow++) {
            sum += m.values[indRow][indCol];
            if (m.values[indRow][indCol] > maxNum) {
                maxNum = m.values[indRow][indCol];
            }
        }

        if (maxNum > sum - maxNum) {
            countSpecialLines++;
        }
    }

    return countSpecialLines;
}

void swapPenultimateRow(matrix *m) {
    int colMinNum = getColMinNum(*m);

    int temp = m->values[m->nRows - 2][colMinNum];
    for (int indRow = 0; indRow < m->nRows; indRow++) {
        m->values[m->nRows - 2][indRow] = m->values[indRow][colMinNum];
    }

    m->values[m->nRows - 2][m->nRows - 2] = temp;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int indMatrix = 0; indMatrix < nMatrix; indMatrix++) {
        if (isNonDescendingRows(ms[indMatrix])) {
            count++;
        }
    }

    return count;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int arrayCountZeroRowsInMatrix[nMatrix];
    for (int indMatrix = 0; indMatrix < nMatrix; indMatrix++) {
        arrayCountZeroRowsInMatrix[indMatrix] = getCountZeroRows(ms[indMatrix]);
    }

    int maxCount = getMax(arrayCountZeroRowsInMatrix, nMatrix);

    for (int indMatrix = 0; indMatrix < nMatrix; indMatrix++) {
        if (arrayCountZeroRowsInMatrix[indMatrix] == maxCount) {
            outputMatrix(ms[indMatrix]);
        }
    }
}

void printMatrixWithMinAbsNorm(matrix *ms, int nMatrix) {
    int arrayMaxAbsNorms[nMatrix];

    for (int indMatrix = 0; indMatrix < nMatrix; indMatrix++) {
        arrayMaxAbsNorms[indMatrix] = getMaxAbsValue(ms[indMatrix]);
    }

    int minAbsNorm = getMin(arrayMaxAbsNorms, nMatrix);
    for (int indMatrix = 0; indMatrix < nMatrix; indMatrix++) {
        if (arrayMaxAbsNorms[indMatrix] == minAbsNorm) {
            outputMatrix(ms[indMatrix]);
        }
    }
}

int getCountSpecialElementsInMatrix(matrix m) {
    int countSpecialElementsInMatrix = 0;
    for (int indRow = 0; indRow < m.nRows; indRow++) {
        countSpecialElementsInMatrix += getCountSpecialElementsInRow(m.values[indRow],
                                                                     m.nCols);
    }

    return countSpecialElementsInMatrix;
}

int getVectorIndexWithMaxAngle(matrix m, int vector[]) {
    double lengthVector = getVectorLength(vector, m.nCols);
    double maxCosine = getCosine(m.values[0], vector,
                                 m.nCols, lengthVector);
    int indRowWithMaxAngle = 0;

    for (int indRow = 1; indRow < m.nRows; indRow++) {
        double cosine = getCosine(m.values[indRow], vector,
                                  m.nCols, lengthVector);
        if (cosine > maxCosine) {
            maxCosine = cosine;
            indRowWithMaxAngle = indRow;
        }
    }

    return indRowWithMaxAngle;
}

long long getSpecialScalarProduct(matrix m) {
    position minNum = getMinValuePos(m);
    position maxNum = getMaxValuePos(m);
    int colWithMinNum[m.nRows];
    for (int indRow = 0; indRow < m.nRows; indRow++) {
        colWithMinNum[indRow] = m.values[indRow][minNum.colIndex];
    }

    long long scalarProduct = getScalarProduct(colWithMinNum,
                                               m.values[maxNum.rowIndex],
                                               m.nCols);

    return scalarProduct;
}