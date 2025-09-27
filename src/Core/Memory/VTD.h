#ifndef VTD_H
#define VTD_H
    #include "Datatype.h"
    
    typedef struct VTDvoid {
        TYPE type;
        size_t length;
        GENERIC *value;
    } VTD_VOID;

    
    typedef struct VTDint{
        TYPE type;
        size_t length;
        LINT value;
    }VTD_INT;
    
    typedef struct VTDstr
    {
        TYPE type;
        size_t length;
        STRING value;
    }VTD_STRING;

    typedef struct VTDshrt{
        TYPE type;
        size_t length;
        SHRINT value;
    }VTD_SHRINT;

    typedef struct VTDflt{
        TYPE type;
        size_t length;
        FLOAT value;
    }VTD_FLOAT;
    
    typedef struct container{
        VTD_FLOAT *VF;
        VTD_INT *VIN;
        VTD_STRING *VSTR;
        VTD_SHRINT *VSHRIN;
        VTD_VOID *VTDVD;
        struct container *(*init)(struct container *ptr);

    }Container;



#endif