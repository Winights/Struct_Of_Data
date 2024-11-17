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
/// <param name="size">Размер.</param>
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
/// <param name="stack">Структура стека.</param>
/// <param name="newSize">Новый размер.</param>
void ResizeStack(Stack* stack, int newSize);

/// <summary>
/// Добавление в стек.
/// </summary>
/// <param name="stack">Структура стека.</param>
/// <param name="value">Значение.</param>
void Push(Stack* stack, int value);

/// <summary>
/// Удаление из стека.
/// </summary>
/// <param name="stack">Структура стека.</param>
int Pop(Stack* stack);

/// <summary>
/// Проверка пустой ли стек.
/// </summary>
/// <param name="stack">Структура стека.</param>
/// <returns>True, если пустой, иначе false.</returns>
bool IsEmpty(Stack* stack);

/// <summary>
/// Вывод стека.
/// </summary>
/// <param name="stack">Структура стека.</param>
void PrintStack(Stack* stack);

/// <summary>
/// Удаление стека.
/// </summary>
/// <param name="stack">Структура стека.</param>
void DeleteStack(Stack* stack);