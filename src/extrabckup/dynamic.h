#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAX_VARGS 10

typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_CHAR, TYPE_STRING } TYPE;
typedef enum Method{Push,Pop,Mid,End,Begin,Swap,Sum,Substract,Division,Avarage,Min,Max,Mod,Multiply,Count}METH;
typedef union {
    int *i;
    float *f;
    char *c;
    char **s;
    void *ptr;
} Data;

typedef struct Variant {
    TYPE type;
    size_t length;
    Data value;
} VTD;

void Free_Variant(VTD *ptr);
int Variant_Compare(const VTD *a, const VTD *b);
static void free_string_array(char **arr, size_t len);
VTD *Variant_vargs(TYPE T, size_t count, ...);
void Variant_print(const VTD *v);
int Variant_search(const VTD *v, const void *value); 
int Variant_update(VTD *v, const void *oldv, const void *newv);
int Variant_delete(VTD *v, const void *value) ;
int Variant_resize(VTD *v, size_t new_len);
void Variant_throw(const char *msg);
VTD *Variant_Method(VTD *V, METH M, ...);
int VTDisNull(VTD *ptr);

void Free_Variant(VTD *ptr) {
    if (!ptr) return;
    if (ptr->type == TYPE_STRING && ptr->value.s) {
        for (size_t i = 0; i < ptr->length; ++i)
            if (ptr->value.s[i]) free(ptr->value.s[i]);
        free(ptr->value.s);
    } else if (ptr->value.ptr) {
        free(ptr->value.ptr);
    }
    free(ptr);
}
static void free_string_array(char **arr, size_t len) {
    if (!arr) return;
    for (size_t i = 0; i < len; ++i)
        if (arr[i]) free(arr[i]);
    free(arr);
}
// --- Variant Builder with va_args ---
VTD *Variant_vargs(TYPE T, size_t count, ...) {
    if (count == 0 || count > MAX_VARGS) return NULL;
    VTD *v = calloc(1, sizeof(VTD));
    if (!v) return NULL;
    v->type = T;
    v->length = count;
    va_list ap;
    va_start(ap, count);

    switch (T) {
        case TYPE_INT:
            v->value.i = calloc(count, sizeof(int));
            for (size_t i = 0; i < count; ++i)
                v->value.i[i] = va_arg(ap, int);
            break;
        case TYPE_FLOAT:
            v->value.f = calloc(count, sizeof(float));
            for (size_t i = 0; i < count; ++i)
                v->value.f[i] = (float)va_arg(ap, double);
            break;
        case TYPE_CHAR:
            v->value.c = calloc(count, sizeof(char));
            for (size_t i = 0; i < count; ++i)
                v->value.c[i] = (char)va_arg(ap, int);
            break;
        case TYPE_STRING:
            v->value.s = calloc(count, sizeof(char*));
            for (size_t i = 0; i < count; ++i) {
                char *tmp = va_arg(ap, char*);
                v->value.s[i] = strdup(tmp ? tmp : "");
            }
            break;
        default:
            va_end(ap);
            Free_Variant(v);
            return NULL;
    }
    va_end(ap);
    return v;
}

// --- Printing ---
void Variant_print(const VTD *v) {
    if (!v) { printf("NULL\n"); return; }
    if (v->length == 0 || !v->value.ptr) { printf("Empty Variant\n"); return; }
    switch (v->type) {
        case TYPE_INT:
            printf("Integer array (%zu): ", v->length);
            for (size_t i = 0; i < v->length; ++i) printf("%d ", v->value.i[i]);
            printf("\n"); break;
        case TYPE_FLOAT:
            printf("Float array (%zu): ", v->length);
            for (size_t i = 0; i < v->length; ++i) printf("%f ", v->value.f[i]);
            printf("\n"); break;
        case TYPE_CHAR:
            printf("Char array (%zu): ", v->length);
            for (size_t i = 0; i < v->length; ++i) printf("%c ", v->value.c[i]);
            printf("\n"); break;
        case TYPE_STRING:
            printf("String array (%zu): ", v->length);
            for (size_t i = 0; i < v->length; ++i) printf("\"%s\" ", v->value.s[i]);
            printf("\n"); break;
        default: printf("\nUnknown\n");
    }
}

