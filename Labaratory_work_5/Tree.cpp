#include "Tree.h"
#include "TreeNode.h"
#include <iostream>

Tree* CreateTree(int value)
{
	Tree* binaryTree = new Tree;
	binaryTree->Root = CreateTreeNode(value);
	binaryTree->Count = 1;

	return binaryTree;
}

void Insert(Tree* binaryTree, int value)
{
	InsertNode(binaryTree->Root, value);
	++binaryTree->Count;
}

void Remove(Tree* binaryTree, int value)
{
	RemoveNode(binaryTree->Root, value);
	--binaryTree->Count;
}

TreeNode* Search(Tree* binaryTree, int value)
{
	TreeNode* result = Search(binaryTree->Root, value);
	return result;
}

TreeNode* FindMin(Tree* binaryTree)
{
	TreeNode* minResult = FindMin(binaryTree->Root);
	return minResult;
}

TreeNode* FindMax(Tree* binaryTree)
{
	TreeNode* maxResult = FindMax(binaryTree->Root);
	return maxResult;
}

/// <summary>
/// Вывод узлов дерева.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="space">Ширина между элементами.</param>
void PrintRoots(TreeNode* node, int space) 
{
	if (node != nullptr) 
	{
		// Ширина между элементами
		space += 10; 

		// Рекурсивно выводим правое поддерево
		PrintRoots(node->Right, space);

		// Вывод текущего узла
		std::cout << std::endl;
		// Отступ
		for (int i = 10; i < space; i++) std::cout << " ";
		std::cout << " " << node->Value << "\n";

		// Рекурсивно выводим левое поддерево
		PrintRoots(node->Left, space);
	}
}

void PrintTree(Tree* binaryTree)
{
	PrintRoots(binaryTree->Root, 0);
	std::cout << std::endl;
}

void DeleteTree(Tree* binaryTree)
{
	DeleteTreeNode(binaryTree->Root);
	delete binaryTree;
}