#include <stdio.h>
#include <stdlib.h>

#define EZreal 2000
#define VENE 1000000
#define Infinity 100000000

typedef struct
{
	int firstblood;
	int legendary;
	int sight;
} shuaifan;

typedef struct
{
	int linkedlist[EZreal];
	int sum;
} vicTorY;

int edgedisjoint[EZreal];
shuaifan chaE[VENE];
int dijointset[EZreal];
int sumnumber[EZreal];
vicTorY sfofgalaxy[EZreal];



void initialize(int N)
{
	int i;
	i = 0;
	while(i < N)
	{
		dijointset[i] = -1;
		sfofgalaxy[i].sum = 0;
		sumnumber[i] = 1;
		edgedisjoint[i] = 0;
		i++;
	}
}


void otherset(shuaifan con_edge);
int attain_parrent(int x);
int yinhexi(const void* a, const void* b);
double calconfindence(int x, double cC);


int main(void)
{

	int numofverticies, numofe;
	int i;
	double cC;
	scanf("%d %d %lf", &numofverticies, &numofe, &cC);


	initialize(numofverticies);
	i = 0;
	while(i < numofe)
	{
		scanf("%d %d %d", &chaE[i].firstblood, &chaE[i].legendary, &chaE[i].sight);
		i++;
	}
	qsort(chaE, numofe, sizeof(shuaifan), yinhexi);

	for (i = 0; i < numofe; i++)
	{
		if (chaE[i].sight <= calconfindence(chaE[i].firstblood, cC))
		{
			if (chaE[i].sight <= calconfindence(chaE[i].legendary, cC))
			{
				otherset(chaE[i]);
			}
		}
	}

	for (i = 0; i < numofverticies; i++)
	{
		sfofgalaxy[attain_parrent(i)].linkedlist[sfofgalaxy[attain_parrent(i)].sum++] = i;
	}

	int j;
	for (i = 0; i < numofverticies; i++)
	{
		if (sfofgalaxy[i].sum != 0)
		{
			printf("%d", sfofgalaxy[i].linkedlist[0]);
			for (j = 1; j < sfofgalaxy[i].sum; j++)
			{
				printf(" %d", sfofgalaxy[i].linkedlist[j]);
			}
			printf("\n");
		}
	}

	return 0;
}

void otherset(shuaifan con_edge)
{
	int f = attain_parrent(con_edge.firstblood);
	int s = attain_parrent(con_edge.legendary);

	if (f != s)
	{
		if (dijointset[f] <= dijointset[s])
		{
			if (dijointset[f] == dijointset[s])
			{
				dijointset[f]--;
			}
			dijointset[s] = f;
		}
		else
		{
			dijointset[f] = s;
		}

		sumnumber[f] = sumnumber[f] + sumnumber[s];
		sumnumber[s] = sumnumber[f];

		int temp_max_edge = ((edgedisjoint[f] > edgedisjoint[s]) ? (edgedisjoint[f] > con_edge.sight ? edgedisjoint[f] : con_edge.sight) : (edgedisjoint[s] > con_edge.sight ? edgedisjoint[s] : con_edge.sight));
		edgedisjoint[f] = edgedisjoint[s] = temp_max_edge;
	}

	return;
}

double calconfindence(int x, double cC)
{
	return edgedisjoint[attain_parrent(x)] + cC / sumnumber[attain_parrent(x)];
}

int yinhexi(const void* a, const void* b)
{
	return ((shuaifan*)a)->sight - ((shuaifan*)b)->sight;
}
int attain_parrent(int x)
{
	while (dijointset[x] >= 0)
	{
		x = dijointset[x];
	}
	return x;
}