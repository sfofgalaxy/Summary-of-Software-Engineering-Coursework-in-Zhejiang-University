#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG()
{
	int vertices, edges, weight, i, start, end, j;
	MGraph graph = (MGraph)malloc(sizeof(struct GNode));

	scanf("%d %d", &vertices, &edges);
	graph->Ne = edges;
	graph->Nv = vertices;

	for (i = 0; i < vertices; i++)
	{
		for (j = 0; j < vertices; j++)
		{
			if (i == j)graph->G[i][j] = 0;
			else graph->G[i][j] = INFINITY;
		}
	}


	for (i = 0; i < edges; i++)
	{
		scanf("%d %d %d", &start, &end, &weight);
		graph->G[start][end] = weight;
	}
	return graph;
}

void ShortestDist(MGraph Graph, int dist[], int path[], Vertex S);

int main()
{
	int dist[MaxVertexNum], path[MaxVertexNum];
	Vertex S, V;
	MGraph G = ReadG();

	scanf("%d", &S);
	ShortestDist(G, dist, path, S);

	for (V = 0; V < G->Nv; V++)
		printf("%d ", dist[V]);
	printf("\n");
	for (V = 0; V < G->Nv; V++)
		printf("%d ", path[V]);
	printf("\n");

	return 0;
}

void ShortestDist(MGraph Graph, int dist[], int path[], Vertex S)
{
	int *visit = (int *)malloc(sizeof(int)*Graph->Nv);
	int *nums = (int *)malloc(sizeof(int)*Graph->Nv);
	int i, index, min, flag;
	for (i = 0; i < Graph->Nv; i++)
	{
		dist[i] = INFINITY;
		path[i] = -1;
		visit[i] = false;
		nums[i] = INFINITY;
	}
	dist[S] = 0;
	nums[S] = 0;

	while (1)
	{
		flag = 0;
		min = INFINITY;
		//找到未被访问过的distance最小者
		for (i = 0; i < Graph->Nv; i++)
		{
			if (!visit[i] && min > dist[i])
			{
				min = dist[i];
				index = i;
				flag = 1;
			}
		}
		if (!flag)break;
		visit[index] = true;

		for (i = 0; i < Graph->Nv; i++)
		{
			if (Graph->G[index][i] < INFINITY && !visit[i])
			{
				if (dist[index] + Graph->G[index][i] < dist[i])
				{
					dist[i] = dist[index] + Graph->G[index][i];
					path[i] = index;
					nums[i] = nums[index] + 1;
				}
				else if (dist[index] + Graph->G[index][i] == dist[i] && nums[i] > nums[index] + 1)
				{
					path[i] = index;
					nums[i] = nums[index] + 1;
				}
			}
		}
	}

	for (i = 0; i < Graph->Nv; i++)
		if (dist[i] == INFINITY)dist[i] = -1;
}