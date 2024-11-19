#pragma once
#include "HashNode.h"

/// <summary>
/// Структура односвязного списка.
/// </summary>
struct LinkedList
{
	/// <summary>
	/// Структура узла.
	/// </summary>
	HashNode* Node;

	/// <summary>
	/// Ссылка на следующий узел.
	/// </summary>
	LinkedList* Next = nullptr;
};

/// <summary>
/// Создание односвязного списка.
/// </summary>
/// <returns>Созданный односвязный список.</returns>
LinkedList* CreateLinkedList();

/// <summary>
/// Добавление узла в односвязный список.
/// </summary>
/// <param name="linkedList">Струкутура односвязного списка.</param>
/// /// <param name="hashNode">Струкутура узла.</param>
/// <returns>Струкутуру односвязного списка.</returns>
LinkedList* InsertInLinkedList(LinkedList* linkedList, HashNode* hashNode);

/// <summary>
/// Удаление узла из односвязного списка.
/// </summary>
/// <param name="linkedList">Струкутура односвязного списка.</param>
/// <returns>Узел.</returns>
HashNode* RemoveInLinkedList(LinkedList* linkedList);

/// <summary>
/// Удаление односвязного списка.
/// </summary>
/// <param name="linkedList">Струкутура односвязного списка.</param>
void DeleteLinkedList(LinkedList* linkedList);