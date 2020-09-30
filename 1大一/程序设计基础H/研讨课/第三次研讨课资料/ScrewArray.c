#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define MAX_SCREW 20

int InputScrewSize();
void GenScrewArray(int ScrewArray[MAX_SCREW][MAX_SCREW], int n);
void PrintScrewArray(int ScrewArray[MAX_SCREW][MAX_SCREW], int n);

main()
{
    int ScrewArray[MAX_SCREW][MAX_SCREW];
    int n;
    
    n = InputScrewSize();
    GenScrewArray(ScrewArray, n);
    PrintScrewArray(ScrewArray, n);
}

int InputScrewSize()
{
    int n;
    
    printf("Please input the Size of Screw Array: ");
    while ((n=GetInteger()) > MAX_SCREW || n < 0) {
          printf("Bad Screw Size, input again: \n");
    }
    return n;
}

void PrintScrewArray(int ScrewArray[MAX_SCREW][MAX_SCREW], int n)
{
     int row, col;
     
     for (row = 0; row < n; row++) {
         for (col = 0; col < n; col++) printf("%4d", ScrewArray[row][col]);
         printf("\n");
     }
}

void GenScrewArray(int ScrewArray[MAX_SCREW][MAX_SCREW], int n)
{
     int i, k, row, col, len, count;
     
     row = col = 0; /*Start (row, col) of every loop*/
     len = n;  /*length of side of erery loop*/
     count = 1; /*from 1~n*n*/
     for (i = 0; i < n/2; i++) { /*Loop 0~n/2*/
         for (k = col; k < col+len-1; k++) ScrewArray[row][k] = count++;
         for (k = row; k < row+len-1; k++) ScrewArray[k][col+len-1] = count++;
         for (k = col+len-1; k > col; k--) ScrewArray[row+len-1][k] = count++;
         for (k = row+len-1; k > row; k--) ScrewArray[k][col] = count++;
         row++;
         col++;
         len -= 2;
     }
     if (n%2) ScrewArray[n/2][n/2] = count;  
}
