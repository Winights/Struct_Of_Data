#pragma once

/// <summary>
/// Структура узла.
/// </summary>
struct Node
{
	/// <summary>
	/// Значение элемента.
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
/// <returns>Созданный узел.</returns>
Node* CreateLinkedListItem();
