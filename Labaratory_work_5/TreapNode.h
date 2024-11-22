#pragma once

/// <summary>
/// Структура узла дерева.
/// </summary>
struct TreapNode
{
	/// <summary>
	/// Ключ.
	/// </summary>
	int Key;

	/// <summary>
	/// Приоритет.
	/// </summary>
	int Priority;

	/// <summary>
	/// Ссылка на правый узел.
	/// </summary>
	TreapNode* Right = nullptr;

	/// <summary>
	/// Ссылка на левый узел.
	/// </summary>
	TreapNode* Left = nullptr;
};

/// <summary>
/// Создание узла.
/// </summary>
/// <param name="key">Ключ.</param>
/// <returns>Созданный узел.</returns>
TreapNode* CreateTreapNode(int key);

/// <summary>
/// Слияние двух деревьев в одно.
/// </summary>
/// <param name="left">Левое дерево.</param>
/// <param name="right">Правое дерево.</param>
/// <returns>Объединенное дерево.</returns>
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// <summary>
/// Разделение дерева на две части.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="key">Ключ для разделения.</param>
/// <param name="left">Ссылка на левое дерево.</param>
/// <param name="right">Ссылка на правое дерево.</param>
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// <summary>
/// Добавление элемента в дерево.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="key">Ключ.</param>
/// <returns>Дерево с новым элементом.</returns>
TreapNode* Add(TreapNode* node, int key);

/// <summary>
/// Удаление элемента из дерева.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="key">Ключ.</param>
/// <returns>Дерево без элемента.</returns>
TreapNode* Remove(TreapNode* node, int key);

/// <summary>
/// Добавление элемента в дерево оптимизированным способом.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="newNode">Структура нового узла.</param>
/// <returns>Узел с новым элементом.</returns>
TreapNode* AddOptimized(TreapNode* node, TreapNode* newNode);

/// <summary>
/// Удаление элемента из дерева оптимизированным способом.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="key">Ключ.</param>
/// <returns>Узел без элемента.</returns>
TreapNode* RemoveOptimized(TreapNode* node, int key);

/// <summary>
/// Поиск элемента в дереве.
/// </summary>
/// <param name="node">Структура узла.</param>
/// <param name="key">Ключ.</param>
/// <returns>Найденный элемент.</returns>
TreapNode* Search(TreapNode* node, int key);

/// <summary>
/// Удаление узла.
/// </summary>
/// <param name="node">Структура узла.</param>
void DeleteTreapNode(TreapNode* node);
