#ifndef SORT_H
#define SORT_H
#include "column.h"

void swap(unsigned long long int *a, unsigned long long int *b);

int asc_partition(COLUMN *column, int left, int right);
void asc_quicksort(COLUMN *column, int left, int right);
void asc_insertionsort(COLUMN *column, int n);
int desc_partition(COLUMN *column, int left, int right);
void desc_quick_sort(COLUMN *column, int left, int right);
void desc_insertionsort(COLUMN *column, int n);
void sort(COLUMN *column, int sort_dir);
void print_col_by_index(COLUMN *column);
void erase_index(COLUMN *column);
int check_index(COLUMN *column);
void update_index(COLUMN *column, int sort_dir);
int search_value_in_column(COLUMN *column, void *value);

#endif
