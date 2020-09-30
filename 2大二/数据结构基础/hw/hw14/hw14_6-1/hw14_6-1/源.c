#include<stdio.h>
#include<stdlib.h>

#define MaxVertices 10
#define	INFINITY 100000000


typedef int Vertex;

typedef struct VNode *PtrToVNode;
struct VNode
{
	Vertex Vert;
	PtrToVNode Next;
};

typedef struct GNode *Graph;
struct GNode
{
	int NumOfVertices;
	int NumOfEdges;
	PtrToVNode *Array;
};



Graph ReadG()
{
	Graph graph = (Graph)malloc(sizeof(struct GNode));
	int i, nv, ne, tail, head;
	PtrToVNode ptr;
	scanf("%d %d", &nv, &ne);
	graph->NumOfEdges = ne;
	graph->NumOfVertices = nv;
	graph->Array = (PtrToVNode *)malloc(sizeof(PtrToVNode)*nv);
	for (i = 0; i < nv; i++)graph->Array[i] = NULL;
	for (i = 0; i < ne; i++)
	{
		scanf("%d %d", &tail, &head);
		ptr = (PtrToVNode)malloc(sizeof(struct VNode));
		ptr->Vert = head;
		ptr->Next = graph->Array[tail];
		graph->Array[tail] = ptr;
	}
	return graph;
}

void PrintV(Vertex V)
{
	printf("%d ", V);
}

void StronglyConnectedComponents(Graph G, void(*visit)(Vertex V));
void DFS(Graph Gr, int *index, void(*visit)(Vertex V));
int FindMax(int *index, int *visited, int n);
Graph reverse(Graph graph, int *index);
void spanningtree(Graph graph, int *index, int *visited, int num);

int main()
{
	Graph G = ReadG();
	StronglyConnectedComponents(G, PrintV);
	return 0;
}

int count = 1;
void DFS(Graph Gr, Vertex thenum, int *visited, void(*visit)(Vertex V))
{
	PtrToVNode ptr;
	ptr = Gr->Array[thenum];
	visited[thenum] = 1;
	(*visit)(thenum);
	while (ptr)
	{
		if (!visited[ptr->Vert])
		{
			DFS(Gr, ptr->Vert, visited, visit);
		}
		ptr = ptr->Next;
	}

}

//返回的是顶点的编号
int FindMax(int *index, int *visited, int n)
{
	int i, max, thenum;
	thenum = -1;
	max = 0;
	for (i = 0; i < n; i++)
	{
		if (!visited[i] && max <= index[i])
		{
			max = index[i];
			thenum = i;
		}
	}
	return thenum;
}

void spanningtree(Graph graph, int *index,int *visited,int num)
{
	PtrToVNode ptr;
	ptr = graph->Array[num];
	while (ptr)
	{
		if (!visited[ptr->Vert])
		{
			visited[ptr->Vert] = 1;
			spanningtree(graph, index, visited, ptr->Vert);
		}
		ptr = ptr->Next;
	}
	index[num] = count;
	count++;
}

//创建个新图，该图反向并且给每个点编号
Graph reverse(Graph graph, int *index)
{
	Graph Gr = (Graph)malloc(sizeof(struct GNode));
	int nv = graph->NumOfVertices;
	int ne = graph->NumOfVertices;
	int i;
	int *visited = (int *)malloc(sizeof(int)*nv);
	PtrToVNode ptr1, ptr2;
	Gr->Array = (PtrToVNode *)malloc(sizeof(PtrToVNode)*nv);
	Gr->NumOfEdges = ne;
	Gr->NumOfVertices = nv;
	for (i = 0; i < nv; i++)
	{
		visited[i] = 0;
		Gr->Array[i] = NULL;
	}

	//反转
	for (i = 0; i < nv; i++)
	{
		ptr1 = graph->Array[i];
		while (ptr1)
		{
			ptr2 = (PtrToVNode)malloc(sizeof(struct VNode));
			ptr2->Vert = i;
			ptr2->Next = Gr->Array[ptr1->Vert];
			Gr->Array[ptr1->Vert] = ptr2;
			ptr1 = ptr1->Next;
		}
	}


	//边生成树边编号
	for (i = 0; i < nv; i++)
	{
		if (!visited[i]) {
			visited[i] = 1;
			spanningtree(graph, index, visited, i);
		}
	}



	return Gr;
}

void StronglyConnectedComponents(Graph G, void(*visit)(Vertex V))
{
	Graph Gr;
	int i;
	Vertex thenum;
	int *index = (int *)malloc(sizeof(int)*G->NumOfVertices);
	int *visited = (int *)malloc(sizeof(int)*G->NumOfVertices);
	for (i = 0; i < G->NumOfVertices; i++)visited[i] = 0;

	//得到反向图以及编号   
	Gr = reverse(G, index);

	//从大到小对每个点进行DFS，其中FindMax返回的是拥有最编号的顶点的下标
	while ((thenum = FindMax(index, visited, G->NumOfVertices)) != -1)
	{
		DFS(Gr, thenum, visited, visit);
		printf("\n");
	}
	return;
}