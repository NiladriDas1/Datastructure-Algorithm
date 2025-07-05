
    #include <stdio.h>    // Standard Input/Output
    #include <stdlib.h>   // General utilities (e.g., malloc, free, exit)
    #include <stdarg.h>   // Variable arguments for functions (e.g., va_list)
    #include <string.h>   // String manipulation functions (e.g., strlen, strcpy)
    #include <stdbool.h>  // Boolean type (bool, true, false) - C99 standard
    #include <math.h>     // Mathematical functions (e.g., sqrt, sin, cos)
    #include <limits.h>   // Limits of integer types (e.g., INT_MAX, CHAR_MIN)
    #include <threads.h>  // C11 threads support (e.g., thrd_t, mtx_t) - C11 standard
    #include <assert.h>   // Assertions for debugging (e.g., assert())
    #include <float.h>    // Characteristics of floating-point types (e.g., FLT_MAX)
    #include <complex.h>  // Complex number arithmetic - C99 standard
    #include <time.h>     // Time and date utilities (e.g., time, clock)
    #include <wctype.h>   // Wide character classification and mapping - C95 standard
    #include <stdalign.h> // Alignment utilities (e.g., alignof, aligned_alloc) - C11 standard
    #include <errno.h>    // Error numbers (e.g., EACCES)
    #include <fenv.h>     // Floating-point environment access - C99 standard
    #include "Memory/dynamic2.h"

    typedef struct Mainarray{
        void *Data;
        unsigned int U_Maxsize ;
        unsigned int L_Maxsize ;
    }Mainarray_;
typedef struct Array{
    
   Mainarray_ *Mainarray; // Pointer to an array of Mainarray structs
    //Cout the current stage
    unsigned int counterPos;
    //Cout the Funciton call
    struct Array *(*Method)(struct Array *Array, unsigned int size, unsigned int Maxsize);
    struct Array *Point_matrix;//Parallel array likend list array ;


}Array;

// Your Array_Create function with the error fixed
Array *Array_Create(int const size , unsigned int maxsize,unsigned int minsize) {
    
    // Note: 'ptr' is unused here as you're allocating a new Array*
    // If 'size' is 0 or negative, allocation for inner array would be problematic.
    if (!size) { // Check for size being 0
        fprintf(stderr, "Error: 'size' for inner array must be positive.\n");
        return NULL;
    }
    

    Array *Newarray = (Array *)malloc(sizeof(Array));
    if (Newarray == NULL) {
        perror("Failed to allocate memory for outer Array structure");
        return NULL;
    }

    Newarray->Mainarray = malloc(size * sizeof( *Newarray->Mainarray));
    if (Newarray->Mainarray == NULL) {
        perror("Failed to allocate memory for dynamic array of inner Mainarray structures");
        free(Newarray); // Clean up the outer Array if inner allocation fails
        return NULL;
    }

    Newarray->counterPos = 0; // Or some initial value
    Newarray->Method = NULL; // Assign your method function pointer here (e.g., &your_method_func)
    Newarray->Point_matrix = NULL; // Initialize pointer

    // Loop to initialize each element of the dynamically allocated Mainarray array
    for (int i = 0; i < size; ++i) {
        Newarray->Mainarray[i].Data = NULL;
        Newarray->Mainarray[i].U_Maxsize = size;
        Newarray->Mainarray[i].L_Maxsize = 0;
        // If Data within each Mainarray needs further allocation, do it here
        // Newarray->Mainarray[i].Data = malloc(some_default_data_size);
    }

    return Newarray;
}

Array *Create_Next_Linked_Array(Array *Array_P, unsigned int const size){
if (!Array_P || !size) {
    
    return NULL;
}
  Array *new_node = malloc(sizeof(Array));
    if (!new_node) return NULL;
    new_node->Mainarray = malloc(size * sizeof(*new_node->Mainarray));
    if (!new_node->Mainarray) {
        free(new_node);
        return NULL;
    }

    // Initialize values
    new_node->counterPos +=1 ;
    new_node->Method = NULL;
    new_node->Point_matrix = NULL;

    for (unsigned int i = 0; i < size; ++i) {
        new_node->Mainarray[i].Data = NULL;
        new_node->Mainarray[i].U_Maxsize = size;
        new_node->Mainarray[i].L_Maxsize = 0;
    }

    Array_P->Point_matrix = new_node; // Link to new node
    return new_node;

}

Array *Destroy_Entire_array(Array *Array_p) {
  if(!Array_p)     return NULL;

    Array *Head = Array_p->Point_matrix; // Start from the head of the linked listArray *Head= Array_p->Point_matrix;
    Array *curr = Array_p->Point_matrix;
    while (curr) {
        if (curr->Mainarray) {
            for (unsigned int i = 0; i < Array_p->Mainarray->U_Maxsize; ++i) {
                if (curr->Mainarray[i].Data) {
                    free(curr->Mainarray[i].Data);
                }
            }
            free(curr->Mainarray);
        }

        Array *next = curr->Point_matrix;
        free(curr);
        curr = next;
    }

    // Free the original Array_p's Mainarray
    if (Array_p->Mainarray) {
        for (unsigned int i = 0; i < Array_p->Mainarray->U_Maxsize; ++i) {
            if (Array_p->Mainarray[i].Data) {
                free(Array_p->Mainarray[i].Data);
            }
        }
        free(Array_p->Mainarray);
    }

    free(Array_p);
    return NULL;
}
void *Print_array(Array *Array_p) {
    if (!Array_p || !Array_p->Mainarray) {
        EXIT_FAILURE;
        return NULL;
    }
    printf("Array Details:\n");
    printf("Counter Position: %u\n", Array_p->counterPos);
    printf("Mainarray Size: %u\n", Array_p->Mainarray->U_Maxsize);
    printf("Point Matrix: %p\n", (void *)Array_p->Point_matrix);    
    for (unsigned int i = 0; i < Array_p->Mainarray->U_Maxsize; ++i) {
        printf("\n\nMainarray[%u]: Data = %p, \n",i, Array_p->Mainarray[i].Data);
    }
    return NULL;
    
    
    
}
void InputArray(Array *ptr_a,int count ,...){
    va_list args;
    va_start(args, count);
    if (!ptr_a || !ptr_a->Mainarray) {
        fprintf(stderr, "Error: Invalid Array pointer or Mainarray not initialized.\n");
        return;
    }
    if (count > ptr_a->Mainarray->U_Maxsize) {
        fprintf(stderr, "Error: Count exceeds the maximum size of the Mainarray.\n");
        va_end(args);
        return; 
    }
    for (size_t i = 0; i < count; ++i) {
        // Assuming Data is of type int for this example, adjust as needed
        int value = va_arg(args, int);
        ptr_a->Mainarray[i].Data = malloc(sizeof(int)); // Allocate memory for each Data element
        if (ptr_a->Mainarray[i].Data == NULL) {
            perror("Failed to allocate memory for Data");
            va_end(args);
            return;
        }
        *(int *)(ptr_a->Mainarray[i].Data) = value; // Store the value in the allocated memory
        //ptr_a->Mainarray[i].U_Maxsize = sizeof(int); // Set U_Maxsize to size of int
        //ptr_a->Mainarray[i].L_Maxsize = sizeof(int); // Set L_Maxsize to size of int
    }
    va_end(args);
    printf("InputArray: Successfully added %d elements to the Array.\n", count);
}
