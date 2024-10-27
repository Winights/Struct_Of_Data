#pragma once

/// <summary>
/// Структура динамического массива.
/// </summary>
struct DynamicArray
{
	/// <summary>
	/// Размер массива.
	/// </summary>
	int Size;

	/// <summary>
	/// Вместимость массива.
	/// </summary>
	int Capacity;
	
	/// <summary>
	/// Массив.
	/// </summary>
	int* Array;

};

const  int originalCapacity = 4;

const  int growthFactor = 2;

/// <summary>
/// Создание динамического массива.
/// </summary>
/// <returns>Возвращает созданный динамический массив с начальным размером</returns>
DynamicArray* CreateDynamicArray();

/// <summary>
/// Инциализация массива случайными значениями.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
void InitializationDynamicArray(DynamicArray* array);

/// <summary>
/// Увеличение размера динамического массива.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
/// <param name="capacity">Емкость массива.</param>
void ResizeArray(DynamicArray* array, int capacity);

/// <summary>
/// Проверка допустимого значения для массива.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
/// <param name="index">Индекс массива.</param>
/// <returns>Возвращает false, если значение выходит за рамки допустимого диапозона, иначе true.</returns>
bool CheckRange(DynamicArray* array, int index);

/// <summary>
/// Добавление элемента в массив.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
/// <param name="index">Индекс массива.</param>
/// <param name="value">Значение элемента.</param>
void AddElement(DynamicArray* array, int index, int value);

/// <summary>
/// Удаление элемента по индексу.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
/// <param name="index">Индекс массива.</param>
void RemoveByIndex(DynamicArray* array, int index);

/// <summary>
/// Удаление элемента по значению.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
/// <param name="value">Значение элемента.</param>
void RemoveByValue(DynamicArray* array, int value);

/// <summary>
/// Сортировка массива.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
void SortArray(DynamicArray* array);

/// <summary>
/// Линейный поиск.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
/// <param name="index">Значение элемента.</param>
/// <returns>Возвращает индекс искомого элемента.</returns>
void LinerSearch(DynamicArray* array, int value);

/// <summary>
/// Бинарный поиск.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
/// <param name="index">Значение элемента.</param>
/// <returns>Возвращает индекс искомого элемента.</returns>
void BinarySearch(DynamicArray* array, int value);

/// <summary>
/// Вывод массива.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
void PrintArray(DynamicArray* array);

/// <summary>
/// Освобождение памяти.
/// </summary>
/// <param name="array">Структура динамического массива.</param>
void FreeArray(DynamicArray* array);