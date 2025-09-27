#ifndef OPCODE_H
#define OPCODE_H

    typedef enum SoRT{
            BUBBLE_SORT,
            SELECTION_SORT,
            INSERTION_SORT,
            MERGE_SORT,
            QUICK_SORT,
            HEAP_SORT,
            COUNTING_SORT,
            RADIX_SORT,
            BUCKET_SORT,
            SHELL_SORT,
            GNOME_SORT,
            CYCLE_SORT,
            COMB_SORT,
            PANCAKE_SORT,
            LINEAR_SEARCH,
            BINARY_SEARCH,
            JUMP_SEARCH,
            INTERPOLATION_SEARCH,
            EXPONENTIAL_SEARCH,
            FIBONACCI_SEARCH,
            TERNARY_SEARCH,
            HASH_SEARCH,
            SENTINEL_LINEAR_SEARCH
    } SORTsEarcHopCode;

    typedef enum Vtype {
        BINARY_TREE,
        BINARY_SEARCH_TREE,
        AVL_TREE,
        RED_BLACK_TREE,
        B_TREE,
        B_PLUS_TREE,
        SEGMENT_TREE,
        FENWICK_TREE,
        TRIE,
        SPLAY_TREE,
        MIN_HEAP,
        MAX_HEAP,
        QUAD_TREE,
        OCTREE,
        NARY_TREE,
        TOURNAMENT_TREE,
        EXPRESSION_TREE,
        DECISION_TREE,
        R_TREE
    } Vtype;

    typedef enum Type{Singly,Doubly,circular,double_cricular,N_Direction_List}TP;
    
    typedef struct Type_Oftensor{const unsigned int Low,High,Right,Left;}Typetensor;
    
    typedef enum ComputerOperation{XOR,AND,NOR,OR,NOT,NAND}CsOpcode;
    
    enum ArrayisNull{NotEmpty,Empty};
    
    typedef enum ItrateLocation{MID,END,START,PRIVIOUS,NEXT}ITRLOC;
    
    typedef enum info{empty, occupied, deleted}INFO;   
#endif