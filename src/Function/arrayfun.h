#include"../Core/datastructure.h"


/*
*  All Funciton of Prototype Basically algorithm Of Array 
*
*/








ARR *Create_array(unsigned int T, ARR *ptr);
enum ArrayisNull ARRAYISNULL(ARR *Ptr);
void ArrayInfo(ARR *ptr);

void FreearrayandLoc(ARR *ptr, unsigned int Len);
void OnlyFreeArrayVardata(ARR *ptr, unsigned int Len);
void OnlyFreeLoc(ARR *ptr, unsigned int Len);
void SpecificFreeLoc(ARR *ptr);

void SwapIndicesAndUpdateLoc(ARR *ptr, unsigned int Len, unsigned int i, unsigned int j);
void Swap_EndToMid(ARR *ptr, unsigned int Len);
void Swap_MidToEnd(ARR *ptr, unsigned int Len);
void Swap_EndToBegin(ARR *ptr, unsigned int Len);
void Swap_BeginToEnd(ARR *ptr, unsigned int Len);
void Swap_PriviousToNext(ARR *ptr, unsigned int Len);
void Swap_NextToPrivious(ARR *ptr, unsigned int Len);

void DeleteVarDataAt(ARR *arr, unsigned int Len, unsigned int idx);
void DeleteVarData_Begin(ARR *arr, unsigned int Len);
void DeleteVarData_End(ARR *arr, unsigned int Len);
void DeleteVarData_Mid(ARR *arr, unsigned int Len);
void DeleteVarData_Privious(ARR *elem, ARR *arr, unsigned int Len);
void DeleteVarData_Next(ARR *elem, ARR *arr, unsigned int Len);

int ARR_LinearSearch(ARR *arr, unsigned int Len, const VTD *query);
int ARR_BinarySearch(ARR *arr, unsigned int Len, const VTD *query);
void ARR_BubbleSort(ARR *arr, unsigned int Len);
void ARR_SelectionSort(ARR *arr, unsigned int Len);
void ARR_PrintForward(const ARR *arr, unsigned int Len);
void ARR_QuickSort(ARR *arr, int low, int high, unsigned int Len);
int ARR_Partition(ARR *arr, int low, int high, unsigned int Len);

void ARR_Merge(ARR *arr, unsigned int l, unsigned int m, unsigned int r, unsigned int Len);
void ARR_MergeSort(ARR *arr, unsigned int l, unsigned int r, unsigned int Len);
void ARR_InsertionSort(ARR *arr, unsigned int Len);
void ARR_Shuffle(ARR *arr, unsigned int Len);
int ARR_Min(ARR *arr, unsigned int Len);
void ARR_Reverse(ARR *arr, unsigned int Len);
void ARR_FilterZero(ARR *arr, unsigned int Len, int value);
void ARR_PushBack(ARR *arr, unsigned int *Len, VTD *data, unsigned int Max);
int Variant_Compare_Multi(const VTD *a, const VTD *b);
float ARR_Average(ARR *arr, unsigned int Len);
void ARR_Deduplicate(ARR *arr, unsigned int Len);


/*Complete these Loc code*/
static ARR* get_loc_node(ARR *base, ITRLOC loc);
void ItrateThroughLoc(ARR *LOCARR,ITRLOC ITloc);
void DeleteThroughLoc(ARR *LOCARR,ITRLOC ITloc);
void UpdateThroughLoc(ARR *LOCARR,ITRLOC ITloc,ITRLOC ITloc2);
void InfoThroughLoc(ARR *LOCARR,ITRLOC ITloc);
void FreethorughLoc(ARR *loc,ITRLOC ITloc);











