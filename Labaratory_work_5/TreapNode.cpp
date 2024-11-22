#include "TreapNode.h"
#include <iostream>

TreapNode* CreateTreapNode(int key)
{
	srand(time(0));

	TreapNode* treapNode = new TreapNode;
	treapNode->Key = key;
	treapNode->Priority = rand() % 31;
	treapNode->Right = nullptr;
	treapNode->Left = nullptr;

	return treapNode;
}

TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (!left)
	{
		return right;
	}
	if (!right)
	{
		return left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (!node) 
	{
		left = right = nullptr;
		return;
	}

	if (node->Key <= key)
	{
		if (!node->Right)
		{
			right = nullptr;
			left = node;
		}
		else
		{
			left = node;
			Split(node->Right, key, left->Right, right);
		}
	}
	else
	{
		if (!node->Left)
		{
			left = nullptr;
			right = node;
		}
		else
		{
			right = node;
			Split(node->Left, key, left, right->Left);
		}
	}
}

TreapNode* Add(TreapNode* node, int key)
{
	TreapNode* left;
	TreapNode* right;
	
	Split(node, key, left, right);
	TreapNode* mergeNode = CreateTreapNode(key);
	
	TreapNode* result = Merge(Merge(left, mergeNode), right);
	return result;
}

TreapNode* AddOptimized(TreapNode* node, TreapNode* newNode)
{	
	if (!node)
	{
		node = newNode;
		return node;
	}

	if (node->Priority > newNode->Priority)
	{
		if (newNode->Key < node->Key)
		{
			node->Left = AddOptimized(node->Left, newNode);
			return node;
		}
		else
		{
			node->Right = AddOptimized(node->Right, newNode);
			return node;
		}
	}

	Split(node, newNode->Key, newNode->Left, newNode->Right);
	node = newNode;
	return node;
}

TreapNode* Remove(TreapNode* node, int key)
{
	TreapNode* left;
	TreapNode* right;
	TreapNode* middle = nullptr;

	Split(node, key, left, right);
	Split(middle, key + 1, middle, right);

	delete middle;

	TreapNode* result = Merge(left, right);
	return result;
}

TreapNode* RemoveOptimized(TreapNode* node, int key)
{
	if (node == nullptr)
	{
		return node;
	}
	if (node->Key > key)
	{
		node->Left = RemoveOptimized(node->Left, key);
		return node;
	}
	else if (node->Key < key)
	{
		node->Right = RemoveOptimized(node->Right, key);
		return node;
	}
	else
	{
		TreapNode* current = node;
		TreapNode* result = Merge(node->Left, node->Right);
		delete current;
		return result;
	}
}

TreapNode* Search(TreapNode* node, int key)
{
	if (node == nullptr || node->Key == key)
	{
		return node;
	}
	if (key < node->Key)
	{
		return Search(node->Left, key);
	}
	else if (key > node->Key)
	{
		return Search(node->Right, key);
	}
}

void DeleteTreapNode(TreapNode* node)
{
	if (node)
	{
		DeleteTreapNode(node->Left);
		DeleteTreapNode(node->Right);
		delete node;
	}
}