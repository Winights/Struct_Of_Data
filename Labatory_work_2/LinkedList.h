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
/// Структура двухсвязанного списка.
/// </summary>
struct LinkedList
{
	/// <summary>
	/// Ссылка на первый элемент.
	/// </summary>
	Node* Head = nullptr;

	/// <summary>
	/// Ссылка на последний элемент.
	/// </summary>
	Node* Tail = nullptr;
};

/// <summary>
/// Создание двухсвязного списка.
/// </summary>
/// <returns>Возвращает созданный двухсвязный спискок</returns>
LinkedList* CreateDynamicList();

/// <summary>
/// Инциализация списка случайными значениями.
/// </summary>
/// <param name="array">Структура двухсвязного списка.</param>
void InitializationLinkedList(LinkedList* list);

/// <summary>
/// Добавление элемента в начало списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="value">Значение.</param>
void AddToBegin(LinkedList* list, int value);

/// <summary>
/// Добавление элемента в конец списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="value">Значение.</param>
void AddToEnd(LinkedList* list, int value);

/// <summary>
/// Получение элемента из списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="index">Индекс элемента.</param>
Node* GetElement(LinkedList* list, int index);

/// <summary>
/// Удалить в начале списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
void RemoveToBegin(LinkedList* list);

/// <summary>
/// Удалить в конце списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
void RemoveToEnd(LinkedList* list);

/// <summary>
/// Вставить элемент в список по индексу.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="index">Индекс элемента.</param>
/// <param name="value">Значение.</param>
int InsertByIndex(LinkedList* list, int index, int value);

/// <summary>
/// Сортировка списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
void SortList(LinkedList* list);

/// <summary>
/// Удалить элемент из списка по индексу.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="index">Индекс элемента.</param>
void RemoveByIndex(LinkedList* list, int index);

/// <summary>
/// Линейный поиск.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="index">Индекс элемента.</param>
void LinerSearch(LinkedList* list, int value);

/// <summary>
/// Вывод списка в консоль.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
void PrintList(LinkedList* list);

/// <summary>
/// Освобождение памяти от списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
void FreeList(LinkedList* list);


