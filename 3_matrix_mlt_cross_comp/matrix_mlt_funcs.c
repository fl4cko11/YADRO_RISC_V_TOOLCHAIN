#include "matrix_mlt_funcs.h"

static size_t get_number_of_columns(const char *matrix_data_file) {
    assert(matrix_data_file != NULL);

    FILE *fp = fopen(matrix_data_file, "rb");
    assert(fp != NULL);

    char line[256];
    int temp = 0;
    size_t count = 0;
    fgets(line, sizeof(line), fp); // достаточно одну считать
    char *ptr = line;
    while (sscanf(ptr, "%d", &temp) == 1) {
        count++;
        while (*ptr != ' ' && *ptr != '\0') ptr++;
        while (*ptr == ' ') ptr++;
    }

    rewind(fp);
    fclose(fp);

    return count;
}

static size_t get_number_of_lines(const char *matrix_data_file) {
    assert(matrix_data_file != NULL);

    FILE *fp = fopen(matrix_data_file, "rb");
    assert(fp != NULL);

    char line[256];
    int count = 0;
    while(fgets(line, sizeof(line), fp) != NULL) {
        count++;
    }

    rewind(fp);
    fclose(fp);

    return count;
}

void matrix_dump(struct matrix *matrix) {
    fprintf(stderr, "this matrix from: %s", matrix->data_file_name);
    for (int i = 0; i < matrix->lines; i++) {
        fprintf(stderr, "\n");
        for (int j = 0; j < matrix->columns; j++) {
            fprintf(stderr, "%d ", matrix->data[i][j]);
        }
    }
    fprintf(stderr, "\n");
}

void matrix_ctor(struct matrix *matrix, const char *matrix_data_file_name) {
    assert(matrix != NULL);
    assert(matrix_data_file_name != NULL);
    FILE *fp = fopen(matrix_data_file_name, "rb");
    assert(fp != NULL);

    matrix->data_file_name = matrix_data_file_name;
    // fprintf(stderr, "now work with: %s\n", matrix->data_file_name);
    matrix->lines = get_number_of_lines(matrix->data_file_name);
    // fprintf(stderr, "lines: %ld\n", matrix->lines);
    matrix->columns = get_number_of_columns(matrix->data_file_name);
    // fprintf(stderr, "columns: %ld\n", matrix->columns);

    matrix->data = (int **)calloc(matrix->lines, sizeof(int *));
    for (int i = 0; i < matrix->lines; i++) {
        matrix->data[i] = (int *)calloc(matrix->columns, sizeof(int));
    }

    for (int i = 0; i < matrix->lines; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            fscanf(fp, "%d", &matrix->data[i][j]);
        }
    }

    fclose(fp);
    matrix_dump(matrix);
}

struct matrix three_cycle_matrix_mlt(struct matrix *matrix1, struct matrix *matrix2, const char *result_matrix_name) {
    assert(matrix1 != NULL);
    assert(matrix2 != NULL);
    assert(result_matrix_name != NULL);

    struct matrix matrix_mlt = {};
    matrix_mlt.data_file_name = result_matrix_name;
    matrix_mlt.lines = matrix1->lines;
    matrix_mlt.columns = matrix2->columns;
    
    matrix_mlt.data = (int **)calloc(matrix_mlt.lines, sizeof(int *));
    for (int i = 0; i < matrix_mlt.lines; i++) {
        matrix_mlt.data[i] = (int *)calloc(matrix_mlt.columns, sizeof(int));
    }

    for (int k = 0; k < matrix2->columns; k++) {
        for (int t = 0; t < matrix1->lines; t++) {
            for (int i = 0; i < matrix1->columns; i++) {
                matrix_mlt.data[t][k] += matrix1->data[t][i]*matrix2->data[i][k];
            }
        }
    }
    matrix_dump(&matrix_mlt);
    return matrix_mlt;
}