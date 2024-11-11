#pragma once

/// <summary>
/// ��������� �����.
/// </summary>
struct Stack
{
	/// <summary>
	/// ����� ����� � ���� �������.
	/// </summary>
	int* Buffer;

	/// <summary>
	/// ������ ������.
	/// </summary>
	int BufferSize;

	/// <summary>
	/// ������ �������� ��������.
	/// </summary>
	int Top;
};

/// <summary>
/// �������� �����.
/// </summary>
/// <returns>��������� ����</returns>
Stack* CreateStack(int size);

/// <summary>
/// ������������ �����.
/// </summary>
void InitializationStack(Stack* stack);

/// <summary>
/// ��������� ����������� �����.
/// </summary>
void ResizeStack(Stack* stack, int newSize);

/// <summary>
/// ���������� � ����.
/// </summary>
void Push(Stack* stack, int value);

/// <summary>
/// �������� �� �����.
/// </summary>
void Pop(Stack* stack);

/// <summary>
/// �������� ������ �� ����.
/// </summary>
/// <returns>true, ���� ������, ����� false.</returns>
bool IsEmpty(Stack* stack);

/// <summary>
/// �������� ����.
/// </summary>
void Delete(Stack* stack);

/// <summary>
/// ����� �����.
/// </summary>
void PrintStack(Stack* stack);