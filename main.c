#include "column.h"
#include "CDataframe.h"

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
    printf("%d\n", count_cells_condition(cdataframe, 1, '='));
    printf("%d\n", count_cells_condition(cdataframe, 4, '>'));
    printf("%d\n", count_cells_condition(cdataframe, 4, '<'));
    add_row_to_cdataframe(cdataframe);
    display_cdataframe(cdataframe);

    return 0;
}

