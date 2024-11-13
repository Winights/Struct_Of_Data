#pragma once
#include "Stack.h"

/// <summary>
/// Структура очереди через 2 стека.
/// </summary>
struct QueueStacks
{
	/// <summary>
	/// Cтек для добавления.
	/// </summary>
	Stack* TopStack;

	/// <summary>
	/// Cтек для удаления.
	/// </summary>
	Stack* TailStack;
};

/// <summary>
/// Создание очереди.
/// </summary>
/// <returns>Созданный очередь</returns>
QueueStacks* CreateQueueStacks(int capacity);

/// <summary>
/// Добавление элемента в очередь.
/// </summary>
void EnqueueQueueStacks(QueueStacks* queueStacks, int value);

/// <summary>
/// Получение элемента из очереди.
/// </summary>
/// <returns>Элемент из очереди</returns>
int DequeueQueueStacks(QueueStacks* queueStacks);

/// <summary>
/// Изменение размерности очереди.
/// </summary>
void ResizeQueueStacks(QueueStacks* queueStacks, int newCapacity);

/// <summary>
/// Вывод очереди.
/// </summary>
void PrintQueueStacks(QueueStacks* queueStacks);

/// <summary>
/// Удаление очереди.
/// </summary>
void DeleteQueueStacks(QueueStacks* queueStacks);