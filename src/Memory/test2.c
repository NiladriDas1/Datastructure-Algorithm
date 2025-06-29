// test_tyecasting.c
#include "dynamic2.h"
//#include "dynamic.h"

int main() {
    malloc_track_switch(1); // Enable memory tracking

    printf("== INT ARRAY ==\n");
    int* iarr = tyecasting_int(GET_MEMORY, 3, 10, 20, 30);
    tyecasting_int(PRINT, 3, 10, 20, 30);
    universal_free(iarr, 3, GET_MEMORY, TYPE_INT);

    printf("\n== FLOAT VARIANT ==\n");
    Variant* fvar = tyecasting_float(DEFINE_VARIANT, 2, 3.14, 6.28);
    for (int i = 0; i < 2; i++)
        printf("[%d] = %.2f (as variant)\n", i, fvar[i].value.f);
    universal_free(fvar, 2, DEFINE_VARIANT, TYPE_FLOAT);

    printf("\n== CHAR ARRAY ==\n");
    char* carr = tyecasting_char(GET_MEMORY, 4, 'A', 'B', 'C', 'D');
    tyecasting_char(PRINT, 4, 'A', 'B', 'C', 'D');
    universal_free(carr, 4, GET_MEMORY, TYPE_CHAR);

    printf("\n== STRING VARIANT ==\n");
    Variant* svar = tyecasting_string(DEFINE_VARIANT, 2, "Hello", "World");
    for (int i = 0; i < 2; i++)
        printf("[%d] = %s (as variant)\n", i, svar[i].value.s);
    universal_free(svar, 2, DEFINE_VARIANT, TYPE_STRING);

    printf("\n== STRING ARRAY ==\n");
    char** sarr = tyecasting_string(GET_MEMORY, 2, "OpenAI", "ChatGPT");
    for (int i = 0; i < 2; i++)
        printf("[%d] = %s\n", i, sarr[i]);
    universal_free(sarr, 2, GET_MEMORY, TYPE_STRING);

    printf("\nTotal allocated memory: %zu bytes\n", get_total_alloc());
    return 0;
}
