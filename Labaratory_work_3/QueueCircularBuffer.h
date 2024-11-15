#pragma once
#include "CircularBuffer.h"

/// <summary>
/// Структура очереди через кольцевой буфер.
/// </summary>
struct QueueCircularBuffer
{
	/// <summary>
	/// Кольцевой буфер.
	/// </summary>
	CircularBuffer* CircularBuffer;
};

/// <summary>
/// Создание очереди.
/// </summary>
/// <returns>Созданная очередь</returns>
QueueCircularBuffer* CreateQueueCircularBuffer(int capacity);

/// <summary>
/// Инциализация очереди случайными значениями.
/// </summary>
/// <param name="stack">Структура очереди.</param>
/// <param name="size">Размер заполнения.</param>
void InitializationQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int size);

/// <summary>
/// Добавление элемента в очередь.
/// </summary>
void EnqueueQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int value);

/// <summary>
/// Получение элемента из очереди.
/// </summary>
/// <returns>Элемент из очереди</returns>
int DequeueQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer);

/// <summary>
/// Изменение размерности очереди.
/// </summary>
void ResizeQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int newCapacity);

/// <summary>
/// Вывод очереди.
/// </summary>
void PrintQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer);

/// <summary>
/// Удаление очереди.
/// </summary>
void DeleteQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer);