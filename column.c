#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"
#define REALLOC_SIZE 256

COLUMN *create_column(ENUM_TYPE type, char *title) {
    COLUMN *column = (COLUMN *)malloc(sizeof(COLUMN));
    column->title = title;
    column->size = 0;
    column->max_size = 0;
    column->column_type = type;
    column->data = NULL;
    column->index = (int *)malloc(sizeof(int));
    column->valid_index = 0;
    column->sort_dir = 0;
    return column;
}


int insert_value(COLUMN *column, void *value) {
    // Check if the logical size has reached the maximum size
    if (column->size == column->max_size) {
        column->max_size += REALLOC_SIZE;
        column->data = (COL_TYPE **)realloc(column->data, column->max_size * sizeof(COL_TYPE *));
        column->index = (unsigned long long int *)realloc(column->index, column->max_size * sizeof(unsigned long long int));
        if (column->data == NULL){
            return 0;
        }
    }

    COL_TYPE *new_entry = (COL_TYPE *) malloc(sizeof(COL_TYPE));
    column->data[column->size] = new_entry;

    // Insert the value based on its type
    switch (column->column_type) {
        case NULLVAL:
            column->data[column->size]->struct_value = NULL;
            break;
        case UINT:
            column->data[column->size] = (COL_TYPE *)malloc(sizeof(unsigned int));
            if(value==NULL) {
                column->data[column->size] = NULL;
            }
            else
                *((unsigned int *)column->data[column->size]) = *((unsigned int *)value);
            break;
        case INT:
            column->data[column->size] = (COL_TYPE *)malloc(sizeof(int));
            if(value==NULL) {
                column->data[column->size] = NULL;
            }
            else
                column->data[column->size]->int_value = *(int *)value;
            break;
        case CHAR:
            column->data[column->size] = (COL_TYPE *)malloc(sizeof(char));
            if(value==NULL) {
                column->data[column->size] = NULL;
            }
            else
                column->data[column->size]->char_value = *(int *)value;
            break;
        case FLOAT:
            column->data[column->size] = (COL_TYPE *)malloc(sizeof(float));
            if(value==NULL) {
                column->data[column->size] = NULL;
            }
            else
                *((float *)column->data[column->size]) = *((float *)value);
            break;
        case DOUBLE:
            column->data[column->size] = (COL_TYPE *)malloc(sizeof(double));
            if(value==NULL) {
                column->data[column->size] = NULL;
            }
            else
                *((double *)column->data[column->size]) = *((double *)value);
            break;
        case STRING: {
            size_t str_len = strlen((char *)value);
            new_entry->string_value = malloc(str_len + 1);
            strcpy((char *) column->data[column->size]->string_value, (char *) value);
        }
            break;

        default:
            return 0;
    }
    column->size++;
    return 1;
}


void convert_value(COLUMN *column, unsigned long long int i, char *str, int size) {
    switch(column->column_type) {
        case NULLVAL:
            snprintf(str, size, "NULL");
            break;
        case UINT:
            snprintf(str, size, "%u", column->data[i]->uint_value);
            break;
        case INT:
            snprintf(str, size, "%d",column->data[i]->int_value);
            break;
        case CHAR:
            snprintf(str, size, "%c", column->data[i]->char_value);
            break;
        case FLOAT:
            snprintf(str, size, "%f", column->data[i]->float_value);
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", column->data[i]->double_value);
            break;
        case STRING:
            snprintf(str, size, "%s", column->data[i]->string_value);
            break;

        default:
            printf("Unsupported type");
    }
}

void print_col(COLUMN *column) {
    for (int i = 0; i < column->size; i++) {
        printf("[%d] ", i);

        if (column->data[i] == NULL) {
            printf("NULL\n");
        }
        else {
            char str[100];
            convert_value(column, i, str, sizeof(str));
            printf("%s\n", str);
        }
    }
}

void sort(COLUMN *column, int sort_dir) {
    for (int i = 1; i < column->size; i++) {
        int j = i - 1;
        int key = column->index[i];
        if (column->column_type == STRING) {
            while(j>=0 && (strcmp(column->data[j], column->data[i]) > 0)) {
                column->index[j + 1] = column->index[j];
                j--;
            }
        }
        else {
            char str[100];
            //
            convert_value(column, j, str, sizeof(str));
            printf("%s(j = %d) <", str, j);
            convert_value(column, i, str, sizeof(str));
            printf(" %s(i = %d)\n", str, i);
            //
            while(j>=0 && (column->data[j] < column->data[i])) {
                //
                convert_value(column, j, str, sizeof(str));
                printf("swaped : %s ", str);
                convert_value(column, j+1, str, sizeof(str));
                printf("with %s\n", str);
                //
                column->index[j+1] = column->index[j];
                j--;
            }
            column->index[j+1] = key;
        }
    }
}



void print_col_by_index(COLUMN *column){
    for (int i = 0; i < column->size ; i++) {
        printf("[%d] ", i);
        char str[100];
        int j = column->index[i];
        convert_value(column, j, str, sizeof(str));
        printf("%s\n", str);

    }
}

