#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
    char* title;
    int* data;
    int physical_size;
    int logical_size;
} COLUMN;

COLUMN* create_column(char* title);
int insert_value(COLUMN* column, int value);
void delete_column(COLUMN **column);
void print_col(COLUMN *col);
int number_of_occurrences(COLUMN *column, int value);

#endif
