#include "column.h"
#include <stdlib.h>
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
        int index = (int)column->index[j];
        switch (column->column_type) {
            case NULLVAL:
                break;
            case UINT:
                if (*(int *)column->data[index] < *(int *)column->data[pivot_index]) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case INT:
                if (*(int *)column->data[index] < *(int *)column->data[pivot_index]) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case CHAR:
                if (*(char *)column->data[index] < *(char *)column->data[pivot_index]) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case FLOAT:
                if (*((float *)column->data[index]) < *((float *)column->data[pivot_index])) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case DOUBLE:
                if (*((double *)column->data[index]) < *((double *)column->data[pivot_index])) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case STRING: {
                char* str_a = (char*)column->data[index];
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


void insertionsort(COLUMN *column, int N) {
    int i, j;
    for (i = 1; i <= N; i++) {
        j = i - 1;
        int temp = (int)column->index[i];
        int index = (int)column->index[j];
        switch (column->column_type) {
            case NULLVAL:
                break;
            case UINT:
                while (j >= 0 && *(int *)column->data[index] > *(int *)column->data[temp]) {
                    column->index[j + 1] = column->index[j];
                    j = j - 1;
                }
            case INT:
                while (j >= 0 && *(int *)column->data[index] > *(int *)column->data[temp]) {
                    column->index[j + 1] = column->index[j];
                    j = j - 1;
                }
                break;
            case CHAR:
                while (j >= 0 && *(char *)column->data[index] > *(char *)column->data[temp]) {
                    column->index[j + 1] = column->index[j];
                    j = j - 1;
                }
                break;
            case FLOAT:
                while (j >= 0 && *((float *)column->data[index]) > *((float *)column->data[temp])) {
                    column->index[j + 1] = column->index[j];
                    j = j - 1;
                }
                break;
            case DOUBLE:
                while (j >= 0 && *((double *)column->data[index]) > *((double *)column->data[temp])) {
                    column->index[j + 1] = column->index[j];
                    j = j - 1;
                }
                break;
            case STRING:
                while (j >= 0 && strcmp((char *)column->data[index], (char *)column->data[temp]) > 0) {
                    column->index[j + 1] = column->index[j];
                    j = j - 1;
                }
                break;

            default:
                return;

        }
        column->index[j + 1] = temp;
    }
}


void sort(COLUMN *column) {
    if (column->valid_index == 1) {
        printf("This column is already sorted\n");

    } else if (column->valid_index == 0) {
        quicksort(column, 0, column->size-1);
        column->valid_index = 1;

    } else if (column->valid_index == -1) {
        insertionsort(column, column->size);
        column->valid_index = 1;
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

void erase_index(COLUMN *column) {
    if (column != NULL && column->index != NULL) {
        free(column->index);
        column->index = NULL;
        column->valid_index = 0;
    }
}

int check_index(COLUMN *column) {
    if (column != NULL && column->index != NULL) {
        if (column->valid_index == 1) {
            return 1;
        } else {
            return -1;
        }
    } else {
        return 0;
    }
}
