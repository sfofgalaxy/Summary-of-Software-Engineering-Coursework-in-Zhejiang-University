#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	PtrToAdjVNode Next;
};

typedef struct Vnode {
	PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG()
{
	int numOfvertices, numOfedges, i, j, start, end;
	PtrToAdjVNode temp = NULL, ptr = NULL;
	LGraph graph = (LGraph)malloc(sizeof(struct GNode));
	scanf("%d %d", &numOfvertices, &numOfedges);
	graph->Ne = numOfedges;
	graph->Nv = numOfvertices;

	for (i = 0; i < numOfvertices; i++)graph->G[i].FirstEdge = NULL;
	for (i = 1; i <= numOfedges; i++)
	{
		scanf("%d %d", &start, &end);
		ptr = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
		ptr->AdjV = end;
		ptr->Next = graph->G[start].FirstEdge;
		graph->G[start].FirstEdge = ptr;
	}
	return graph;
}

bool TopSort(LGraph Graph, Vertex TopOrder[]);

int main()
{
	int i;
	Vertex TopOrder[MaxVertexNum];

	LGraph G = ReadG();
	
	/*PtrToAdjVNode ptr = NULL;

		for (i = 0; i < G->Nv; i++)
		{
			ptr = G->G[i].FirstEdge;
			while (ptr)
			{
				printf("%d ", ptr->AdjV);
				ptr = ptr->Next;
			}
			printf("\n");
		}
		return;
	*/

	if (TopSort(G, TopOrder) == true)
		for (i = 0; i < G->Nv; i++)
			printf("%d ", TopOrder[i]);
	else
		printf("ERROR");
	printf("\n");

	return 0;
}

bool TopSort(LGraph Graph, Vertex TopOrder[])
{
	PtrToAdjVNode ptr = NULL;
	int i, count, head, tail;
	int *a = (int *)malloc(sizeof(int)*(Graph->Nv));
	int *queue = (int *)malloc(sizeof(int)*(Graph->Nv));

	//初始化
	count = head = tail = 0;
	for (i = 0; i < Graph->Nv; i++)a[i] = 0;
	for (i = 0; i < Graph->Nv; i++)
	{
		ptr = Graph->G[i].FirstEdge;
		while (ptr)
		{
			a[ptr->AdjV]++;
			ptr = ptr->Next;
		}
	}

	//所有入度为0的节点入队
	for (i = 0; i < Graph->Nv; i++)
		if (a[i] == 0)
			queue[tail++] = i;


	while (tail-head>0)
	{
		//出队
		TopOrder[count++] = queue[head];
		ptr = Graph->G[queue[head++]].FirstEdge;
		while (ptr)
		{
			//将入度减一并且入度为0则减一
			if (--a[ptr->AdjV] == 0)
			{
				queue[tail] = ptr->AdjV;
				tail++;
			}
			ptr = ptr->Next;
		}
	}
	if (count < Graph->Nv - 1)return false;
	return true;
}