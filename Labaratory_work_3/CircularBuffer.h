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
/// <param name="capacity">Размер.</param>
/// <returns>Созданный кольцевой буфер</returns>
CircularBuffer* CreateCircularBuffer(int capacity);

/// <summary>
/// Инциализация кольцевого буфера случайными значениями.
/// </summary>
/// <param name="circularBuffer">Структура кольцевого буфера.</param>
/// <param name="size">Размер заполнения.</param>
void InitializationCircularBuffer(CircularBuffer* circularBuffer, int size);

/// <summary>
/// Изменение размерности буфера.
/// </summary>
/// <param name="circularBuffer">Структура кольцевого буфера.</param>
/// <param name="newCapacity">новый размер.</param>
void ResizeCircularBuffer(CircularBuffer* circularBuffer, int newCapacity);

/// <summary>
/// Добавление элемента в кольцевого буфера.
/// </summary>
/// <param name="circularBuffer">Структура кольцевого буфера.</param>
/// <param name="value">Значение.</param>
void Enqueue(CircularBuffer* circularBuffer, int value);

/// <summary>
/// Получение элемента из кольцевого буфера.
/// </summary>
/// <param name="circularBuffer">Структура кольцевого буфера.</param>
/// <returns>Элемент из буфера</returns>
int Dequeue(CircularBuffer* circularBuffer);

/// <summary>
/// Вывод кольцевого буфера.
/// </summary>
/// <param name="circularBuffer">Структура кольцевого буфера.</param>
void PrintCircularBuffer(CircularBuffer* circularBuffer);

/// <summary>
/// Удаление кольцевого буфера.
/// </summary>
/// <param name="circularBuffer">Структура кольцевого буфера.</param>
void DeleteCircularBuffer(CircularBuffer* circularBuffer);