// --- Search ---
int Variant_search(const VTD *v, const void *value) {
    if (!v || v->length == 0 || !value) return -1;
    switch (v->type) {
        case TYPE_INT: {
            int x = *(int *)value;
            for (size_t i = 0; i < v->length; ++i)
                if (v->value.i[i] == x) return (int)i;
            break;
        }
        case TYPE_FLOAT: {
            float x = *(float *)value;
            for (size_t i = 0; i < v->length; ++i)
                if (v->value.f[i] == x) return (int)i;
            break;
        }
        case TYPE_CHAR: {
            char x = *(char *)value;
            for (size_t i = 0; i < v->length; ++i)
                if (v->value.c[i] == x) return (int)i;
            break;
        }
        case TYPE_STRING: {
            char *x = (char *)value;
            for (size_t i = 0; i < v->length; ++i)
                if (strcmp(v->value.s[i], x) == 0) return (int)i;
            break;
        }
    }
    return -1;
}

// --- Update ---
int Variant_update(VTD *v, const void *oldv, const void *newv) {
    int found = 0;
    int idx = Variant_search(v, oldv);
    if (idx < 0) return 0;
    switch (v->type) {
        case TYPE_INT: v->value.i[idx] = *(int *)newv; found = 1; break;
        case TYPE_FLOAT: v->value.f[idx] = *(float *)newv; found = 1; break;
        case TYPE_CHAR: v->value.c[idx] = *(char *)newv; found = 1; break;
        case TYPE_STRING: {
            free(v->value.s[idx]);
            v->value.s[idx] = strdup((const char *)newv);
            found = 1;
            break;
        }
    }
    return found;
}

// --- Delete ---
int Variant_delete(VTD *v, const void *value) {
    int idx = Variant_search(v, value);
    if (idx < 0) return 0;
    switch (v->type) {
        case TYPE_INT: v->value.i[idx] = 0; break;
        case TYPE_FLOAT: v->value.f[idx] = 0.0f; break;
        case TYPE_CHAR: v->value.c[idx] = '\0'; break;
        case TYPE_STRING:
            free(v->value.s[idx]);
            v->value.s[idx] = strdup("");
            break;
    }
    return 1;
}

// --- Resize ---
int Variant_resize(VTD *v, size_t new_len) {
    if (!v || new_len == 0 || new_len > MAX_VARGS) return 0;
    if (v->type == TYPE_INT) {
        int *newarr = realloc(v->value.i, new_len * sizeof(int));
        if (!newarr) return 0;
        for (size_t i = v->length; i < new_len; ++i) newarr[i] = 0;
        v->value.i = newarr;
    } else if (v->type == TYPE_FLOAT) {
        float *newarr = realloc(v->value.f, new_len * sizeof(float));
        if (!newarr) return 0;
        for (size_t i = v->length; i < new_len; ++i) newarr[i] = 0.0f;
        v->value.f = newarr;
    } else if (v->type == TYPE_CHAR) {
        char *newarr = realloc(v->value.c, new_len * sizeof(char));
        if (!newarr) return 0;
        for (size_t i = v->length; i < new_len; ++i) newarr[i] = '\0';
        v->value.c = newarr;
    } else if (v->type == TYPE_STRING) {
        char **newarr = realloc(v->value.s, new_len * sizeof(char*));
        if (!newarr) return 0;
        for (size_t i = v->length; i < new_len; ++i) newarr[i] = strdup("");
        v->value.s = newarr;
    }
    v->length = new_len;
    return 1;
}

// --- Throw ---
void Variant_throw(const char *msg) {
    fprintf(stderr, "[VTD ERROR]: %s\n", msg);
    exit(EXIT_FAILURE);
}

