#ifndef DATAFRAME_H
#define DATAFRAME_H
#include "column.h"

typedef struct {
    COLUMN** columns;
    int number_columns;
    int number_rows;
} CDATAFRAME;

CDATAFRAME* create_cdataframe();
void delete_cdataframe(CDATAFRAME* cdataframe);
void fill_cdataframe(CDATAFRAME* cdataframe);
void hard_fill(CDATAFRAME* cdataframe);
void display_cdataframe(CDATAFRAME* cdataframe);
void display_limited_rows_cdataframe(CDATAFRAME* cdataframe, int start, int end);
void display_limited_columns_cdataframe(CDATAFRAME* cdataframe, int start, int end);
void add_row_to_cdataframe(CDATAFRAME* cdataframe);
void delete_row_from_cdataframe(CDATAFRAME* cdataframe, int row);
void add_column_to_cdataframe(CDATAFRAME* cdataframe);
void delete_column_from_cdataframe(CDATAFRAME* cdataframe, int column);
void rename_column(CDATAFRAME* cdataframe, int column, char* new_title);
int check_if_value_exists_in_cdataframe(CDATAFRAME* cdataframe, ENUM_TYPE value_type, void* value);
void replace_value(CDATAFRAME* cdataframe, int column, int row, ENUM_TYPE value_type, void* new_val);
void display_number_of_rows(CDATAFRAME* cdataframe);
void display_number_of_columns(CDATAFRAME* cdataframe);
void display_name_of_columns(CDATAFRAME* cdataframe);
int count_cells_condition(CDATAFRAME* cdataframe, ENUM_TYPE x_type, void* x, char op);
int search_value_in_column(COLUMN *col, void *val);

#endif
