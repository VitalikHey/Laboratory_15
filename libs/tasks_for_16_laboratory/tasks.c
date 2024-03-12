#include "../algorithms/algorithms.h"
#include "../data_structures/matrix/matrix.h"
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
