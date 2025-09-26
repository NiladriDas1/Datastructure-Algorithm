#include <stdio.h>
#include <stdlib.h>
#include "../Core/datastructure.h"



// Main test
int main() {
    unsigned int size = 8, len = 8;
    ARR *arr = Create_array(size, NULL);
    // Fill with int VTDs
    for (unsigned int i = 0; i < size; ++i) {
        arr[i].var_Data = New_IntVTD(i*2);
    }

    printf("Initial array:\n");
    ARR_PrintForward(arr, len);

    printf("\nBubble Sort:\n");
    ARR_BubbleSort(arr, len);
    ARR_PrintForward(arr, len);

    printf("\nSelection Sort:\n");
    ARR_SelectionSort(arr, len);
    ARR_PrintForward(arr, len);

    printf("\nReverse:\n");
    ARR_Reverse(arr, len);
    ARR_PrintForward(arr, len);

    printf("\nShuffle:\n");
    ARR_Shuffle(arr, len);
    ARR_PrintForward(arr, len);

    printf("\nLinear Search for 6:\n");
    VTD* searchVal = New_IntVTD(6);
    int index = ARR_LinearSearch(arr, len, searchVal);
    printf("Found at index: %d\n", index);

    printf("\nBinary Search after sorting for 6:\n");
    ARR_BubbleSort(arr, len);
    index = ARR_BinarySearch(arr, len, searchVal);
    printf("Found at index: %d\n", index);

    printf("\nMinimum element index:\n");
    printf("Min index: %d\n", ARR_Min(arr, len));

    printf("\nDeleting var_Data at index 3:\n");
    DeleteVarDataAt(arr, len, 3);
    ARR_PrintForward(arr, len);

    printf("\nDeduplicate (injecting duplicate):\n");
    arr[4].var_Data = New_IntVTD(4);
    arr[5].var_Data = New_IntVTD(4);
    ARR_Deduplicate(arr, len);
    ARR_PrintForward(arr, len);

    printf("\nSwap indices 2 and 6:\n");
    SwapIndicesAndUpdateLoc(arr, len, 2, 6);
    ARR_PrintForward(arr, len);

    printf("\nArray Info of arr[0]:\n");
    ArrayInfo(&arr[0]);

    printf("\nTesting loc API (InfoThroughLoc):\n");
    InfoThroughLoc(&arr[0], MID);

    printf("\nPushing back a value (10)...\n");
    VTD* newV = New_IntVTD(10);
    ARR_PushBack(arr, &len, newV, size);

    printf("\nFinalize - freeing everything:\n");
    FreearrayandLoc(arr, len);

    // more loc-specific API like ItrateThroughLoc, DeleteThroughLoc etc. can be called here with proper setup
    // for brevity, only signatures shown
    // e.g.
    // ItrateThroughLoc(&arr[0], NEXT);
    // DeleteThroughLoc(&arr[0], MID);

    free(searchVal);
    return 0;
}
