#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length){
    if (length == 0) return NULL;
    
    size_t mid = length/2;
    
    if(value == arr[mid]) return &arr[mid];
    
    if(mid == 0) return NULL;
    
    if(value > arr[mid])
        return binary_search(value, &arr[mid + 1], length - mid - 1);
    else
        return binary_search(value, arr, mid);
    
    return NULL;
}