#ifndef Array_H
#define Array_H


    #ifndef DYNAMIC_H
        #include"Memory\dynamic.h"
    #endif


typedef struct Array {
    
    struct loc {
        struct Array *Privious;
        struct Array *Next;
        struct Array *Mid;
        struct Array *end; 
        struct Array *start; 
    } Loc;
    VTD *var_Data;
    int Max;
    unsigned int Counter;
    unsigned int pos;
} ARR;


// 2D macro: row, col to linear index
#define IDX_2D(row, col, ncols)       ((row) * (ncols) + (col))

// 3D macro: depth, row, col to linear index
#define IDX_3D(depth, row, col, nrows, ncols) \
        ((depth) * (nrows) * (ncols) + (row) * (ncols) + (col))

typedef struct A3D{
    ARR *data;
    unsigned int depth, rows, cols;
    struct A3D *Depth, *Rows, *Cols;
} ARR_TENSOR;

typedef struct A2D{
    ARR *data;
    unsigned int  rows, cols;
    struct A2D *Rows, *Cols;
} ARR_MATRIX;
// operate as 1D array with index: d*(rows*cols) + r*cols + c


#endif