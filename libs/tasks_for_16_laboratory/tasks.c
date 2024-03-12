#include "../algorithms/algorithms.h"
#include "tasks.h"


void task1(matrix m) {
    swapRowsWithMinimumAndMaximumNumber(m);
}

void task2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void task3(matrix m){
    selectionSortColsMatrixByColCriteria(m, getMin);
}

void task4(matrix *m){
    if (isSymmetricMatrix(m)){
        getSquareOfMatrix(m);
    }
}

void task5(matrix m){
    if (isSquareMatrix(&m)){
        int arraySum[m.nRows];
        for (int ind = 0; ind < m.nRows; ind++){
            arraySum[ind] = getSum(m.values[ind], m.nCols);
        }

        if (isUnique(arraySum, m.nRows)){
            transposeSquareMatrix(&m);
        }
    }
}

bool task6(matrix m1, matrix m2){
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols){
        return false;
    }

    bool flagIsMutuallyInverseMatrices = isMutuallyInverseMatrices(m1, m2);

    return flagIsMutuallyInverseMatrices;
}

long long task7(matrix m){
    return findSumOfMaxesOfPseudoDiagonal(m);
}

int task8(matrix m, int arrayLengthsShadedColumns[]){
    int minNum = getMinInArea(m, arrayLengthsShadedColumns);

    return minNum;
}

void task9(matrix m){
    sortByDistances(m);
}

int task10(matrix m){
    int countUniqueSum = getCountUniqueSum(m);

    return countUniqueSum;
}

int task11(matrix m){
    int countSpecialLines = calculateCountSpecialLines(m);

    return countSpecialLines;
}

void task12(matrix m){
    if (isSquareMatrix(&m) && m.nRows > 1){
        swapPenultimateRow(&m);
    }
}

int task13(matrix *ms, int nMatrix){
    int count = countNonDescendingRowsMatrices(ms, nMatrix);

    return count;
}

void task14(matrix *ms, int nMatrix){
    printMatrixWithMaxZeroRows(ms, nMatrix);
}

void task15(matrix *ms, int nMatrix){
    if ((nMatrix > 0) && (ms[0].nRows > 0) && (ms[0].nRows == ms[0].nCols)){
        printMatrixWithMinAbsNorm(ms, nMatrix);
    }
}


int task16(matrix m){
    int countSpecialElementsInMatrix = 0;
    if (m.nRows > 0) {
        countSpecialElementsInMatrix += getCountSpecialElementsInMatrix(m);
    }

    return countSpecialElementsInMatrix;
}


int task17(matrix m, int vector[]){
    int indVector;
    if (m.nRows > 0){
        indVector = getVectorIndexWithMaxAngle(m, vector);
    } else {
        indVector = -1;
    }

    return indVector;
}


long long task18(matrix m){
    long long scalarProduct = getSpecialScalarProduct(m);

    return scalarProduct;
}