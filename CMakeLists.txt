cmake_minimum_required(VERSION 3.26)
project(Laboratory_15 C)

set(CMAKE_C_STANDARD 11)

add_executable(Laboratory_15
        main.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/test_matrix/test_matrix.h
        libs/data_structures/test_matrix/test_matrix.c
        libs/data_structures/test_matrix/test_matrix.c
        libs/data_structures/matrix/matrix.h
        libs/tasks_for_16_laboratory/tasks.c
        libs/algorithms/algorithms.c
        libs/test_tasks_for_16_laboratory/test_tasks_for_16_laboratory.h
        libs/test_tasks_for_16_laboratory/test_tasks_for_16_laboratory.c
)