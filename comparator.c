#include "comparator.h"

int int_comp(const void* p1, const void* p2) {
    int x = *(int *) p1;
    int y = *(int *) p2;
    return x - y;
}

int float_comp(const void* p1, const void* p2) {
    float x = *(float *) p1;
    float y = *(float *) p2;
    return x - y;
}