#include<iostream>
#include<cstdlib>

using namespace std;

int seq[11000];//record sequence (sequence)
int up[11000];//record the longest sequence of increments with i as the last node
int down[11000];//records with i as the first node to decrement the longest sequence


//Dynamic programming algorithm
void DP(int index, int N)
{
	int temp;
	temp = 0;

	//Calculating incremental sequences
	for (int i = 0; i < index; i++)
	{
		if (seq[index] > seq[i] && temp < up[i] + 1)//if the sequence[index] > sequence[i] and temp < up[i]+1, means that this incremental sequence is longer
		{
			temp = up[i] + 1;
			up[index] = temp;						//let down[index] be the longer incremental sequence
		}
	}

	temp = 0;

	//Calculating descending sequence(from the last number to the first number, contrary to the incremental sequence)
	for (int i = N - 1; i > N - 1 - index; i--)
	{
		if (seq[N - 1 - index] > seq[i] && temp < down[i] + 1)//if the sequence[index] > sequence[i] and temp < down[i]+1, means that this incremental sequence is longer
		{
			temp = down[i] + 1;
			down[N - 1 - index] = temp;						//let down[N-1-index] be the longer incremental sequence
		}
	}

	return;
}


int main()
{	
	
	//N is the number of the sequence£¬max records the maximum value subscript and determine if there is a peak
	int N, max = 0, maxindex, difference = 1000000;
	printf("please input the number of the sequence(3-10000):\n");
	//initialize the data
	cin >> N;
	printf("please input %d numbers(split with spaces or carriage returns):\n", N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &seq[i]);
		up[i] = 1;
		down[i] = 1;
	}

	//excute the dynamic programming algorithm
	for (int i = 0; i < N; i++)
		DP(i, N);


	//Find the longest "peak" and compare the symmetry of the longest "peak"
	for (int i = 0; i < N; i++)
	{
		if (up[i] > 1 && down[i] > 1)		//First, find the longest "peak"
		{
			if (max < up[i] + down[i] - 1 )
			{
				difference = abs(up[i] - down[i]);
				max = up[i] + down[i] - 1;
				maxindex = i;
			}
			//finally, if it is equal, find the most symmetrical "peak"(the absolute value of (up[i] - down[i]) is the smallest)
			else if (max == up[i] + down[i] - 1 && difference > abs(up[i] - down[i]))
			{
				difference = abs(up[i] - down[i]);
				max = up[i] + down[i] - 1;
				maxindex = i;
			}
		}
	}


	//Output the corresponding result if it exists
	if (max)
		printf("%d %d %d\n", max, maxindex + 1, seq[maxindex]);
	else printf("No peak shape\n");

	system("pause");
	return 0;
}
