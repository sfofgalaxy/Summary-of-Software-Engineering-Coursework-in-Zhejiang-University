// @author
// @Date 27-3-19
// @Attnetion: the program and txt should be put the same dir
//
// @comments:
// The program realizes Dijkstra's algorithm with normal heap and Fibonacci heap && We compare the
// time spends of these two algorithms. And our tester will give his analysis.
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <cmath>
#include <time.h>
#define INFI 1e9
using namespace std;
class HeapGraph
{
public:
	HeapGraph(int Vertex, int edges); // Constructor Function
	void Addedge(int start, int end, int distance);//Add a New edge into the Graph
	void ShortestPath(int source); // Get the minimum distance of each node
	vector<int> distance; // Initialize each vertex distance
private:
	int Vertex; // the value of vertex
	int source; // the origin of the graph
	int edges; // the number of edges
	list<pair<int, int> >*adj_List; // The adj_List save the distance and end

};

HeapGraph::HeapGraph(int Vertex, int edges)
{
	this->edges = edges;
	this->Vertex = Vertex; // Save the number of Vertex
	adj_List = new list<pair<int, int> >[edges]; // Create an adjacent List to save the time
	for (int i = 0; i <= Vertex; i++)
		distance.push_back(INFI);
}



void HeapGraph::ShortestPath(int source)
{
	// use priority_queue to realize the dijkstra algorithm
	// which based on heaps
	// origin priority_queue< typename, vector<typename>, greater<typename>>
	// greater means the minimum heap
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >Heap;

	Heap.push(make_pair(0, source)); // Push into the array
	distance[source] = 0;

	while (!Heap.empty()) // Loop until all the vertex have been labeled
	{
		// Heap.top() returns pair<int,int>
		// The first int refers to the vertex with the minimum distance
		// The second int refers to the distance
		int start = Heap.top().second;
		Heap.pop();

		for (auto i : adj_List[start])
		{
			int end = i.first; // end refers to the another vertex
			int dist = i.second; // dist refers to the old distance

			if (distance[end] > distance[start] + dist)
			{
				distance[end] = distance[start] + dist;
				Heap.push(make_pair(distance[end], end));
			}
		}
	}

}

void HeapGraph::Addedge(int start, int end, int distance)
{
	//Save source, end, distance into the graph
	adj_List[start].push_back(make_pair(end, distance));
}


// The part of Fibnoaci Heap
struct FibNode
{
	FibNode* left; // left sibling
	FibNode* right; // right sibling
	FibNode* parent;
	FibNode* child;
	pair<int, int> element; // Value of the node
	int degree; // Degree of the node
};

class FibGraph
{
public:
	FibGraph(int Vertex, int edges); // Initialize the newheap
	void Push(pair<int, int>element); // Push a new node into the heap
	pair<int, int> Pop(void); // Pop the minimum node from the heap
	vector<int>distance; // save the distance of each node;
	void Addedge(int start, int end, int distance); //Add a new edge into the graph
	void ShortestPath(int source); // Get the minimum distance of each node
private:
	int Vertex; // the number of vertex in the graph
	int edges; // the number of edges in the graph
	struct FibNode* Minnode = NULL; // the FibNode pointer to the mininum number
	int numbernode; // the number of nodes in the graph
	list<pair<int, int>>*adj_List; // the adjacent Lis
	void Link(FibNode* Anode, FibNode* PNode); // Link the two Node
	void Consolidate(void); // merge the pieces after pop
};


FibGraph::FibGraph(int Vertex, int edges)
{
	this->edges = edges;
	this->Vertex = Vertex;
	this->numbernode = 0;
	adj_List = new list<pair<int, int>>[edges];
	for (int i = 0; i <= Vertex; i++)
		distance.push_back(INFI);
}


