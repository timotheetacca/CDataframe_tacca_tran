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

    cdataframe->columns = (COLUMN **) malloc(INITIAL_COLUMNS * sizeof(COLUMN *));
    if (cdataframe->columns == NULL) {
        return 0;
    }
    cdataframe->number_columns= 0;
    cdataframe->number_rows = 0;

    return cdataframe;
}

void fill_cdataframe(CDATAFRAME* cdataframe) {
    printf("Enter the number of columns in the dataframe:");
    scanf("%d", &cdataframe->number_columns);

    if (cdataframe->number_columns <= 0) {
        printf("Invalid number of columns\n");
        return;
    }

    printf("Enter the number of rows in the dataframe:");
    scanf("%d", &cdataframe->number_rows);

    if (cdataframe->number_rows <= 0) {
        printf("Invalid number of rows\n");
        return;
    }

    cdataframe->columns = (COLUMN **)malloc(cdataframe->number_columns * sizeof(COLUMN *));

    for (int i = 0; i < cdataframe->number_columns; i++) {
        char *title = (char *) malloc(sizeof(char) * 100);
        printf("Enter the title of column %d: ", i);
        scanf("%s", title);

        ENUM_TYPE column_type;
        printf("\n1-NULLVAL\n2-UINT\n3-INT\n4-CHAR\n5-FLOAT\n6-DOUBLE\n7-STRING\n\nEnter the type of data for column %s:", title);
        scanf("%d", (int *)&column_type);

        cdataframe->columns[i] = create_column(column_type, title);

        for (int j = 0; j < cdataframe->number_rows; j++) {
            switch (column_type) {
                case 1:{
                    insert_value(cdataframe->columns[i], NULL);
                    break;
                }
                case 2: {
                    unsigned int value;
                    printf("Enter the element of column %s at position %d: ", title, j );
                    scanf("%u", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 3: {
                    int value;
                    printf("Enter the element of column %s at position %d: ", title, j);
                    scanf("%d", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 4: {
                    char value;
                    printf("Enter the element of column %s at position %d: ", title, j);
                    scanf(" %c", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 5: {
                    float value;
                    printf("Enter the element of column %s at position %d: ", title, j);
                    scanf("%f", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 6: {
                    double value;
                    printf("Enter the element of column %s at position %d: ", title, j);
                    scanf("%lf", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 7: {
                    char *value = (char *) malloc(sizeof(char) * 100);
                    printf("Enter the element of column %s at position %d: ", title, j);
                    scanf("%s", value);
                    insert_value(cdataframe->columns[i], value);
                    break;
                }
                default:
                    printf("Unsupported type, try again\n");
                    break;
            }
        }
    }
}


void display_cdataframe(CDATAFRAME* cdataframe) {
    for (int i = 0; i < cdataframe->number_columns; i++) {
        printf("%s\n", cdataframe->columns[i]->title);
        print_col(cdataframe->columns[i]);
        printf("\n");
    }
}


