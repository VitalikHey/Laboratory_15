#include "test_tasks_for_16_laboratory.h"
#include "../data_structures/tasks_for_16_laboratory/tasks.h"
#include "stdbool.h"
#include "assert.h"

void test_all(){
    test_task1();
    test_task2();
    test_task3();
    test_task4();
    test_task5();
    test_task6();
    test_task7();
    test_task8();
    test_task9();
    test_task10();
    test_task11();
    test_task12();
    test_task13();
    test_task14();
    test_task15();
    test_task16();
    test_task17();
    test_task18();
}


void test_task1(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 1, 3,
                    6, 7, 10,
                    11, 33, 17,
                    19, 20, 21,
            }, 4, 3
    );

    task1(m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    11, 33, 17,
                    6, 7, 10,
                    2, 1, 3,
                    19, 20, 21,
            }, 4, 3
    );

    assert(areTwoMatricesEqual(&m1, &m2) == true);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 33, 17,
                    6, 7, 10,
                    2, 4, 3,
                    19, 20, 21,
            }, 4, 3
    );
    task1(m3);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    1, 33, 17,
                    6, 7, 10,
                    2, 4, 3,
                    19, 20, 21,
            }, 4, 3
    );

    assert(areTwoMatricesEqual(&m3, &m4) == true);
}


void test_task2(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 11, 3,
                    6, 7, 10,
                    12, 33, 17,
                    19, 20, 21,
            }, 4, 3
    );
    task2(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    6, 7, 10,
                    2, 11, 3,
                    19, 20, 21,
                    12, 33, 17,
            }, 4, 3
    );

    assert(areTwoMatricesEqual(&m1, &m2) == true);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    2, 11, 33,
                    6, 33, 10,
                    12, 33, 17,
                    19, 33, 21,
            }, 4, 3
    );
    task2(m3);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    2, 11, 33,
                    6, 33, 10,
                    12, 33, 17,
                    19, 33, 21,
            }, 4, 3
    );

    assert(areTwoMatricesEqual(&m3, &m4) == true);
}


void test_task3(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            }, 3, 6
    );
    task3(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4
            }, 3, 6
    );
    assert(areTwoMatricesEqual(&m1, &m2) == true);
}


void test_task4(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            }, 3, 6
    );
    task4(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            }, 3, 6
    );
    assert(areTwoMatricesEqual(&m1, &m2) == true);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0, 1,
                    0, 2, 2, 0,
                    0, 2, 2, 0,
                    1, 0, 0, 1
            }, 4, 4
    );
    task4(&m3);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    2, 0, 0, 2,
                    0, 8, 8, 0,
                    0, 8, 8, 0,
                    2, 0, 0, 2,
            }, 4, 4
    );
    assert(areTwoMatricesEqual(&m3, &m4));
}


void test_task5(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 11, 3,
                    6, 7, 10,
                    12, 33, 17
            }, 3, 3
    );
    task5(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 6, 12,
                    11, 7, 33,
                    3, 10, 17
            }, 3, 3
    );
    assert(areTwoMatricesEqual(&m1, &m2));

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    8, 11, 4,
                    6, 7, 10,
                    12, 33, 17
            }, 3, 3
    );
    task5(m3);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    8, 11, 4,
                    6, 7, 10,
                    12, 33, 17
            }, 3, 3
    );
    assert(areTwoMatricesEqual(&m3, &m4));
}


void test_task6(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3,
                    0, 1,
            }, 2, 2
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, -3,
                    0, 1,
            }, 2, 2
    );

    assert(task6(m1, m2) == true);
}


void test_task7(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2,
            }, 3, 4
    );

    long long sum = task7(m1);
    assert(sum == 20);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    2, 3, 2,
                    5, 6, 1,
                    4, 3, 2
            }, 4, 3
    );
    sum = task7(m2);
    assert(sum == 20);
}


void test_task8(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2,
            }, 3, 4
    );
    int arrayLengthsShadedColumns1[4] = {1, 2, 3, 2};
    assert(task8(m1, arrayLengthsShadedColumns1) == 5);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1,
            }, 3, 4
    );
    int arrayLengthsShadedColumns2[4] = {1, 2, 1, 0};
    assert(task8(m2, arrayLengthsShadedColumns2) == 6);
}


void test_task9(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 13,
                    7, 12, 7, 4,
                    10, 11, 5, 1,
            }, 3, 4
    );
    task9(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    10, 11, 5, 1,
                    7, 12, 7, 4,
                    6, 8, 9, 13,
            }, 3, 4
    );
    assert(areTwoMatricesEqual(&m1, &m2));
}


void test_task10(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0
            }, 6, 2
    );
    assert(task10(m) == 3);
}


void test_task11(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            }, 3, 4
    );
    assert(task11(m) == 2);
}


void test_task12(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1,
            }, 3, 3
    );
    task12(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1,
            }, 3, 3
    );
    assert(areTwoMatricesEqual(&m1, &m2));
}


void test_task13(){
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            }, 4, 2, 2
    );

    assert(task13(ms, 4) == 2);
}


void test_task14(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 1,
                    1, 0,
                    0, 0,
            }, 3, 2
    );
    assert(getCountZeroRows(m1) == 1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    2, 1,
                    1, 1,
            }, 3, 2
    );
    assert(getCountZeroRows(m2) == 0);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    0, 0,
                    4, 7,
            }, 3, 2
    );
    assert(getCountZeroRows(m3) == 2);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    0, 1,
                    0, 0,
            }, 3, 2
    );
    assert(getCountZeroRows(m4) == 2);

    matrix m5 = createMatrixFromArray(
            (int[]) {
                    0, 1,
                    0, 2,
                    0, 3,
            }, 3, 2
    );
    assert(getCountZeroRows(m5) == 0);
}


void test_task15(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -8, 1, 10,
                    2, 4, 6,
                    -6, -11, 9
            }, 3, 3
    );
    assert(getMaxAbsValue(m1) == 11);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    -17, 16, 15,
                    -2, 1, 4,
                    18, 11, 17
            }, 3, 3
    );
    assert(getMaxAbsValue(m2) == 18);
}


void test_task16(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 3, 5, 5, 4,
                    6, 2, 3, 8, 12,
                    12, 12, 2, 1, 2,
            }, 3, 5
    );
    assert(task16(m) == 4);
}


void test_task17(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 3, 5,
                    6, 2, 3,
                    12, 12, 2,
            }, 3, 3
    );

    int vector[3] = {3, 4, 5};
    assert(task17(m, vector) == 0);
}


void test_task18(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            }, 3, 3
    );
    assert(task18(m) == 102);
}
