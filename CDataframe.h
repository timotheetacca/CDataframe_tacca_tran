#ifndef DATAFRAME_H
#define DATAFRAME_H

#include "column.h"

typedef struct {
    COLUMN** columns;
    int number_columns;
    int number_rows;
} CDATAFRAME;

CDATAFRAME* create_cdataframe();
void fill_cdataframe(CDATAFRAME* cdataframe);
void display_cdataframe(CDATAFRAME* cdataframe);
void display_limited_rows_cdataframe(CDATAFRAME* cdataframe, int start, int end);
void display_limited_columns_cdataframe(CDATAFRAME* cdataframe, int start, int end);
void display_number_of_rows(CDATAFRAME* cdataframe);
void display_number_of_columns(CDATAFRAME* cdataframe);
int count_cells_condition(CDATAFRAME* cdataframe, int x, char op);
void add_row_to_cdataframe(CDATAFRAME* cdataframe);

#endif
