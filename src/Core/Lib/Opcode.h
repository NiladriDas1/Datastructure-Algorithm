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

    typedef struct Type_Oftensor{const unsigned int Low,High,Right,Left;}Typetensor;
    typedef enum ComputerOperation{XOR,AND,NOR,OR,NOT,NAND}CsOpcode;
    enum ArrayisNull{NotEmpty,Empty};
    typedef enum ItrateLocation{MID,END,START,PRIVIOUS,NEXT}ITRLOC;


    // AND gate prototypes
    char and_char(const char *a, const char *b);
    int and_int(const int *a, const int *b);
    float and_float(const float *a, const float *b);
    double and_double(const double *a, const double *b);
    long long int and_llint(const long long int *a, const long long int *b);
    short int and_sint(const short int *a, const short int *b);

    // OR gate prototypes
    char or_char(const char *a, const char *b);
    int or_int(const int *a, const int *b);
    float or_float(const float *a, const float *b);
    double or_double(const double *a, const double *b);
    long long int or_llint(const long long int *a, const long long int *b);
    short int or_sint(const short int *a, const short int *b);

    // NOT gate prototypes (unary, takes one pointer)
    char not_char(const char *a);
    int not_int(const int *a);
    float not_float(const float *a);
    double not_double(const double *a);
    long long int not_llint(const long long int *a);
    short int not_sint(const short int *a);

    // NAND gate prototypes
    char nand_char(const char *a, const char *b);
    int nand_int(const int *a, const int *b);
    float nand_float(const float *a, const float *b);
    double nand_double(const double *a, const double *b);
    long long int nand_llint(const long long int *a, const long long int *b);
    short int nand_sint(const short int *a, const short int *b);

    // NOR gate prototypes
    char nor_char(const char *a, const char *b);
    int nor_int(const int *a, const int *b);
    float nor_float(const float *a, const float *b);
    double nor_double(const double *a, const double *b);
    long long int nor_llint(const long long int *a, const long long int *b);
    short int nor_sint(const short int *a, const short int *b);

    // XOR gate prototypes
    char xor_char(const char *a, const char *b);
    int xor_int(const int *a, const int *b);
    float xor_float(const float *a, const float *b);
    double xor_double(const double *a, const double *b);
    long long int xor_llint(const long long int *a, const long long int *b);
    short int xor_sint(const short int *a, const short int *b);

    // XNOR gate prototypes
    char xnor_char(const char *a, const char *b);
    int xnor_int(const int *a, const int *b);
    float xnor_float(const float *a, const float *b);
    double xnor_double(const double *a, const double *b);
    long long int xnor_llint(const long long int *a, const long long int *b);
    short int xnor_sint(const short int *a, const short int *b);


    // char
    char and_char(const char *a, const char *b) { return (*a && *b); }
    // int
    int and_int(const int *a, const int *b) { return (*a && *b); }
    // float
    float and_float(const float *a, const float *b) { return (*a && *b); }
    // double
    double and_double(const double *a, const double *b) { return (*a && *b); }
    // long long int
    long long int and_llint(const long long int *a, const long long int *b) { return (*a && *b); }
    // short int
    short int and_sint(const short int *a, const short int *b) { return (*a && *b); }

    char or_char(const char *a, const char *b) { return (*a || *b); }
    int or_int(const int *a, const int *b) { return (*a || *b); }
    float or_float(const float *a, const float *b) { return (*a || *b); }
    double or_double(const double *a, const double *b) { return (*a || *b); }
    long long int or_llint(const long long int *a, const long long int *b) { return (*a || *b); }
    short int or_sint(const short int *a, const short int *b) { return (*a || *b); }

    char not_char(const char *a) { return !(*a); }
    int not_int(const int *a) { return !(*a); }
    float not_float(const float *a) { return !(*a); }
    double not_double(const double *a) { return !(*a); }
    long long int not_llint(const long long int *a) { return !(*a); }
    short int not_sint(const short int *a) { return !(*a); }

    char nand_char(const char *a, const char *b) { return !(*a && *b); }
    int nand_int(const int *a, const int *b) { return !(*a && *b); }
    float nand_float(const float *a, const float *b) { return !(*a && *b); }
    double nand_double(const double *a, const double *b) { return !(*a && *b); }
    long long int nand_llint(const long long int *a, const long long int *b) { return !(*a && *b); }
    short int nand_sint(const short int *a, const short int *b) { return !(*a && *b); }

    char nor_char(const char *a, const char *b) { return !(*a || *b); }
    int nor_int(const int *a, const int *b) { return !(*a || *b); }
    float nor_float(const float *a, const float *b) { return !(*a || *b); }
    double nor_double(const double *a, const double *b) { return !(*a || *b); }
    long long int nor_llint(const long long int *a, const long long int *b) { return !(*a || *b); }
    short int nor_sint(const short int *a, const short int *b) { return !(*a || *b); }

    char xor_char(const char *a, const char *b) { return ((*a && !*b) || (!*a && *b)); }
    int xor_int(const int *a, const int *b) { return ((*a && !*b) || (!*a && *b)); }
    float xor_float(const float *a, const float *b) { return ((*a && !*b) || (!*a && *b)); }
    double xor_double(const double *a, const double *b) { return ((*a && !*b) || (!*a && *b)); }
    long long int xor_llint(const long long int *a, const long long int *b) { return ((*a && !*b) || (!*a && *b)); }
    short int xor_sint(const short int *a, const short int *b) { return ((*a && !*b) || (!*a && *b)); }

    char xnor_char(const char *a, const char *b) { return !(((*a && !*b) || (!*a && *b))); }
    int xnor_int(const int *a, const int *b) { return !(((*a && !*b) || (!*a && *b))); }
    float xnor_float(const float *a, const float *b) { return !(((*a && !*b) || (!*a && *b))); }
    double xnor_double(const double *a, const double *b) { return !(((*a && !*b) || (!*a && *b))); }
    long long int xnor_llint(const long long int *a, const long long int *b) { return !(((*a && !*b) || (!*a && *b))); }
    short int xnor_sint(const short int *a, const short int *b) { return !(((*a && !*b) || (!*a && *b))); }

#endif