#include "column.h"
#include "CDataframe.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#define ASC 0
#define DESC 1

void print_function_table() {
    printf("\n\n1  - Create a new CDATAFRAME\n");
    printf("2  - Fill a CDATAFRAME with data\n");
    printf("3  - Hard fill a CDATAFRAME\n");
    printf("4  - Display the contents of a CDATAFRAME\n");
    printf("5  - Display a limited range of rows in a CDATAFRAME\n");
    printf("6  - Display a limited range of columns in a CDATAFRAME\n");
    printf("7  - Add a row to a CDATAFRAME\n");
    printf("8  - Delete a row from a CDATAFRAME\n");
    printf("9  - Add a column to a CDATAFRAME\n");
    printf("10 - Delete a column from a CDATAFRAME\n");
    printf("11 - Rename a column in a CDATAFRAME\n");
    printf("12 - Check if a value exists in a CDATAFRAME\n");
    printf("13 - Access a value in a CDATAFRAME\n");
    printf("14 - Replace a value in a CDATAFRAME\n");
    printf("15 - Display the number of rows in a CDATAFRAME\n");
    printf("16 - Display the number of columns in a CDATAFRAME\n");
    printf("17 - Display the names of columns in a CDATAFRAME\n");
    printf("18 - Count cells in a CDATAFRAME based on a condition\n");
    printf("19 - Sort a column\n");
    printf("20 - Print a column by index\n");
    printf("21 - Erase index of a column\n");
    printf("22 - Check if index exists in a column\n");
    printf("23 - Update index of a column\n");
    printf("24 - Search for a value in a column\n");
    printf("25 - Leave the program\n");
}

int main() {
    CDATAFRAME *cdataframe = NULL;
    int cdataframe_index_1,cdataframe_index_2 ,option;
    char *string = (char *) malloc(sizeof(char) * 100);

    print_function_table();
    while (1) {
        printf("\nEnter the number associated with the function. If you want the list of commands and their numbers, type 0 :");
        scanf("%d", &option);

        switch (option) {
            case 0:
                print_function_table();
                break;

            case 1:
                cdataframe = create_cdataframe();
                printf("\nA CDATAFRAME has been created\n");
                break;

            case 2:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    fill_cdataframe(cdataframe);
                    printf("\nA CDATAFRAME has been hard-filled\n");
                }
                break;

            case 3:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    hard_fill(cdataframe);
                }
                break;

            case 4:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\n\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2 or 9\n");
                }
                else{
                    display_cdataframe(cdataframe);
                }
                break;

            case 5:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    printf("Enter a starting index :");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter a ending index :");
                    scanf("%d", &cdataframe_index_2);
                    display_limited_rows_cdataframe(cdataframe,cdataframe_index_1,cdataframe_index_2);
                }
                break;

            case 6:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    printf("Enter a starting index :");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter a ending index :");
                    scanf("%d", &cdataframe_index_2);
                    display_limited_columns_cdataframe(cdataframe,cdataframe_index_1,cdataframe_index_2);
                }
                break;

            case 7:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\n\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2 or 9\n");
                }
                else{
                    add_row_to_cdataframe(cdataframe);
                    printf("\nA row has been added\n");
                }
                break;

            case 8:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\n\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2 or 9\n");
                }
                else{
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    delete_row_from_cdataframe( cdataframe, cdataframe_index_1);
                    printf("\nA row has been deleted\n");
                }
                break;

            case 9:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    add_column_to_cdataframe(cdataframe);
                    printf("\nA column has been added\n");
                }
                break;

            case 10:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\n\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2 or 9\n");
                }
                else{
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    delete_column_from_cdataframe( cdataframe, cdataframe_index_1);
                    printf("\nA column has been deleted\n");
                }
                break;

            case 11:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\n\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2 or 9\n");
                }
                else {
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter the new title of column %d :", cdataframe_index_1);
                    scanf("%s", string);
                    rename_column(cdataframe, cdataframe_index_1, string);
                    printf("\nA column has been renamed\n");
                }
                break;

            case 12:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    ENUM_TYPE data_type;
                    void* val_check_cdataframe;
                    printf("\n1-NULLVAL\n2-UINT\n3-INT\n4-CHAR\n5-FLOAT\n6-DOUBLE\n7-STRING\nEnter the type of data to seach for:");
                    scanf("%d", (int *)&data_type);
                    switch (data_type) {
                        case NULLVAL :{
                            val_check_cdataframe=NULL;
                            break;
                        }
                        case UINT :{
                            unsigned int uint_value;
                            printf("Enter the unsigned integer value to search for :\n");
                            scanf("%u", &uint_value);
                            val_check_cdataframe = malloc(sizeof(unsigned int));
                            *((unsigned int*)val_check_cdataframe) = uint_value;
                            break;
                        }
                        case INT :{
                            int int_value;
                            printf("Enter the integer value to search for :\n");
                            scanf("%d", &int_value);
                            val_check_cdataframe = malloc(sizeof(int));
                            *((int*)val_check_cdataframe) = int_value;
                            break;
                        }
                        case CHAR :{
                            char char_value;
                            printf("Enter the character value to search for :\n");
                            scanf(" %c", &char_value);
                            val_check_cdataframe = malloc(sizeof(char));
                            *((char*)val_check_cdataframe) = char_value;
                            break;
                        }
                        case FLOAT :{
                            float float_value;
                            printf("Enter the float value to search for :\n");
                            scanf("%f", &float_value);
                            val_check_cdataframe = malloc(sizeof(float));
                            *((float*)val_check_cdataframe) = float_value;
                            break;
                        }
                        case DOUBLE :{
                            double double_value;
                            printf("Enter the double value to search for :\n");
                            scanf("%lf", &double_value);
                            val_check_cdataframe = malloc(sizeof(double));
                            *((double*)val_check_cdataframe) = double_value;
                            break;
                        }
                        case STRING :{
                            char* string_value = (char*)malloc(sizeof(char) * 100);
                            printf("Enter the string value to search for :\n");
                            scanf("%s", string_value);
                            val_check_cdataframe = string_value;
                            break;
                        }
                        default:
                            printf("Unsupported type, try again\n");
                            break;
                    }
                    if(check_if_value_exists_in_cdataframe(cdataframe, data_type, val_check_cdataframe)==1){
                        printf("Value exist in the CDataframe\n");
                    }
                    else if(check_if_value_exists_in_cdataframe(cdataframe, data_type, val_check_cdataframe)==-1){
                        printf("Value does not exist in the CDataframe\n");
                    }
                }
                break;

            case 13:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else {
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter a row number :");
                    scanf("%d", &cdataframe_index_2);
                    convert_value(cdataframe->columns[cdataframe_index_1], cdataframe_index_2, string,
                                  cdataframe->columns[cdataframe_index_1]->size);
                }
                break;

            case 14:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else {
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter a row number :");
                    scanf("%d", &cdataframe_index_2);
                    ENUM_TYPE value_type = cdataframe->columns[cdataframe_index_1]->column_type;
                    void* new_value;
                    switch (value_type) {
                        case NULLVAL :{
                            printf("NULLVAL type is not supported\n");
                            break;
                        }
                        case UINT :{
                            unsigned int new_uint_value;
                            printf("Enter a new unsigned integer value :");
                            scanf("%u", &new_uint_value);
                            new_value = malloc(sizeof(unsigned int));
                            *((unsigned int*)new_value) = new_uint_value;
                            break;
                        }
                        case INT :{
                            int new_int_value;
                            printf("Enter a new integer value :");
                            scanf("%d", &new_int_value);
                            new_value = malloc(sizeof(int));
                            *((int*)new_value) = new_int_value;
                            break;
                        }
                        case CHAR :{
                            char new_char_value;
                            printf("Enter a new character value :");
                            scanf(" %c", &new_char_value);
                            new_value = malloc(sizeof(char));
                            *((char*)new_value) = new_char_value;
                            break;
                        }
                        case FLOAT :{
                            float new_float_value;
                            printf("Enter a new float value :");
                            scanf("%f", &new_float_value);
                            new_value = malloc(sizeof(float));
                            *((float*)new_value) = new_float_value;
                            break;
                        }
                        case DOUBLE :{
                            double new_double_value;
                            printf("Enter a new double value :");
                            scanf("%lf", &new_double_value);
                            new_value = malloc(sizeof(double));
                            *((double*)new_value) = new_double_value;
                            break;
                        }
                        case STRING :{
                            char* new_string_value = (char*)malloc(sizeof(char) * 100);
                            printf("Enter a new string value :");
                            scanf("%s", new_string_value);
                            new_value = new_string_value;
                            break;
                        }
                    }
                    replace_value(cdataframe, cdataframe_index_1, cdataframe_index_2, value_type, new_value);
                    printf("\nA value has been replaced\n");
                }
                break;

            case 15:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    display_number_of_rows(cdataframe);
                }
                break;

            case 16:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    display_number_of_columns(cdataframe);
                }
                break;

            case 17:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    display_name_of_columns(cdataframe);
                }
                break;

            case 18:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else {
                    ENUM_TYPE data_type;
                    void *value_to_compare;
                    int op_choice;
                    char op;
                    printf("\n1-NULLVAL\n2-UINT\n3-INT\n4-CHAR\n5-FLOAT\n6-DOUBLE\n7-STRING\nEnter the type of data to compare:");
                    scanf("%d", (int *) &data_type);
                    switch (data_type) {
                        case NULLVAL:{
                            printf("Can't operate comparisons with NULL values\n");
                            break;
                        }
                        case UINT :{
                            unsigned int uint_value;
                            printf("Enter x (an unsigned integer) :");
                            scanf("%u", &uint_value);
                            value_to_compare = malloc(sizeof(unsigned int));
                            *((unsigned int *) value_to_compare) = uint_value;
                            break;
                        }
                        case INT :{
                            int int_value;
                            printf("Enter x (an integer) :");
                            scanf("%d", &int_value);
                            value_to_compare = malloc(sizeof(int));
                            *((int *) value_to_compare) = int_value;
                            break;
                        }
                        case CHAR :{
                            char char_value;
                            printf("Enter x (a character) :");
                            scanf(" %c", &char_value);
                            value_to_compare = malloc(sizeof(char));
                            *((char *) value_to_compare) = char_value;
                            break;
                        }
                        case FLOAT :{
                            float float_value;
                            printf("Enter x (a float) :");
                            scanf("%f", &float_value);
                            value_to_compare = malloc(sizeof(float));
                            *((float *) value_to_compare) = float_value;
                            break;
                        }
                        case DOUBLE :{
                            double double_value;
                            printf("Enter x (a double) :");
                            scanf("%lf", &double_value);
                            value_to_compare = malloc(sizeof(double));
                            *((double *) value_to_compare) = double_value;
                            break;
                        }
                        case STRING :{
                            char *string_value = (char *) malloc(sizeof(char) * 100);
                            printf("Enter x (a string) :");
                            scanf("%s", string_value);
                            value_to_compare = string_value;
                            break;
                        }
                        default:
                            printf("Unsupported type, try again\n");
                            break;
                    }
                    if(data_type!=NULLVAL){
                        printf("\n1- equal to (=)\n2- greater than (>)\n3- less than (<)\nChoose one operator:");
                        scanf("%d", &op_choice);
                        // Need to handle errors
                        switch (op_choice){
                            case 1:
                                op = '=';
                                printf("There is %d values equal to x\n", count_cells_condition(cdataframe, data_type, value_to_compare, op), op);
                                break;
                            case 2:
                                op = '>';
                                printf("There is %d values greater than x\n", count_cells_condition(cdataframe, data_type, value_to_compare, op), op);
                                break;
                            case 3:
                                op = '<';
                                printf("There is %d values less than x\n", count_cells_condition(cdataframe, data_type, value_to_compare, op), op);
                                break;
                            default:
                                printf("Invalid choice\n");
                                break;
                        }
                    }
                }
                break;

            case 19:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else {
                    int sort_dir, dir_choice;
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    printf("\n1- Ascending order\n2- Descending order\nChoose the order you want to sort in:");
                    scanf("%d",&dir_choice);
                    switch(dir_choice){
                        case 1:
                            sort_dir=ASC;
                            sort(cdataframe->columns[cdataframe_index_1],sort_dir);
                            printf("\nA column has been sorted\n");
                            break;
                        case 2:
                            sort_dir=DESC;
                            sort(cdataframe->columns[cdataframe_index_1],sort_dir);
                            printf("\nA column has been sorted\n");
                            break;
                        default:
                            printf("Invalid choice\n");
                            break;
                    }
                }
                break;

            case 20:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else {
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    print_col_by_index(cdataframe->columns[cdataframe_index_1]);
                }
                break;

            case 21:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else {
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    erase_index(cdataframe->columns[cdataframe_index_1]);
                    if (cdataframe->columns[0]->index == NULL) {
                        printf("Memory has been successfully freed\n");
                    }
                    else {
                        printf("Memory has not been freed\n");
                    }
                }
                break;

            case 22:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else {
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    int index_status = check_index(cdataframe->columns[cdataframe_index_1]);
                    if (index_status == 1) {
                        printf("Index is correct\n");
                    }
                    else if (index_status == -1) {
                        printf("Index exists but is invalid\n");
                    }
                    else {
                        printf("Index does not exist\n");
                    }
                }
                break;

            case 23:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else {
                    int sort_dir, dir_choice;
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    printf("\n1- Ascending order\n2- Descending order\nChoose the order you want to sort in:");
                    scanf("%d",&dir_choice);
                    switch(dir_choice){
                        case 1:
                            sort_dir=ASC;
                            update_index(cdataframe->columns[cdataframe_index_1],sort_dir);
                            printf("\nA index has been updated\n");
                            break;
                        case 2:
                            sort_dir=DESC;
                            update_index(cdataframe->columns[cdataframe_index_1],sort_dir);
                            printf("\nA index has been updated\n");
                            break;
                        default:
                            printf("Invalid choice\n");
                            break;
                    }
                }
                break;

            case 24:
                if (cdataframe==NULL){
                    printf("\n\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    COLUMN *column;
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    column=cdataframe->columns[cdataframe_index_1];
                    ENUM_TYPE column_type=column->column_type;
                    void* value;
                    switch (column_type) {
                        case NULLVAL :{
                            value=NULL;
                            break;
                        }
                        case UINT :{
                            unsigned int new_uint_value;
                            printf("Enter an unsigned integer value :");
                            scanf("%u", &new_uint_value);
                            value = malloc(sizeof(unsigned int));
                            *((unsigned int*)value) = new_uint_value;
                            break;
                        }
                        case INT :{
                            int new_int_value;
                            printf("Enter an integer value :");
                            scanf("%d", &new_int_value);
                            value = malloc(sizeof(int));
                            *((int*)value) = new_int_value;
                            break;
                        }
                        case CHAR :{
                            char new_char_value;
                            printf("Enter a character value :");
                            scanf(" %c", &new_char_value);
                            value = malloc(sizeof(char));
                            *((char*)value) = new_char_value;
                            break;
                        }
                        case FLOAT :{
                            float new_float_value;
                            printf("Enter a float value :");
                            scanf("%f", &new_float_value);
                            value = malloc(sizeof(float));
                            *((float*)value) = new_float_value;
                            break;
                        }
                        case DOUBLE :{
                            double new_double_value;
                            printf("Enter a double value :");
                            scanf("%lf", &new_double_value);
                            value = malloc(sizeof(double));
                            *((double*)value) = new_double_value;
                            break;
                        }
                        case STRING :{
                            char* new_string_value = (char*)malloc(sizeof(char) * 100);
                            printf("Enter a string value :");
                            scanf("%s", new_string_value);
                            value = new_string_value;
                            break;
                        }
                        default:
                            printf("Unsupported type, try again\n");
                            break;
                    }
                    if(search_value_in_column(column, value)==1){
                        printf("Value has been found\n");
                    }
                    else if(search_value_in_column(column, value)==0){
                        printf("Value has not been found\n");
                    }
                    else if(search_value_in_column(column, value)==-1){
                        printf("Column is not sorted, please sort it using command number 19 or 23\n");
                    }
                }
                break;

            case 25:
                return 0;

            default:
                printf("Invalid number, try again\n");
                break;
        }
    }
    return 0;
}
