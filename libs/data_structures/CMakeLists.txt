add_library(data_structures
        matrix/matrix.c
        test_matrix/test_matrix.c
        test_matrix/test_matrix.h
)
target_link_libraries(data_structures algorithms)