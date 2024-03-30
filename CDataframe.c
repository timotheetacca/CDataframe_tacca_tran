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
    char title[100];

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
            printf("Enter the title of column %d:", i + 1);
            scanf(" %s", title);
            COLUMN* column = create_column(title);
            for (int j = 0; j < cdataframe->number_rows; j++) {
                int value;
                printf("Enter the element of column %s at position %d:", title, j + 1);
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