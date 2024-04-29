#include "column.h"
#include "CDataframe.h"
#include <stddef.h>

int main() {
    CDATAFRAME* cdataframe = create_cdataframe();
    fill_cdataframe(cdataframe);
    display_cdataframe(cdataframe);

    return 0;
}