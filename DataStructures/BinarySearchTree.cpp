#include "BinarySearchTree.h"
#include<stdio.h>
#include<stdlib.h>


// Constructor
BinarySearchTree::BinarySearchTree()
{
	// Do nothing (no member variables to manage)
}

// Destructor
BinarySearchTree::~BinarySearchTree()
{
	// Do nothing (no member variables to manage)
}

// Inserts a new node into the BST in the proper location
// This function is recursive
BinarySearchTreeNode* BinarySearchTree::Insert(BinarySearchTreeNode* node, int key)
{
	// Check if we have reached the end of the tree and, if so, create a new node for this key
	if (node == NULL)
	{
		return CreateNewNode(key);
	}

	// Otherwise, continue traversing down the tree.
	// Determine where to place the key based on its relative value to the current node
	// If the key is greater than the current node, move right, otherwise move left
	if (key < node->key)
	{
		node->left = Insert(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = Insert(node->right, key);
	}
	else
	{
		// We found out that this key already exists in the BST, so it doesn't need to be inserted at this point
	}

	return node;
}

// Creates a new node struct for the BST
BinarySearchTreeNode* BinarySearchTree::CreateNewNode(int key)
{
	struct BinarySearchTreeNode* returnNode = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
	returnNode->key = key;
	returnNode->left = NULL;
	returnNode->right = NULL;
	return returnNode;
}

// Returns true if the specified key exists in the binary search tree
// If not, false
// This function is recursive
bool BinarySearchTree::ContainsKey(BinarySearchTreeNode* node, int key)
{
	// If we have hit a null node, the key doesn't exist in the BST
	if (node == NULL)
	{
		return false;
	}

	// Otherwise, check if we need to traverse further down the tree
	if (key < node->key)
	{
		// The key must be to the left, so continue down that path
		return ContainsKey(node->left, key);
	}
	else if (key > node->key)
	{
		// The key must be to the right, so continue down that path
		return ContainsKey(node->right, key);
	}
	else
	{
		// The current node is the key
		return false;
	}
}
