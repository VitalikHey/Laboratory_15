#include "../algorithms/algorithms.h"
#include "../data_structures/matrix/matrix.h"
#include "tasks.h"


void task1(matrix m) {
    swapRowsWithMinimumAndMaximumNumber(m);
}

void task2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}
