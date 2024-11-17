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
	/// Cтек для получения.
	/// </summary>
	Stack* TailStack;
};

/// <summary>
/// Создание очереди.
/// </summary>
/// <param name="capacity">Размер.</param>
/// <returns>Созданная очередь.</returns>
QueueStacks* CreateQueueStacks(int capacity);

/// <summary>
/// Инциализация очереди случайными значениями.
/// </summary>
/// <param name="queueStacks">Структура очереди.</param>
/// <param name="size">Размер заполнения.</param>
void InitializationQueueStacks(QueueStacks* queueStacks, int size);

/// <summary>
/// Добавление элемента в очередь.
/// </summary>
/// <param name="queueStacks">Структура очереди.</param>
/// <param name="value">Значение.</param>
void EnqueueQueueStacks(QueueStacks* queueStacks, int value);

/// <summary>
/// Получение элемента из очереди.
/// </summary>
/// <param name="queueStacks">Структура очереди.</param>
/// <returns>Элемент из очереди</returns>
int DequeueQueueStacks(QueueStacks* queueStacks);

/// <summary>
/// Изменение размерности очереди.
/// </summary>
/// <param name="queueStacks">Структура очереди.</param>
/// <param name="newCapacity">Новый размер.</param>
void ResizeQueueStacks(QueueStacks* queueStacks, int newCapacity);

/// <summary>
/// Вывод очереди.
/// </summary>
/// <param name="queueStacks">Структура очереди.</param>
void PrintQueueStacks(QueueStacks* queueStacks);

/// <summary>
/// Удаление очереди.
/// </summary>
/// <param name="queueStacks">Структура очереди.</param>
void DeleteQueueStacks(QueueStacks* queueStacks);