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
    column->index = NULL;

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

    // Insert the value based on its type
    switch (column->column_type) {
        case NULLVAL:
            column->data[column->size] = NULL;
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
            column->data[column->size] = (COL_TYPE *)malloc(sizeof(signed int));
            if(value==NULL) {
                column->data[column->size] = NULL;
            }
            else
            *((signed int *)column->data[column->size]) = *((signed int *)value);
            break;
        case CHAR:
            column->data[column->size] = (COL_TYPE *)malloc(sizeof(char));
            if(value==NULL) {
                column->data[column->size] = NULL;
            }
            else
            *((char *)column->data[column->size]) = *((char *)value);
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
        case STRING:
            column->data[column->size] = (COL_TYPE *)malloc(strlen((char *)value) + 1); // +1 for the \O
            if(value==NULL) {
                column->data[column->size] = NULL;
            }
            else
            strcpy((char *)column->data[column->size], (char *)value);
            break;
        case STRUCTURE:
            column->data[column->size] = malloc(sizeof(void *));
            if(value==NULL) {
                column->data[column->size] = NULL;
            }
            else
            *((void **)column->data[column->size]) = *((void **)value);
            break;
        default:
            return 0;
    }
    column->index[column->size] = column->size;
    column->size++;
    return 1;
}


void convert_value(COLUMN *col, unsigned long long int i, char *str, int size) {
    switch(col->column_type) {
        case UINT:
            snprintf(str, size, "%u", *((unsigned int *)col->data[i]));
            break;
        case INT:
            snprintf(str, size, "%d", *((int *)col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char *)col->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float *)col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double *)col->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", *((char *)col->data[i]));
            break;
        case STRUCTURE:
            snprintf(str, size, "%p", *((void **)col->data[i]));
            break;
        default:
            printf("Unsupported type");
    }
}

void print_col(COLUMN *column) {
    for (unsigned int i = 0; i < column->size; i++) {
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

