#include "libs/data_structures/matrix/matrix.h"

int main () {
    matrix M1 = getMemMatrix(3,3);

    inputMatrix(&M1);

    outputMatrix(M1);

    freeMemMatrix(&M1);

    return 0;
}