void FibGraph::Addedge(int start, int end, int distance)
{
	//Save source, end, distance into the graph
	adj_List[start].push_back(make_pair(end, distance));

}
void FibGraph::Push(pair<int, int>element)
{
	FibNode* newNode = new FibNode;
	newNode->degree = 0;
	newNode->element = element;
	newNode->parent = NULL;
	newNode->child = NULL;
	newNode->left = newNode; // use double-link List to express the data-structure
	newNode->right = newNode;
	if (Minnode != NULL)
	{
		// case 1:exists at least one node in the heap
		// we insert the node to the left of the least node in the heap
		Minnode->left->right = newNode;
		newNode->left = Minnode->left;
		newNode->right = Minnode;
		Minnode->left = newNode;
		// second here means to the distance
		// Cause the  Fib-heap shall always pop the vertex with minimum distance
		if (newNode->element.second < Minnode->element.second)
			Minnode = newNode;
	}
	else
		// case 2: Not exists any node in the heap
		Minnode = newNode;

	numbernode++;
}


pair<int, int> FibGraph::Pop(void)
{
	//Add all children of Minnode to childList
	FibNode *OldSmallNode, *childTraverse, *next;
	FibNode ** childList;
	//return the Min's element and delete Minnode
	auto element = Minnode->element;
	OldSmallNode = Minnode;

	if (OldSmallNode != NULL)
	{
		childTraverse = OldSmallNode->child;
		if (childTraverse != NULL) // Travere all children of smallNode
		{
			childList = new FibNode*[OldSmallNode->degree];
			next = childTraverse;
			for (int i = 0; i < OldSmallNode->degree; i++) // Traverse its sibling
			{
				childList[i] = next;
				next = next->right;
			}
			// Insert them to the left of the new min node
			for (int i = 0; i < OldSmallNode->degree; i++)
			{
				childTraverse = childList[i];
				Minnode->left->right = childTraverse;
				childTraverse->left = Minnode->left;
				Minnode->left = childTraverse;
				childTraverse->right = Minnode;
				childTraverse->parent = NULL;
			}
			delete[] childList;
		}
		// Cut the chain and delete small Node
		OldSmallNode->left->right = OldSmallNode->right;
		OldSmallNode->right->left = OldSmallNode->left;

		if (OldSmallNode == OldSmallNode->right) // only exits itself
		{
			Minnode = NULL;
		}
		else
		{
			Minnode = OldSmallNode->right;
			// Make up all the pieces to a new Fibo Heap
			Consolidate();
		}
		numbernode--;
	}
	return element;
}


void FibGraph::Link(FibNode* Anode, FibNode* PNode)
{
	// Extract Anode from its former chain
	Anode->left->right = Anode->right;
	Anode->right->left = Anode->left;

	//Insert A node to the child of Pnode
	if (PNode->child != NULL)
	{
		// case 1: Pnode already has children
		PNode->child->left->right = Anode;
		Anode->left = PNode->child->left;
		PNode->child->left = Anode;
		Anode->right = PNode->child;
	}
	else // case 2: Pnode is empty
	{
		PNode->child = Anode;
		Anode->right = Anode;
		Anode->left = Anode;
	}
	//Set Pnode as Anode's Parent
	Anode->parent = PNode;
	PNode->degree++;
}


