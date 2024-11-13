#pragma once

/// <summary>
/// Структура кольцевого буфера.
/// </summary>
struct CircularBuffer 
{
    /// <summary>
    /// Буфер в виде масиива.
    /// </summary>
    int* Buffer;    

    /// <summary>
    /// Емкость буфера.
    /// </summary>
    int Capacity; 

    /// <summary>
    /// Индекс для получения элементов.
    /// </summary>
    int Read;   

    /// <summary>
    /// Индекс для внесения в буфер.
    /// </summary>
    int Write; 

    /// <summary>
    /// Сколько элементов в буфере.
    /// </summary>
    int Size;           
};

/// <summary>
/// Создание кольцевого буфера.
/// </summary>
/// <returns>Созданный кольцевой буфер</returns>
CircularBuffer* CreateCircularBuffer(int capacity);

/// <summary>
/// Изменение размерности буфера.
/// </summary>
void ResizeCircularBuffer(CircularBuffer* circularBuffer, int newCapacity);

/// <summary>
/// Добавление элемента в кольцевого буфера.
/// </summary>
void Enqueue(CircularBuffer* circularBuffer, int value);

/// <summary>
/// Получение элемента из кольцевого буфера.
/// </summary>
/// <returns>Элемент из буфера</returns>
int Dequeue(CircularBuffer* circularBuffer);

/// <summary>
/// Вывод кольцевого буфера.
/// </summary>
void PrintCircularBuffer(CircularBuffer* circularBuffer);

/// <summary>
/// Удаление кольцевого буфера.
/// </summary>
void DeleteCircularBuffer(CircularBuffer* circularBuffer);

