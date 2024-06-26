// CDataframe TACCA - TRAN    Interaction with the user and main usage of the functions
#include "column.h"
#include "CDataframe.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#define ASC 0
#define DESC 1


// Print all the functions available; no return as the function only displays information
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
    printf("25 - Delete the CDataframe\n");
    printf("26 - Leave the program\n");
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    fill_cdataframe(cdataframe);
                }
                break;

            case 3:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    hard_fill(cdataframe);
                    printf("\nA CDATAFRAME has been hard-filled\n");
                }
                break;

            case 4:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else{
                    display_cdataframe(cdataframe);
                }
                break;

            case 5:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else{
                    add_row_to_cdataframe(cdataframe);
                    printf("\nA row has been added\n");
                }
                break;

            case 8:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else{
                    printf("Enter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    delete_row_from_cdataframe( cdataframe, cdataframe_index_1);
                }
                break;

            case 9:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    add_column_to_cdataframe(cdataframe);
                    printf("\nA column has been added\n");
                }
                break;

            case 10:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else{
                    printf("\nEnter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    delete_column_from_cdataframe( cdataframe, cdataframe_index_1);
                }
                break;

            case 11:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else {
                    printf("\nEnter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter the new title of column %d :", cdataframe_index_1);
                    scanf("%s", string);
                    rename_column(cdataframe, cdataframe_index_1, string);
                    printf("\nA column has been renamed\n");
                }
                break;

            case 12:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
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
                        printf("\nValue exist in the CDataframe\n");
                    }
                    else if(check_if_value_exists_in_cdataframe(cdataframe, data_type, val_check_cdataframe)==-1){
                        printf("\nValue does not exist in the CDataframe\n");
                    }
                    else if(check_if_value_exists_in_cdataframe(cdataframe, data_type, val_check_cdataframe)==0){
                        printf("\nCan't use this function with NULLVAL\n");
                    }
                }
                break;

            case 13:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else {
                    printf("\nEnter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter a row number :");
                    scanf("%d", &cdataframe_index_2);
                    convert_value(cdataframe->columns[cdataframe_index_1], cdataframe_index_2, string,
                                  cdataframe->columns[cdataframe_index_1]->size);
                    printf("\n%s\n[%d] %s\n",cdataframe->columns[cdataframe_index_1]->title ,cdataframe_index_2, string);
                }
                break;

            case 14:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else {
                    printf("\nEnter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter a row number :");
                    scanf("%d", &cdataframe_index_2);
                    ENUM_TYPE value_type = cdataframe->columns[cdataframe_index_1]->column_type;
                    void* new_value;
                    switch (value_type) {
                        case NULLVAL :{
                            printf("Can't use this function with NULLVAL\n");
                            break;
                        }
                        case UINT :{
                            new_value = (unsigned int *) malloc(sizeof(unsigned int));
                            printf("Enter a new unsigned integer value :");
                            scanf("%lf", new_value);
                            printf("\nA value has been replaced\n");
                            break;
                        }
                        case INT :{
                            new_value = (int *) malloc(sizeof(int));
                            printf("Enter a new int value :");
                            scanf("%d", new_value);
                            printf("\nA value has been replaced\n");
                            break;
                        }
                        case CHAR :{
                            char new_char_value;
                            new_value = (char *) malloc(sizeof(char));
                            printf("Enter a new char value :");
                            scanf("%c", new_value);
                            printf("\nA value has been replaced\n");
                            break;
                        }
                        case FLOAT :{
                            new_value = (float *) malloc(sizeof(float));
                            printf("Enter a new float value :");
                            scanf("%f", new_value);
                            printf("\nA value has been replaced\n");
                            break;
                        }
                        case DOUBLE :{
                            new_value = (double *) malloc(sizeof(double));
                            printf("Enter a new double value :");
                            scanf("%lf", new_value);
                            printf("\nA value has been replaced\n");
                            break;
                        }
                        case STRING :{
                            new_value = (char*) malloc(sizeof(char) * 100);
                            printf("Enter a new string value :");
                            scanf("%s", new_value);
                            printf("\nA value has been replaced\n");
                            break;
                        }
                    }
                    replace_value(cdataframe, cdataframe_index_1, cdataframe_index_2, value_type, new_value);
                    free(new_value);

                }
                break;

            case 15:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    display_number_of_rows(cdataframe);
                }
                break;

            case 16:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    display_number_of_columns(cdataframe);
                }
                break;

            case 17:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else{
                    display_name_of_columns(cdataframe);
                }
                break;

            case 18:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
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
                            printf("Can't use this function with NULLVAL\n");
                            break;
                        }
                        case UINT :{
                            unsigned int uint_value;
                            printf("Enter an unsigned integer :");
                            scanf("%u", &uint_value);
                            value_to_compare = malloc(sizeof(unsigned int));
                            *((unsigned int *) value_to_compare) = uint_value;
                            break;
                        }
                        case INT :{
                            int int_value;
                            printf("Enter an integer :");
                            scanf("%d", &int_value);
                            value_to_compare = malloc(sizeof(int));
                            *((int *) value_to_compare) = int_value;
                            break;
                        }
                        case CHAR :{
                            char char_value;
                            printf("Enter a character :");
                            scanf(" %c", &char_value);
                            value_to_compare = malloc(sizeof(char));
                            *((char *) value_to_compare) = char_value;
                            break;
                        }
                        case FLOAT :{
                            float float_value;
                            printf("Enter a float :");
                            scanf("%f", &float_value);
                            value_to_compare = malloc(sizeof(float));
                            *((float *) value_to_compare) = float_value;
                            break;
                        }
                        case DOUBLE :{
                            double double_value;
                            printf("Enter a double :");
                            scanf("%lf", &double_value);
                            value_to_compare = malloc(sizeof(double));
                            *((double *) value_to_compare) = double_value;
                            break;
                        }
                        case STRING :{
                            char *string_value = (char *) malloc(sizeof(char) * 100);
                            printf("Enter a string :");
                            scanf("%s", string_value);
                            value_to_compare = string_value;
                            break;
                        }
                        default:
                            printf("Unsupported type, try again\n");
                            break;
                    }
                    if(data_type!=NULLVAL){
                        printf("\n1-Equal to (=)\n2-Greater than (>)\n3-Less than (<)\nChoose one operator:");
                        scanf("%d", &op_choice);
                        switch (op_choice){
                            case 1:
                                op = '=';
                                printf("There is %d values equal to the chosen value\n", count_cells_condition(cdataframe, data_type, value_to_compare, op), op);
                                break;
                            case 2:
                                op = '>';
                                printf("There is %d values greater than the chosen value\n", count_cells_condition(cdataframe, data_type, value_to_compare, op), op);
                                break;
                            case 3:
                                op = '<';
                                printf("There is %d values less than the chosen value\n", count_cells_condition(cdataframe, data_type, value_to_compare, op), op);
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else {
                    int sort_dir, dir_choice;
                    printf("\nEnter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    printf("\n1-Ascending order\n2-Descending order\nChoose the order you want to sort in:");
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else {
                    printf("\nEnter a column number :");
                    scanf("%d", &cdataframe_index_1);
                    print_col_by_index(cdataframe->columns[cdataframe_index_1]);
                }
                break;

            case 21:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else {
                    printf("\nEnter a column number :");
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else {
                    printf("\nEnter a column number :");
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else {
                    int sort_dir, dir_choice;
                    printf("\nEnter a column number :");
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2,3 or 9\n");
                }
                else{
                    COLUMN *column;
                    printf("\nEnter a column number :");
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
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n");
                }
                else {
                    delete_cdataframe(cdataframe);
                    printf("\nA CDataframe has been deleted\n");
                }
                break;
            case 26:
                return 0;

            default:
                printf("Invalid number, try again\n");
                break;
        }
    }
    return 0;
}
