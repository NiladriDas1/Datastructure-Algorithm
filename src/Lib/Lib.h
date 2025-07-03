#ifndef LIB_H
#define LIB_H

#ifdef __cplusplus
    // This block is active when compiled by a C++ compiler
    #define LANGUAGE_DETECTED "C++"
    // C++ specific headers
    #include <iostream> // For std::cout, std::endl, std::cerr
    #include <string>   // For std::string
    #include <vector>   // Example C++ container
    #include <new>      // For std::bad_alloc
    #include <memory>   // For smart pointers (std::unique_ptr, std::shared_ptr)
    #include <algorithm> // For algorithms like std::sort, std::find
    #include <iterator> // For iterators
    // Include C standard headers with C++ compatibility
    #include <cstdio>   // For printf (C-style I/O)
    #include <cstdlib>  // For malloc, free, exit
    #include <cstdarg>  // For va_list, etc.
    #include <cstring>  // For string manipulation
    #include <cmath>    // For math functions
    #include <climits>  // For integer limits
    #include <cassert>  // For assert()
    #include <cfloat>   // For float limits
    #include <complex>  // For complex numbers
    #include <ctime>    // For time functions
    #include <cwctype>  // For wide character types
    #include <cstdalign> // For alignment utilities
    #include <cerrno>   // For errno
    #include <cfenv>    // For floating-point environment
    // Note: <stdbool.h> is not needed in C++ as 'bool' is a built-in type.
    // Note: <threads.h> is C11 standard; C++ uses <thread> for threading.
#else
    // This block is active when compiled by a C compiler
    #define LANGUAGE_DETECTED "C"
    // C specific headers (as per your list)
    #include <stdio.h>    // Standard Input/Output
    #include <stdlib.h>   // General utilities (e.g., malloc, free, exit)
    #include <stdarg.h>   // Variable arguments for functions (e.g., va_list)
    #include <string.h>   // String manipulation functions (e.g., strlen, strcpy)
    #include <stdbool.h>  // Boolean type (bool, true, false) - C99 standard
    #include <math.h>     // Mathematical functions (e.g., sqrt, sin, cos)
    #include <limits.h>   // Limits of integer types (e.g., INT_MAX, CHAR_MIN)
    #include <threads.h>  // C11 threads support (e.g., thrd_t, mtx_t) - C11 standard
    #include <assert.h>   // Assertions for debugging (e.g., assert())
    #include <float.h>    // Characteristics of floating-point types (e.g., FLT_MAX)
    #include <complex.h>  // Complex number arithmetic - C99 standard
    #include <time.h>     // Time and date utilities (e.g., time, clock)
    #include <wctype.h>   // Wide character classification and mapping - C95 standard
    #include <stdalign.h> // Alignment utilities (e.g., alignof, aligned_alloc) - C11 standard
    #include <errno.h>    // Error numbers (e.g., EACCES)
    #include <fenv.h>     // Floating-point environment access - C99 standard
#endif




#endif