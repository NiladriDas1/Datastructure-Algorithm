#ifndef VTD_H
#define VTD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#define MAX_VARGS 10

typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_CHAR, TYPE_STRING } TYPE;
typedef enum Method{Push,Pop,Mid,End,Begin,Swap,Sum,Substract,Division,Avarage,Min,Max,Mod,Multiply,Count}METH;
typedef union {
   long long int *i;
    double *f;
    char *c;
    char **s;
    void *ptr;
} Data;

typedef struct Variant {
    TYPE type;
    size_t length;
    Data value;
} VTD;
#endif