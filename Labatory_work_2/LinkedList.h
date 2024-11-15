#pragma once
#include "LinkedListItem.h"

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

	/// <summary>
	/// Размер списка.
	/// </summary>
	int Size;
};

/// <summary>
/// Создание двухсвязного списка.
/// </summary>
/// <returns>Созданный двухсвязный список</returns>
LinkedList* CreateLinkedList();

/// <summary>
/// Инциализация списка случайными значениями.
/// </summary>
/// <param name="array">Структура двухсвязного списка.</param>
/// <param name="size">Размер заполнения.</param>
void InitializationLinkedList(LinkedList* list, int size);

/// <summary>
/// Добавление элемента в начало списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="value">Значение.</param>
void InsertBegin(LinkedList* list, int value);

/// <summary>
/// Добавление элемента в конец списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="value">Значение.</param>
void InsertEnd(LinkedList* list, int value);

/// <summary>
/// Получение элемента из списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="index">Индекс элемента.</param>
/// <returns>Узел.</returns>
Node* GetElement(LinkedList* list, int index);

/// <summary>
/// Удалить в начале списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
void RemoveBegin(LinkedList* list);

/// <summary>
/// Удалить в конце списка.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
void RemoveEnd(LinkedList* list);

/// <summary>
/// Вставить элемент в список по индексу.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="index">Индекс элемента.</param>
/// <param name="value">Значение.</param>
void InsertByIndex(LinkedList* list, int index, int value);

/// <summary>
/// Вставить элемент в список после определенного элемента.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="target">Элемент, после которого вставят значение.</param>
/// <param name="value">Значение.</param>
void InsertByValueAfter(LinkedList* list, int value, int target);

/// <summary>
/// Вставить элемент в список перед определенным элементом.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="target">Элемент, перед которым вставят значение.</param>
/// <param name="value">Значение.</param>
void InsertByValueBefore(LinkedList* list, int value, int target);

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
/// Удалить элемент из списка по значению.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param>
/// <param name="index">Значение элемента.</param>
void RemoveByValue(LinkedList* list, int value);

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

/// <summary>
/// Сортировка списка пузырьком.
/// </summary>
/// <param name="list">Структура двухсвязного списка.</param
void BubbleSort(LinkedList* list);


