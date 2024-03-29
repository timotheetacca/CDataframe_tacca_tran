#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    COLUMN column;
    column.title = "1";
    column.data = (int*)malloc(5 * sizeof(int));
    column.physical_size = 5;
    column.logical_size = 5;

    for (int i = 0; i < column.logical_size; ++i) {
        column.data[i] = i + 1;
    }

    printf("Title: %s\n", column.title);
    printf("Data: ");
    for (int i = 0; i < column.logical_size; ++i) {
        printf("%d ", column.data[i]);
    }

    insert_value(&column, 6);

    printf("\nNew data: ");
    for (int i = 0; i < column.logical_size; ++i) {
        printf("%d ", column.data[i]);
    }
    printf("\n");

    return 0;
}
