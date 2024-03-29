#ifndef FUNCTION_H
#define FUNCTION_H
#define SIZE 256

typedef struct{
    char* title;
    int* data;
    int physical_size;
    int logical_size;
} COLUMN;

void insert_value(COLUMN *column, int value);

#endif
