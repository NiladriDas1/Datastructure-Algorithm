#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

typedef enum ErrorCode{
        SUCCESS = 0,
        ERROR_NULL_POINTER = 1,
        ERROR_INVALID_SIZE = 2,
        ERROR_MEMORY_ALLOCATION_FAILED = 3,
        ERROR_INDEX_OUT_OF_BOUNDS = 4,
        ERROR_UNSUPPORTED_OPERATION = 5
    }ErrorCode;
typedef enum Operation{
        CREATE = 0,
        DESTROY = 1,
        INSERT = 2,
        DELETE = 3,
        SEARCH = 4,
        SORT = 5,
        PRINT = 6
    }Operation;



    typedef enum Arraytype{Matrix,Parallel_Linked,Normal_Array}Arraytype;       

    typedef struct Mainarray{
        void *Data;
        unsigned int U_Maxsize ;
        unsigned int L_Maxsize ;

    }Mainarray_;

    typedef struct Array{
    
        Mainarray_ *Mainarray;
    //Cout the current stage
    
    unsigned int counterPos;
    
    //Cout the Funciton call
    
    struct Array *(*Method)(struct Array *Array, unsigned int size, unsigned int Maxsize);
    
    struct Array *Point_matrix;}Array;//Parallel array likend list array 

//linked list
//Linked list is a data structure that consists of a sequence of elements, each containing a reference
// to the next element in the sequence. This allows for efficient insertion and deletion of elements,
// as well as dynamic resizing of the list. Linked lists can be singly linked, doubly linked, or circular,
// depending on the structure of the nodes and the way they are connected. In a singly linked list,
// each node contains a reference to the next node, while in a doubly linked list,
// each node contains references to both the next and previous nodes. Circular linked lists connect the
// last node back to the first node, creating a loop. Linked lists are commonly used in
// applications where dynamic memory allocation and efficient insertion and deletion are required,
// such as in implementing stacks, queues, and other data structures.
typedef enum Type{Singly,Doublly,Circular,DoublyCircular,singllyCircular}Type;

        typedef struct Singly{
            void *Data;
            void *current_adress;

            struct Singly *Nextnode;
        }Singly;

        typedef struct Doublly{
            void *Data;
            
            void *Currentnode_add;
            void *Priviousnode_add;
            
            struct Doublly *Pvnode;
            struct Doublly *Nxtnode;
        }Doublly;

        typedef struct Circular{
            void *Data;
            void *current_adress;
            
            struct Singly *Nextnode;
        }Circular;

        typedef union List{
        
            Circular *Circular;
            Singly *Singly;
            Doublly *Doublly;
            Type Type;    
        }LList;

    typedef struct Linkedlist{
        LList *Mainlist; // Pointer to an array of Mainarray structs
        unsigned int Totalnumlst;//Size can be Increased or decreased
        unsigned int Minimumlst;
    
        struct Linkedlist *(*Method)();
    }Linkedlist;
//ending Linked list



//Stack is a data structure that follows the Last In First Out (LIFO) principle, meaning that the last element added to the stack is the first one to be removed. It is often implemented using an array or a linked list, where elements can be pushed onto the top of the stack and popped off from the top. Stacks are commonly used in programming for tasks such as function call management, expression evaluation, and backtracking algorithms.  
// A stack can be implemented using an array or a linked list, where elements can be pushed onto the top of the stack and popped off from the top. Stacks are commonly used in programming for tasks such as function call management, expression evaluation, and backtracking algorithms.
typedef enum Stacktype{Array_Stack,Linked_Stack,Container}Stacktype;


 typedef struct stack{
    void *data;
    unsigned int size;
    
    struct stack *Top;
    struct stack *Current_order;
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


typedef struct Container{
    
    void *Data;
    unsigned int const size;
    unsigned int const Maxsize_data;
    
    void *Current_address;
    void *Previous_address;
    void *Next_address;
    void *Top_address;
    void *Mid_address;
    void *End_address;
    
    struct Container *End;
    struct Container *Top;
    struct Container *Mid;
    struct Container *(*Method)();
    
}Container;

struct STK_QUE{
    Stack *Stack;
    Queue *Queue;
    Container *Container;
    unsigned int const size;
    unsigned int const Maxsize_data;
    
    struct STK_QUEUE *(*Method)();
};



#endif