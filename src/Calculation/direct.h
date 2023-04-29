// #include <gsl/gsl_vector.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>
// #include "../Render/graph.h"

// typedef enum FileType
// {
//     CELLS,
//     RECEIVERS,
//     OUTPUT
// } FileType;

// typedef struct Cell
// {
//     double I;
//     Point *Center;
//     Point *P;
//     Point *nodes[2];    

// } Cell;

// typedef struct Receiver
// {
//     Point *B;
//     Point *Point;
// } Receiver;

// typedef struct Direct
// {
//     int N, K;
//     Cell *cellObjects;
//     Receiver *receivers;
//     char *fileName;
// } Direct;

// extern Direct* direct_calc;

// int load(const char* fileName, enum FileType fileType);
// int save(const char* fileName, enum FileType fileType);
// int calculate();
// double get_r(Cell cell, Receiver receiver);
// double get_cell_area(Cell cell);