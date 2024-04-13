#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#define REALLOC_SIZE 256

COLUMN* create_column(char* title) {
    COLUMN* column = (COLUMN*)malloc(sizeof(COLUMN));
    column->title = title;
    column->data = NULL;
    column->physical_size = 0;
    column->logical_size = 0;

    return column;
}

int insert_value(COLUMN* column, int value) {
    // Check if reallocation is needed
    if (column->logical_size == column->physical_size) {
        // Reallocate another block of 256 cells
        int new_physical_size = column->physical_size + REALLOC_SIZE;
        int *new_data = (int *) realloc(column->data, new_physical_size * sizeof(int));
        // Return 0 if reallocation is NULL
        if (new_data == NULL) {
            return 0;
        }
        column->data = new_data;
        column->physical_size = new_physical_size;
    }
    // Insert the value into the column
    column->data[column->logical_size] = value;
    column->logical_size++;
    return 1;
}

void delete_column(COLUMN **column){
    free((**column).data);
    free(*column);
    *column = NULL;
}

void print_col(COLUMN *column){
    for(int i=0; i<column->logical_size;i++) {
        printf("[%d] %d\n", i, column->data[i]);
    }
}

int number_of_occurrences(COLUMN *column, int value){
    int occurrences=0;
    for (int i=0; i<column->logical_size; i++){
        if (column->data[i]==value){
            occurrences++;
        }
    }
    return occurrences;
}

int number_at_position(COLUMN *column, int value){
    if (value >= 0 && value < column->logical_size) {
        return column->data[value];
    } else {
        // Returns -1 if the position is invalid
        return -1;
    }
}




