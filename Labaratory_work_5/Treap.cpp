#include "TreapNode.h"
#include "Treap.h"
#include <iostream>
#include <iomanip>

Treap* CreateTreap(int key)
{
	Treap* treap = new Treap;
	treap->Root = CreateTreapNode(key);
	treap->Count = 1;

	return treap;
}

TreapNode* SearchTreap(Treap* treap, int key)
{
	TreapNode* result = Search(treap->Root, key);
	return result;
}

void AddTreap(Treap* treap, int key)
{
	if (Search(treap->Root, key))
	{
		std::cout << std::endl;
		std::cout << "Element is in a treap" << std::endl;
		std::cout << std::endl;
		return;
	}

	TreapNode* result = Add(treap->Root, key);
	treap->Root = result;
	++treap->Count;
}

void AddTreapOptimized(Treap* treap, int key)
{
	if (Search(treap->Root, key))
	{
		std::cout << std::endl;
		std::cout << "Element is in a treap" << std::endl;
		std::cout << std::endl;
		return;
	}
	TreapNode* newNode = CreateTreapNode(key);
	TreapNode* result = AddOptimized(treap->Root, newNode);
	treap->Root = result;
	++treap->Count;
}

void RemoveTreap(Treap* treap, int key)
{
	if (!Search(treap->Root, key))
	{
		std::cout << std::endl;
		std::cout << "Element is not in a treap" << std::endl;
		std::cout << std::endl;
		return;
	}
	Remove(treap->Root, key);
	--treap->Count;
}

void RemoveTreapOptimized(Treap* treap, int key)
{
	if (!Search(treap->Root, key))
	{
		std::cout << std::endl;
		std::cout << "Element is not in a treap" << std::endl;
		std::cout << std::endl;
		return;
	}
	RemoveOptimized(treap->Root, key);
	--treap->Count;
}

void PrintRoots(TreapNode* node, int space)
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
		std::cout << " " << node->Key << ":" << node->Priority << "\n";

		// Рекурсивно выводим левое поддерево
		PrintRoots(node->Left, space);
	}
}

void PrintTreap(Treap* treap)
{
	PrintRoots(treap->Root, 0);
	std::cout << std::endl;
}

void DeleteTreap(Treap* treap)
{
	DeleteTreapNode(treap->Root);
	delete treap;
}