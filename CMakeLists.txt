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
        libs/tasks_for_16_laboratory/tasks.h
        libs/algorithms/algorithms.c
)