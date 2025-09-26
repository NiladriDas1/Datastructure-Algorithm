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












/*
*   Declearation of All prototype function 
*/

ARR *Create_array(unsigned int T, ARR *ptr) {
    if (!ptr) {
        ptr = (ARR *)malloc(T * sizeof(ARR));
        if (!ptr) return NULL;
        for (unsigned int i = 0; i < T; ++i) {
            ptr[i].Max = T;
            ptr[i].Loc.Privious = (i == 0) ? NULL : &ptr[i-1];
            ptr[i].Loc.Next = (i == T-1) ? NULL : &ptr[i+1];
            ptr[i].Loc.start = &ptr[0];
            ptr[i].Loc.end = &ptr[T-1];
            ptr[i].Loc.Mid = &ptr[T/2];  // rounds down for even T
            ptr[i].var_Data = NULL;
            ptr[i].Counter = 0;
            ptr[i].pos = i;
        }
        return ptr;
    }
    return ptr;
}



enum ArrayisNull ARRAYISNULL(ARR *Ptr){
    
 if (Ptr == NULL) {
        return Empty;
    } else {
        return NotEmpty;
    }

}


void FreearrayandLoc(ARR *ptr, unsigned int Len) {
    if (ARRAYISNULL(ptr) == Empty)
        return;

    for (unsigned int i = 0; i < Len; ++i) {
        if (ptr[i].var_Data != NULL)
            Free_Variant(ptr[i].var_Data);

    }
    free(ptr);
}

void OnlyFreeArrayVardata(ARR *ptr,unsigned int Len){
    /*This function actually for reuse the allocated array through free the variant*/
        if (ARRAYISNULL(ptr) == Empty)
        return;

    for (unsigned int i = 0; i < Len; ++i) {
        if (ptr[i].var_Data) Free_Variant(ptr[i].var_Data);
        ptr[i].var_Data = NULL;

    }
}
void OnlyFreeLoc(ARR *ptr,unsigned int Len){
        if (ARRAYISNULL(ptr) == Empty)
        return;
        /*this Function for reassing the all location with own coustom of choice */
    for (unsigned int i = 0; i < Len; ++i) {
        
            ptr[i].Loc.Privious = NULL;
            ptr[i].Loc.Next     = NULL;
            ptr[i].Loc.Mid      = NULL;
            ptr[i].Loc.end      = NULL;
            ptr[i].Loc.start    = NULL;
    
    }

    }
void SpecificFreeLoc(ARR *ptr){
    if (ARRAYISNULL(ptr) == Empty)
        return;
        ptr->Loc.Privious = NULL;
            ptr->Loc.Next     = NULL;
            ptr->Loc.Mid      = NULL;
            ptr->Loc.end      = NULL;
            ptr->Loc.start    = NULL;
    

}    

void SwapIndicesAndUpdateLoc(ARR *ptr, unsigned int Len, unsigned int i, unsigned int j) {
    if (!ptr || i >= Len || j >= Len || i == j ||ARRAYISNULL(ptr)) return;
    ARR tmp = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = tmp;
    for (unsigned int k = 0; k < Len; ++k) {
        ptr[k].Loc.Privious = (k == 0)     ? NULL      : &ptr[k-1];
        ptr[k].Loc.Next     = (k == Len-1) ? NULL      : &ptr[k+1];
        ptr[k].Loc.start    = &ptr[0];
        ptr[k].Loc.end      = &ptr[Len-1];
        ptr[k].Loc.Mid      = &ptr[Len/2];
        ptr[k].pos          = k;
    }
}


void Swap_EndToMid(ARR *ptr, unsigned int Len) {
    if (ARRAYISNULL(ptr))
    {
        return;
    }
    
    SwapIndicesAndUpdateLoc(ptr, Len, Len-1, Len/2);
}

void Swap_MidToEnd(ARR *ptr, unsigned int Len) {
    if (ARRAYISNULL(ptr))
    {
        return;
    }
    Swap_EndToMid(ptr, Len); // same as above
}

void Swap_EndToBegin(ARR *ptr, unsigned int Len) {
    if (ARRAYISNULL(ptr))
    {
        return;
    }
    SwapIndicesAndUpdateLoc(ptr, Len, Len-1, 0);
}

void Swap_BeginToEnd(ARR *ptr, unsigned int Len) {
    if (ARRAYISNULL(ptr))
    {
        return;
    }
    Swap_EndToBegin(ptr, Len); // same as above
}

