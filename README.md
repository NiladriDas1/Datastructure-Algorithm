# Datastructure-Algorithm
Making a comprehensive Framework  


## Function List & Usage
# Array:
**Array Creation & Info**
- `Create_array(T, ptr)` - Initializes array
- `ARRAYISNULL(Ptr)` - Checks if array is null
- `ArrayInfo(ptr)` - Prints array info

**Memory Management**
- `FreearrayandLoc(ptr, Len)` - Frees array and its data
- `OnlyFreeArrayVardata(ptr, Len)` - Frees only var_Data
- `OnlyFreeLoc(ptr, Len)` - Frees only location pointers
- `SpecificFreeLoc(ptr)` - Frees location pointers for one node

**Swaps**
- `SwapIndicesAndUpdateLoc(ptr, Len, i, j)`
- `Swap_EndToMid`, `Swap_MidToEnd`, `Swap_EndToBegin`,
`Swap_BeginToEnd`, `Swap_PriviousToNext`, `Swap_NextToPrivious`

**Deletions**
- `DeleteVarDataAt(arr, Len, idx)` - Delete VTD Data according to location 
- `DeleteVarData_Begin`, `DeleteVarData_End`, `DeleteVarData_Mid` 
- `DeleteVarData_Privious`, `DeleteVarData_Next`-Delete only Begin/End/Mid/Next/Privious VTD Data

**Search/Sort/Print**
- `ARR_LinearSearch(arr, Len, query)`- Perform the Linear Search 
- `ARR_BinarySearch(arr, Len, query)`-Perform the Binary Search 
- `ARR_BubbleSort(arr, Len)`, `ARR_SelectionSort(arr, Len)`-Perform the Bubble/selection sort 
- `ARR_PrintForward(arr, Len)` -Print The array 
- `ARR_QuickSort`, `ARR_Partition` 

**Merge/Manage**
- `ARR_Merge`, `ARR_MergeSort`, `ARR_InsertionSort`, `ARR_Shuffle`, `ARR_Min`, `ARR_Reverse`, `ARR_FilterZero`
- `ARR_PushBack(arr, Len*, data, Max)`

**Compare/Average/Dedup**
- `Variant_Compare_Multi(a, b)`
- `ARR_Average(arr, Len)`
- `ARR_Deduplicate(arr, Len)`

**Advanced Locators/Iterators**
- `ItrateThroughLoc(LOCARR, ITloc)`
- `DeleteThroughLoc(LOCARR, ITloc)`
- `UpdateThroughLoc(LOCARR, ITloc, ITloc2)`
- `InfoThroughLoc(LOCARR, ITloc)`
- `FreethorughLoc(LOCARR, ITloc)`

## Note:

- The test file just shows the usage and calling pattern—no expected output unless the framework and internals are in place.
- You can fill input data/types as your codebase requires.
