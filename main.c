#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    while (1) {
        Matrix table = {0, NULL};
        int flag = input_matrix(&table);
        if (flag == 0) {
            erase(&table);
            printf("End Of File\n");
            break;
        } else if (flag > 0) {
            printf("Your Input Matrix is:\n");
            output_matrix(table);

            Matrix new_table = new_matrix(table);
            printf("Your Output Matrix is:\n");
            output_matrix(new_table);

            printf("Your Input Matrix is:\n");
            output_matrix(table);

            erase(&table);
            erase(&new_table);
        } else if (flag < 0) {
            printf("The Matrix Is Empty.\n");
        }
    }
    return 0;
}
