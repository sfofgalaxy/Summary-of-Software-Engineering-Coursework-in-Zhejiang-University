#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define MAX_NUM 250
#define Sentinel -1

int InputArray(int array[MAX_NUM], int max_num, int sentinel);
void SortArray(int array[MAX_NUM], int n);
void PrintArray(int array[MAX_NUM], int n);
int FindMinIndex(int array[MAX_NUM], int sIndex, int n);
void SwapArrayElements(int array[MAX_NUM], int i, int j);

main()
{
    int array[MAX_NUM];
    int n;
    
    n = InputArray(array, MAX_NUM, Sentinel);
    SortArray(array, n);
    PrintArray(array, n);
}

int InputArray(int array[MAX_NUM], int max_num, int sentinel)
{
    int n, value;
    
    n = 0; 
    while (TRUE) {
          printf("? ");
          value = GetInteger();
          if (value == sentinel) break;
          if (n == max_num) Error("Too many input items for array!");
          array[n++] = value;
    }
    return n;
}

void PrintArray(int array[MAX_NUM], int n)
{
     int i;
     
     for (i = 0; i < n; i++) printf("%d ", array[i]);
     printf("\n");
}

void SortArray(int array[MAX_NUM], int n)
{
     int i;
     int mIndex;
     for (i = 0; i < n-1; i++) {
         mIndex = FindMinIndex(array, i, n);
         if (i != mIndex) SwapArrayElements(array, i, mIndex);
     }
}

int FindMinIndex(int array[MAX_NUM], int sIndex, int n)
{
    int mIndex = sIndex, k;
    
    for (k = sIndex+1; k < n; k++)
        if (array[k] < array[mIndex]) mIndex = k;
    return mIndex;
}

void SwapArrayElements(int array[MAX_NUM], int i, int j)
{
     int tmp;
     
     tmp = array[i];
     array[i] = array[j];
     array[j] = tmp;
}
