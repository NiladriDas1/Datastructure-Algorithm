#include "Array.h"

int main() {
    Array *myArray = Array_Create(10);
    if (!myArray) {
        fprintf(stderr, "Failed to create array.\n");
        return 1;
    }

    Print_array(myArray);

    // ✅ Create and link next node without using separate variable
    Create_Next_Linked_Array(myArray, 5);

    // Optional: Print the linked node via myArray->Point_matrix
    if (myArray->Point_matrix) {
        Print_array(myArray->Point_matrix);
    } else {
        fprintf(stderr, "Failed to link new node.\n");
    }
    InputArray(myArray, 5, 10);
    Print_array(myArray);

    // ✅ Destroy full chain starting from head
    Destroy_Entire_array(myArray);
    printf("Array destroyed successfully.\n");

    return 0;
}

