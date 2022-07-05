
#ifndef ARRAY_SORTING
#define ARRAY_SORTING

#include "Big_Array.h" 

void selectionSort(int* array, int SIZE, int left, int right);
void mergeSort(int* array, int SIZE);
void _mergeSort(int* array, int* temp_array, int left, int right);
void _QUICKSORT(int* array, int SIZE);
void quickSort(int* array, int SIZE, int left, int right);

#endif
