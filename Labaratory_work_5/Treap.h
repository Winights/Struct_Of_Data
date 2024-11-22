#pragma once
#include "TreapNode.h"

/// <summary>
/// Структура декартового дерева.
/// </summary>
struct Treap
{
	/// <summary>
	/// Структура узла дерева.
	/// </summary>
	TreapNode* Root;

	/// <summary>
	/// Количество элементов в дереве.
	/// </summary>
	int Count;
};

/// <summary>
/// Создание дерева.
/// </summary>
/// <param name="key">Ключ.</param>
/// <returns>Созданное дерево.</returns>
Treap* CreateTreap(int key);

/// <summary>
/// Поиск элемента в дереве.
/// </summary>
/// <param name="node">Структура дерева.</param>
/// <param name="key">Ключ.</param>
/// <returns>Найденный элемент.</returns>
TreapNode* SearchTreap(Treap* treap, int key);

/// <summary>
/// Добавления элемента в дерево.
/// </summary>
/// <param name="node">Структура дерева.</param>
/// <param name="key">Ключ.</param>
void AddTreap(Treap* treap, int key);

/// <summary>
/// Удаление элемента из дерева.
/// </summary>
/// <param name="node">Структура дерева.</param>
/// <param name="key">Ключ.</param>
void RemoveTreap(Treap* treap, int key);

/// <summary>
/// Добавления элемента в дерево оптимизированным способом.
/// </summary>
/// <param name="node">Структура дерева.</param>
/// <param name="key">Ключ.</param>
void AddTreapOptimized(Treap* treap, int key);

/// <summary>
/// Удаление элемента из дерева оптимизированным способом.
/// </summary>
/// <param name="node">Структура дерева.</param>
/// <param name="key">Ключ.</param>
void RemoveTreapOptimized(Treap* treap, int key);

/// <summary>
/// Вывод узлов дерева.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="space">Ширина между элементами.</param>
void PrintRoots(TreapNode* node, int space);

/// <summary>
/// Вывод дерева.
/// </summary>
/// <param name="treap">Структура дерева.</param>
void PrintTreap(Treap* treap);

/// <summary>
/// Удаление дерева.
/// </summary>
/// <param name="treap">Структура дерева.</param>
void DeleteTreap(Treap* treap);