#include "TreeNode.h"
#include <iostream>

TreeNode* CreateTreeNode(int value)
{
	TreeNode* treeNode = new TreeNode;
	treeNode->Value = value;
	treeNode->Left = nullptr;
	treeNode->Right = nullptr;
	
	return treeNode;
}

TreeNode* InsertNode(TreeNode* node, int value)
{
	if (node == nullptr)
	{
		node = CreateTreeNode(value);
	}
	else if (node->Value == value)
	{
		std::cout << std::endl;
		std::cout << "This value is" << std::endl;
		return node;
	}
	else if (value < node->Value)
	{
		node->Left = InsertNode(node->Left, value);
	}
	else
	{
		node->Right = InsertNode(node->Right, value);
	}
	return node;
}

TreeNode* RemoveNode(TreeNode* node, int value)
{
	if (node == nullptr)
	{
		return node;
	}

	if (value < node->Value)
	{
		node->Left = RemoveNode(node->Left, value);
		return node;
	}
	else if (value > node->Value)
	{
		node->Right = RemoveNode(node->Right, value);
		return node;
	}
	else
	{
		if (node->Left == nullptr)
		{
			TreeNode* temp = node->Right;
			delete node;
			return temp;
		}
		else if (node->Right == nullptr)
		{
			TreeNode* temp = node->Left;
			delete node;
			return temp;
		}
		else
		{
			TreeNode* minNode = FindMin(node->Right);
			node->Value = minNode->Value;
			RemoveNode(node->Right, minNode->Value);
			return minNode;
		}
	}
}

TreeNode* Search(TreeNode* node, int value)
{
	if (node == nullptr || node->Value == value)
	{
		return node;
	}
	if (value < node->Value)
	{
		return Search(node->Left, value);
	}
	else if (value > node->Value)
	{
		return Search(node->Right, value);
	}
}

TreeNode* FindMin(TreeNode* node)
{
	while (node->Left != nullptr)
	{
		node = node->Left;
	}
	return node;
}

TreeNode* FindMax(TreeNode* node)
{
	while (node->Right != nullptr)
	{
		node = node->Right;
	}
	return node;
}

void DeleteTreeNode(TreeNode* node)
{
	if (node)
	{
		DeleteTreeNode(node->Left);
		DeleteTreeNode(node->Right);
		delete node;
	}
}