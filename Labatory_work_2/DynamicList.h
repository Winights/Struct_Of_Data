#pragma once

/// <summary>
/// ��������� ����.
/// </summary>
struct Node
{
	/// <summary>
	/// �������.
	/// </summary>
	int Data;

	/// <summary>
	/// ������ �� ��������� �������.
	/// </summary>
	Node* Next = nullptr;

	/// <summary>
	/// ������ �� ���������� �������.
	/// </summary>
	Node* Prev = nullptr;
};

/// <summary>
/// ��������� �������������� ������.
/// </summary>
struct LinkedList
{
	/// <summary>
	/// ������ �� ������ �������.
	/// </summary>
	Node* Head = nullptr;

	/// <summary>
	/// ������ �� ��������� �������.
	/// </summary>
	Node* Tail = nullptr;
};

/// <summary>
/// �������� ������������ ������.
/// </summary>
/// <returns>���������� ��������� ����������� �������</returns>
LinkedList* CreateDynamicList();

/// <summary>
/// ���������� �������� � ������ ������.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
/// <param name="value">��������.</param>
void AddToBegin(LinkedList* list, int value);

/// <summary>
/// ���������� �������� � ����� ������.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
/// <param name="value">��������.</param>
void AddToEnd(LinkedList* list, int value);

/// <summary>
/// ��������� �������� �� ������.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
/// <param name="index">������ ��������.</param>
Node* GetElement(LinkedList* list, int index);

/// <summary>
/// ������� � ������ ������.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
void RemoveToBegin(LinkedList* list);

/// <summary>
/// ������� � ����� ������.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
void RemoveToEnd(LinkedList* list);

/// <summary>
/// �������� ������� � ������ �� �������.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
/// <param name="index">������ ��������.</param>
/// <param name="value">��������.</param>
int InsertByIndex(LinkedList* list, int index, int value);

/// <summary>
/// ������� ������� �� ������ �� �������.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
/// <param name="index">������ ��������.</param>
void RemoveByIndex(LinkedList* list, int index);

/// <summary>
/// �������� �����.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
/// <param name="index">������ ��������.</param>
void LinerSearch(LinkedList* list, int value);

/// <summary>
/// ����� ������ � �������.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
void PrintList(LinkedList* list);

/// <summary>
/// ������������ ������ �� ������.
/// </summary>
/// <param name="list">��������� ������������ ������.</param>
void FreeList(LinkedList* list);


