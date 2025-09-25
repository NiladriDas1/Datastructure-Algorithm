#ifndef STQ_H
#define STQ_H

    #ifndef DYNAMIC_H
        #include"Memory\dynamic.h"
    #endif
    typedef struct treeData{
        VTD *point_v;
        VTD *Point_2V;
    }treedt;
    
   typedef struct stq{
        treedt DATA;
        
        STACK_QUEUE* (*Dtfun)(STACK_QUEUE *ptr);
        

        struct stq *hold;
        struct stq *next;
        struct stq *privious;

    }STACK_QUEUE;


#endif