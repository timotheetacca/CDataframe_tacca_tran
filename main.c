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

    return 0;
}
