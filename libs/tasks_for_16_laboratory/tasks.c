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
