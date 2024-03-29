#include <stdlib.h>
#include "functions.h"
#define REALLOC_SIZE 256

int insert_value(COLUMN* column, int value) {
    // Check if reallocation is needed
    if (column->logical_size == column->physical_size) {
        // Reallocate another block of 256 cells
        int new_physical_size = column->physical_size + REALLOC_SIZE;
        int *new_data = (int *) realloc(column->data, new_physical_size * sizeof(int));
        column->data = new_data;
        column->physical_size = new_physical_size;
    }
    else{
        return 0;
    }
    // Insert the value into the column
    column->data[column->logical_size] = value;
    column->logical_size++;
    return 1;
}

COLUMN* create_column(char* title) {
    COLUMN* column = (COLUMN*)malloc(sizeof(COLUMN));
    column->title = title;
    column->data = NULL;
    column->physical_size = 0;
    column->logical_size = 0;

    return column;
}