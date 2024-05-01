#include "column.h"
#include "CDataframe.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    CDATAFRAME* cdataframe = create_cdataframe();
    fill_cdataframe(cdataframe);
    display_cdataframe(cdataframe);

    // Print rows 0-1
    display_limited_rows_cdataframe(cdataframe, 0, 1);
    printf("\n");

    // Print columns 0-1
    display_limited_columns_cdataframe(cdataframe, 0,1);

    // Add row
    add_row_to_cdataframe(cdataframe);
    display_cdataframe(cdataframe);

    // Delete row
    delete_row_from_cdataframe(cdataframe, 1);
    display_cdataframe(cdataframe);

    // Add column
    add_column_to_cdataframe(cdataframe);

    // Delete column
    delete_column_from_cdataframe(cdataframe, 0);

    // Rename column
    rename_column(cdataframe,0, "Column 0");

    // Check existence of value
    ENUM_TYPE value_type = INT;
    int value = 0;
    printf("%d", check_if_value_exists(cdataframe, value_type, &value));

    // Access value
    void* accessed_value = access_value(cdataframe, 0, 0);
    int* int_ptr = (int*)accessed_value;
    printf("%d\n", *int_ptr);

    // Replace value
    ENUM_TYPE new_value_type = INT;
    int new_value = 0;
    replace_value(cdataframe, 0, 0, new_value_type, &new_value);

    // Display CDataframe number of rows and columns and columns name
    display_number_of_rows(cdataframe);
    display_number_of_columns(cdataframe);
    display_name_of_columns(cdataframe);

    // Comparison with x
    ENUM_TYPE x_type = INT;
    int x1=1,x2=4,x3=40;
    printf("%d\n", count_cells_condition(cdataframe, x_type, &x1, '='));
    printf("%d\n", count_cells_condition(cdataframe, x_type, &x2, '>'));
    printf("%d\n", count_cells_condition(cdataframe, x_type, &x3, '<'));

    return 0;
}