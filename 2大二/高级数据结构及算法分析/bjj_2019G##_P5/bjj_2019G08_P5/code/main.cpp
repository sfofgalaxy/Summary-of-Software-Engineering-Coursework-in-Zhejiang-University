#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
struct node // intialize the node
{
    int weight; // the weight of each character
    char character; // character of the node
    node* left; // point to the left
    node* right; // point to the right
    node(int a = 0, char b = '*', node* c = nullptr, node* d = nullptr):
    weight(a),character(b),left(c),right(d){}
};
// overload cmp function
bool operator <(const node &a,const node &b)
{
    return a.weight > b.weight;
}

int CalculateWeight(const node*p,int depth)
{
    
    if(p->left == nullptr && p->right == nullptr)
    {
        return depth*(p->weight);
    }
    else
        // calculate the weight of left node & right node
        return (CalculateWeight(p->left, depth+1) + CalculateWeight(p->right, depth+1));
}


int main()
{
    // use priority_heap to simulate the heap
    // number refers the number of huffman nodes
    // use map to save the relationship between char & int
    priority_queue<node>heap;
    int number;
    cin >> number;
    char character;
    int weight;
    map<char,int>table;
    // input and create the huffman tree
    for(int i = 0;i < number; i++)
    {
        cin >> character >> weight;
        table[character] = weight;
        heap.push(node(weight,character));
    }
    for(int i = 0;i < number - 1;i ++)
    {
        // the first pop returns the node with current largest weight
        // use copy constructor for the top element
        // because it will be deleted soon
        auto left = new node(heap.top());
        heap.pop(); // delete the node at the top of tree
        auto right =new node(heap.top());
        heap.pop();
        heap.push(node(left->weight+right->weight,'*',left,right));
    }
    // cost refers to the total cost the heap
    int cost = CalculateWeight(&heap.top(), 0);
    
    // the numberinput refers to the number of loops to be examined
    int numberinput;
    cin >> numberinput;
    vector<string>huff;
    // flag saves whether exists one node that is prefix of other node
    int flag = 1;
    for(int i = 0;i < numberinput; i++)
    {
        char tempchacter;
        int tempcost = 0;
        // loop to examine all the input
        for(int j = 0;j < number; j++)
        {
            string huffcode;
            cin >> tempchacter >> huffcode;
            // the first element should be saved in the huffcode
            if (huff.size() > 1)
            {
                // loop the vector & test all the nodes in the hufftree
                for(int k = 0;k < huff.size();k ++)
                {
                    int z;
                    // always compare node with the smaller length to larger one
                    if(huff[k].length() > huffcode.length())
                    {
                        for(z = 0;z < huffcode.length();z ++)
                            if(huff[k][z] != huffcode[z])
                                break;
                        if(z == huffcode.length())
                            flag = 0;
                    }
                    else
                    {
                        for(z = 0;z < huff[k].length();z ++)
                            if(huff[k][z] != huffcode[z])
                                break;
                        if(z == huff[k].length())
                            flag = 0;
                    }
                }
            }
            // push it to the vector
            huff.push_back(huffcode);
            // save it in the tempcost
            tempcost += huffcode.length() * table[tempchacter];
        }
        // the cost of two tree is the same & no prefix is the same
        if(tempcost == cost && flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        huff.clear();
        flag = 1;
    }
}

