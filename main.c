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
    printf("25 - Leave the program\n\n");
}

int main() {
    CDATAFRAME *cdataframe = NULL;
    int cdataframe_index_1,cdataframe_index_2 ,option;
    char *string = (char *) malloc(sizeof(char) * 100);

    print_function_table();
    while (1) {
        printf("Enter the number associated with the function. If you want the list of commands and their numbers, type 0 :");
        scanf("%d", &option);

        switch (option) {
            case 0:
                print_function_table();
                break;

            case 1:
                cdataframe = create_cdataframe();
                printf("\nA CDATAFRAME has been created\n\n");
                break;

            case 2:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else{
                    fill_cdataframe(cdataframe);
                }
                break;

            case 3:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else{
                    // Hard fill
                }
                break;

            case 4:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else{
                    display_cdataframe(cdataframe);
                }
                break;

            case 5:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
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
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2 or 9\n\n");
                }
                else{
                    add_row_to_cdataframe(cdataframe);
                }
                break;

            case 8:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2 or 9\n\n");
                }
                else{
                    printf("Enter a column number: ");
                    scanf("%d", &cdataframe_index_1);
                    delete_row_from_cdataframe( cdataframe, cdataframe_index_1);
                }
                break;

            case 9:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else{
                    add_column_to_cdataframe(cdataframe);
                }
                break;

            case 10:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2 or 9\n\n");
                }
                else{
                    printf("Enter a column number: ");
                    scanf("%d", &cdataframe_index_1);
                    delete_column_from_cdataframe( cdataframe, cdataframe_index_1);
                }
                break;

            case 11:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else if (cdataframe->number_columns==0){
                    printf("\nTo use this function you need to create have at least 1 column in your CDATAFRAME, which you can do using command number 2 or 9\n\n");
                }
                else {
                    printf("Enter a column number: ");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter the new title of column %d: ", cdataframe_index_1);
                    scanf("%s", string);
                    rename_column(cdataframe, cdataframe_index_1, string);
                }
                break;

            case 12:
                // Check if a value exist
                break;

            case 13:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else {
                    printf("Enter a column number: ");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter a row number: ");
                    scanf("%d", &cdataframe_index_2);
                    convert_value(cdataframe->columns[cdataframe_index_1], cdataframe_index_2, string,
                                  cdataframe->columns[cdataframe_index_1]->size);
                }
                break;

            case 14:
                if (cdataframe==NULL){
                    printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                }
                else{
                    printf("Enter a column number: ");
                    scanf("%d", &cdataframe_index_1);
                    printf("Enter a row number: ");
                    scanf("%d", &cdataframe_index_2);
                    //replace_value(cdataframe,cdataframe_index_1, cdataframe_index_2, ENUM_TYPE value_type, void* new_val);
                    printf("Not finished");
                    break;

                    case 15:
                        if (cdataframe==NULL){
                            printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                        }
                        else{
                            display_number_of_rows(cdataframe);
                        }
                    break;

                    case 16:
                        if (cdataframe==NULL){
                            printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                        }
                        else{
                            display_number_of_columns(cdataframe);
                        }
                    break;

                    case 17:
                        if (cdataframe==NULL){
                            printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                        }
                        else{
                            display_name_of_columns(cdataframe);
                        }
                    break;

                    case 18:
                        // Count cells condition
                        break;

                    case 19:
                        if (cdataframe==NULL){
                            printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                        }
                        else {
                            printf("Enter a column number: ");
                            scanf("%d", &cdataframe_index_1);
                            sort(cdataframe->columns[cdataframe_index_1]);
                        }
                    break;

                    case 20:
                        if (cdataframe==NULL){
                            printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                        }
                        else {
                            printf("Enter a column number: ");
                            scanf("%d", &cdataframe_index_1);
                            print_col_by_index(cdataframe->columns[cdataframe_index_1]);
                        }
                    break;

                    case 21:
                        if (cdataframe==NULL){
                            printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                        }
                        else {
                            printf("Enter a column number: ");
                            scanf("%d", &cdataframe_index_1);
                            erase_index(cdataframe->columns[cdataframe_index_1]);
                            if (cdataframe->columns[0]->index == NULL) {
                                printf("Memory has been successfully freed\n");
                            } else {
                                printf("Memory has not been freed\n");
                            }
                        }
                    break;

                    case 22:
                        if (cdataframe==NULL){
                            printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                        }
                        else {
                            printf("Enter a column number: ");
                            scanf("%d", &cdataframe_index_1);
                            int index_status = check_index(cdataframe->columns[cdataframe_index_1]);
                            if (index_status == 1) {
                                printf("Index is correct\n");
                            } else if (index_status == -1) {
                                printf("Index exists but is invalid\n");
                            } else {
                                printf("Index does not exist\n");
                            }
                        }
                    break;

                    case 23:
                        if (cdataframe==NULL){
                            printf("\nTo use this function you need to create a CDATAFRAME, which you can do using command number 1\n\n");
                        }
                        else {
                            printf("Enter a column number: ");
                            scanf("%d", &cdataframe_index_1);
                            update_index(cdataframe->columns[cdataframe_index_1]);
                        }
                    break;

                    case 24:
                        // Search for a value
                        break;

                    case 25:
                        return 0;

                    default:
                        printf("Invalid number, try again\n");
                    break;
                }
        }
    }
    return 0;
}