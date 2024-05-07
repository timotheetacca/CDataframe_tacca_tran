#include "column.h"
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap(unsigned long long int *a, unsigned long long int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int asc_partition(COLUMN *column, int left, int right) {
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


void asc_quicksort(COLUMN *column, int left, int right) {
    if (left <= right) {
        int pi = asc_partition(column, left, right);
        asc_quicksort(column, left, pi - 1);
        asc_quicksort(column, pi + 1, right);
    }
}


void asc_insertionsort(COLUMN *column, int N) {
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


int desc_partition(COLUMN *column, int left, int right){
    int pivot_index = column->index[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        int index = (int)column->index[j];
        switch (column->column_type) {
            case NULLVAL:
                break;
            case UINT:
                if (*(int *)column->data[index] > *(int *)column->data[pivot_index]) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case INT:
                if (*(int *)column->data[index] > *(int *)column->data[pivot_index]) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case CHAR:
                if (*(char *)column->data[index] > *(char *)column->data[pivot_index]) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case FLOAT:
                if (*((float *)column->data[index]) > *((float *)column->data[pivot_index])) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case DOUBLE:
                if (*((double *)column->data[index]) > *((double *)column->data[pivot_index])) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
                break;
            case STRING: {
                char* str_a = (char*)column->data[index];
                char* str_b = (char*)column->data[pivot_index];
                if (strcmp(str_a, str_b) > 0) {
                    i++;
                    swap(&column->index[i], &column->index[j]);
                }
            }
                break;
            default:
                break;
        }
    }
    swap(&column->index[i + 1], &column->index[right]);
    return i + 1;
}

void desc_quicksort(COLUMN *column, int left, int right){
    if (left <= right) {
        int pi = desc_partition(column, left, right);
        desc_quicksort(column, left, pi - 1);
        desc_quicksort(column, pi + 1, right);
    }
}

void desc_insertionsort(COLUMN *column, int n){
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = (int)column->index[i];
        int index = (int)column->index[j];
        switch (column->column_type) {
            case NULLVAL:
                break;
            case UINT:
                while (j >= 0 && *(int *)column->data[index] < *(int *)column->data[temp]) {
                    column->index[j + 1] = column->index[j];
                    j--;
                }
                break;
            case INT:
                while (j >= 0 && *(int *)column->data[index] < *(int *)column->data[temp]) {
                    column->index[j + 1] = column->index[j];
                    j--;
                }
                break;
            case CHAR:
                while (j >= 0 && *(char *)column->data[index] < *(char *)column->data[temp]) {
                    column->index[j + 1] = column->index[j];
                    j--;
                }
                break;
            case FLOAT:
                while (j >= 0 && *((float *)column->data[index]) < *((float *)column->data[temp])) {
                    column->index[j + 1] = column->index[j];
                    j--;
                }
                break;
            case DOUBLE:
                while (j >= 0 && *((double *)column->data[index]) < *((double *)column->data[temp])) {
                    column->index[j + 1] = column->index[j];
                    j--;
                }
                break;
            case STRING:
                while (j >= 0 && strcmp((char *)column->data[index], (char *)column->data[temp]) < 0) {
                    column->index[j + 1] = column->index[j];
                    j--;
                }
                break;
            default:
                break;
        }
        column->index[j + 1] = temp;
    }
}


void sort(COLUMN *column, int sort_dir) {
    if (column->valid_index == 1) {
        printf("This column is already sorted\n");

    } else if (column->valid_index == 0) {
        if(sort_dir==0)
            asc_quicksort(column, 0, column->size-1);
        else if(sort_dir==1)
            desc_quicksort(column, 0, column->size-1);
        column->valid_index = 1;

    } else if (column->valid_index == -1) {
        if(sort_dir==0)
            asc_insertionsort(column, column->size);
        else if(sort_dir==1)
            desc_insertionsort(column, column->size);
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

void update_index(COLUMN *column, int sort_dir) {
    asc_insertionsort(column, column->size);
}

int search_value_in_column(COLUMN *col, void *val){

}