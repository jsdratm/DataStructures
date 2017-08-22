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
	BinarySearchTreeNode* Insert(struct BinarySearchTreeNode* node, int key);
	BinarySearchTreeNode* Delete(struct BinarySearchTreeNode* node, int key);
	BinarySearchTreeNode* FindKey(struct BinarySearchTreeNode* node, int key);
	BinarySearchTreeNode* CreateNewNode(int key);
	BinarySearchTreeNode* GetMinimumValueNode(struct BinarySearchTreeNode* node);
	BinarySearchTreeNode* GetMaximumValueNode(struct BinarySearchTreeNode* node);
	bool ContainsKey(BinarySearchTreeNode* node, int key);
};

