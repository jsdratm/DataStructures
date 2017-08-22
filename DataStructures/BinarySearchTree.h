#pragma once

struct BinarySearchTreeNode
{
	int key;
	struct BinarySearchTreeNode* left;
	struct BinarySearchTreeNode* right;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTreeNode* Insert(struct BinarySearchTreeNode* nodeToInsert, int key);
	BinarySearchTreeNode* CreateNewNode(int key);
};

