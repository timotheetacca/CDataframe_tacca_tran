#include <stdlib.h>
#include "functions.h"
#define REALLOC_SIZE 256

void insert_value(COLUMN *column, int value){
    // Check if reallocation is needed
    if (column->logical_size == column->physical_size) {
        // Reallocate another block of 256 cells
        int new_physical_size = column->physical_size + REALLOC_SIZE;
        int *new_data = (int *) realloc(column->data, new_physical_size * sizeof(int));
        column->data = new_data;
        column->physical_size = new_physical_size;
    }
    // Insert the value into the column
    column->data[column->logical_size] = value;
    column->logical_size++;
}