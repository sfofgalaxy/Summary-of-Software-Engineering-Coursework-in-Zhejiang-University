#include<stdio.h>
#include<stdlib.h>

#define MAXVERTICIES 20

struct GNode
{
	int NumofVertices;
	int NumofEdges;
	int AdjacentMatrix[MAXVERTICIES][MAXVERTICIES];
};

typedef struct GNode* GRAPH;

int visited[MAXVERTICIES];

GRAPH ReadGraph()
{
	GRAPH graph = (GRAPH)malloc(sizeof(struct GNode));
	int i, j, nv, ne, tail, head;
	scanf("%d %d", &nv, &ne);
	graph->NumofEdges = ne;
	graph->NumofVertices = nv;
	for (i = 0; i < nv; i++)
		for (j = 0; j < nv; j++)
			graph->AdjacentMatrix[i][j] = 0;
	for (i = 0; i < ne; i++)
	{
		scanf("%d %d", &tail, &head);
		graph->AdjacentMatrix[tail][head] = 1;
		graph->AdjacentMatrix[head][tail] = 1;
	}
	return graph;
}

void DFS(GRAPH graph, int index)
{
	visited[index] = 1;
	printf(" %d", index);
	for (int i = 0; i < graph->NumofVertices; i++)
	{
		if (!visited[i]&&graph->AdjacentMatrix[index][i])
		{
			DFS(graph, i);
		}
	}
	return;
}

void BFS(GRAPH graph,int index)
{
	int queue[MAXVERTICIES];
	int front, rear;
	front = rear = 0;
	visited[index] = 1;
	queue[rear++] = index;
	while (rear - front)
	{
		index = queue[front++];
		printf(" %d", index);
		for (int i = 0; i < graph->NumofVertices; i++)
		{
			if (!visited[i] && graph->AdjacentMatrix[index][i])
			{
				visited[i] = 1;
				queue[rear++] = i;
			}
		}
	}
	return;
}


int main()
{
	GRAPH graph;
	graph = ReadGraph();

	for (int i = 0; i < graph->NumofVertices; i++)visited[i] = 0;
	for (int i = 0; i < graph->NumofVertices; i++)
	{
		if (!visited[i])
		{
			printf("{");
			DFS(graph, i);
			printf(" }");
			printf("\n");
		}
	}


	for (int i = 0; i < graph->NumofVertices; i++)visited[i] = 0;
	for (int i = 0; i < graph->NumofVertices; i++)
	{
		if (!visited[i])
		{
			printf("{");
			BFS(graph, i);
			printf(" }");
			printf("\n");
		}
	}
}