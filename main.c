#include "column.h"
#include "CDataframe.h"
#include <stdio.h>

int main() {
    COLUMN *mycol = create_column("My column");

    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);

    print_col(mycol);

    CDATAFRAME* cdataframe = create_cdataframe();
    fill_cdataframe(cdataframe);
    display_cdataframe(cdataframe);

    display_limited_rows_cdataframe(cdataframe, 2, 3);
    display_limited_columns_cdataframe(cdataframe, 2, 3);

    display_number_of_rows(cdataframe);
    display_number_of_columns(cdataframe);
    display_name_of_columns(cdataframe);

    printf("%d\n", count_cells_condition(cdataframe, 1, '='));
    printf("%d\n", count_cells_condition(cdataframe, 4, '>'));
    printf("%d\n", count_cells_condition(cdataframe, 4, '<'));

    add_column_to_cdataframe(cdataframe);
    rename_column(cdataframe, 0, "Col1");
    delete_column_to_cdataframe(cdataframe, 1);
    display_cdataframe(cdataframe);

    delete_row_from_cdataframe(cdataframe, 0);
    display_cdataframe(cdataframe);

    add_row_to_cdataframe(cdataframe);
    display_cdataframe(cdataframe);

    printf("%d\n", check_if_value_exists(cdataframe, 1));
    printf("%d\n", check_if_value_exists(cdataframe, 1234));

    printf("%d\n", access_value(cdataframe, 0, 0));
    replace_value(cdataframe, 0, 0, 4);
    display_cdataframe(cdataframe);

    hard_fill_cdataframe(cdataframe);
    display_cdataframe(cdataframe);

    return 0;
}

