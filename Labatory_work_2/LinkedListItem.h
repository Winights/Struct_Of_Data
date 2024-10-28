#pragma once

/// <summary>
/// Структура узла.
/// </summary>
struct Node
{
	/// <summary>
	/// Элемент.
	/// </summary>
	int Data;

	/// <summary>
	/// Ссылка на следующий элемент.
	/// </summary>
	Node* Next = nullptr;

	/// <summary>
	/// Ссылка на предыдущий элемент.
	/// </summary>
	Node* Prev = nullptr;
};

/// <summary>
/// Создание узла двухсвязного списка.
/// </summary>
/// <returns>Возвращает созданный узла.</returns>
Node* CreateLinkedListItem();
