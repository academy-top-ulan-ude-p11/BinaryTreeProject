#include <iostream>
#pragma once
class BinaryTree
{
	struct Node
	{
		int value;
		Node* parent = nullptr;
		Node* leftChild = nullptr;
		Node* rightChild = nullptr;
	};

	Node* root;
	int size;

	void AddInside(int value, Node*& nodeTop);
public:
	BinaryTree() : root{ nullptr }, size{ 0 } {};

	void AddLoop(int value);
	void AddReq(int value);

	int Value(Node* node);

	Node*& Min(Node* nodeTop);
	Node*& MinTree();
	Node*& Max(Node* nodeTop);
	Node*& MaxTree();

	Node*& Search(int key);

	void Delete(Node* nodeDel);

	void PrintReq(Node* nodeTop);
	void Print();
};

