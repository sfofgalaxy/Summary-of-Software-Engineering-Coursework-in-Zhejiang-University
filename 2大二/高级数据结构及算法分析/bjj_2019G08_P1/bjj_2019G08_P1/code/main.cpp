/*@Date:1-3-2019
 You can simply do according to the instructions
 If you want to change the data
 You can save it into the corresponding txt
 And Program will naively load in
 
 Note that:
 Splay Tree's Algorithms has been partly merged into the splay Tree
 Becuase the Rotation opeation is quite Similar
 Default SplayNode's height = -1
 
 Sample.txt is mainly a reference for the tester
 Choice one is to prove the correctess of the program
 
 Thank you for your patient reading
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




/*AVL Functions
1.Both single and double rotation
2.Level order traversal
3.Get the height of tree
4.Get the Maximum of two numbers
5.AvlNode Definition
6.Delete Node
7.Level Order Traverse
 */
struct AvlNode;
typedef struct AvlNode *PosAvl;
typedef struct AvlNode *AvlTree;
AvlTree AVLInsert(int element,AvlTree T);//Insert an element into the Tree
AvlTree AvlFindMin(AvlTree T);
AvlTree AVLDelete(int element, AvlTree T);
PosAvl SingleRotateWithLeft(AvlTree T);
PosAvl DoubleRotateWithLeft(AvlTree T);
PosAvl SingleRotateWithRight(AvlTree T);
PosAvl DoubleRotateWithRight(AvlTree T);
void LevelOrder_AvlTree(AvlTree T, int number_Nodes);
static int HeightAvl(PosAvl P);
int Maximum(int a,int b);
//structs Define
struct AvlNode
{
    int element;//element
    AvlTree Left;//Pointer to the left root
    AvlTree Right;//Pointer to the right root
    int height;//the height of the Tree
};




/*BST Functions
 1.Insert an element
 2.Find the minimum element
 3.Delete the element
 4.Level-order Traverse
 */
struct BSTNode;
typedef BSTNode* BSTTree;
typedef BSTNode* PosBST;
BSTTree BSTInsert(int element, BSTTree T);
PosBST BSTFindMin(BSTTree T);
BSTTree BSTDelete(int element, BSTTree T);
void LevelOrder_BSTTree(BSTTree T,int number_Nodes);
struct BSTNode
{
    int element;
    BSTTree Left;
    BSTTree Right;
};






/*Splay Functions
 1.Insert an element
 2.Initialize the NULLNode
 3.Delete Functions
 4.Splay Function
 */
typedef AvlNode SplayNode;
typedef SplayNode* SplayTree;
SplayTree SplayInsert(int element,SplayTree T);
SplayTree SplayDelete(int element,SplayTree T);
SplayTree Splay(int element,SplayTree T);
static AvlTree NULLNode = NULL;//Make the program run faster
SplayTree Initialize(void);
void LevelOrder_SplayTree(SplayTree T,int number_Nodes);

int main()
{
    int choice = 0;
    printf("Input the Number\n");
    printf("0:Test the Correctess of the program\n");
    printf("1:Calculate the Input AND Delete time of three structure\n");
    scanf("%d",&choice);
    /*The part is mainly For Test the Correctess of the program*/
    if (choice == 0) {
        
        
        int number_Nodes;
        int element;
        NULLNode = Initialize();
        SplayTree SplayTree = NULLNode;
        BSTTree BSTTRee = NULL;
        AvlTree AVLTree = NULL;
        
        printf("Input number_Nodes\n");
        scanf("%d",&number_Nodes);//Input the numbers
        for(int i = 0;i < number_Nodes;i++)
        {
            scanf("%d",&element);
            SplayTree = SplayInsert(element, SplayTree);
            BSTTRee = BSTInsert(element, BSTTRee);
            AVLTree = AVLInsert(element, AVLTree);
        }
        
        printf("Input the element deleted\n");
        scanf("%d",&element);
        SplayTree =  SplayDelete(element,SplayTree);
        BSTTRee = BSTDelete(element, BSTTRee);
        AVLTree = AVLDelete(element, AVLTree);
        //
        LevelOrder_BSTTree(BSTTRee, number_Nodes);
        LevelOrder_AvlTree(AVLTree, number_Nodes);
        LevelOrder_SplayTree(SplayTree, number_Nodes);
        /*End Of the Program Test*/
        
        
    }
    else
    {
        //Initializing the data
        FILE *fp = NULL;
        int number_Nodes = 1000;
        int i = 0;
        printf("Reading the Txt\n");
        printf("* 1:demand1.txt\n");
        printf("* 2:demand2.txt\n");
        printf("* 3:demand3.txt\n");
        printf("* 4:Sample.txt\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                fp =fopen("demand1.txt", "r");
                break;
            case 2:
                fp =fopen("demand2.txt", "r");
                break;
            case 3:
                fp =fopen("demand3.txt", "r");
                break;
            case 4:
                fp =fopen("Sample.txt", "r");
            default:
                break;
        }

        if(!fp)
        {
            printf("TXT OPEN ERROR! You may check and rectify its address\n");
            return -1;
        }
        
        //Scan the data into the file
        fscanf(fp, "%d[^\n]", &number_Nodes);
        fgetc(fp);
        int Input_array[number_Nodes+1];
        int Delete_array[number_Nodes+1];
        for (i = 0; i < number_Nodes; i++)
        {
            fscanf(fp,"%d[^\n]",&Input_array[i]);
            fgetc(fp);
            //printf("%d",Input_array[i]);
        }
        for (i = 0; i < number_Nodes; i++)
        {
            fscanf(fp,"%d[^\n]",&Delete_array[i]);
            fgetc(fp);
         //  printf("%d",Delete_array[i]);
        }
        
        //Test the time
        clock_t start = clock();
        AvlTree AVLTree = NULL;
        	for(i = 0;i < number_Nodes; i++)
            	AVLTree = AVLInsert(Input_array[i], AVLTree);
        //LevelOrder_AvlTree(AVLTree, number_Nodes);
        
        	for(i = 0;i < number_Nodes; i++)
            	AVLTree = AVLDelete(Delete_array[i], AVLTree);
        clock_t end = clock();
        double TimeAVL = (double)(end - start)/CLK_TCK;
        
        
        start = clock();
        BSTTree BSTTREE = NULL;
        	for(i = 0;i < number_Nodes; i++)
            	BSTTREE = BSTInsert(Input_array[i], BSTTREE);
        	for(i = 0;i < number_Nodes; i++)
            	BSTTREE = BSTDelete(Delete_array[i], BSTTREE);
        end = clock();
		double TimeBST = (double)(end - start)/CLK_TCK;
		
		
        start = clock();
        NULLNode = Initialize();
        SplayTree SPLAYTREE = NULLNode;
        for(i = 0;i < number_Nodes; i++)
            SPLAYTREE = SplayInsert(Input_array[i], SPLAYTREE);
        for(i = 0;i < number_Nodes; i++)
           	SPLAYTREE = SplayDelete(Delete_array[i], SPLAYTREE);
        end = clock();
        double TimeSplay = (double)(end - start)/CLK_TCK;
        
        
        printf("The time cost of BST & AVL & Splay respecitvely are \n%lfms, %lfms, %lfms",
               TimeBST*1000,TimeAVL*1000,TimeSplay*1000);
    }
    
    
    return 0;
}





static int HeightAvl(PosAvl P)
{
    if(P == NULL)//Default:the empty Tree's height is -1
        return -1;
    return P->height;
}


