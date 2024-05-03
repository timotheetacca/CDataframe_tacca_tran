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

    // Replace value
    ENUM_TYPE new_value_type = INT;
    int new_value = 0;
    replace_value(cdataframe, 0, 0, new_value_type, &new_value);

    // Comparison with x
    ENUM_TYPE x_type1 = INT;
    int x1=1,x2=4,x3=50;
    printf("%d\n", count_cells_condition(cdataframe, x_type1, &x1, '='));
    printf("%d\n", count_cells_condition(cdataframe, x_type1, &x2, '>'));
    printf("%d\n", count_cells_condition(cdataframe, x_type1, &x3, '<'));

    return 0;
}