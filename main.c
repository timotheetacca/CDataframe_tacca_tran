#include "column.h"
#include "CDataframe.h"
#include <stddef.h>

int main() {
    CDATAFRAME* cdataframe = create_cdataframe();
    fill_cdataframe(cdataframe);
    display_cdataframe(cdataframe);

    display_limited_rows_cdataframe(cdataframe, 2, 3);
    printf("\n");
    display_limited_columns_cdataframe(cdataframe, 2,3);

    return 0;
}