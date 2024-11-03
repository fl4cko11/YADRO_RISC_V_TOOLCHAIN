#ifndef MATRIX_MLT_FUNCS_H
#define MATRIX_MLT_FUNCS_H
#include "matrix_mlt_structs.h"

static size_t get_number_of_columns(const char *matrix_data_file);

static size_t get_number_of_lines(const char *matrix_data_file);

void matrix_dump(struct matrix *matrix);

void matrix_ctor(struct matrix *matrix, const char *matrix_data_file_name);

struct matrix three_cycle_matrix_mlt(struct matrix *matrix1, struct matrix *matrix2, const char *result_matrix_name);

#endif