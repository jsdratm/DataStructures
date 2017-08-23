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
	BinarySearchTreeNode* root;
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTreeNode* Insert(int key);
	BinarySearchTreeNode* Insert(struct BinarySearchTreeNode* node, int key);
	BinarySearchTreeNode* Delete(int key);
	BinarySearchTreeNode* Delete(struct BinarySearchTreeNode* node, int key);
	BinarySearchTreeNode* Search(int key);
	BinarySearchTreeNode* Search(struct BinarySearchTreeNode* node, int key);
	BinarySearchTreeNode* GetMinimumValueNode();
	BinarySearchTreeNode* GetMinimumValueNode(struct BinarySearchTreeNode* node);
	BinarySearchTreeNode* GetMaximumValueNode();
	BinarySearchTreeNode* GetMaximumValueNode(struct BinarySearchTreeNode* node);
	bool ContainsKey(int key);
	bool ContainsKey(BinarySearchTreeNode* node, int key);
};

