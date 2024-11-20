#pragma once

/// <summary>
/// Структура узла дерева.
/// </summary>
struct TreeNode
{
	/// <summary>
	/// Значение.
	/// </summary>
	int Value;

	/// <summary>
	/// Ссылка на правый узел.
	/// </summary>
	TreeNode* Right = nullptr;

	/// <summary>
	/// Ссылка на левый узел.
	/// </summary>
	TreeNode* Left = nullptr;
};

/// <summary>
/// Создание узла.
/// </summary>
/// <param name="value">Значение.</param>
/// <returns>Созданный узел.</returns>
TreeNode* CreateTreeNode(int value);

/// <summary>
/// Добавление узла.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="value">Значение.</param>
TreeNode* InsertNode(TreeNode* node, int value);

/// <summary>
/// Удаление узла.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="value">Значение.</param>
TreeNode* RemoveNode(TreeNode* node, int value);

/// <summary>
/// Поиск значения.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="value">Значение.</param>
/// <returns>Найденный узел с данным значением.</returns>
TreeNode* Search(TreeNode* node, int value);

/// <summary>
/// Поиск минимума.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <returns>Найденный узел с минимальным значением.</returns>
TreeNode* FindMin(TreeNode* node);

/// <summary>
/// Поиск максимума.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <returns>Найденный узел с максимальным значением.</returns>
TreeNode* FindMax(TreeNode* node);

/// <summary>
/// Освобождение памяти узла.
/// </summary>
/// <param name="node">Структура узла.</param>
void DeleteTreeNode(TreeNode* node);