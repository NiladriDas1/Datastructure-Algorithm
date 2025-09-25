#ifndef List_H
#define List_H

    #ifndef DYNAMIC_H
        #include"Memory\dynamic.h"
    #endif
typedef enum Type{Singly,Doubly,circular,double_cricular,N_Direction_List}TP;
typedef struct Linked_list{
    TP T;
    void *Casting;
    VTD *var_Data;
    struct Linked_list *rnode;
    struct Linked_list *lnode;
    
    struct Linked_list*(*init)(struct Linked_list *LL,VTD *V_D);
    struct Linked_list*(*Distructor)(struct Linked_list *LL,VTD *V_D);
}List;

typedef struct N_Directionlist{
    
    
    VTD *var_Data;
    struct N_Directionlist **Nnode;

    struct N_Directionlist*(*Init)(struct N_Directionlist *Node, VTD *v_D);
    struct N_Directionlist*(*Distructor)(struct N_Directionlist *Node, VTD *v_D);



}N_Dir_list;

#endif