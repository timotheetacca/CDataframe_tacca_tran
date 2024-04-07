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

#endif