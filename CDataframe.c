#include <stdio.h>
#include <stdlib.h>
#include "CDataframe.h"
#define INITIAL_COLUMNS 8

CDATAFRAME* create_cdataframe() {
    // Allocate memory for the CDataframe structure
    CDATAFRAME *cdataframe = (CDATAFRAME *) malloc(sizeof(CDATAFRAME));
    if (cdataframe == NULL) {
        return 0;
    }

    // Allocate memory for the columns of the CDataframe
    cdataframe->columns = (COLUMN **) malloc(INITIAL_COLUMNS * sizeof(COLUMN *));
    if (cdataframe->columns == NULL) {
        return 0;
    }
    cdataframe->number_columns= INITIAL_COLUMNS;
    cdataframe->number_rows = 0;

    return cdataframe;
}


void fill_cdataframe(CDATAFRAME* cdataframe) {
    printf("Enter the size of the data frame:");
    scanf(" %d", &cdataframe->number_columns);

    if (cdataframe->number_columns > 0) {
        printf("Enter the number of rows:");
        scanf(" %d", &cdataframe->number_rows);

        cdataframe->columns = (COLUMN **)malloc(cdataframe->number_columns * sizeof(COLUMN *));
        if (cdataframe->columns == NULL) {
            return;
        }

        for (int i = 0; i < cdataframe->number_columns; i++) {
            // Allocate and stores the column title
            char *title = (char *) malloc(sizeof(char) * 100);
            printf("Enter the title of column %d:", i );
            scanf(" %s", title);
            COLUMN* column = create_column(title);

            for (int j = 0; j < cdataframe->number_rows; j++) {
                int value;
                // scanf each value of the column
                printf("Enter the element of column %s at position %d:", title, j);
                scanf("%d", &value);
                insert_value(column, value);
            }
            cdataframe->columns[i] = column;
        }
    }
}

/* Hard filling of the CDataframe */


void display_cdataframe(CDATAFRAME* cdataframe){
    for (int i=0; i < cdataframe->number_columns; i++){
        printf("%s \n", cdataframe->columns[i]->title);
        print_col(cdataframe->columns[i]);
    }
}


void display_limited_rows_cdataframe(CDATAFRAME* cdataframe, int start, int end) {
    if (start < 0 || start >= cdataframe->number_rows || end < 0 || end >= cdataframe->number_rows || start > end) {
        printf("Invalid range\n");
        return;
    }
    for (int i = 0; i < cdataframe->number_columns; i++) {
        printf("%s \n", cdataframe->columns[i]->title);
        for (int j = start; j <= end; j++) {
            if (j < cdataframe->columns[i]->logical_size) {
                printf("[%d] %d\n", j, cdataframe->columns[i]->data[j]);
            }
        }
    }
}

void display_limited_columns_cdataframe(CDATAFRAME* cdataframe, int start, int end) {
    if (start < 0 || start >= cdataframe->number_columns || end < 0 || end >= cdataframe->number_columns || start > end) {
        printf("Invalid range\n");
        return;
    }
    for (int i = start; i <= end; i++) {
        printf("%s \n", cdataframe->columns[i]->title);
        print_col(cdataframe->columns[i]);
    }
}


void display_number_of_rows(CDATAFRAME* cdataframe) {
    printf("Number of rows: %d\n", cdataframe->number_rows);
}


void display_number_of_columns(CDATAFRAME* cdataframe) {
    printf("Number of columns: %d\n", cdataframe->number_columns);
}

void display_name_of_columns(CDATAFRAME* cdataframe) {
    for (int i = 0; i < cdataframe->number_columns; i++) {
        printf("Title of column %d: %s\n", i, cdataframe->columns[i]->title);
    }
}