void FibGraph::Consolidate()
{

	FibNode* w, *next, *x, *y, *temp;
	FibNode** NodeCarry, ** rootList;
	int d, rootSize;
	// Calcalate the upper bounding of the nodes
	int max_degree = int(log(numbernode) / log(2));
	// Create a New FibNodeCarry to save the node according to their degree
	NodeCarry = new FibNode*[max_degree + 2];
	fill_n(NodeCarry, max_degree + 2, nullptr);

	w = Minnode;
	rootSize = 0;
	next = w;
	//Calcalate the number of nodes of the floor
	do
	{
		rootSize++;
		next = next->right;
	} while (next != w);
	rootList = new FibNode*[rootSize];
	for (int i = 0; i < rootSize; i++)
	{
		rootList[i] = next;
		next = next->right;
	}
	// Traverse the whole upper List and Merge them with the same degree
	for (int i = 0; i < rootSize; i++)
	{
		w = rootList[i];
		x = w;
		d = x->degree;
		while (NodeCarry[d] != nullptr)
		{
			y = NodeCarry[d];
			//Swap two nodes if finding a smaller one
			if (x->element.second > y->element.second)
			{
				temp = x;
				x = y;
				y = temp;
			}

			Link(y, x);
			NodeCarry[d] = nullptr;
			d++;
		}
		NodeCarry[d] = x;
	}
	delete[] rootList;
	Minnode = nullptr;
	for (int i = 0; i < max_degree + 2; i++)
	{
		if (NodeCarry[i] != nullptr)
		{
			if (Minnode == nullptr) // Case NULL Minnode: Initlilize it
				Minnode = NodeCarry[i]->left = NodeCarry[i]->right = NodeCarry[i];
			else
			{
				// Insert NodeCarry to the Left of the min node
				Minnode->left->right = NodeCarry[i];
				NodeCarry[i]->left = Minnode->left;
				Minnode->left = NodeCarry[i];
				NodeCarry[i]->right = Minnode;
				// Update Minnode when necessary
				if (NodeCarry[i]->element.second < Minnode->element.second)
					Minnode = NodeCarry[i];
			}
		}
	}
	delete[] NodeCarry;
}


void FibGraph::ShortestPath(int source)
{

	Push(make_pair(source, 0)); // Push into the array
	distance[source] = 0;

	while (numbernode != 0) // Loop until all the vertex have been labeled
	{
		// The first int refers to the vertex with the minimum distance
		// The second int refers to the distance
		auto element = Pop();
		int start = element.first;

		for (auto i : adj_List[start])
		{
			int end = i.first; // end refers to the another vertex
			int dist = i.second; // dist refers to the old distance

			if (distance[end] > distance[start] + dist)
			{
				distance[end] = distance[start] + dist;
				Push(make_pair(end, distance[end]));
			}
		}
	}

}


int main()
{
	int Vertex, edges, choice;
	int start, end, distance;
	ifstream input;
	cout << "1.Open Sample map" << endl;
	cout << "2.Open NY map" << endl;
	cout << "3.Open USA Bay map" << endl;
	cout << "4.Open USA FLA map" << endl;

	cin >> choice;
	switch (choice)
	{
	case 1:
		input.open("Sample.txt");
		break;
	case 2:
		input.open("NY_road.txt");
		break;
	case 3:
		input.open("USA_Bay.txt");
		break;
	case 4:
		input.open("USA_FLA.txt");
		break;
	default:
		break;
	}


	input >> Vertex;
	//FibGraph FG(Vertex);
	input >> edges;
	HeapGraph HG(Vertex, edges);
	FibGraph FG(Vertex, edges);
	for (int i = 0; i < edges; i++) // Load from the corresponding file
	{
		char temp;
		input >> temp; // Drop 'a' in the text
		input >> start; // Get start from the file
		input >> end; // Get end from the file
		input >> distance; // Get distance from the file
		HG.Addedge(start, end, distance);
		FG.Addedge(start, end, distance);
	}
	clock_t BEGIN, END;
	double HGtime, FGtime;
	BEGIN = clock();
	HG.ShortestPath(1);
	END = clock();
	HGtime = (double)(END - BEGIN) / CLOCKS_PER_SEC;

	BEGIN = clock();
	FG.ShortestPath(1);
	END = clock();
	FGtime = (double)(END - BEGIN) / CLOCKS_PER_SEC;
	cout << Vertex << " Vertices and " << edges << " Edges in the graph" << endl;
	cout << "The time of Heap is:" << HGtime << "s" << endl;
	cout << "The time of FibHeap is:" << FGtime << "s" << endl;

	cout << "Press '1' to show outcomes" << endl;
	cin >> choice;
	if (choice == 1)
	{
		for (int i = 1; i <= Vertex; i++)
			cout << "HG: The distance of " << i << " is:" << HG.distance[i] << endl;
		for (int i = 1; i <= Vertex; i++)
			cout << "FG: The distance of " << i << " is:" << FG.distance[i] <<  endl;
	}
	system("pause");
}
