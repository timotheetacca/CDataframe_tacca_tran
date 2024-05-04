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



    return 0;
}