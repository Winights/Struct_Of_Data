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
};

/// <summary>
/// Создание стека.
/// </summary>
/// <returns>Созданный стек</returns>
Stack* CreateStack(int size);

/// <summary>
/// Инциализация стека.
/// </summary>
void InitializationStack(Stack* stack);

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
void Pop(Stack* stack);

/// <summary>
/// Проверка пустой ли стек.
/// </summary>
/// <returns>true, если пустой, иначе false.</returns>
bool IsEmpty(Stack* stack);

/// <summary>
/// Удаление стек.
/// </summary>
void Delete(Stack* stack);

/// <summary>
/// Вывод стека.
/// </summary>
void PrintStack(Stack* stack);