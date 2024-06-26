// CDataframe TACCA - TRAN    Create the main functions to handle the sorting of the CDataframe's columns
#include "column.h"
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Swaps two elements; no return as it directly modifies memory addresses
void swap(unsigned long long int *a, unsigned long long int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partitions the column for ascending quicksort; no return as it modifies the column
int asc_partition(COLUMN *column, int left, int right) {
    int pivot_index = column->index[right];
    int i = left - 1;
    for (int j = left; j <= right; j++) {
        int index = (int)column->index[j];
        // Loop through the cdataframe depending and swap if the current element is smaller than the pivot
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
    // Swap the element with the element at index i+1
    swap(&column->index[i + 1], &column->index[right]);
    return i + 1;
}

// Sorts the column in ascending order using quicksort; no return as it sorts the array
void asc_quicksort(COLUMN *column, int left, int right) {
    if (left <= right) {
        int pi = asc_partition(column, left, right);
        asc_quicksort(column, left, pi - 1);
        asc_quicksort(column, pi + 1, right);
    }
}

// Sorts the column in ascending order using insertionsort; no return as it sorts the array
void asc_insertionsort(COLUMN *column, int N) {
    int i, j;
    // Iterate through each element in the column
    for (i = 1; i <= N; i++) {
        j = i - 1;
        // Store the current and previous indexes
        int temp = (int)column->index[i];
        int index = (int)column->index[j];

        // Loop through cdataframe depending on type, and shift elements to the right
        switch (column->column_type) {
            case NULLVAL:
                break;
            case UINT:
                while (j >= 0 && *(int *)column->data[index] > *(int *)column->data[temp]) {
                    column->index[j + 1] = column->index[j];
                    j = j - 1;
                }
                break;
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
        // Insert the element
        column->index[j + 1] = temp;
    }
}

// Partitions the column for descending quicksort; no return as it modifies the column
int desc_partition(COLUMN *column, int left, int right){
    // Partition swap in descending order
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

// Sorts the column in descending order using quicksort; no return as it sorts the array
void desc_quicksort(COLUMN *column, int left, int right){
    // Quick sort in descending order
    if (left <= right) {
        int pi = desc_partition(column, left, right);
        desc_quicksort(column, left, pi - 1);
        desc_quicksort(column, pi + 1, right);
    }
}

// Sorts the column in descending order using insertionsort; no return as it sorts the array
void desc_insertionsort(COLUMN *column, int n){
    // Insertion sort in descending order
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

// Sorts the column based on the specified direction; no return as it sorts the array (or not)
void sort(COLUMN *column, int sort_dir) {
    // Check if the column is sorted ot not
    if (column->valid_index == 1) {
        printf("This column is already sorted\n");
    }
    // Check if the index is 0 and if it is, quicksort the column
    else if (column->valid_index == 0) {
        if(sort_dir==0)
            asc_quicksort(column, 0, column->size-1);
        else if(sort_dir==1)
            desc_quicksort(column, 0, column->size-1);
        column->valid_index = 1;
    }
    // If the index is -1, insertionsort the column
    else if (column->valid_index == -1) {
        if(sort_dir==0)
            asc_insertionsort(column, column->size);
        else if(sort_dir==1)
            desc_insertionsort(column, column->size);
        column->valid_index = 1;
    }
}

// Prints the column based on the index; no return as it only prints the contents
void print_col_by_index(COLUMN *column) {
    // Print the column based on the index
    for (int i = 0; i < column->size; i++) {
        printf("[%d] ", i);
        char str[100];
        int j = column->index[i];
        convert_value(column, j, str, sizeof(str));
        printf("%s (index = %d)\n", str, j);
    }
}

// Erases the index of the column; no return as it directly modifies the given CDataframe
void erase_index(COLUMN *column) {
    // Check if the column and its index are not NULL to free it if it's the case
    if (column != NULL && column->index != NULL) {
        free(column->index);
        column->index = NULL;
        column->valid_index = 0;
    }
}

// Checks if the column's index is valid; returns 1 if valid, -1 if invalid, 0 if NULL
int check_index(COLUMN *column) {
    // Check if ccolumn and index is NULL
    if (column != NULL && column->index != NULL) {
        // Return 1 if the index is valid, -1 if it is invalid
        if (column->valid_index == 1) {
            return 1;
        } else {
            return -1;
        }
    } else {
        // Return 0 f it's NULL
        return 0;
    }
}

// Updates the index of the column; no return as it sorts the array (or not)
void update_index(COLUMN *column, int sort_dir) {
    asc_insertionsort(column, column->size);
}

// Searches for a value in the column; returns 1 if value found, -1 if index is not valid, 0 if value not found, -2 if unsupported type
int search_value_in_column(COLUMN *column, void *value){
    if (column != NULL && column->index != NULL) {
        if(column->valid_index != 1){
            return -1;
        }
        else{
            // Loop through the column to search for the value depending on the type
            for (int i = 0; i < column->size; i++){
                ENUM_TYPE column_type=column->column_type;
                switch (column_type) {
                    case NULLVAL:
                        if (column->data[i] == NULL)
                            return 1;
                        break;
                    case UINT:
                        if (*((unsigned int*)column->data[i]) == *((unsigned int*)value))
                            return 1;
                        break;
                    case INT:
                        if (*((int*)column->data[i]) ==*((int*)value))
                            return 1;
                        break;
                    case CHAR:
                        if (*((char*)column->data[i]) == *((char*)value))
                            return 1;
                        break;
                    case FLOAT:
                        if (*((float*)column->data[i]) == *((float*)value))
                            return 1;
                        break;
                    case DOUBLE:
                        if (*((double*)column->data[i]) == *((double*)value))
                            return 1;
                        break;
                    case STRING: {
                        char *str1 = (char*)column->data[i];
                        char *str2 = (char*)value;
                        int index = 0;
                        while (str1[index] != '\0' && str2[index] != '\0') {
                            if (str1[index] != str2[index])
                                break;
                            index++;
                        }
                        if (str1[index] == '\0' && str2[index] == '\0')
                            return 1;
                        break;
                    }
                    default:
                        printf("Unsupported type, try again\n");
                        return -2;
                }
            }
        }
    }
    return 0;
}