#ifndef SORT_H
#define SORT_H
#include "column.h"

void swap(unsigned long long int *a, unsigned long long int *b);
int partition(COLUMN *column, int left, int right);
void quicksort(COLUMN *column, int left, int right);
void insertionsort(COLUMN *column, int n);
void sort(COLUMN *column);
void print_col_by_index(COLUMN *column);
void erase_index(COLUMN *column);
int check_index(COLUMN *column);
void update_index(COLUMN *column);

#endif
