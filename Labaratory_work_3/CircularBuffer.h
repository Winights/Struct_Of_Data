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
/// Проверка на пустой буфер.
/// </summary>
/// <returns>На сколько пустой буфер</returns>
int GetFreeSpace(CircularBuffer* circularBuffer);

/// <summary>
/// Проверка на полный буфер.
/// </summary>
/// <returns>На сколько занят</returns>
int GetOccupiedSpace(CircularBuffer* circularBuffer);

/// <summary>
/// Добавление элемента в кольцевого буфера.
/// </summary>
void AddElement(CircularBuffer* circularBuffer, int value);

/// <summary>
/// Получение элемента из кольцевого буфера.
/// </summary>
/// <returns>Элемент из буфера</returns>
int GetElement(CircularBuffer* circularBuffer);

/// <summary>
/// Удаление кольцевого буфера.
/// </summary>
void DeleteBuffer(CircularBuffer* circularBuffer);

/// <summary>
/// Вывод кольцевого буфера.
/// </summary>
void PrintCircularBuffer(CircularBuffer* circularBuffer);