int count_cells_condition(CDATAFRAME* cdataframe, int x, char op) {
    int count = 0;
    for (int i = 0; i < cdataframe->number_columns; i++) {
        for (int j = 0; j < cdataframe->columns[i]->logical_size; j++) {
            switch (op) {
                case '=':
                    if (cdataframe->columns[i]->data[j] == x) {
                        count++;
                    }
                    break;
                case '>':
                    if (cdataframe->columns[i]->data[j] > x) {
                        count++;
                    }
                    break;
                case '<':
                    if (cdataframe->columns[i]->data[j] < x) {
                        count++;
                    }
                    break;
                default:
                    printf("Invalid comparison symbol\n");
                    return -1;
            }
        }
    }
    return count;
}


void add_row_to_cdataframe(CDATAFRAME* cdataframe) {
    for (int i = 0; i < cdataframe->number_columns; i++) {
        int value;
        printf("Enter the value for column '%s' row number %d:", cdataframe->columns[i]->title, (cdataframe->number_rows)+1);
        scanf("%d", &value);
        insert_value(cdataframe->columns[i], value);
    }

    // Increment the number of rows in the Cdataframe
    cdataframe->number_rows++;
}

void delete_row_from_cdataframe(CDATAFRAME* cdataframe, int row) {
    if (row < 0 || row >= cdataframe->number_rows)
        return;
    for (int i = 0; i < cdataframe->number_columns; i++) {
        for (int j = row; j < cdataframe->number_rows - 1; j++) {
            cdataframe->columns[i]->data[j] = cdataframe->columns[i]->data[j + 1];
        }
        cdataframe->columns[i]->logical_size = cdataframe->columns[i]->logical_size-1;
    }
    // Decrement the number of rows in the Cdataframe
    cdataframe->number_rows--;
}

void add_column_to_cdataframe(CDATAFRAME* cdataframe){
    char *title = (char *) malloc(sizeof(char) * 100);
    printf("Enter the title of column %d:", cdataframe->number_columns+1);
    scanf(" %s", title);
    COLUMN* column = create_column(title);
    for (int j = 0; j < cdataframe->number_rows; j++) {
        int value;
        // scanf each value of the column
        printf("Enter the element of column %s at position %d:", title, j);
        scanf("%d", &value);
        insert_value(column, value);
    }
    cdataframe->columns[cdataframe->number_columns] = column;
    cdataframe->number_columns++;
}

void delete_column_to_cdataframe(CDATAFRAME* cdataframe, int column){
    if (column < 0 || column >= cdataframe->number_columns)
        return;
    for (int i = column; i < cdataframe->number_columns - 1; i++) {
        for (int j = 0; j < cdataframe->number_rows; j++) {
            cdataframe->columns[i]->data[j] = cdataframe->columns[i+1]->data[j];
            rename_column(cdataframe,i, cdataframe->columns[i+1]->title);
        }
    }
    // Decrement the number of columns in the Cdataframe
    cdataframe->number_columns--;
}

void rename_column(CDATAFRAME* cdataframe, int column, char* new_title){
    if (column < 0 || column >= cdataframe->number_columns) {
        printf("Invalid column index\n");
        return;
    }
    cdataframe->columns[column]->title = new_title;
}


int check_if_value_exists(CDATAFRAME* cdataframe, int value) {
    // Returns 1 if the value exist in the CDataframe, else returns -1
    for (int i = 0; i < cdataframe->number_columns; i++) {
        for (int j = 0; j < cdataframe->columns[i]->logical_size; j++) {
            if (cdataframe->columns[i]->data[j] == value) {
                return 1;
            }
        }
    }
    return -1;
}

int access_value(CDATAFRAME* cdataframe, int column, int row){
    if ((column < 0 || column >= cdataframe->number_columns)||(row < 0 || row >= cdataframe->number_rows)) {
        return -1;
    }
    return cdataframe->columns[column]->data[row];
}

void replace_value(CDATAFRAME* cdataframe, int column, int row, int new_val) {
    if ((column < 0 || column >= cdataframe->number_columns) || (row < 0 || row >= cdataframe->number_rows)){
        return;
    }
    cdataframe->columns[column]->data[row]=new_val;
}