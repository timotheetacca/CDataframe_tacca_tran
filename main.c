#include "column.h"
#include "CDataframe.h"

int main() {
    COLUMN *mycol = create_column("My column");

    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);

    return 0;
}
