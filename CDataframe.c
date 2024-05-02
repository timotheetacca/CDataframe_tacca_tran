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
            cdataframe->columns[i]->index[cdataframe->columns[i]->size] = cdataframe->columns[i]->size;
            switch (column_type) {
                case NULLVAL:{
                    insert_value(cdataframe->columns[i], NULL);
                    break;
                }
                case UINT: {
                    unsigned int value;
                    printf("Enter the element of column %s at position %d: ", title, j );
                    scanf("%u", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case INT: {
                    int value;
                    printf("Enter the element of column %s at position %d: ", title, j);
                    scanf("%d", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case CHAR: {
                    char value;
                    printf("Enter the element of column %s at position %d: ", title, j);
                    scanf(" %c", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case FLOAT: {
                    float value;
                    printf("Enter the element of column %s at position %d: ", title, j);
                    scanf("%f", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case DOUBLE: {
                    double value;
                    printf("Enter the element of column %s at position %d: ", title, j);
                    scanf("%lf", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case STRING: {
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

void display_limited_rows_cdataframe(CDATAFRAME* cdataframe, int start, int end) {
    if (start < 0 || start >= cdataframe->number_rows || end < 0 || end >= cdataframe->number_rows || start > end) {
        printf("Invalid range\n");
        return;
    }
    for (int i = 0; i < cdataframe->number_columns; i++) {
        printf("%s \n", cdataframe->columns[i]->title);
        for (int j = start; j <= end; j++) {
            if (j < cdataframe->columns[i]->size) {
                printf("[%d] ", j);
                if (cdataframe->columns[i]->data[i] == NULL) {
                    printf("NULL\n");
                }
                else {
                    char str[100];
                    convert_value(cdataframe->columns[i], i, str, sizeof(str));
                    printf("%s\n", str);

                }
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


void add_row_to_cdataframe(CDATAFRAME* cdataframe) {
    for (int i = 0; i < cdataframe->number_columns; i++) {
        void *value;
        printf("Enter the element of type %u for column '%s' row number %d:", cdataframe->columns[i]->column_type, cdataframe->columns[i]->title, (cdataframe->number_rows));
        switch (cdataframe->columns[i]->column_type) {
            case UINT: {
                unsigned int *val = malloc(sizeof(unsigned int));
                scanf("%u", val);
                value = val;
                break;
            }
            case INT: {
                int *val = malloc(sizeof(int));
                scanf("%d", val);
                value = val;
                break;
            }
            case CHAR: {
                char *val = malloc(sizeof(char));
                scanf(" %c", val);
                value = val;
                break;
            }
            case FLOAT: {
                float *val = malloc(sizeof(float));
                scanf("%f", val);
                value = val;
                break;
            }
            case DOUBLE: {
                double *val = malloc(sizeof(double));
                scanf("%lf", val);
                value = val;
                break;
            }
            case STRING: {
                char *val = malloc(sizeof(char) * 100);
                scanf("%s", val);
                value = val;
                break;
            }
            default:
                printf("Unsupported type\n");
                return;
        }
        insert_value(cdataframe->columns[i], value);
    }
    cdataframe->number_rows++;
}


void delete_row_from_cdataframe(CDATAFRAME* cdataframe, int row) {
    if (row < 0 || row >= cdataframe->number_rows)
        return;
    for (int i = 0; i < cdataframe->number_columns; i++) {
        for (int j = row; j < cdataframe->number_rows - 1; j++) {
            cdataframe->columns[i]->data[j] = cdataframe->columns[i]->data[j + 1];
        }
        cdataframe->columns[i]->size = cdataframe->columns[i]->size-1;
    }
    // Decrement the number of rows in the Cdataframe
    cdataframe->number_rows--;
}

void add_column_to_cdataframe(CDATAFRAME* cdataframe){
    ENUM_TYPE column_type;
    char *title = (char *) malloc(sizeof(char) * 100);
    printf("Enter the title of the new column: ");
    scanf("%s", title);
    printf("\n1-NULLVAL\n2-UINT\n3-INT\n4-CHAR\n5-FLOAT\n6-DOUBLE\n7-STRING\n\nEnter the type of data for column %s:", title);
    scanf("%d", (int *)&column_type);
    COLUMN* new_column = create_column(column_type, title);
    for (int i = 0; i < cdataframe->number_rows; i++) {
        switch (column_type) {
            case NULLVAL:{
                insert_value(new_column, NULL);
                break;
            }
            case UINT: {
                unsigned int value;
                printf("Enter the element of column %s at position %d: ", title, i);
                scanf("%u", &value);
                insert_value(new_column, &value);
                break;
            }
            case INT: {
                int value;
                printf("Enter the element of column %s at position %d: ", title, i);
                scanf("%d", &value);
                insert_value(new_column, &value);
                break;
            }
            case CHAR: {
                char value;
                printf("Enter the element of column %s at position %d: ", title, i);
                scanf(" %c", &value);
                insert_value(new_column, &value);
                break;
            }
            case FLOAT: {
                float value;
                printf("Enter the element of column %s at position %d: ", title, i);
                scanf("%f", &value);
                insert_value(new_column, &value);
                break;
            }
            case DOUBLE: {
                double value;
                printf("Enter the element of column %s at position %d: ", title, i);
                scanf("%lf", &value);
                insert_value(new_column, &value);
                break;
            }
            case STRING: {
                char *value = (char *) malloc(sizeof(char) * 100);
                printf("Enter the element of column %s at position %d: ", title, i);
                scanf("%s", value);
                insert_value(new_column, value);
                break;
            }
            default:
                printf("Unsupported type, try again\n");
                break;
        }
    }
    cdataframe->columns[cdataframe->number_columns] = new_column;
    cdataframe->number_columns++;
}


void delete_column_from_cdataframe(CDATAFRAME* cdataframe, int column){
    if (column < 0 || column >= cdataframe->number_columns)
        return;
    for (int i = column; i < cdataframe->number_columns - 1; i++) {
        for (int j = 0; j < cdataframe->number_rows; j++) {
            cdataframe->columns[i]->column_type = cdataframe->columns[i+1]->column_type;
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

int check_if_value_exists(CDATAFRAME* cdataframe, ENUM_TYPE value_type, void* value) {
    // Returns 1 if the value exist in the CDataframe, else returns -1
    for (int i = 0; i < cdataframe->number_columns; i++) {
        if (cdataframe->columns[i]->column_type == value_type) {
            for (int j = 0; j < cdataframe->number_rows; j++) {
                switch (value_type) {
                    case NULLVAL:
                        if (cdataframe->columns[i]->data[j] == NULL)
                            return 1;
                        break;
                    case UINT:
                        if (*((unsigned int*)cdataframe->columns[i]->data[j]) == value)
                            return 1;
                        break;
                    case INT:
                        if (*((int*)cdataframe->columns[i]->data[j]) == value)
                            return 1;
                        break;
                    case CHAR:
                        if (*((char*)cdataframe->columns[i]->data[j]) == value)
                            return 1;
                        break;
                    case FLOAT:
                        if (*((float*)cdataframe->columns[i]->data[j]) == *((float*)value))
                            return 1;
                        break;
                    case DOUBLE:
                        if (*((double*)cdataframe->columns[i]->data[j]) == *((double*)value))
                            return 1;
                        break;
                    case STRING: {
                        char *str1 = (char*)cdataframe->columns[i]->data[j];
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
    return -1;
}

void* access_value(CDATAFRAME* cdataframe, int column, int row){
    if ((column < 0 || column >= cdataframe->number_columns)||(row < 0 || row >= cdataframe->number_rows)) {
        return NULL;
    }
    return cdataframe->columns[column]->data[row];
}

void replace_value(CDATAFRAME* cdataframe, int column, int row, ENUM_TYPE value_type, void* new_val) {
    if ((column < 0 || column >= cdataframe->number_columns) || (row < 0 || row >= cdataframe->number_rows)){
        return;
    }
    if (cdataframe->columns[column]->column_type != value_type){
        printf("Incompatible data types. The value can't be replaced\n");
        return;
    }
    cdataframe->columns[column]->data[row]=new_val;
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

int count_cells_condition(CDATAFRAME* cdataframe, void* x, char op){

}
