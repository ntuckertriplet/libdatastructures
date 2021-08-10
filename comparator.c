#include "comparator.h"

/**
 * A comparator that casts void* to int* and returns the difference.
 * If p1 is larger, it will be negative. Likewise, if p2 is larger, it will be positive.
 * 
 * @param p1 data value 1 to compare
 * @param p2 data value 2 to compare
 * 
 * @returns an integer that is negative if p1 is smaller, positive if p2 is smaller, 
 *          or 0 if they are equal
 */
int int_comp(const void *p1, const void *p2)
{
    int x = *(int *)p1;
    int y = *(int *)p2;
    return x - y;
}

/**
 * A comparator that casts void* to float* and returns the difference.
 * If p1 is larger, it will be negative. Likewise, if p2 is larger, it will be positive.
 * 
 * @param p1 data value 1 to compare
 * @param p2 data value 2 to compare
 * 
 * @returns an integer that is negative if p1 is smaller, positive if p2 is smaller, 
 *          or 0 if they are equal
 */
int float_comp(const void *p1, const void *p2)
{
    float x = *(float *)p1;
    float y = *(float *)p2;
    return x - y;
}