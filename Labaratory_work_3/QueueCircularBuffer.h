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
/// <param name="capacity">Размер.</param>
/// <returns>Созданная очередь</returns>
QueueCircularBuffer* CreateQueueCircularBuffer(int capacity);

/// <summary>
/// Инциализация очереди случайными значениями.
/// </summary>
/// <param name="queueCircularBuffer">Структура очереди.</param>
/// <param name="size">Размер заполнения.</param>
void InitializationQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int size);

/// <summary>
/// Добавление элемента в очередь.
/// </summary>
/// <param name="queueCircularBuffer">Структура очереди.</param>
/// <param name="value">Значение.</param>
void EnqueueQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int value);

/// <summary>
/// Получение элемента из очереди.
/// </summary>
/// <<param name="queueCircularBuffer">Структура очереди.</param>
/// <returns>Элемент из очереди</returns>
int DequeueQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer);

/// <summary>
/// Изменение размерности очереди.
/// </summary>
/// <param name="queueCircularBuffer">Структура очереди.</param>
/// <param name="NewCapacity">Новый размер.</param>
void ResizeQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int newCapacity);

/// <summary>
/// Вывод очереди.
/// </summary>
/// <param name="queueCircularBuffer">Структура очереди.</param>
void PrintQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer);

/// <summary>
/// Удаление очереди.
/// </summary>
/// <param name="queueCircularBuffer">Структура очереди.</param>
void DeleteQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer);