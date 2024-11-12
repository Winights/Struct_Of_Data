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
/// <returns>Созданный очередь</returns>
QueueCircularBuffer* CreateQueueCircularBuffer(int capacity);

/// <summary>
/// Добавление элемента в очередь.
/// </summary>
void Enqueue(QueueCircularBuffer* queueCircularBuffer, int value);

/// <summary>
/// Получение элемента из очереди.
/// </summary>
/// <returns>Элемент из очереди</returns>
int Dequeue(QueueCircularBuffer* queueCircularBuffer);

/// <summary>
/// Изменение размерности очереди.
/// </summary>
void ResizeQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int newCapacity);

/// <summary>
/// Вывод очереди.
/// </summary>
void PrintQueue(QueueCircularBuffer* queueCircularBuffer);

/// <summary>
/// Удаление очереди.
/// </summary>
void DeleteBuffer(QueueCircularBuffer* queueCircularBuffer);


