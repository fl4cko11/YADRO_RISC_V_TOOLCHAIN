#include "matrix_mlt_funcs.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <full path to matrix1_file>, <full path to matrix2_file>\n", argv[0]);
        return 1;
    }

    struct matrix matrix1 = {};
    struct matrix matrix2 = {};

    matrix_ctor(&matrix1, argv[1]);
    matrix_ctor(&matrix2, argv[2]);

    struct matrix matrix_mlt = three_cycle_matrix_mlt(&matrix1, &matrix2, "mlt_matrix");

    return 0;
}