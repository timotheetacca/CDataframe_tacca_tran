#include "column.h"
#include "CDataframe.h"
#include <stddef.h>
#include <stdio.h>

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

    // Add a column
    add_column_to_cdataframe(cdataframe);

    // Delete a column
    delete_column_from_cdataframe(cdataframe, 0);

    // Rename a column
    rename_column(cdataframe,0, "Column 0");

    // Display CDataframe number of rows and columns and columns name
    display_number_of_rows(cdataframe);
    display_number_of_columns(cdataframe);
    display_name_of_columns(cdataframe);

    return 0;
}