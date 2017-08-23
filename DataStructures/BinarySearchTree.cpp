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
BinarySearchTreeNode* BinarySearchTree::Insert(int key)
{
	BinarySearchTreeNode* returnNode = Insert(root, key);

	if (root == NULL)
	{
		root = returnNode;
	}

	return returnNode;
}

// Inserts a new node into the BST in the proper location
// This function is recursive
BinarySearchTreeNode* BinarySearchTree::Insert(BinarySearchTreeNode* node, int key)
{
	// Check if we have reached the end of the tree and, if so, create a new node for this key
	if (node == NULL)
	{
		struct BinarySearchTreeNode* returnNode = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
		returnNode->key = key;
		returnNode->left = NULL;
		returnNode->right = NULL;
		return returnNode;
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

// Deletes the node with the specified key from the BST passed in
// Returns the new BST root since the one passed in may no longer exist
BinarySearchTreeNode* BinarySearchTree::Delete(int key)
{
	if (root != NULL && key == root->key)
	{
		root = Delete(root, key);
		return root;
	}
	else
	{
		return Delete(root, key);
	}	
}

// Deletes the node with the specified key from the BST passed in
// Returns the new BST root since the one passed in may no longer exist
BinarySearchTreeNode* BinarySearchTree::Delete(BinarySearchTreeNode* node, int key)
{
	// If the node passed in is null, we can't do anything except return it
	if (node == NULL)
	{
		return node;
	}

	if (key < node->key)
	{
		// The key is to the left of the passed in node, so continue traversing until it is found
		node->left = Delete(node->left, key);
	}
	else if (key > node->key)
	{
		// The key is to the right of the passed in node, so continue traversing until it is found
		node->right = Delete(node->right, key);
	}
	else
	{
		// The key to be deleted matches the current node, so time to do some deletin'
		if (node->left == NULL && node->right == NULL)
		{
			// In this case, the node to be deleted has no children, so it can just be deleted without worrying about children
			free(node);
			return NULL;
		}
		else if (node->left == NULL)
		{
			// In this case, the left child node is null and the right child node is not null
			// We are going to make the right child node replace the current node that we are deleting
			struct BinarySearchTreeNode* tempNode = node->right;
			free(node);
			return tempNode;
		}
		else if (node->right == NULL)
		{
			// In this case, the right child node is null and the left child node is not null
			// We are going to make the left child node replace the current node that we are deleting
			struct BinarySearchTreeNode* tempNode = node->left;
			free(node);
			return tempNode;
		}
		else
		{
			// In this case, the node to be deleted has two children (left and right)
			// We must find the smallest node on the right hand side to replact the node that is being deleted
			// This will maintain the correct BST hierarchy
			struct BinarySearchTreeNode* tempNode = GetMinimumValueNode(node->right);
			node->key = tempNode->key;
			node->right = Delete(node->right, tempNode->key);
		}
	}

	return node;
}

// Searches for the specified key from the specified BST node
// Returns null if the key is not found in the BST
// Otherwise returns the node containing the key
BinarySearchTreeNode* BinarySearchTree::Search(int key)
{
	return Search(root, key);
}

// Searches for the specified key from the specified BST node
// Returns null if the key is not found in the BST
// Otherwise returns the node containing the key
BinarySearchTreeNode* BinarySearchTree::Search(BinarySearchTreeNode* node, int key)
{
	if (node == NULL)
	{
		// The node is NULL, so the key doesn't exist in the BST
		// return NULL to indicate this
		return node;
	}
	else if (node->key < key)
	{
		// Traverse right
		return Search(node->right, key);
	}
	else if (node->key > key)
	{
		// Traverse left
		return Search(node->left, key);
	}
	else
	{
		// We found a node that has a key matching the specified key, so return the node
		return node;
	}
}

// Returns the node in the tree with the minimum (lowest) value
// If the node passed in is NULL or the minimum, it will be returned
BinarySearchTreeNode* BinarySearchTree::GetMinimumValueNode()
{
	return GetMinimumValueNode(root);
}

// Returns the node in the tree with the minimum (lowest) value
// If the node passed in is NULL or the minimum, it will be returned
BinarySearchTreeNode* BinarySearchTree::GetMinimumValueNode(BinarySearchTreeNode* node)
{
	struct BinarySearchTreeNode* currentNode = node;

	while (currentNode->left != NULL)
	{
		currentNode = currentNode->left;
	}

	return currentNode;
}

// Returns the node in the tree with the maximum (highest) value
// If the node passed in is NULL or the maximum, it will be returned
BinarySearchTreeNode* BinarySearchTree::GetMaximumValueNode()
{
	return GetMaximumValueNode(root);
}

// Returns the node in the tree with the maximum (highest) value
// If the node passed in is NULL or the maximum, it will be returned
BinarySearchTreeNode* BinarySearchTree::GetMaximumValueNode(BinarySearchTreeNode* node)
{
	struct BinarySearchTreeNode* currentNode = node;

	while (currentNode->right != NULL)
	{
		currentNode = currentNode->right;
	}

	return currentNode;
}

// Returns true if the specified key exists in the binary search tree
// If not, false
bool BinarySearchTree::ContainsKey(int key)
{
	return ContainsKey(root, key);
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
		return true;
	}
}
