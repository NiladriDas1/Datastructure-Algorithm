#include "D:\Datastructure-Algorithm\src\Core\Memory\dynamic.h"

int main() {
    // Integer variant
    VTD *vi = Variant_vargs(TYPE_INT, 8, 10, 20, 30, 40,201,301,401,901);
    printf("\n-- INT Operations --\n");
    Variant_print(vi);

    Variant_Method(vi, Push, 55);         Variant_print(vi);

    Variant_Method(vi, Pop);              Variant_print(vi);
    
    Variant_print(Variant_Method(vi, Mid));
    Variant_print(Variant_Method(vi, End));
    Variant_print(Variant_Method(vi, Begin));
    Variant_Method(vi, Swap, 0, 2);       Variant_print(vi);
    
    /*Variant_print(Variant_Method(vi, Sum));

    Variant_print(Variant_Method(vi, Substract));*/
    Variant_print(Variant_Method(vi, Division));
    Variant_print(Variant_Method(vi, Avarage));

    
    Variant_print(Variant_Method(vi, Multiply));
    Variant_print(Variant_Method(vi, Count));
    Free_Variant(vi);

    
    // Char variant
    VTD *vc = Variant_vargs(TYPE_CHAR, 4, 'a', 'b', 'c', 'z');
    printf("\n-- CHAR Operations --\n");
    Variant_print(vc);
    Variant_Method(vc, Push, 'q');        Variant_print(vc);
    Variant_Method(vc, Pop);              Variant_print(vc);
    Variant_print(Variant_Method(vc, Mid));
    Variant_print(Variant_Method(vc, End));
    Variant_print(Variant_Method(vc, Begin));

    Variant_Method(vc, Swap, 1, 2);       Variant_print(vc);
    
    Variant_print(Variant_Method(vc, Sum));
    
    Variant_print(Variant_Method(vc, Substract));
 
    Variant_print(Variant_Method(vc, Division));
    Variant_print(Variant_Method(vc, Avarage));
    Variant_print(Variant_Method(vc, Min));
    Variant_print(Variant_Method(vc, Max));
    Variant_print(Variant_Method(vc, Mod));
    Variant_print(Variant_Method(vc, Multiply));
    Variant_print(Variant_Method(vc, Count));
    Free_Variant(vc);

    // String variant
    VTD *vs = Variant_vargs(TYPE_STRING, 3, "cat", "dog", "bird");
    printf("\n-- STRING Operations --\n");
    Variant_print(vs);
    Variant_Method(vs, Push, "lion");     Variant_print(vs);
    Variant_Method(vs, Pop);              Variant_print(vs);
    Variant_print(Variant_Method(vs, Mid));
    Variant_print(Variant_Method(vs, End));
    Variant_print(Variant_Method(vs, Begin));
    Variant_Method(vs, Swap, 0, 2);       Variant_print(vs);
    Variant_print(Variant_Method(vs, Sum));
    Variant_print(Variant_Method(vs, Substract));
    Variant_print(Variant_Method(vs, Division));
    Variant_print(Variant_Method(vs, Avarage));
    Variant_print(Variant_Method(vs, Min));
    Variant_print(Variant_Method(vs, Max));
    Variant_print(Variant_Method(vs, Mod));
    Variant_print(Variant_Method(vs, Multiply));
    Variant_print(Variant_Method(vs, Count));
    Free_Variant(vs);

    return 0;
}
