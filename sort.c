#include "column.h"
#include <string.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(COLUMN *column, int left, int right) {
    int pivot_index = column->index[right];
    int i = left - 1;
    for (int j = left; j <= right; j++) {
        switch (column->column_type) {
            case UINT:
                if (*(int *)column->data[column->index[j]] < *(int *)column->data[pivot_index]) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case INT:
                if (*(int *)column->data[column->index[j]] < *(int *)column->data[pivot_index]) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case CHAR:
                if (*(char *)column->data[column->index[j]] < *(char *)column->data[pivot_index]) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case FLOAT:
                if (*((float *)column->data[column->index[j]]) < *((float *)column->data[pivot_index])) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case DOUBLE:
                if (*((double *)column->data[column->index[j]]) < *((double *)column->data[pivot_index])) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case STRING: {
                char* str_a = (char*)column->data[column->index[j]];
                char* str_b = (char*)column->data[pivot_index];
                if (strcmp(str_a, str_b) < 0) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
            }
                break;
            default:
                return 0;
        }
    }
    swap(&column->index[i + 1], &column->index[right]);
    return i + 1;
}


void quicksort(COLUMN *column, int left, int right) {
    if (left <= right) {
        int pi = partition(column, left, right);
        quicksort(column, left, pi - 1);
        quicksort(column, pi + 1, right);
    }
}


void insertionsort(COLUMN *column, int n) {
    int i, j;
    unsigned long long int key;
    for (i = 1; i < n; i++) {
        key = column->index[i];
        j = i - 1;
        while (j >= 0 && (column->data[column->index[j]] < column->data[key])) { // Use "<" for descending order
            column->index[j + 1] = column->index[j];
            j = j - 1;
        }
        column->index[j + 1] = key;
    }
}

void sort(COLUMN *column) {
    if (column->valid_index == 1) {
        printf("This column is already sorted.\n");

    } else if (column->valid_index == 0) {
        quicksort(column, 1, column->size-1);

    } else if (column->valid_index == -1) {
        insertionsort(column, column->size);
        for (int i = 0; i < column->size / 2; i++) {
            unsigned long long int temp = column->index[i];
            column->index[i] = column->index[column->size - i - 1];
            column->index[column->size - i - 1] = temp;
        }
    }
}

void print_col_by_index(COLUMN *column) {
    for (int i = 0; i < column->size; i++) {
        printf("[%d] ", i);
        char str[100];
        int j = column->index[i];
        convert_value(column, j, str, sizeof(str));
        printf("%s (index = %d)\n", str, j);
    }
}
