#ifndef TREE_H
#define TREE_H
    #ifndef DYNAMIC_H
        #include"Memory\dynamic.h"
    #endif    
    #include "Opcode.h"

  

typedef struct Tree
{ 

    Vtype T;
    
   struct validD{
        unsigned int key;
        unsigned int height;
        unsigned int Flag :1;
        unsigned int Color :1;
        unsigned int M_size_tree;
        unsigned int Capacity;
        unsigned int Size;

    }valid_d;

    VTD *var_Data;
    void *Casting;

    struct Tree *Left;
    struct Tree *right;
    struct Tree *Parent;
    struct Tree **MULTISTRUCTPOINTER;
   

}TRee;

#endif
