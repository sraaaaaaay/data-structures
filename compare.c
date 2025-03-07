#include "compare.h"
#include <string.h>

int compare_strings(const void* lhs, const void* rhs){
    return strcmp((const char*)lhs, (const char*)rhs);
}

int compare_ints(const void* lhs, const void* rhs){
    return *(int*)lhs-*(int*)rhs;
}

int compare(const void* lhs, const void* rhs, size_t size){
    return memcmp(lhs, rhs, size);
}