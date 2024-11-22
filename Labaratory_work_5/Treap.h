#pragma once
#include "TreapNode.h"

/// <summary>
/// ��������� ����������� ������.
/// </summary>
struct Treap
{
	/// <summary>
	/// ��������� ���� ������.
	/// </summary>
	TreapNode* Root;

	/// <summary>
	/// ���������� ��������� � ������.
	/// </summary>
	int Count;
};

/// <summary>
/// �������� ������.
/// </summary>
/// <param name="key">����.</param>
/// <returns>��������� ������.</returns>
Treap* CreateTreap(int key);

/// <summary>
/// ����� �������� � ������.
/// </summary>
/// <param name="node">��������� ������.</param>
/// <param name="key">����.</param>
/// <returns>��������� �������.</returns>
TreapNode* SearchTreap(Treap* treap, int key);

/// <summary>
/// ���������� �������� � ������.
/// </summary>
/// <param name="node">��������� ������.</param>
/// <param name="key">����.</param>
void AddTreap(Treap* treap, int key);

/// <summary>
/// �������� �������� �� ������.
/// </summary>
/// <param name="node">��������� ������.</param>
/// <param name="key">����.</param>
void RemoveTreap(Treap* treap, int key);

/// <summary>
/// ���������� �������� � ������ ���������������� ��������.
/// </summary>
/// <param name="node">��������� ������.</param>
/// <param name="key">����.</param>
void AddTreapOptimized(Treap* treap, int key);

/// <summary>
/// �������� �������� �� ������ ���������������� ��������.
/// </summary>
/// <param name="node">��������� ������.</param>
/// <param name="key">����.</param>
void RemoveTreapOptimized(Treap* treap, int key);

/// <summary>
/// ����� ����� ������.
/// </summary>
/// <param name="node">��������� ����.</param>
/// <param name="space">������ ����� ����������.</param>
void PrintRoots(TreapNode* node, int space);

/// <summary>
/// ����� ������.
/// </summary>
/// <param name="treap">��������� ������.</param>
void PrintTreap(Treap* treap);

/// <summary>
/// �������� ������.
/// </summary>
/// <param name="treap">��������� ������.</param>
void DeleteTreap(Treap* treap);