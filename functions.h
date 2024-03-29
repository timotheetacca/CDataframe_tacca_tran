#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SIZE 256

typedef struct {
    char* title;
    int* data;
    int physical_size;
    int logical_size;
} COLUMN;

int insert_value(COLUMN* column, int value);
COLUMN* create_column(char* title);

#endif
