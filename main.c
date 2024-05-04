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

    sort(cdataframe->columns[0]);
    print_col_by_index(cdataframe->columns[0]);

    add_row_to_cdataframe(cdataframe);
    sort(cdataframe->columns[0]);
    print_col_by_index(cdataframe->columns[0]);

    // Add column
    add_column_to_cdataframe(cdataframe);

    // Delete column
    delete_column_from_cdataframe(cdataframe, 0);

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


    return 0;
}