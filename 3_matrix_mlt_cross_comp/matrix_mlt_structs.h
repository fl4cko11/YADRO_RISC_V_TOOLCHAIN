#ifndef MATRIX_MLT_STRUCTS_H
#define MATRIX_MLT_STRUCTS_H
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct matrix {
    const char *data_file_name;
    int **data;
    size_t lines;
    size_t columns;
};

#endif