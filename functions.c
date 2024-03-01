#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void output_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.number_of_lines; ++i) {
        for (int j = 0; j < matrix.line[i].line_size; ++j) {
            printf("%d ", matrix.line[i].line[j]);
        }
        printf("\n");
    }
}

void erase(Matrix *matrix) {
    for (int i = 0; i < matrix->number_of_lines; ++i) {
        free(matrix->line[i].line);
    }
    free(matrix->line);
    matrix->number_of_lines = 0;
    matrix->line = NULL;
}

int get_int(int *number) {
    int flag;
    flag = scanf("%d", number);
    if (flag == EOF) {
        return 0;
    }
    while (flag != 1) {
        printf("Incorrectly Entered Number\n");
        printf("Enter Correct Integer Number:\n");
        scanf("%*[^\n]");
        scanf("%*c");
        flag = scanf("%d", number);
        if (flag == EOF) {
            return 0;
        }
    }
    return 1;
}

int input_matrix(Matrix *matrix) {
    int size_of_smth;
    printf("Input Positive Integer Size Of Matrix:\n");
    int flag = get_int(&size_of_smth);
    if (flag && size_of_smth == 0) {
        return -1;
    } else if (!flag) {
        return 0;
    }
    while (size_of_smth < 0) {
        printf("Incorrectly Entered Size Of Array\n");
        printf("Enter Correct Positive Integer Size Of Matrix:\n");
        get_int(&size_of_smth);
    }
    matrix->number_of_lines = size_of_smth;
    int *array;
    matrix->line = (MatrixLine *) calloc(size_of_smth, sizeof(MatrixLine));
    for (int i = 0; i < matrix->number_of_lines; i++) {
        printf("Input Positive Integer Size Of Line # %d:\n", i + 1);
        int f = get_int(&size_of_smth);
        if (!f) {
            return 0;
        }
        while (size_of_smth < 0) {
            printf("Incorrectly Entered Size Of Array\n");
            printf("Enter Correct Positive Integer Size Of Matrix:\n");
            get_int(&size_of_smth);
        }
        matrix->line[i].line_size = size_of_smth;
        array = (int *) malloc(size_of_smth * sizeof(int));
        if (matrix->line[i].line_size == 0) {
            printf("There Is No Elements In This Line.\n");
        } else {
            printf("Input Elements Of Line # %d:\n" , i + 1);
        }
        for (int j = 0; j < size_of_smth; j++) {
            int fl = get_int(&(array[j]));
            if (!fl) {
                free(array);
                return 0;
            }
        }
        matrix->line[i].line = array;
    }
    return 1;
}

Matrix new_matrix(Matrix matrix) {
    Matrix new_table = {0, NULL};
    new_table.number_of_lines = matrix.number_of_lines;
    new_table.line = (MatrixLine *) calloc(matrix.number_of_lines, sizeof(MatrixLine));
    for (int i = 0; i < new_table.number_of_lines; i++) {
        new_table.line[i].line_size = 0;
        for (int j = 0; j < matrix.line[i].line_size; j++) {
            int flag = 0;
            for (int k = 0; k < matrix.line[i].line_size; k++) {
                if ((k != j) && (matrix.line[i].line[j] == matrix.line[i].line[k])) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                int checker = 0;
                if (new_table.line[i].line_size == 0) {
                    (new_table.line[i].line_size)++;
                    new_table.line[i].line = (int *) realloc(new_table.line[i].line, new_table.line[i].line_size * sizeof(int));
                    new_table.line[i].line[new_table.line[i].line_size - 1] = matrix.line[i].line[j];
                }
                for (int k = 0; k < new_table.line[i].line_size; k++) {
                    if (new_table.line[i].line[k] == matrix.line[i].line[j]) {
                        checker = 1;
                        break;
                    }
                }
                if (!checker) {
                    (new_table.line[i].line_size)++;
                    new_table.line[i].line = (int *) realloc(new_table.line[i].line, new_table.line[i].line_size * sizeof(int));
                    new_table.line[i].line[new_table.line[i].line_size - 1] = matrix.line[i].line[j];
                }
            }
        }
    }
    return new_table;
}
