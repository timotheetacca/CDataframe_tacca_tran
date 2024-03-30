#ifndef COLUMN_H
#define COLUMN_H

typedef struct {
    char* title;
    int* data;
    int physical_size;
    int logical_size;
} COLUMN;

COLUMN* create_column(char* title);
int insert_value(COLUMN* column, int value);
void delete_column(COLUMN **column);
void print_col(COLUMN *column);
int number_of_occurrences(COLUMN *column, int value);
int number_at_position(COLUMN *column, int value);

#endif
