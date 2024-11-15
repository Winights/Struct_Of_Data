#pragma once

/// <summary>
/// Структура стека.
/// </summary>
struct Stack
{
	/// <summary>
	/// Буфер стека в виде масиива.
	/// </summary>
	int* Buffer;

	/// <summary>
	/// Размер буфера.
	/// </summary>
	int BufferSize;

	/// <summary>
	/// Индекс верхнего элемента.
	/// </summary>
	int Top;

	/// <summary>
	/// Количество элементов.
	/// </summary>
	int Count;
};

/// <summary>
/// Создание стека.
/// </summary>
/// <returns>Созданный стек</returns>
Stack* CreateStack(int size);

/// <summary>
/// Инциализация стека случайными значениями.
/// </summary>
/// <param name="stack">Структура стека.</param>
/// <param name="size">Размер заполнения.</param>
void InitializationStack(Stack* stack, int size);

/// <summary>
/// Изменение размерности стека.
/// </summary>
void ResizeStack(Stack* stack, int newSize);

/// <summary>
/// Добавление в стек.
/// </summary>
void Push(Stack* stack, int value);

/// <summary>
/// Удаление из стека.
/// </summary>
int Pop(Stack* stack);

/// <summary>
/// Проверка пустой ли стек.
/// </summary>
/// <returns>True, если пустой, иначе false.</returns>
bool IsEmpty(Stack* stack);

/// <summary>
/// Вывод стека.
/// </summary>
void PrintStack(Stack* stack);

/// <summary>
/// Удаление стека.
/// </summary>
void DeleteStack(Stack* stack);