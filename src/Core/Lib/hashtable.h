#ifndef Hashtable_H
#define Hashtable_H
    #ifndef DYNAMIC_H
        #include"Memory\dynamic.h"
    #endif
    #include "Opcode.h"
 
typedef struct hashT{ 
        
    struct node{
            long long int key,probe_distance,is_occupied;
            unsigned long long int hop_info;
            INFO Info;
            VTD *v_data;
            struct node *next;
        }**TableNode ;    


        VTD **Emptycase;
        
        struct hashT **HSHnode;
    }HASH;

    
#endif