#include "column.h"
#include "CDataframe.h"
#include "sort.h"
#include <stdio.h>
#define ASC 0
#define DESC 1

int main() {
    CDATAFRAME* cdataframe = create_cdataframe();
    fill_cdataframe(cdataframe);
    display_cdataframe(cdataframe);

    // First sorting with quicksort
    sort(cdataframe->columns[0]);
    print_col_by_index(cdataframe->columns[0]);


    // Check for index
    printf("\n");
    int index_status = check_index(cdataframe->columns[0]);

    if (index_status == 1) {
        printf("Index is correct\n");
    } else if (index_status == -1) {
        printf("Index exists but is invalid\n");
    } else {
        printf("Index does not exist\n");
    }

    // Second sorting with insertion sort
    add_row_to_cdataframe(cdataframe);
    printf("\n");
    sort(cdataframe->columns[0]);
    print_col_by_index(cdataframe->columns[0]);

    // Erase index
    erase_index(cdataframe->columns[0]);
    if (cdataframe->columns[0]->index == NULL) {
        printf("Memory has been successfully freed \n");
    } else {
        printf("Memory has not been freed \n");
    }

    return 0;
}