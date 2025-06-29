// dynamic.h
#ifndef DYNAMIC_H
#define DYNAMIC_H
    
    #ifdef COUSTOM_LIB
        #include<Lib/Lib.h>
    #else
        #include <stdio.h>
        #include <stdlib.h>
        #include <stdarg.h>
        #include <string.h>
    #endif

// Memory tracking
static size_t total_alloc = 0;
static int tracking_enabled = 0;
#define malloc_track_switch(state) (tracking_enabled = (state))
#define malloc_with_track(sz) (tracking_enabled ? (total_alloc += (sz), malloc(sz)) : malloc(sz))
#define get_total_alloc()     (total_alloc)
// Memory part end is here

// Initializing the type:
typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_CHAR, TYPE_STRING } TYPE;

// Working with the structure code, define in basic data type
typedef union {
    int i;
    float f;
    char c;
    char* s;
} Data;

// Making more efficient to access with their type
typedef struct {
    TYPE type;
    Data value;
} Variant;

typedef enum MoDE { PRINT = 3, GET_MEMORY = 1, DEFINE_VARIANT = 2 } mode;

// Making all prototype functions
void* tyecasting_int(mode m, int vcount, ...);
void* tyecasting_float(mode m, int vcount, ...);
void* tyecasting_char(mode m, int vcount, ...);
void* tyecasting_string(mode m, int vcount, ...);
void universal_free(void* ptr, int count, mode m, TYPE type);

// Generic type detection
#define tyecasting_auto(m, vcount, ...) \
    _Generic((__VA_ARGS__, 0), \
        int: (void* (*)(mode, int, ...))tyecasting_int, \
        float: (void* (*)(mode, int, ...))tyecasting_float, \
        double: (void* (*)(mode, int, ...))tyecasting_float, \
        char: (void* (*)(mode, int, ...))tyecasting_char, \
        char*: (void* (*)(mode, int, ...))tyecasting_string \
    )(m, vcount, __VA_ARGS__)

void* tyecasting_int(mode m, int vcount, ...) {
    va_list args;
    va_start(args, vcount);
    void *result = NULL;

    if (m == GET_MEMORY) {
        int *arr = malloc_with_track(sizeof(int) * vcount);
        if (!arr) { va_end(args); return NULL; }
        for (int i = 0; i < vcount; i++)
            arr[i] = va_arg(args, int);
        result = arr;
    } else if (m == DEFINE_VARIANT) {
        Variant *arr = malloc_with_track(sizeof(Variant) * vcount);
        if (!arr) { va_end(args); return NULL; }
        for (int i = 0; i < vcount; i++) {
            arr[i].type = TYPE_INT;
            arr[i].value.i = va_arg(args, int);
        }
        result = arr;
    } else if (m == PRINT) {
        for (int i = 0; i < vcount; i++) {
            printf("[%d] = %d\n", i, va_arg(args, int));
        }
    }

    va_end(args);
    return result;
}

void* tyecasting_float(mode m, int vcount, ...) {
    va_list args;
    va_start(args, vcount);
    void *result = NULL;

    if (m == GET_MEMORY) {
        float *arr = malloc_with_track(sizeof(float) * vcount);
        if (!arr) { va_end(args); return NULL; }
        for (int i = 0; i < vcount; i++)
            arr[i] = (float)va_arg(args, double);
        result = arr;
    } else if (m == DEFINE_VARIANT) {
        Variant *arr = malloc_with_track(sizeof(Variant) * vcount);
        if (!arr) { va_end(args); return NULL; }
        for (int i = 0; i < vcount; i++) {
            arr[i].type = TYPE_FLOAT;
            arr[i].value.f = (float)va_arg(args, double);
        }
        result = arr;
    } else if (m == PRINT) {
        for (int i = 0; i < vcount; i++) {
            printf("[%d] = %.2f\n", i, (float)va_arg(args, double));
        }
    }

    va_end(args);
    return result;
}

void* tyecasting_char(mode m, int vcount, ...) {
    va_list args;
    va_start(args, vcount);
    void *result = NULL;

    if (m == GET_MEMORY) {
        char *arr = malloc_with_track(sizeof(char) * vcount);
        if (!arr) { va_end(args); return NULL; }
        for (int i = 0; i < vcount; i++)
            arr[i] = (char)va_arg(args, int);
        result = arr;
    } else if (m == DEFINE_VARIANT) {
        Variant *arr = malloc_with_track(sizeof(Variant) * vcount);
        if (!arr) { va_end(args); return NULL; }
        for (int i = 0; i < vcount; i++) {
            arr[i].type = TYPE_CHAR;
            arr[i].value.c = (char)va_arg(args, int);
        }
        result = arr;
    } else if (m == PRINT) {
        for (int i = 0; i < vcount; i++) {
            printf("[%d] = '%c'\n", i, (char)va_arg(args, int));
        }
    }

    va_end(args);
    return result;
}

void* tyecasting_string(mode m, int vcount, ...) {
    va_list args;
    va_start(args, vcount);
    void *result = NULL;

    if (m == GET_MEMORY) {
        char **arr = malloc_with_track(sizeof(char*) * vcount);
        if (!arr) { va_end(args); return NULL; }
        for (int i = 0; i < vcount; i++) {
            char *src = va_arg(args, char*);
            arr[i] = malloc_with_track(strlen(src) + 1);
            strcpy(arr[i], src);
        }
        result = arr;
    } else if (m == DEFINE_VARIANT) {
        Variant *arr = malloc_with_track(sizeof(Variant) * vcount);
        if (!arr) { va_end(args); return NULL; }
        for (int i = 0; i < vcount; i++) {
            arr[i].type = TYPE_STRING;
            char *src = va_arg(args, char*);
            arr[i].value.s = malloc_with_track(strlen(src) + 1);
            strcpy(arr[i].value.s, src);
        }
        result = arr;
    } else if (m == PRINT) {
        for (int i = 0; i < vcount; i++) {
            printf("[%d] = \"%s\"\n", i, va_arg(args, char*));
        }
    }

    va_end(args);
    return result;
}

// Universal free function for Variant and char** arrays
void universal_free(void* ptr, int count, mode m, TYPE type) {
    if (!ptr) return;

    if (m == GET_MEMORY) {
        if (type == TYPE_STRING) {
            char** arr = (char**)ptr;
            for (int i = 0; i < count; ++i)
                if (arr[i]) free(arr[i]);
        }
        free(ptr);
    } else if (m == DEFINE_VARIANT) {
        Variant* arr = (Variant*)ptr;
        for (int i = 0; i < count; ++i) {
            if (arr[i].type == TYPE_STRING && arr[i].value.s)
                free(arr[i].value.s);
        }
        free(ptr);
    }
}

#endif // DYNAMIC_H
