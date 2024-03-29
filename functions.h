#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SIZE 256

typedef struct {
    char* title;
    int* data;
    int physical_size;
    int logical_size;
} COLUMN;

COLUMN* create_column(char* title);
int insert_value(COLUMN* column, int value);
void print_col(COLUMN *col);

#endif
