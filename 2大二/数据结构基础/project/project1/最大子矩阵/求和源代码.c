#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//the define of the function of O(N^6) version.
int N6_Version(int **a, int N) {						
	int row1, column1, row2, column2, row3, column3, currentSum, MaxSum=0;
	for (row1 = 0; row1 < N; row1++) {
		for (column1 = 0; column1 < N; column1++) {			//the start integer(the integer of the upper left corner of the submatrix): from a[0][0] to a[N][N] 

			for (row2 = row1; row2 < N; row2++) {
				for (column2 = column1; column2 < N; column2++) {		//the end integer(the integer of the bottom right corner of the submatrix):from a[row1][column1] to a[N][N]

					currentSum = 0;					
					for (row3 = row1; row3 <= row2; row3++)
						for (column3 = column1; column3 <= column2; column3++) {			//calculate the sum of the number of submatrix from a[row1][column1] to a[row2][column2] 
							currentSum += a[row3][column3];
						}
					if (currentSum > MaxSum)MaxSum = currentSum;
				}
			}
		}
	}
	return MaxSum;
}


//the define of the function of O(N^4) version.
int N4_Version(int **a,int N) {								
	int row1, column1, row2, column2, currentSum = 0, MaxSum = 0;

	//define an array to store the sum of the a[currentrow][column] to a[temporaryrow][column] into temporary_array[column] 
	int *Temporary_array = (int *)malloc(sizeof(int)*N);

	for (row1 = 0; row1 < N; row1++) {						//the start integer(the integer of the upper left corner of the submatrix): from a[0][0] to a[N][N] 
		for (column1 = 0; column1 < N; column1++) {										

			for (column2 = 0; column2 < N; column2++)Temporary_array[column2] = 0;		// turn the value of temporary_array[column] to 0

			for (row2 = row1; row2 < N; row2++) {									// a[row2][column2] is the end integer(the integer of the bottom right corner of the submatrix)
				currentSum = 0;

				for (column2 = column1; column2 < N; column2++) {
					Temporary_array[column2] += a[row2][column2];					//temporay_array[column2] is the sum of the a[currentrow][column] to a[temporaryrow][column]
					currentSum += Temporary_array[column2];
					if (currentSum > MaxSum)MaxSum = currentSum;
				}
			}
		}
	}
	return MaxSum;
}

//the define of the function of the less time complexity version.
int Bonus_Version(int **a, int N) {
	int row, column, currentSum = 0, MaxSum = 0, Temporary_row, Temporary_column;

	//define an array to store the sum of the a[row1][column] to a[row2][column] into temporary_array[row2][column] 
	int **Temporary_array = (int **)malloc(sizeof(int*)*N);
	for (row = 0; row < N; row++)Temporary_array[row] = (int *)malloc(sizeof(int)*N);

	//store the sum of the a[row1][column] to a[row2][column] into temporary_array[row2][column] 
	for (row = 0; row < N; row++) {
		for (column = 0; column < N; column++) {
			for (Temporary_row = N-1; Temporary_row >= row; Temporary_row--)Temporary_array[Temporary_row][column] += a[row][column];
		}
	}


	//traverse all rows
	for (row = 0; row < N; row++) {
		for (Temporary_row = row; Temporary_row < N; Temporary_row++) {

			//online refresh   O(N)
			currentSum = 0;
			for (column = 0; column < N; column++) {
				//the "Temporary_array[Temporary_row][column] - Temporary_array[row][column] + a[row][column]" is the sum of a[row][column] to a[tamporary_row][column]
				//Then , I take the "online refresh" way to calculate the Max sum
				currentSum = Temporary_array[Temporary_row][column] - Temporary_array[row][column] + a[row][column] + currentSum;	
				if (currentSum > MaxSum)MaxSum = currentSum;
				else if (currentSum < 0)currentSum = 0;
			}


		}
	}
	return MaxSum;
}

int main(void) {

	//define the necessary variables
	clock_t start, stop;
	int row,column,N,N6_Result,N4_Result,Bonus_Result;
	double N6_Duration, N4_Duration,Bonus_Duration;					
	printf("please input the size of the matrix:");

	//intput the size of the matrix and Dynamic allocation of arrays
	scanf("%d", &N);											
	int **a = (int **)malloc(sizeof(int *)*N);
	for (row = 0; row < N; row++)a[row] = (int *)malloc(sizeof(int)*N);	
	
	//intput the matrix
	for (row = 0; row < N; row++)
		for (column = 0; column < N; column++)
			scanf("%d", &a[row][column]);

	//test programe
	start = clock();
	N6_Result = N6_Version(a, N);
	stop = clock();
	N6_Duration = ((double)(stop - start)) / CLK_TCK;


	start = clock();
	N4_Result = N4_Version(a, N);
	stop = clock();
	N4_Duration = ((double)(stop - start)) / CLK_TCK;
	
	start = clock();
	Bonus_Result = Bonus_Version(a, N);
	stop = clock();
	Bonus_Duration = ((double)(stop - start)) / CLK_TCK;
	
	printf("The result of O(N^6) version, O(N^4) version and bonus version are :%d  %d  %d\n", N6_Result, N4_Result, Bonus_Result);
	printf("The run time of O(N^6) version, O(N^4) version and bonus version are :%lfs  %lfs  %lfs\n", N6_Duration, N4_Duration, Bonus_Duration);
	return 0;
}
