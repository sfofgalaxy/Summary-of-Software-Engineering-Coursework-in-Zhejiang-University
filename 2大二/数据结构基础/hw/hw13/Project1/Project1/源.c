#include<stdio.h>
#include<stdlib.h>

#define INFINITY 1e9

/*
��ÿ��Vertex�ȵ���һ��compoment
�Ȱѵ�һ��compoment���
Ȼ����ӣ��ѳ��ӵ��Ǹ�compoment���ڵ�compoment���
Ȼ����Щcompoment�͸ճ��ӵ��Ǹ�compoment���бȽϣ����Ƿ�����������compoment��ʵ��һ��compoment���ǵĻ��ͺϲ�
*/

struct COMPOMENT
{
	int confidence;
	int num;
	struct LINKEDLIST *FirstVertex;
};

struct COMPOMENT compoment[1200];		

struct LINKEDLIST
{
	int IndexOfVertex;
	struct LINKEDLIST *NEXT;
};

typedef struct UndirectedGraph
{
	int NumberOfVertices;
	int NumberOfEdges;
	int AdjacentMatrix[1200][1200];
}GRAPH;

int main(void)
{
	int c, N, i;
	GRAPH *graph = (GRAPH *)malloc(sizeof(struct UndirectedGraph));
	scanf("%d %d %d", &(graph->NumberOfVertices), &(graph->NumberOfEdges), &c);
	for (i = 0; i < 1200; i++)
	{
		compoment[i].confidence = c;
		compoment[i].FirstVertex->NEXT = NULL;
		compoment[i].FirstVertex = i;
		compoment[i].num = 1;
	}
	//�����ͱ߲������ڽӾ���
	InputVertices(graph);
	//��������compoment�ĸ���
	N = Process(graph, c);
	OutPut(N);
}

int Process(GRAPH *graph, int c)
{

}

//��һ��compoment���vertices��������(ð������
void sort(struct COMPOMENT *c)
{
	//flag���ã����������������˳��û��������Ѿ��ź��ˣ�ֱ���˳�
	int i, flag, temp;
	struct LINKEDLIST *ptr;
	for (i = 0; i < c->num; i++)
	{
		flag = 0;
		for (ptr = c->FirstVertex; ptr->NEXT; ptr = ptr->NEXT)
		{
			if (ptr->IndexOfVertex > ptr->NEXT->IndexOfVertex)
			{
				temp = ptr->IndexOfVertex;
				ptr->IndexOfVertex = ptr->NEXT->IndexOfVertex;
				ptr->NEXT->IndexOfVertex = temp;
				flag = 1;
			}
		}
		if (!flag)break;
	}
}

void OutPut(int N)
{
	int i, j, flag;
	struct LINKEDLIST *ptr;
	struct COMPOMENT temp;
	struct COMPOMENT *pointer;

	//�ȶ�ÿ��compment���vertex��������
	for (i = 0; i < N; i++)
	{
		pointer = compoment + i;
		sort(pointer);
	}

	//�ٶ����е�compoment��������
	//flag���ã����������������˳��û��������Ѿ��ź��ˣ�ֱ���˳�
	for (i = 0; i < N - 1; i++)
	{
		flag = 0;
		for (j = 0; j < N - 1; j++)
		{
			if (compoment[j].FirstVertex->IndexOfVertex > compoment[j+1].FirstVertex->IndexOfVertex)
			{
				temp = compoment[j];
				compoment[j] = compoment[j+1];
				compoment[j + 1] = temp;
				flag = 1;
			}
		}
		if (!flag)break;
	}

	//��ʽ��ʼ���
	for (i = 0; i < N; i++)
	{
		ptr = compoment[i].FirstVertex;
		printf("%d", ptr->IndexOfVertex);
		ptr = ptr->NEXT;
		while (ptr)
		{
			printf(" %d", ptr->IndexOfVertex);
		}
		printf("\n");
	}
}

//�����ͱ߲������ڽӾ���
void InputVeretices(GRAPH *graph)
{
	int i, j;
	int tail, head, weight;
	for (i = 0; i < graph->NumberOfVertices; i++)
		for (j = 0; j < graph->NumberOfVertices; j++)
			graph->AdjacentMatrix[i][j] = INFINITY;

	for (i = 0; i < graph->NumberOfEdges; i++)
	{
		scanf("%d %d %d", &tail, &head, &weight);
		graph->AdjacentMatrix[tail][head] = weight;
	}
}

//��������compoment�������
int dissimilarity(struct COMPOMENT c1, struct COMPOMENT c2, GRAPH *graph)
{
	struct LINKEDLIST *ptr1, *ptr2;
	int dis = INFINITY;
	ptr1 = c1.FirstVertex;
	while (ptr1)
	{
		ptr2 = c2.FirstVertex;
		while (ptr2)
		{
			if (graph->AdjacentMatrix[ptr1->IndexOfVertex][ptr2->IndexOfVertex] < dis)
				dis = graph->AdjacentMatrix[ptr1->IndexOfVertex][ptr2->IndexOfVertex];
			ptr2 = ptr2->NEXT;
		}
		ptr1 = ptr1->NEXT;
	}
	return dis;
}

//����һ��compoment�����Ŷ�
int CONFIDENCE(struct COMPOMENT c1, int c, GRAPH *graph)
{
	int *dist = (int *)malloc(sizeof(int)*graph->NumberOfVertices);
	int *visited = (int *)malloc(sizeof(int)*(graph->NumberOfVertices));
	int i, con, index;
	for (i = 0; i < graph->NumberOfVertices; i++)
	{
		visited[i] = 0;
		dist[i] = INFINITY;
	}
	index = c1.FirstVertex->IndexOfVertex;
	visited[index] = 1;
	dist[index] = 0;
	while (1)
	{

	}
}

//�ж�һ���Ƿ�ͬʱ��compoment�У�����Ŀǰѡ�е�ֱ������
