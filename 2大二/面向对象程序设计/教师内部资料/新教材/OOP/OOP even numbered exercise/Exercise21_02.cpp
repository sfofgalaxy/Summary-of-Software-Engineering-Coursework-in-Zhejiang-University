#include <iostream>
#include <string>
#include <cmath>
#include "Queue.h"
using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

template < typename T >
class TreeNode
{
public:
  T element; // Element contained in the node
  TreeNode < T > * left; // Pointer to the left child
  TreeNode < T > * right; // Pointer to the right child

  TreeNode() // No-arg constructor
  {
    left = NULL;
    next = NULL;
  }

  TreeNode(T element) // Constructor
  {
    this->element = element;
    left = NULL;
    right = NULL;
  }
};



template < typename T >
class BinaryTree
{
public:
  BinaryTree();
  BinaryTree(T elements[], int arraySize);
  bool insert(T element);
  void inorder();
  void preorder();
  void postorder();
  int getSize();
  bool search(T element);
  void breadthFirstTraversal();
  int depth();

private:
  TreeNode < T > * root;
  int size;
  void inorder(TreeNode < T > * root);
  void postorder(TreeNode < T > * root);
  void preorder(TreeNode < T > * root);
  bool search(T element, TreeNode < T > * root);
  int depth(TreeNode<T> * root);
};



template < typename T >
BinaryTree < T >::BinaryTree()
{
  root = NULL;
  size = 0;
}

template < typename T >
BinaryTree < T >::BinaryTree(T elements[], int arraySize)
{
  root = NULL;
  size = 0;
  for (int i = 0; i < arraySize; i++)
  {
    insert(elements[i]);
  }
}

/* Insert element into the binary tree * Return true if the element is inserted successfully
* Return false if the element is already in the list */

template < typename T >
bool BinaryTree < T >::insert(T element)
{
  if (root == NULL)
    root = new TreeNode < T > (element); // Create a new root
  else
  {
    // Locate the parent node
    TreeNode < T > * parent = NULL;
    TreeNode < T > * current = root;
    while (current != NULL)
      if (element < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (element > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        return false; // Duplicate node not inserted

    // Create the new node and attach it to the parent node
    if (element < parent->element)
      parent->left = new TreeNode < T > (element);
    else
      parent->right = new TreeNode < T > (element);
  }

  size++;
  return true; // Element inserted
}

/* Inorder traversal */

template < typename T >
void BinaryTree < T >::inorder()
{
  inorder(root);
}

/* Inorder traversal from a subtree */

template < typename T >
void BinaryTree < T >::inorder(TreeNode < T > * root)
{
  if (root == NULL) return;
  inorder(root->left);
  cout << root->element << " ";
  inorder(root->right);
}

/* Postorder traversal */

template < typename T >
void BinaryTree < T >::postorder()
{
  postorder(root);
}

/** Inorder traversal from a subtree */

template < typename T >
void BinaryTree < T >::postorder(TreeNode < T > * root)
{
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->element << " ";
}

/* Preorder traversal */

template < typename T >
void BinaryTree < T >::preorder()
{
  preorder(root);
}

/* Preorder traversal from a subtree */

template < typename T >
void BinaryTree < T >::preorder(TreeNode < T > * root)
{
  if (root == NULL) return;
  cout << root->element << " ";
  preorder(root->left);
  preorder(root->right);
}

/* Get the number of nodes in the tree */

template < typename T >
int BinaryTree < T >::getSize()
{
  return size;
}

template < typename T >
void BinaryTree < T >::breadthFirstTraversal()
{
  Queue<TreeNode<T> *> queue;

  if (root != NULL)  queue.enqueue(root);

  while (queue.getSize() > 0)
  {
    TreeNode<T> * node = queue.dequeue();
    cout << node->element << " ";

    if ( (node->left) != NULL)
      queue.enqueue(node->left);

    if ( (node->right) != NULL)
      queue.enqueue(node->right);
  }
}
#endif

int main()
{
  BinaryTree < string > tree1;
  tree1.insert("George");
  tree1.insert("Michael");
  tree1.insert("Tom");
  tree1.insert("Adam");
  tree1.insert("Jones");
  tree1.insert("Peter");
  tree1.insert("Daniel");

  cout << "Inorder (sorted): ";
  tree1.inorder();

  cout << "\nPostorder: ";
  tree1.postorder();

  cout << "\nPreorder: ";
  tree1.preorder();

  cout << "\nThe number of nodes is " << tree1.getSize();

  int numbers[] =
  {
    2, 4, 3, 1, 8, 5, 6, 7
  };
  BinaryTree < int > tree2(numbers, 8);
  cout << "\nInorder (sorted): ";
  tree2.inorder();

  // Test breadth-first
  cout << "\nBreadth-first: ";
  tree2.breadthFirstTraversal();

  return 0;
}
