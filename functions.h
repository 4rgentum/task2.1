#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct MatrixLine {
    int line_size;
    int *line;
}MatrixLine;

typedef struct Matrix {
    int number_of_lines;
    MatrixLine *line;
}Matrix;

int get_int(int *);
int input_matrix(Matrix *);
void output_matrix(Matrix);
void erase(Matrix *);
Matrix new_matrix(Matrix);

#endif