VTD *Variant_Method(VTD *V, METH M, ...) {
    if (!V) return NULL;

    va_list ap;
    va_start(ap, M);

    switch (M) {
        case Push: {
            // Push: Add new element to end
            if (V->length >= MAX_VARGS) {
                va_end(ap);
                return V;
            }
            // Allocate new variant with +1 length
            size_t new_len = V->length + 1;
            Variant_resize(V, new_len);
            // Add new value at last index
            switch (V->type) {
                case TYPE_INT:   V->value.i[new_len-1] = va_arg(ap, int);          break;
                case TYPE_FLOAT: V->value.f[new_len-1] = (float)va_arg(ap, double);break;
                case TYPE_CHAR:  V->value.c[new_len-1] = (char)va_arg(ap, int);    break;
                case TYPE_STRING:
                    V->value.s[new_len-1] = strdup(va_arg(ap, char *));
                    break;
            }
            break;
        }
        case Pop: {
            // Pop: Remove last element
            if (V->length == 0) break;
            if (V->type == TYPE_STRING && V->value.s[V->length-1])
                free(V->value.s[V->length-1]);
            Variant_resize(V, V->length-1);
            break;
        }
        case Mid: {
            // Return new Variant containing only mid element
            if (V->length == 0) break;
            size_t mid = V->length / 2;
            VTD *mid_variant = NULL;
            switch (V->type) {
                case TYPE_INT:
                    mid_variant = Variant_vargs(TYPE_INT, 1, V->value.i[mid]);
                    break;
                case TYPE_FLOAT:
                    mid_variant = Variant_vargs(TYPE_FLOAT, 1, V->value.f[mid]);
                    break;
                case TYPE_CHAR:
                    mid_variant = Variant_vargs(TYPE_CHAR, 1, V->value.c[mid]);
                    break;
                case TYPE_STRING:
                    mid_variant = Variant_vargs(TYPE_STRING, 1, V->value.s[mid]);
                    break;
            }
            va_end(ap);
            return mid_variant;
        }
        case End: {
            // Return new Variant containing last element
            if (V->length == 0) break;
            size_t idx = V->length - 1;
            VTD *end_variant = NULL;
            switch (V->type) {
                case TYPE_INT:    end_variant = Variant_vargs(TYPE_INT, 1, V->value.i[idx]);        break;
                case TYPE_FLOAT:  end_variant = Variant_vargs(TYPE_FLOAT, 1, V->value.f[idx]);      break;
                case TYPE_CHAR:   end_variant = Variant_vargs(TYPE_CHAR, 1, V->value.c[idx]);       break;
                case TYPE_STRING: end_variant = Variant_vargs(TYPE_STRING, 1, V->value.s[idx]);     break;
            }
            va_end(ap);
            return end_variant;
        }
        case Begin: {
            // Return new Variant containing first element
            if (V->length == 0) break;
            VTD *begin_variant = NULL;
            switch (V->type) {
                case TYPE_INT:    begin_variant = Variant_vargs(TYPE_INT, 1, V->value.i[0]);        break;
                case TYPE_FLOAT:  begin_variant = Variant_vargs(TYPE_FLOAT, 1, V->value.f[0]);      break;
                case TYPE_CHAR:   begin_variant = Variant_vargs(TYPE_CHAR, 1, V->value.c[0]);       break;
                case TYPE_STRING: begin_variant = Variant_vargs(TYPE_STRING, 1, V->value.s[0]);     break;
            }
            va_end(ap);
            return begin_variant;
        }
        case Swap: {
            // Swap two elements: Provide two indices
            int idx1 = va_arg(ap, int);
            int idx2 = va_arg(ap, int);
            if (idx1 < 0 || idx2 < 0 || idx1 >= V->length || idx2 >= V->length) break;
            switch (V->type) {
                case TYPE_INT: {
                    int tmp = V->value.i[idx1];
                    V->value.i[idx1] = V->value.i[idx2];
                    V->value.i[idx2] = tmp;
                    break;
                }
                case TYPE_FLOAT: {
                    float tmp = V->value.f[idx1];
                    V->value.f[idx1] = V->value.f[idx2];
                    V->value.f[idx2] = tmp;
                    break;
                }
                case TYPE_CHAR: {
                    char tmp = V->value.c[idx1];
                    V->value.c[idx1] = V->value.c[idx2];
                    V->value.c[idx2] = tmp;
                    break;
                }
                case TYPE_STRING: {
                    char *tmp = V->value.s[idx1];
                    V->value.s[idx1] = V->value.s[idx2];
                    V->value.s[idx2] = tmp;
                    break;
                }
            }
            break;
        }
                    // Add more methods if needed
                    case Sum: {
                int total_i = 0;
                float total_f = 0;
                switch (V->type) {
                    case TYPE_INT:
                        for (size_t i = 0; i < V->length; ++i) total_i += V->value.i[i];
                        return Variant_vargs(TYPE_INT, 1, total_i);
                    case TYPE_FLOAT:
                        for (size_t i = 0; i < V->length; ++i) total_f += V->value.f[i];
                        return Variant_vargs(TYPE_FLOAT, 1, total_f);
                    case TYPE_CHAR:
                        for (size_t i = 0; i < V->length; ++i) total_i += (unsigned char)V->value.c[i];
                        return Variant_vargs(TYPE_CHAR, 1, total_i % 256); // ASCII back to char
                    case TYPE_STRING: {
                        total_i = 0;
                        for (size_t i = 0; i < V->length; ++i)
                            for (char *p = V->value.s[i]; *p; ++p)
                                total_i += (unsigned char)*p;
                        char str[2] = { (char)(total_i % 256), '\0' };
                        return Variant_vargs(TYPE_STRING, 1, str);
                    }
                }
                break;
            }
            case Substract: {
                if (V->length == 0) break;
                int res_i = V->type == TYPE_INT ? V->value.i[0] : (V->type == TYPE_CHAR ? (unsigned char)V->value.c[0] : V->type == TYPE_STRING ? (unsigned char)V->value.s[0][0] : 0);
                float res_f = V->type == TYPE_FLOAT ? V->value.f[0] : 0;
                switch (V->type) {
                    case TYPE_INT:
                        for (size_t i = 1; i < V->length; ++i) res_i -= V->value.i[i];
                        return Variant_vargs(TYPE_INT, 1, res_i);
                    case TYPE_FLOAT:
                        for (size_t i = 1; i < V->length; ++i) res_f -= V->value.f[i];
                        return Variant_vargs(TYPE_FLOAT, 1, res_f);
                    case TYPE_CHAR:
                        for (size_t i = 1; i < V->length; ++i) res_i -= (unsigned char)V->value.c[i];
                        return Variant_vargs(TYPE_CHAR, 1, res_i % 256);
                    case TYPE_STRING:
                        for (size_t i = 1; i < V->length; ++i) res_i -= (unsigned char)V->value.s[i][0];
                        char str[2] = { (char)(res_i % 256), '\0' };
                        return Variant_vargs(TYPE_STRING, 1, str);
                }
                break;
            }
            case Division: {
                if (V->length < 2) break;
                float res_f = V->type == TYPE_FLOAT ? V->value.f[0] : (V->type == TYPE_INT ? V->value.i[0] : (V->type == TYPE_CHAR ? (unsigned char)V->value.c[0] : V->type == TYPE_STRING ? (unsigned char)V->value.s[0][0] : 1));
                for (size_t i = 1; i < V->length; ++i) {
                    switch (V->type) {
                        case TYPE_INT:   if (V->value.i[i] != 0) res_f /= V->value.i[i]; break;
                        case TYPE_FLOAT: if (V->value.f[i] != 0) res_f /= V->value.f[i]; break;
                        case TYPE_CHAR:  if (V->value.c[i] != 0) res_f /= (unsigned char)V->value.c[i]; break;
                        case TYPE_STRING:if (V->value.s[i][0] != 0) res_f /= (unsigned char)V->value.s[i][0]; break;
                    }
                }
                if (V->type == TYPE_FLOAT)       return Variant_vargs(TYPE_FLOAT, 1, res_f);
                else if (V->type == TYPE_INT)    return Variant_vargs(TYPE_FLOAT, 1, res_f);
                else if (V->type == TYPE_CHAR)   return Variant_vargs(TYPE_CHAR, 1, (char)((int)res_f % 256));
                else {
                    char str[2] = { (char)((int)res_f % 256), '\0' };
                    return Variant_vargs(TYPE_STRING, 1, str);
                }
            }
            case Avarage: {
                if (V->length == 0) break;
                float sum = 0;
                switch (V->type) {
                    case TYPE_INT:
                        for (size_t i = 0; i < V->length; ++i) sum += V->value.i[i];
                        sum /= V->length;
                        return Variant_vargs(TYPE_FLOAT, 1, sum);
                    case TYPE_FLOAT:
                        for (size_t i = 0; i < V->length; ++i) sum += V->value.f[i];
                        sum /= V->length;
                        return Variant_vargs(TYPE_FLOAT, 1, sum);
                    case TYPE_CHAR:
                        for (size_t i = 0; i < V->length; ++i) sum += (unsigned char)V->value.c[i];
                        sum /= V->length;
                        return Variant_vargs(TYPE_CHAR, 1, (char)((int)sum % 256));
                    case TYPE_STRING:
                        for (size_t i = 0; i < V->length; ++i) sum += (unsigned char)V->value.s[i][0];
                        sum /= V->length;
                        char str[2] = { (char)((int)sum % 256), '\0' };
                        return Variant_vargs(TYPE_STRING, 1, str);
                }
                break;
            }
            case Min: {
                if (V->length == 0) break;
                int min_i = V->type == TYPE_INT ? V->value.i[0] : (V->type == TYPE_CHAR ? (unsigned char)V->value.c[0] : V->type == TYPE_STRING ? (unsigned char)V->value.s[0][0] : 0);
                float min_f = V->type == TYPE_FLOAT ? V->value.f[0] : 0;
                switch (V->type) {
                    case TYPE_INT:
                        for (size_t i = 1; i < V->length; ++i) if (V->value.i[i] < min_i) min_i = V->value.i[i];
                        return Variant_vargs(TYPE_INT, 1, min_i);
                    case TYPE_FLOAT:
                        for (size_t i = 1; i < V->length; ++i) if (V->value.f[i] < min_f) min_f = V->value.f[i];
                        return Variant_vargs(TYPE_FLOAT, 1, min_f);
                    case TYPE_CHAR:
                        for (size_t i = 1; i < V->length; ++i) if ((unsigned char)V->value.c[i] < min_i) min_i = (unsigned char)V->value.c[i];
                        return Variant_vargs(TYPE_CHAR, 1, min_i % 256);
                    case TYPE_STRING:
                        for (size_t i = 1; i < V->length; ++i) if ((unsigned char)V->value.s[i][0] < min_i) min_i = (unsigned char)V->value.s[i][0];
                        char str[2] = { (char)(min_i % 256), '\0' };
                        return Variant_vargs(TYPE_STRING, 1, str);
                }
                break;
            }
            case Max: {
                if (V->length == 0) break;
                int max_i = V->type == TYPE_INT ? V->value.i[0] : (V->type == TYPE_CHAR ? (unsigned char)V->value.c[0] : V->type == TYPE_STRING ? (unsigned char)V->value.s[0][0] : 0);
                float max_f = V->type == TYPE_FLOAT ? V->value.f[0] : 0;
                switch (V->type) {
                    case TYPE_INT:
                        for (size_t i = 1; i < V->length; ++i) if (V->value.i[i] > max_i) max_i = V->value.i[i];
                        return Variant_vargs(TYPE_INT, 1, max_i);
                    case TYPE_FLOAT:
                        for (size_t i = 1; i < V->length; ++i) if (V->value.f[i] > max_f) max_f = V->value.f[i];
                        return Variant_vargs(TYPE_FLOAT, 1, max_f);
                    case TYPE_CHAR:
                        for (size_t i = 1; i < V->length; ++i) if ((unsigned char)V->value.c[i] > max_i) max_i = (unsigned char)V->value.c[i];
                        return Variant_vargs(TYPE_CHAR, 1, max_i % 256);
                    case TYPE_STRING:
                        for (size_t i = 1; i < V->length; ++i) if ((unsigned char)V->value.s[i][0] > max_i) max_i = (unsigned char)V->value.s[i][0];
                        char str[2] = { (char)(max_i % 256), '\0' };
                        return Variant_vargs(TYPE_STRING, 1, str);
                }
                break;
            }
            case Mod: {
                if (V->length == 0) break;
                int mod_i = V->type == TYPE_INT ? V->value.i[0] : (V->type == TYPE_CHAR ? (unsigned char)V->value.c[0] : V->type == TYPE_STRING ? (unsigned char)V->value.s[0][0] : 0);
                float mod_f = V->type == TYPE_FLOAT ? V->value.f[0] : 0;
                switch (V->type) {
                    case TYPE_INT:
                        for (size_t i = 1; i < V->length; ++i) if(V->value.i[i]!=0) mod_i %= V->value.i[i];
                        return Variant_vargs(TYPE_INT, 1, mod_i);
                    case TYPE_FLOAT:
                        for (size_t i = 1; i < V->length; ++i) if(V->value.f[i]!=0) mod_f = fmod(mod_f, V->value.f[i]);
                        return Variant_vargs(TYPE_FLOAT, 1, mod_f);
                    case TYPE_CHAR:
                        for (size_t i = 1; i < V->length; ++i) if(V->value.c[i]!=0) mod_i %= (unsigned char)V->value.c[i];
                        return Variant_vargs(TYPE_CHAR, 1, mod_i % 256);
                    case TYPE_STRING:
                        for (size_t i = 1; i < V->length; ++i) if(V->value.s[i][0]!=0) mod_i %= (unsigned char)V->value.s[i][0];
                        char str[2] = { (char)(mod_i % 256), '\0' };
                        return Variant_vargs(TYPE_STRING, 1, str);
                }
                break;
            }
            case Multiply: {
                if (V->length == 0) break;
                int prod_i = V->type == TYPE_INT ? V->value.i[0] : (V->type == TYPE_CHAR ? (unsigned char)V->value.c[0] : V->type == TYPE_STRING ? (unsigned char)V->value.s[0][0] : 1);
                float prod_f = V->type == TYPE_FLOAT ? V->value.f[0] : 1;
                switch (V->type) {
                    case TYPE_INT:
                        for (size_t i = 1; i < V->length; ++i) prod_i *= V->value.i[i];
                        return Variant_vargs(TYPE_INT, 1, prod_i);
                    case TYPE_FLOAT:
                        for (size_t i = 1; i < V->length; ++i) prod_f *= V->value.f[i];
                        return Variant_vargs(TYPE_FLOAT, 1, prod_f);
                    case TYPE_CHAR:
                        for (size_t i = 1; i < V->length; ++i) prod_i *= (unsigned char)V->value.c[i];
                        return Variant_vargs(TYPE_CHAR, 1, prod_i % 256);
                    case TYPE_STRING:
                        for (size_t i = 1; i < V->length; ++i) prod_i *= (unsigned char)V->value.s[i][0];
                        char str[2] = { (char)(prod_i % 256), '\0' };
                        return Variant_vargs(TYPE_STRING, 1, str);
                }
                break;
            }
            case Count: { // Just returns the length
                return Variant_vargs(TYPE_INT, 1, (int)V->length);
            }

                    
                }
    va_end(ap);
    return V;
}

int Variant_Compare(const VTD *a, const VTD *b) {
    if (!a || !b) return 0;
    switch (a->type) {
    case TYPE_INT:    return a->value.i[0] - b->value.i[0];
    case TYPE_FLOAT:  return (a->value.f[0] > b->value.f[0]) - (a->value.f[0] < b->value.f[0]);
    case TYPE_CHAR:   return a->value.c[0] - b->value.c[0];
    case TYPE_STRING: return strcmp(a->value.s[0], b->value.s[0]);
    default:          return 0;
    }
}

int VTDisNull(VTD *ptr){
    if (ptr!=NULL)
    {
        return 0;
    }
    return 1;
}
#endif
