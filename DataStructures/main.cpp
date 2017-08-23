#include <iostream>  
#include "BinarySearchTree.h"

using namespace std;
void main()
{
	// Create the binary search tree
	BinarySearchTree* binaryTree = new BinarySearchTree();
	cout << binaryTree->ContainsKey(1);
	binaryTree->Insert(1);
	cout << binaryTree->ContainsKey(1);

	cout << binaryTree->ContainsKey(2);
	binaryTree->Insert(2);
	cout << binaryTree->ContainsKey(2);

	cout << binaryTree->ContainsKey(3);
	binaryTree->Insert(3);
	cout << binaryTree->ContainsKey(3);

	cout << endl;

	// Delete the binary search tree nodes
	binaryTree->Delete(1);
	cout << binaryTree->ContainsKey(1);
	cout << binaryTree->ContainsKey(2);
	cout << binaryTree->ContainsKey(3);
	cout << endl;

	binaryTree->Delete(2);
	cout << binaryTree->ContainsKey(1);
	cout << binaryTree->ContainsKey(2);
	cout << binaryTree->ContainsKey(3);
	cout << endl;

	binaryTree->Delete(3);
	cout << binaryTree->ContainsKey(1);
	cout << binaryTree->ContainsKey(2);
	cout << binaryTree->ContainsKey(3);
	cout << endl;
	
	int x;
	cin >> x;
}