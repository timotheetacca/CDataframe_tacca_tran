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
                // scanf each vvalue of the column
                printf("Enter the element of column %s at position %d:", title, j);
                scanf("%d", &value);
                insert_value(column, value);
            }
            cdataframe->columns[i] = column;
        }
    }
}


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