// Swaps i with i+1 for all elements except the last
void Swap_PriviousToNext(ARR *ptr, unsigned int Len) {
    if (ARRAYISNULL(ptr))
    {
        return;
    }
    for (unsigned int i = 0; i < Len-1; ++i) {
        SwapIndicesAndUpdateLoc(ptr, Len, i, i+1);
    }
}

// Swaps i+1 with i for all elements except the first
void Swap_NextToPrivious(ARR *ptr, unsigned int Len) {
    if (ARRAYISNULL(ptr))
    {
        return;
    }
    for (unsigned int i = Len-1; i > 0; --i) {
        SwapIndicesAndUpdateLoc(ptr, Len, i, i-1);
    }
}

void DeleteVarDataAt(ARR *arr, unsigned int Len, unsigned int idx) {
    if (ARRAYISNULL(arr)|| !arr || idx >= Len) return;
    if (arr[idx].var_Data)
        Free_Variant(arr[idx].var_Data);
    arr[idx].var_Data = NULL;
}
void DeleteVarData_Begin(ARR *arr, unsigned int Len) {
    if (!arr||ARRAYISNULL(arr)) return;
    DeleteVarDataAt(arr, Len, 0);
}

void DeleteVarData_End(ARR *arr, unsigned int Len) {
    if (!arr||ARRAYISNULL(arr)) return;
    DeleteVarDataAt(arr, Len, Len-1);
}

void DeleteVarData_Mid(ARR *arr, unsigned int Len) {
    if (!arr||ARRAYISNULL(arr)) return;
    DeleteVarDataAt(arr, Len, Len/2);
}

// Delete at element's Privious (if exists)
void DeleteVarData_Privious(ARR *elem, ARR *arr, unsigned int Len) {
    if(!elem || ARRAYISNULL(elem)||ARRAYISNULL(arr)||!Len)return;
    if (elem->Loc.Privious)
        DeleteVarDataAt(arr, Len, elem->Loc.Privious->pos);
}

// Delete at element's Next (if exists)
void DeleteVarData_Next(ARR *elem, ARR *arr, unsigned int Len) {
    if(!elem || ARRAYISNULL(elem)||ARRAYISNULL(arr)||!Len)return;
    if (elem->Loc.Next)
        DeleteVarDataAt(arr, Len, elem->Loc.Next->pos);
}

int ARR_LinearSearch(ARR *arr, unsigned int Len, const VTD *query) {
    if(ARRAYISNULL(arr)|| !Len || query ==NULL)return;
    for (unsigned int i = 0; i < Len; ++i) {
        if (!arr[i].var_Data) continue;
        if (Variant_Compare(arr[i].var_Data, query) == 0)
            return i;
    }
    return -1;
}

