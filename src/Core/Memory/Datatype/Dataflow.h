#ifndef DATAFLOW_H
#define DATAFLOW_H
    #include "Datatype.h"
    
    GENERIC GAlloc(size_t size, TYPE T) {
        switch (T) {
            case TYPE_FLOAT:    return FAlloc(size);
            case TYPE_INT:      return LINAlloc(size);
            case TYPE_SHORT:    return SHAlloc(size);
            case TYPE_STRING:   return STAlloc(size) ;
            case TYPE_GENERIC:     return malloc(size ); // Handle other container types
            default:            return NULL;
        }
    }

// Allocators for specific pointer types
    FLOAT FAlloc(size_t size) {
        return (FLOAT)malloc(size * sizeof(double));
    }

    SHRINT SHAlloc(size_t size) {
        return (SHRINT)malloc(size * sizeof(short int));
    }

    STRING STAlloc(size_t size) {
        return (STRING)malloc(size * sizeof(char));
    }

    LINT LINAlloc(size_t size) {
        return (LINT)malloc(size * sizeof(long long int));
    }





#endif