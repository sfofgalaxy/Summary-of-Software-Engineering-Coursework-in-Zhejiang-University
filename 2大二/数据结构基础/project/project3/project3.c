//  DS LAB 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXIMUM 1e9
#define Elementtype int
typedef struct hash *HASH;//define a hash table structure
struct hash
{
	int TableSize;
	Elementtype* Table;
};
void MakeGraph(HASH HashTable, int** Graph, int* Indegree);//declaration for function MakeGraph
void SolveReHash(HASH HashTable, int** Graph, int* Indegree, int Count);//declaration for function SolveReHash

int main()
{
	int CurrentIndex = 0;
	int Count = 0;
	HASH HashTable = (HASH)malloc(sizeof(struct hash));
	int i, j;
//create a hash table
	scanf("%d", &HashTable->TableSize);
	HashTable->Table = (Elementtype *)malloc(sizeof(Elementtype) * HashTable->TableSize);
	for (i = 0; i < HashTable->TableSize; i++)
	{
		scanf("%d", &HashTable->Table[i]);
		if (HashTable->Table[i] >= 0)
		{
			Count++;
		}
	}
//allocate space for array Graph and array Indegree and initialize them
	int** Graph = (int **)malloc(sizeof(int *) * HashTable->TableSize);
	int* Indegree = (int *)malloc(sizeof(int) * HashTable->TableSize);
	for (i = 0; i < HashTable->TableSize; i++)
	{
		Graph[i] = (int *)malloc(sizeof(int) * HashTable->TableSize);
	}
	for (i = 0; i < HashTable->TableSize; i++)
	{
		Indegree[i] = 0;
		for (j = 0; j < HashTable->TableSize; j++)
		{
			Graph[i][j] = 0;
		}
	}
//create a corresponding graph.
	MakeGraph(HashTable, Graph, Indegree);
//solve the problem by topological sort.
	SolveReHash(HashTable, Graph, Indegree, Count);

	return 0;
}


//create a corresponding graph.
void MakeGraph(HASH HashTable, int** Graph, int* Indegree)
{
	int CurrentIndex = 0;
	int TempIndex;
//consider all slots in the hash table as vertexes
	while (CurrentIndex < HashTable->TableSize)
	{
//connect the collided numbers
		if (HashTable->Table[CurrentIndex] >= 0 && (HashTable->Table[CurrentIndex] % HashTable->TableSize) != CurrentIndex)
		{
			TempIndex = CurrentIndex;
			while ((HashTable->Table[CurrentIndex] % HashTable->TableSize) != TempIndex)
			{
				if (TempIndex == 0)
				{
					TempIndex = HashTable->TableSize - 1;
				}
				else
				{
					TempIndex--;
				}
				Graph[TempIndex][CurrentIndex] = 1;
				Indegree[CurrentIndex]++;
			}
		}
		CurrentIndex++;
	}
	return;
}


void SolveReHash(HASH HashTable, int** Graph, int* Indegree, int Count)
{
	int repeat;
	int tempkey;
	int tempindex;
	int i;
//find the smallest number that could be incerted into hash table for now (whose indegree is one)
	for (repeat = 0; repeat < Count; repeat++)
	{
		tempkey = MAXIMUM;
		tempindex = 0;
		
		for (i = 0; i < HashTable->TableSize; i++)
		{
			if (HashTable->Table[i] >= 0 && HashTable->Table[i] < tempkey && Indegree[i] == 0)
			{
				tempindex = i;
				tempkey = HashTable->Table[i];
			}
		}
//delete that number and the indegree of those which is connected to it minus 1
		HashTable->Table[tempindex] = -1;
		for (i = 0; i < HashTable->TableSize; i++)
		{
			if (Graph[tempindex][i] == 1)
			{
				Graph[tempindex][i] = 0;
				Indegree[i]--;
			}
		}
//output the results one by one
		if (repeat == Count - 1)
		{
			printf("%d", tempkey);
		}
		else
		{
			printf("%d ", tempkey);
		}
	}
	return;
}
