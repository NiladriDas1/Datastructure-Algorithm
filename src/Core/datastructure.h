#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

typedef struct Array{
    void *Data;
    unsigned int U_Maxsize ;
    unsigned int L_Maxsize ;
    //Cout the current stage
    unsigned int counterPos;
    struct Array *(*Method)();
    struct Array *Point_matrix;


}Array;

typedef struct Linkedlist{
    enum Type{Singly,Doublly,Circular,DoublyCircular,singllyCircular}Type;

    union List{
        struct Singly{
            void *Data;
            void *current_adress;
            unsigned int Totalnumlst;
            unsigned int Minimumlst;
            struct Singly *Nextnode;
        }Singly;
        struct Doublly{
            void *Data;
            void *Currentnode_add;
            void *Priviousnode_add;
            struct Doublly *Pvnode;
            struct Doublly *Nxtnode;
        }Doublly;
        struct Circular{
            void *Data;
            void *current_adress;
            unsigned int Totalnumlst;
            unsigned int Minimumlst;
            struct Singly *Nextnode;
        }Circular;
    }LList;
    struct Linkedlist *(*Method)();
}Linkedlist;

typedef struct stack{
    void *data;
    unsigned int size;
    struct stack *Current;
    struct stack*(*Method)();
}Stack;

typedef struct queue{
    void *data;
    void *Priority;
    unsigned int size;
    struct queue *front;
    struct queue *reare;
    struct queue *(*Method)();

}Queue;






#endif