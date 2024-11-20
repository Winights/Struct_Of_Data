#pragma once
#include "TreeNode.h"

/// <summary>
/// Структура дерева.
/// </summary>
struct Tree
{
	/// <summary>
	/// Структура узла дерева.
	/// </summary>
	TreeNode* Root;

	/// <summary>
	/// Количество узлов в дереве.
	/// </summary>
	int Count;
};

/// <summary>
/// Создание дерева.
/// </summary>
/// <param name="value">Значение.</param>
/// <returns>Созданное дерево.</returns>
Tree* CreateTree(int value);

/// <summary>
/// Добавление узла.
/// </summary>
/// <param name="binaryTree">Структура дерева.</param>
/// <param name="value">Значение.</param>
void Insert(Tree* binaryTree, int value);

/// <summary>
/// Удаление узла.
/// </summary>
/// <param name="binaryTree">Структура дерева.</param>
/// <param name="value">Значение.</param>
void Remove(Tree* binaryTree, int value);

/// <summary>
/// Поиск значения.
/// </summary>
/// <param name="binaryTree">Структура дерева.</param>
/// <param name="value">Значение.</param>
/// <returns>Найденный узел с данным значением.</returns>
TreeNode* Search(Tree* binaryTree, int value);

/// <summary>
/// Поиск минимума.
/// </summary>
/// <param name="binaryTree">Структура дерева.</param>
/// <returns>Найденный узел с минимальным значением.</returns>
TreeNode* FindMin(Tree* binaryTree);

/// <summary>
/// Поиск максимума.
/// </summary>
/// <param name="binaryTree">Структура дерева.</param>
/// <returns>Найденный узел с максимальным значением.</returns>
TreeNode* FindMax(Tree* binaryTree);

/// <summary>
/// Вывод дерева.
/// </summary>
/// <param name="binaryTree">Структура дерева.</param>
void PrintTree(Tree* binaryTree);

/// <summary>
/// Осбождение памяти у дерева.
/// </summary>
/// <param name="binaryTree">Структура дерева.</param>
void DeleteTree(Tree* binaryTree);