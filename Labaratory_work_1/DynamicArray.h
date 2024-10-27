#pragma once

/// <summary>
/// ��������� ������������� �������.
/// </summary>
struct DynamicArray
{
	/// <summary>
	/// ������ �������.
	/// </summary>
	int Size;

	/// <summary>
	/// ����������� �������.
	/// </summary>
	int Capacity;
	
	/// <summary>
	/// ������.
	/// </summary>
	int* Array;

};

const  int originalCapacity = 4;

const  int growthFactor = 2;

/// <summary>
/// �������� ������������� �������.
/// </summary>
/// <returns>���������� ��������� ������������ ������ � ��������� ��������</returns>
DynamicArray* CreateDynamicArray();

/// <summary>
/// ������������ ������� ���������� ����������.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
void InitializationDynamicArray(DynamicArray* array);

/// <summary>
/// ���������� ������� ������������� �������.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
/// <param name="capacity">������� �������.</param>
void ResizeArray(DynamicArray* array, int capacity);

/// <summary>
/// �������� ����������� �������� ��� �������.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
/// <param name="index">������ �������.</param>
/// <returns>���������� false, ���� �������� ������� �� ����� ����������� ���������, ����� true.</returns>
bool CheckRange(DynamicArray* array, int index);

/// <summary>
/// ���������� �������� � ������.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
/// <param name="index">������ �������.</param>
/// <param name="value">�������� ��������.</param>
void AddElement(DynamicArray* array, int index, int value);

/// <summary>
/// �������� �������� �� �������.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
/// <param name="index">������ �������.</param>
void RemoveByIndex(DynamicArray* array, int index);

/// <summary>
/// �������� �������� �� ��������.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
/// <param name="value">�������� ��������.</param>
void RemoveByValue(DynamicArray* array, int value);

/// <summary>
/// ���������� �������.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
void SortArray(DynamicArray* array);

/// <summary>
/// �������� �����.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
/// <param name="index">�������� ��������.</param>
/// <returns>���������� ������ �������� ��������.</returns>
void LinerSearch(DynamicArray* array, int value);

/// <summary>
/// �������� �����.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
/// <param name="index">�������� ��������.</param>
/// <returns>���������� ������ �������� ��������.</returns>
void BinarySearch(DynamicArray* array, int value);

/// <summary>
/// ����� �������.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
void PrintArray(DynamicArray* array);

/// <summary>
/// ������������ ������.
/// </summary>
/// <param name="array">��������� ������������� �������.</param>
void FreeArray(DynamicArray* array);