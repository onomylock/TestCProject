#include <gsl/gsl_vector.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum FileType
{
    CELLS,
    RECEIVERS,
    OUTPUT
} FileType;

typedef struct Cell
{
    double I;
    gsl_vector *Center;
    gsl_vector *P;
    gsl_vector *nodes[2];    

} Cell;

typedef struct Receiver_
{
    gsl_vector *B;
    gsl_vector *Point;
} Receiver;

typedef struct Direct
{
    int N, K;
    Cell *cellObjects;
    Receiver *receivers;
    char *fileName;
} Direct;

extern Direct* direct_calc;


//void open();
int load(const char* fileName, enum FileType fileType);
int save(const char* fileName, enum FileType fileType);
int calculate();
//void read_data(const char* fileName, enum FileType);
//void read_receivers(const char* fileName);
//void read_cells(const char* fileName);
double get_r(Cell cell, Receiver receiver);
double get_cell_area(Cell cell);