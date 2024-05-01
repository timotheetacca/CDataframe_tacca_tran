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

    // Display CDataframe number of rows and columns and columns name
    display_number_of_rows(cdataframe);
    display_number_of_columns(cdataframe);
    display_name_of_columns(cdataframe);
    
    return 0;
}