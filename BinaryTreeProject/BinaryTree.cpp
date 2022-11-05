#include "BinaryTree.h"

void BinaryTree::AddInside(int value, Node*& nodeTop)
{
	if (!nodeTop)
	{
		Node* nodeNew = new Node();
		nodeNew->value = value;
		nodeNew->parent = nodeTop;
		nodeTop = nodeNew;
	}
	else
	{
		if (value <= nodeTop->value)
			AddInside(value, nodeTop->leftChild);
		else
			AddInside(value, nodeTop->rightChild);
	}
}

void BinaryTree::AddLoop(int value)
{
	Node* nodeCurr{ root };
	Node* nodeParent{ nullptr };

	while (nodeCurr)
	{
		nodeParent = nodeCurr;
		if (value <= nodeCurr->value)
			nodeCurr = nodeCurr->leftChild;
		else
			nodeCurr = nodeCurr->rightChild;
	}

	Node* nodeNew = new Node();
	nodeNew->value = value;
	nodeNew->parent = nodeParent;
	
	if (!nodeParent)
	{
		root = nodeNew;
	}
	else
	{
		if (nodeNew->value <= nodeParent->value)
			nodeParent->leftChild = nodeNew;
		else
			nodeParent->rightChild = nodeNew;
	}
}

void BinaryTree::AddReq(int value)
{
	AddInside(value, root);
}

int BinaryTree::Value(Node* node)
{
	return node->value;
}

BinaryTree::Node*& BinaryTree::Min(Node* nodeTop)
{
	if (!nodeTop->leftChild)
		return nodeTop;
	else
		Min(nodeTop->leftChild);
}

BinaryTree::Node*& BinaryTree::MinTree()
{
	return Min(root);
}

BinaryTree::Node*& BinaryTree::Max(Node* nodeTop)
{
	if (!nodeTop->rightChild)
		return nodeTop;
	else
		Min(nodeTop->rightChild);
}

BinaryTree::Node*& BinaryTree::MaxTree()
{
	return Max(root);
}

BinaryTree::Node*& BinaryTree::Search(int key)
{
	Node* nodeCurr{ root };
	while (nodeCurr)
	{
		if (nodeCurr->value == key)
			break;
		if (key < nodeCurr->value)
			nodeCurr = nodeCurr->leftChild;
		else
			nodeCurr = nodeCurr->rightChild;
	}
	return nodeCurr;
}

void BinaryTree::Delete(Node* nodeDel)
{
	// leftChild == nullptr && rightChild == nullptr
	if (!nodeDel->leftChild && !nodeDel->rightChild)
	{
		if (root == nodeDel)
			root = nullptr;
		else
		{
			if (nodeDel == nodeDel->parent->leftChild)
				nodeDel->parent->leftChild = nullptr;
			else
				nodeDel->parent->rightChild = nullptr;
		}

		delete nodeDel;
		return;
	}

	// leftChild == nullptr || rightChild == nullptr
	if (nodeDel->leftChild && !nodeDel->rightChild || !nodeDel->leftChild && nodeDel->rightChild)
	{

		Node* child;
		if (nodeDel->leftChild)
			child = nodeDel->leftChild;
		else
			child = nodeDel->rightChild;		

		if (root == nodeDel)
		{
			root = child;
			child->parent = nullptr;
		}
		else
		{
			if (nodeDel == nodeDel->parent->leftChild)
				nodeDel->parent->leftChild = child;
			else
				nodeDel->parent->rightChild = child;
		}

		delete nodeDel;
		return;
	}

	// leftChild != nullptr && rightChild != nullptr
	Node* minRight = Min(nodeDel->rightChild);
	nodeDel->value = minRight->value;
	if (minRight->parent != nodeDel)
		minRight->parent->leftChild = nullptr;
	else
		minRight->parent->rightChild = minRight->rightChild;
	delete minRight;
}


void BinaryTree::PrintReq(Node* nodeTop)
{
	if (nodeTop)
	{
		PrintReq(nodeTop->leftChild);
		std::cout << nodeTop->value << " ";
		PrintReq(nodeTop->rightChild);
	}
}

void BinaryTree::Print()
{
	PrintReq(root);
}
