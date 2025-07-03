#include<datastructure.h>
#include "Lib/Lib.h"


// Your Array_Create function with the error fixed
Array *Array_Create(int const size) {
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

    // --- CORRECTED LINE HERE ---
    // Allocate memory for a dynamic array of 'struct Array::Mainarray'
    Newarray->Mainarray = (struct Array::Mainarray *)malloc(size * sizeof(struct Array::Mainarray));
    if (Newarray->Mainarray == NULL) {
        perror("Failed to allocate memory for dynamic array of inner Mainarray structures");
        free(Newarray); // Clean up the outer Array if inner allocation fails
        return NULL;
    }

    // --- You would continue your initialization logic here ---
    // Example initializations for the new Array instance:
    Newarray->counterPos = 0; // Or some initial value
    Newarray->Method = NULL; // Assign your method function pointer here (e.g., &your_method_func)
    Newarray->Point_matrix = NULL; // Initialize pointer

    // Loop to initialize each element of the dynamically allocated Mainarray array
    for (int i = 0; i < size; ++i) {
        Newarray->Mainarray[i].Data = NULL;
        Newarray->Mainarray[i].U_Maxsize = 0;
        Newarray->Mainarray[i].L_Maxsize = 0;
        // If Data within each Mainarray needs further allocation, do it here
        // Newarray->Mainarray[i].Data = malloc(some_default_data_size);
    }

    return Newarray;
}


Array *Destroy_Entire_array(Array *Array) {
    
}