int ARR_BinarySearch(ARR *arr, unsigned int Len, const VTD *query) {
    if(ARRAYISNULL(arr)|| !Len || query ==NULL)return;
    int lo = 0, hi = Len-1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int cmp = Variant_Compare(arr[mid].var_Data, query);
        if (cmp == 0) return mid;
        else if (cmp < 0) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
void ARR_BubbleSort(ARR *arr, unsigned int Len) {
    if(ARRAYISNULL(arr)|| !Len )return;
    for (unsigned int i = 0; i < Len-1; ++i) {
        for (unsigned int j = 0; j < Len-i-1; ++j) {
            if (arr[j].var_Data && arr[j+1].var_Data &&
                Variant_Compare(arr[j].var_Data, arr[j+1].var_Data) > 0) {
                SwapIndicesAndUpdateLoc(arr, Len, j, j+1);
            }
        }
    }
}
void ARR_SelectionSort(ARR *arr, unsigned int Len) {
    if(ARRAYISNULL(arr)|| !Len )return;
    for (unsigned int i = 0; i < Len-1; ++i) {
        unsigned int min_idx = i;
        for (unsigned int j = i+1; j < Len; ++j) {
            if (arr[j].var_Data &&
                Variant_Compare(arr[j].var_Data, arr[min_idx].var_Data) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i)
            SwapIndicesAndUpdateLoc(arr, Len, i, min_idx);
    }
}
void ARR_PrintForward(const ARR *arr, unsigned int Len) {
    if(arr==NULL|| !Len )return;
    const ARR *current = &arr[0];
    while (current) {
        if (current->var_Data)
            Variant_print(current->var_Data);
        current = current->Loc.Next;
    }
}
void ARR_QuickSort(ARR *arr, int low, int high, unsigned int Len) {
    if(ARRAYISNULL(arr)|| !Len || !low || !high)return;
    if (low < high) {
        int pi = ARR_Partition(arr, low, high, Len);
        ARR_QuickSort(arr, low, pi - 1, Len);
        ARR_QuickSort(arr, pi + 1, high, Len);
    }
}
int ARR_Partition(ARR *arr, int low, int high, unsigned int Len) {
    if(ARRAYISNULL(arr)|| !Len || !low || !high)return;
    VTD *pivot = arr[high].var_Data;
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (Variant_Compare(arr[j].var_Data, pivot) < 0) {
            ++i;
            SwapIndicesAndUpdateLoc(arr, Len, i, j);
        }
    }
    SwapIndicesAndUpdateLoc(arr, Len, i + 1, high);
    return (i + 1);
}

void ARR_Merge(ARR *arr, unsigned int l, unsigned int m, unsigned int r, unsigned int Len) {
    if(ARRAYISNULL(arr)|| !Len || !l || !m || !r || !Len)return;
    unsigned int n1 = m - l + 1, n2 = r - m;
    ARR *L =(ARR*)malloc(n1 * sizeof(ARR));
    ARR *R =(ARR*)malloc(n2 * sizeof(ARR));
    if (ARRAYISNULL(L) || ARRAYISNULL(R))
    {
        return ;
    }
    
    for (unsigned int i = 0; i < n1; ++i) L[i] = arr[l+i];
    for (unsigned int j = 0; j < n2; ++j) R[j] = arr[m+1+j];
    unsigned int i=0, j=0, k=l;
    while (i < n1 && j < n2)
        arr[k++] = (Variant_Compare(L[i].var_Data, R[j].var_Data) <= 0) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
    for (unsigned int idx = 0; idx < Len; ++idx) {
        arr[idx].Loc.Privious = (idx == 0) ? NULL : &arr[idx-1];
        arr[idx].Loc.Next     = (idx == Len-1) ? NULL : &arr[idx+1];
        arr[idx].Loc.start    = &arr[0];
        arr[idx].Loc.end      = &arr[Len-1];
        arr[idx].Loc.Mid      = &arr[Len/2];
        arr[idx].pos          = idx;
    }
}
void ARR_MergeSort(ARR *arr, unsigned int l, unsigned int r, unsigned int Len) {
    if(ARRAYISNULL(arr)|| !Len || !r || !l)return;
    if (l < r) {
        unsigned int m = l + (r - l) / 2;
        ARR_MergeSort(arr, l, m, Len);
        ARR_MergeSort(arr, m+1, r, Len);
        ARR_Merge(arr, l, m, r, Len);
    }
}

 void ARR_InsertionSort(ARR *arr, unsigned int Len) {
    if (ARRAYISNULL(arr)|| !Len) return;
    
    
    for (unsigned int i=1; i < Len; ++i) {
        ARR key = arr[i];
        int j = i-1;
        while (j >= 0 && Variant_Compare(arr[j].var_Data, key.var_Data) > 0) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
    for (unsigned int idx=0; idx<Len; ++idx) {
        arr[idx].Loc.Privious = (idx == 0)? NULL : &arr[idx-1];
        arr[idx].Loc.Next     = (idx == Len-1)? NULL : &arr[idx+1];
        arr[idx].Loc.start    = &arr[0];
        arr[idx].Loc.end      = &arr[Len-1];
        arr[idx].Loc.Mid      = &arr[Len/2];
        arr[idx].pos          = idx;
    }
}

void ARR_Shuffle(ARR *arr, unsigned int Len) {
    if (ARRAYISNULL(arr)|| !Len) return;
    for (unsigned int i = Len - 1; i > 0; --i) {
        unsigned int j = rand() % (i+1);
        SwapIndicesAndUpdateLoc(arr, Len, i, j);
    }
}

int ARR_Min(ARR *arr, unsigned int Len) {
    if (ARRAYISNULL(arr)|| !Len) return 1;
    if (!arr || Len==0) return -1;
    unsigned int min_idx = 0;
    for (unsigned int i=1; i < Len; ++i) {
        if (Variant_Compare(arr[i].var_Data, arr[min_idx].var_Data) < 0)
            min_idx = i;
    }
    return min_idx;
}

void ARR_Reverse(ARR *arr, unsigned int Len) {
    if (ARRAYISNULL(arr)|| !Len) return;
    for (unsigned int i=0; i < Len/2; ++i) {
        SwapIndicesAndUpdateLoc(arr, Len, i, Len-i-1);
    }
}

void ARR_FilterZero(ARR *arr, unsigned int Len, int value) {
    if (ARRAYISNULL(arr)|| !Len ||!value) return;
    for (unsigned int i=0; i < Len; ++i) {
        if (arr[i].var_Data && arr[i].var_Data->type == TYPE_INT && arr[i].var_Data->value.i[0] == value) {
            arr[i].var_Data->value.i[0] = 0;
        }
    }
}

void ARR_PushBack(ARR *arr, unsigned int *Len, VTD *data, unsigned int Max) {
    if(ARRAYISNULL(arr)||!Len||!Max ||VTDisNull(data));
    if (*Len < Max) {
        arr[*Len].var_Data = data;
        arr[*Len].pos = *Len;
        ++(*Len);
        for (unsigned int i=0; i < *Len; ++i) {
            arr[i].Loc.Privious = (i == 0)? NULL : &arr[i-1];
            arr[i].Loc.Next = (i == *Len-1)? NULL : &arr[i+1];
            arr[i].Loc.start = &arr[0];
            arr[i].Loc.end = &arr[*Len-1];
            arr[i].Loc.Mid = &arr[*Len/2];
            arr[i].pos = i;
        }
    }
}

int Variant_Compare_Multi(const VTD *a, const VTD *b) {
    if (!a || !b) return 0;
    if (a->type == TYPE_INT && b->type == TYPE_INT) {
        if (a->length < 2 || b->length < 2) return 0;
        if (a->value.i[0] == b->value.i[0])
            return a->value.i[1] - b->value.i[1];
        return a->value.i[0] - b->value.i[0];
    }
    return Variant_Compare(a, b);
}

float ARR_Average(ARR *arr, unsigned int Len) {
    if(ARRAYISNULL(arr)||!Len)return;
    float sum = 0; unsigned int count = 0;
    for (unsigned int i=0; i<Len; ++i) {
        if (arr[i].var_Data && arr[i].var_Data->type == TYPE_FLOAT) {
            sum += arr[i].var_Data->value.f[0];
            ++count;
        }
    }
    return count > 0 ? sum / count : 0.0f;
}

void ARR_Deduplicate(ARR *arr, unsigned int Len) {
    if(ARRAYISNULL(arr)||!Len) return;
    for (unsigned int i=0; i<Len; ++i) {
        for (unsigned int j=i+1; j<Len; ++j) {
            if (arr[i].var_Data && arr[j].var_Data &&
                Variant_Compare(arr[i].var_Data, arr[j].var_Data) == 0)
                arr[j].var_Data->value.i[0] = 0; // Mark duplicate
        }
    }
}

void ArrayInfo(ARR *ptr) {
    if (ARRAYISNULL(ptr) || !ptr) return;

    // Print addresses of all pointer fields in loc struct
    printf("Loc.end:      %p\n", (void*)ptr->Loc.end);
    printf("Loc.Mid:      %p\n", (void*)ptr->Loc.Mid);
    printf("Loc.Next:     %p\n", (void*)ptr->Loc.Next);
    printf("Loc.Privious: %p\n", (void*)ptr->Loc.Privious);
    printf("Loc.start:    %p\n", (void*)ptr->Loc.start);

    // Print other fields of ARR struct
    printf("var_Data:     %p\n", (void*)ptr->var_Data);
    printf("Counter:      %u\n", ptr->Counter);
    printf("Max:          %d\n", ptr->Max);
    printf("pos:          %u\n", ptr->pos);
}


// Returns the node corresponding to type in ITRLOC enum, or NULL if not available.
static ARR* get_loc_node(ARR *base, ITRLOC loc) {
    if (!base) return NULL;
    switch (loc) {
        case MID:      return base->Loc.Mid;
        case END:      return base->Loc.end;
        case START:    return base->Loc.start;
        case PRIVIOUS: return base->Loc.Privious;
        case NEXT:     return base->Loc.Next;
        default:       return NULL;
    }
}


void ItrateThroughLoc(ARR *LOCARR, ITRLOC ITloc) {
    if (!LOCARR) return;

    ARR *cur = NULL;
    if (ITloc == START || ITloc == END || ITloc == MID ||
        ITloc == PRIVIOUS || ITloc == NEXT)
        cur = get_loc_node(LOCARR, ITloc);

    // If not found, fallback to LOCARR itself
    if (!cur) cur = LOCARR;

    // Decide iteration direction: forward, backward, or single node
    switch (ITloc) {
        case START:
             while (cur) {
                Variant_print(cur->var_Data);
                printf("pos: %u\n", cur->pos);
                printf("%u->",cur->Loc.start);
                
                cur = cur->Loc.start;
            }
            break;
        case NEXT:
         while (cur) {
                Variant_print(cur->var_Data);
                printf("pos: %u\n", cur->pos);
                printf("%u",cur->Loc.Next);
                
                cur = cur->Loc.Next;
            }
            break;
        case MID:
            // Forward iteration
            while (cur) {
                Variant_print(cur->var_Data);
                printf("pos: %u\n", cur->pos);
                printf("%u",cur->Loc.Mid);
                
                cur = cur->Loc.Mid;
            }
            break;
        case END:
             while (cur) {
                Variant_print(cur->var_Data);
                printf("pos: %u\n", cur->pos);
                printf("%u",cur->Loc.end);
                
                cur = cur->Loc.end;
            }
            break;
        case PRIVIOUS:
            // Backward iteration
            while (cur) {
                printf("pos: %u\n", cur->pos);
                cur = cur->Loc.Privious;
            }
            break;
        default:
            // Single node
            printf("pos: %u\n", cur->pos);
            break;
    }
}


void DeleteThroughLoc(ARR *LOCARR, ITRLOC ITloc) {
    if (!LOCARR) return;
    ARR *Temp = get_loc_node(LOCARR, ITloc);
    if (!Temp) Temp = LOCARR;

    switch (ITloc)
    {
        case MID: {
            // Only free the internal var_Data of the MID node
            if (Temp->var_Data) {
                Free_Variant(Temp->var_Data);
                Temp->var_Data = NULL;
            }
            // Optionally clear other fields if desired
            break;
        }

        case END: {
            // Unlink the END node from the chain
            if (Temp->Loc.Privious)
                Temp->Loc.Privious->Loc.Next = NULL;
            if (Temp->var_Data) {
                Free_Variant(Temp->var_Data);
                Temp->var_Data = NULL;
            }
            Temp->Loc.Privious = NULL;
            Temp->Loc.Next = NULL;
            Temp->Loc.Mid = NULL;
            Temp->Loc.start = NULL;
            Temp->Loc.end = NULL;
            free(Temp);
            break;
        }

        case START: {
            // Unlink the START node from the chain
            if (Temp->Loc.Next)
                Temp->Loc.Next->Loc.Privious = NULL;
            if (Temp->var_Data) {
                Free_Variant(Temp->var_Data);
                Temp->var_Data = NULL;
            }
            Temp->Loc.Privious = NULL;
            Temp->Loc.Next = NULL;
            Temp->Loc.Mid = NULL;
            Temp->Loc.start = NULL;
            Temp->Loc.end = NULL;
            free(Temp);
            break;
        }

        case PRIVIOUS: {
            // Unlink the previous node of LOCARR (if it exists)
            ARR *prev = Temp->Loc.Privious;
            if (prev) {
                if (prev->Loc.Privious)
                    prev->Loc.Privious->Loc.Next = prev->Loc.Next;
                if (prev->Loc.Next)
                    prev->Loc.Next->Loc.Privious = prev->Loc.Privious;
                if (prev->var_Data) {
                    Free_Variant(prev->var_Data);
                    prev->var_Data = NULL;
                }
                prev->Loc.Privious = NULL;
                prev->Loc.Next = NULL;
                prev->Loc.Mid = NULL;
                prev->Loc.start = NULL;
                prev->Loc.end = NULL;
                free(prev);
            }
            break;
        }

        case NEXT: {
            // Unlink the next node of LOCARR (if it exists)
            ARR *next = Temp->Loc.Next;
            if (next) {
                if (next->Loc.Next)
                    next->Loc.Next->Loc.Privious = next->Loc.Privious;
                if (next->Loc.Privious)
                    next->Loc.Privious->Loc.Next = next->Loc.Next;
                if (next->var_Data) {
                    Free_Variant(next->var_Data);
                    next->var_Data = NULL;
                }
                next->Loc.Privious = NULL;
                next->Loc.Next = NULL;
                next->Loc.Mid = NULL;
                next->Loc.start = NULL;
                next->Loc.end = NULL;
                free(next);
            }
            break;
        }

        default:
            // If ITRLOC is not recognized, just free Temp's var_Data
            if (Temp->var_Data) {
                Free_Variant(Temp->var_Data);
                Temp->var_Data = NULL;
            }
            break;
    }
}





void FreethorughLoc(ARR *loc,ITRLOC ITloc){
    if(!ITloc||!loc||ARRAYISNULL(loc))return;
    switch (ITloc)
    {
        case MID:
            Free_Variant(loc->Loc.Mid->var_Data);
            loc->Loc.Mid->var_Data=NULL;
            loc->Loc.Mid=NULL;
            break;
        case NEXT:
            Free_Variant(loc->Loc.Next->var_Data);
            loc->Loc.Next->var_Data=NULL;
            loc->Loc.Next=NULL;
            break;
        case PRIVIOUS:
            Free_Variant(loc->Loc.Privious->var_Data);
            loc->Loc.Privious->var_Data=NULL;
            loc->Loc.Privious=NULL;
            break;
        case START:
        Free_Variant(loc->Loc.start->var_Data);
            loc->Loc.start->var_Data=NULL;
            loc->Loc.start=NULL;   
        case END:
        Free_Variant(loc->Loc.end->var_Data);
            loc->Loc.end->var_Data=NULL;
            loc->Loc.end=NULL;
        default:
            return;
            break;
    }

}

void UpdateThroughLoc(ARR *LOCARR, ITRLOC ITloc, ITRLOC ITloc2) {
    struct Array **loc1 = NULL, **loc2 = NULL;

    // Assign pointers based on enum location
    switch (ITloc) {
        case MID:      loc1 = &(LOCARR->Loc.Mid); break;
        case END:      loc1 = &(LOCARR->Loc.end); break;
        case START:    loc1 = &(LOCARR->Loc.start); break;
        case PRIVIOUS: loc1 = &(LOCARR->Loc.Privious); break;
        case NEXT:     loc1 = &(LOCARR->Loc.Next); break;
    }
    switch (ITloc2) {
        case MID:      loc2 = &(LOCARR->Loc.Mid); break;
        case END:      loc2 = &(LOCARR->Loc.end); break;
        case START:    loc2 = &(LOCARR->Loc.start); break;
        case PRIVIOUS: loc2 = &(LOCARR->Loc.Privious); break;
        case NEXT:     loc2 = &(LOCARR->Loc.Next); break;
    }
    if (loc1 && loc2) {
        struct Array *tmp = *loc1;
        *loc1 = *loc2;
        *loc2 = tmp;
    }
}





void InfoThroughLoc(ARR *LOCARR, ITRLOC ITloc) {
    struct Array *ptr = NULL;
    const char *loc_name = "";

    switch (ITloc) {
        case MID:      ptr = LOCARR->Loc.Mid; loc_name = "MID"; break;
        case END:      ptr = LOCARR->Loc.end; loc_name = "END"; break;
        case START:    ptr = LOCARR->Loc.start; loc_name = "START"; break;
        case PRIVIOUS: ptr = LOCARR->Loc.Privious; loc_name = "PRIVIOUS"; break;
        case NEXT:     ptr = LOCARR->Loc.Next; loc_name = "NEXT"; break;
    }

    printf("[LOCARR %p] Loc.%s = %p\n", (void *)LOCARR, loc_name, (void *)ptr);
    if (ptr) {
        // Show details of the referenced ARR node
        printf(
            "  At %s: VTD* = %p, pos = %u, Counter = %u, Max = %d\n",
            loc_name, (void *)ptr->var_Data, ptr->pos, ptr->Counter, ptr->Max
        );
    } else {
        printf("  [NULL node at %s]\n", loc_name);
    }
    // Optionally, print info about current node
    printf(
        "Current: VTD* = %p, pos = %u, Counter = %u, Max = %d\n",
        (void *)LOCARR->var_Data, LOCARR->pos, LOCARR->Counter, LOCARR->Max
    );
}
