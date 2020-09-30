#include<stdio.h>
#include<stdlib.h>

#define INFINITY 10000000

struct record
{
	char start[4];
	char end[4];
	int capacity;
};

char planet[1000][4];

typedef struct a
{
	int nv;
	int ne;
	int **adjmatrix;
}GRAPH;

int MFP(GRAPH *graph);
int inputvertices(int N, struct record *records);
int findpath(GRAPH *graph);
int findindex(char a[4], int n);
int inputvertices(int N, struct record *records);
void creategraph(GRAPH *graph, struct record *records);

int main(void)
{
	int i;
	GRAPH *graph = (GRAPH *)malloc(sizeof(struct a));

	//初始化和创建
	scanf("%s %s %d", planet[0], planet[1], &(graph->ne));
	struct record* records = (struct record *)malloc(sizeof(struct record)*1000);
	graph->nv = inputvertices(graph->ne,records);
	graph->adjmatrix = (int **)malloc(sizeof(int *)*1000);
	for (i = 0; i < 1000; i++)graph->adjmatrix[i] = (int *)malloc(sizeof(int)*1000);


	creategraph(graph, records);
			


	i = MFP(graph);
	printf("%d", i);

}

//最大流算法
int MFP(GRAPH *graph)
{
	int i, j;
	int flow, sum;
	sum = 0;
	while (flow = findpath(graph))
	{
		sum += flow;
	}
	return sum;
}


//用广搜找路径并处理路径
int findpath(GRAPH *graph)
{
	int front, rear, i, temp, flag, min;
	int *path = (int *)malloc(sizeof(int) * 1000);
	int *queue = (int *)malloc(sizeof(int) * 1000);
	int *visited = (int *)malloc(sizeof(int) * 1000);

	for (i = 0; i < 1000; i++)
	{
		path[i] = -1;
		visited[i] = 0;
	}
	front = rear = 0;
	queue[rear++] = 0;
	flag = 0;
	visited[0] = 1;
	//找路径，如果找到了flag设置为1,否则return 0
	while (rear - front)
	{
		temp = queue[front++];
		for (i = 0; i < graph->nv; i++)
		{
			if (graph->adjmatrix[temp][i] < INFINITY && !visited[i])
			{
				visited[i] = 1;
				path[i] = temp;
				queue[rear++] = i;
				if (i == 1)
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag)break;
	}

	if (!flag)
	{
		free(queue);
		free(path);
		free(visited);
		return 0;
	}
	else
	{
		//找最小值
		i = 1;
		min = graph->adjmatrix[path[1]][1];
		while (path[i] != -1)
		{
			if (min > graph->adjmatrix[path[i]][i])min = graph->adjmatrix[path[i]][i];
			i = path[i];
		}

		//增加反向路以及去掉使用完的路、没用完的路减去min
		i = 1;
		while (path[i]!=-1)
		{
			if (graph->adjmatrix[path[i]][i] > min)graph->adjmatrix[path[i]][i] -= min;
			else graph->adjmatrix[path[i]][i] = INFINITY;
			if(graph->adjmatrix[i][path[i]] < INFINITY) graph->adjmatrix[i][path[i]] += min;
			else graph->adjmatrix[i][path[i]] = min;
			i = path[i];
		}
		free(queue);
		free(visited);
		free(path);
		return min;
	}
}

//找名字对应的下表
int findindex(char a[4],int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (!strcmp(a, planet[i]))break;
	}
	return i;
}

//创建图
void creategraph(GRAPH *graph, struct record *records)
{
	int i, j, n;
	n = graph->nv;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			graph->adjmatrix[i][j] = INFINITY;
		
	
	//开始建图
	for (i = 0; i < graph->ne; i++)graph->adjmatrix[findindex(records[i].start, n)][findindex(records[i].end, n)] = records[i].capacity;
}

//输入处理并记录
int inputvertices(int N, struct record *records)
{
	int nv = 1;
	int i, j, flag1, flag2;
	for (i = 0; i < N; i++)
	{
		scanf("%s %s %d", records[i].start, records[i].end, &(records[i].capacity));
		//找寻是否已经出现过这个PLANET
		flag1 = flag2 = 0;
		for (j = 0; j <= nv; j++)
		{
			if (!strcmp(planet[j], records[i].start))flag1 = 1;
			if (!strcmp(planet[j], records[i].end))flag2 = 1;
		}
		if (!flag1)strcpy(planet[++nv], records[i].start);
		if (!flag2)strcpy(planet[++nv], records[i].end);
	}
	return nv + 1;
}