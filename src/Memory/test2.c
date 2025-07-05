// test_tyecasting.c
#include "dynamic2.h"
//#include "dynamic.h"

int main() {
    malloc_track_switch(1); // Enable memory tracking

    printf("== INT ARRAY ==\n");
    int* iarr = tyecasting_auto(GET_MEMORY, 3, 10, 20, 30);
    tyecasting_int(PRINT, 3, 10, 20, 30);
    universal_free(iarr, 3, GET_MEMORY, TYPE_INT);

    
    return 0;
}