AvlTree AVLInsert(int element,AvlTree T)
{
    if(T == NULL)/*Situation One： Create One node Tree*/
    {
        T = (struct AvlNode *)malloc(sizeof(struct AvlNode));
        if(T == NULL)//In case:Not Enough Space
            printf("Out of Space\n");
        else//Create element
        {
            T->element = element;
            T->height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if(element < T->element)
    {
        T -> Left = AVLInsert(element, T->Left);//Insert recursively
        if(HeightAvl(T -> Left) - HeightAvl(T->Right) == 2)
            //adding the left Node can only make the left larger than right
            if(element < T->Left->element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
    }
    else if(element > T->element)
    {
        T -> Right = AVLInsert(element, T->Right);
        if(HeightAvl(T->Right) - HeightAvl(T->Left) == 2)
            //adding the right Node can only make the right larger than left
            if(element > T ->Right->element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
    }
    /*Nothing has been done when the node is already in the Tree*/
    T->height = Maximum(HeightAvl(T->Left),HeightAvl(T->Right)) + 1;
    return T;
}



int Maximum(int a,int b)//Return with the larger number
{
    if (a > b)
        return a;
    else
        return b;
}



PosAvl SingleRotateWithLeft(AvlTree T)//When the height of Left is larger
{
    PosAvl Ttemp;
    Ttemp = T->Left;
    T->Left = Ttemp->Right;
    Ttemp -> Right = T;
    T->height = Maximum(HeightAvl(T->Left), HeightAvl(T->Right)) + 1;
    Ttemp->height = Maximum(HeightAvl(Ttemp->Left), HeightAvl(Ttemp->Right)) + 1;
    return Ttemp;
}



PosAvl SingleRotateWithRight(AvlTree T)//When the height of Right is larger
{
    PosAvl Ttemp;
    Ttemp = T->Right;
    T->Right = Ttemp->Left;
    Ttemp -> Left = T;
    T->height = Maximum(HeightAvl(T->Left), HeightAvl(T->Right)) + 1;
    Ttemp->height = Maximum(HeightAvl(Ttemp->Left), HeightAvl(Ttemp->Right)) + 1;
    return Ttemp;
}



PosAvl DoubleRotateWithLeft(AvlTree T)
//The Left height is larger AND the specific node is in the right side of the Left Child
{
    T->Left = SingleRotateWithRight(T->Left);
    return SingleRotateWithLeft(T);
}



PosAvl DoubleRotateWithRight(AvlTree T)
//The Right height is larger AND the specific node is in the left side of the Right Child
{
    T->Right = SingleRotateWithLeft(T->Right);
    return SingleRotateWithRight(T);
}



AvlTree AvlFindMin(AvlTree T)//Find the minimum number in the AVL Tree
{
    if (T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return AvlFindMin(T->Left);
}



AvlTree AVLDelete(int element, AvlTree T)//Delete the specific element in the AVLTree T
{
    AvlTree TmpCell = NULL;
    
    if(T == NULL)//No element in the Tree
        ;
    else if(element < T->element)
        {
            T->Left = AVLDelete(element, T->Left);
            if(HeightAvl(T->Right) - HeightAvl(T->Left) == 2)
                //deleting the left node may cause the height change beyond the range
            {
                if(T->Right != NULL)
                {
                    if (HeightAvl(T->Right->Left) > HeightAvl(T->Right->Right))
                        //Similar to inner Left insert to the Left Child
                        T = DoubleRotateWithRight(T);
                    else
                        //Similar to outer Right insert to the Right Child
                        T = SingleRotateWithRight(T);
                }
            }
        }
    else if(element > T->element)
        {
            T->Right = AVLDelete(element, T->Right);
            if(HeightAvl(T->Left) - HeightAvl(T->Right) == 2)
                //deleting the right node may cause the height change beyond the range
            {
                if(T->Left != NULL)
                {
                    if (HeightAvl(T->Left->Right) > HeightAvl(T->Left->Left))
                        //Similar to inner Left insert to the Left child
                        T = DoubleRotateWithLeft(T);
                    else
                        //Similar to outer Right insert to the Left child
                        T = SingleRotateWithLeft(T);
                }
            }
        }
    else if(T->Left != NULL && T->Right != NULL)//Find the element with both children
    {
        TmpCell = AvlFindMin(T->Right);//Find the minimum number from the right children
        T -> element = TmpCell->element;
        T->Right = AVLDelete(T->element, T->Right);
    }
    else//The specific element is leaf in the Tree
    {
        TmpCell = T;
        if(T->Left == NULL)
            T = T->Right;
        else if(T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }
    
    if(T != NULL)//Adjust the height of the Tree
        T->height = Maximum(HeightAvl(T->Left), HeightAvl(T->Right)) + 1;
    return T;
}



void LevelOrder_AvlTree(AvlTree T,int number_Nodes)//Level Order Traverse of AVLTREE
{
    if (T == NULL) {
        printf("The AVL Tree is NULL\n");
        return;
    }
    printf("The Level Order Traversal of AVL Tree is:");
    AvlTree queue[number_Nodes + 1];//Use queue to saver the nodes
    
    int current = 0,tail = 0;
    queue[current ++] = T;
    while (tail < current) {//if the tree is non-empty
        printf(" %d",queue[tail]->element);
        if (queue[tail]->Left != NULL)//Add left node into the array if not empty
            queue[current++] = queue[tail]->Left;
        if (queue[tail]->Right != NULL)//Add right node into the array if not empty
        queue[current++] = queue[tail]->Right;
        tail++;
    }
    printf("\n");
}



BSTTree BSTInsert(int element, BSTTree T)
{
    if (T == NULL)
    {
        /*Create and return a one-node Tree*/
        T = (BSTTree)malloc(sizeof(struct BSTNode));
        T->element = element;
        T->Left = T->Right = NULL;
    }
    else if(element < T->element)//Recuesivly Insert when insertion number smaller than T
    {
        T->Left = BSTInsert(element, T->Left);
    }
    else if(element > T->element)//Recuesivly Insert when insertion number larger than T
    {
        T->Right = BSTInsert(element, T->Right);
    }//nothing has been done when x is already in the Tree
    return T;
}



BSTTree BSTDelete(int element, BSTTree T)
{
    BSTTree TmpCell = NULL;
    
    if(T == NULL)//No Element in the Tree
        ;
    else if(element < T->element)//Situation 1:Insertion number < T's number
        T->Left = BSTDelete(element, T->Left);
    else if(element > T->element)//Situation 2:Insertion number > T's number
        {
            T->Right = BSTDelete(element, T->Right);
        }
    else if (T->Left != NULL && T->Right != NULL)//Find the right position(parent)
    {
        TmpCell = BSTFindMin(T->Right);
        T->element = TmpCell->element;
        T->Right = BSTDelete(T->element, T->Right);
    }
    else//Find the Right Position(child)
    {
        TmpCell = T;
        if(T -> Left == NULL)
            T = T->Right;
        else if(T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }
    
    return T;
}



PosBST BSTFindMin(BSTTree T)//Find the minimum number in the right side of Tree
{
    if (T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return BSTFindMin(T->Left);
}



void LevelOrder_BSTTree(BSTTree T,int number_Nodes)//Level Order Traverse of BST and PRINT
{
    if (T == NULL) {
        printf("The BST Tree is NULL\n");
        return;
    }
    printf("The Level Order Traversal of BST Tree is:");
    BSTTree queue[number_Nodes + 1];//Use queue to saver the nodes
    
    int current = 0,tail = 0;
    queue[current ++] = T;
    while (tail < current) {//if the tree is non-empty
        printf(" %d",queue[tail]->element);
        if (queue[tail]->Left != NULL)//Add left node into the array if not empty
            queue[current++] = queue[tail]->Left;
        if (queue[tail]->Right != NULL)//Add right node into the array if not empty
            queue[current++] = queue[tail]->Right;
        tail++;
    }
    printf("\n");
}



SplayTree Initialize(void)//Initialize the NULLNODE
{
    if(NULLNode == NULL)
    {
        NULLNode = (SplayTree)malloc(sizeof(struct AvlNode));
        NULLNode->Left = NULLNode->Right = NULLNode;
    }
    return NULLNode;
}

SplayTree SplayInsert(int element,SplayTree T)//Insert the nodes into the splay Tree
{
    static SplayTree NewNode = NULL;
    if(NewNode == NULL)
        NewNode = (SplayTree)malloc(sizeof(struct AvlNode));
    NewNode->element = element;
    
    if(T == NULLNode)//If empty Tree , create the root
    {
        NewNode->Left = NewNode->Right = NULLNode;
        T = NewNode;
    }
    else
    {
        T = Splay(element, T);//Rectify the Splay Tree
        if(element < T->element)//the insertion is smaller than T
        {
            NewNode->Left = T->Left;
            NewNode->Right = T;
            T->Left = NULLNode;
            T = NewNode;
        }
        else if(T->element < element)//the insertion is larger than T
        {
            NewNode->Right = T->Right;
            NewNode->Left = T;
            T->Right = NULLNode;
            T = NewNode;
        }
        else//Already in the Tree
            return T;
    }
    
    NewNode = NULL;//Next Insert can call malloc
    return T;
}



SplayTree SplayDelete(int element,SplayTree T)
{
    SplayTree NewTree;
    
    if(T != NULLNode)
    {
        T = Splay(element, T);//In case: Wrong Delete
        if(element == T->element)
        {//Already in the Tree
            if(T->Left == NULLNode)//If the Tree has no LEFT child,simply delete its root
                NewTree = T->Right;
            else
            //If the tree has LEFT child,move its largest to the root AND DELETE the specific number
            {
                NewTree = T->Left;
                NewTree = Splay(element, NewTree);//GET the biggest Number in its LEft Child
                NewTree->Right = T->Right;
            }
            free(T);
            T = NewTree;
        }
    }
    
    return T;
}





SplayTree Splay(int element,SplayTree T)
{
    static struct AvlNode Header;//Default:AvlNode is equivalence to SplayNode in this scenario
    SplayTree LeftTreeMax, RightTreeMin;
    //LeftTreeMax will point to the largest node of left child
    //RightTreeMin will point to the minimum node of the Right child
    
    Header.Left = Header.Right = NULLNode;
    LeftTreeMax = RightTreeMin = &Header;
    NULLNode->element = element;
    
    while (element != T->element)
    {
        if(element < T->element)//element < T,its rotation with Left
        {
            if(element < T->Left->element)//Zip-Zip image
                T = SingleRotateWithLeft(T);
            if(T->Left == NULLNode)//Come to the end
                break;
            RightTreeMin->Left = T;
            //Change its Pointer similar to SingleRotationWithright
            RightTreeMin = T;
            T = T->Left;
        }
        else
        {
            if(element > T->Right->element)//Zip-Zip image
                T = SingleRotateWithRight(T);
            if(T->Right == NULLNode)//Come to the end
                break;
            LeftTreeMax->Right = T;
            //Change its Pointer similar to SingleRotationWithLeft
            LeftTreeMax = T;
            T = T->Right;
        }
    }//End with element = T->element
    
    LeftTreeMax->Right = T->Left;
    RightTreeMin->Left = T->Right;
    T->Left = Header.Right;
    T->Right = Header.Left;
    
    return T;
}



void LevelOrder_SplayTree(SplayTree T,int number_Nodes)//Level Order Traverse of SplayTREE
//Notice that the NULL pointer of Splay Tree is NULLNode
{
    if (T == NULL) {
        printf("The Splay Tree is NULL\n");
        return;
    }
    printf("The Level Order Traversal of Splay Tree is:");
    SplayTree queue[number_Nodes + 1];//Use queue to saver the nodes
    
    int current = 0,tail = 0;
    queue[current ++] = T;
    while (tail < current) {//if the tree is non-empty
        printf(" %d",queue[tail]->element);
        if (queue[tail]->Left != NULLNode)//Add left node into the array if not empty
            queue[current++] = queue[tail]->Left;
        if (queue[tail]->Right != NULLNode)//Add right node into the array if not empty
            queue[current++] = queue[tail]->Right;
        tail++;
    }
    printf("\n");
}
