#pragma once

/// <summary>
/// ��������� ���� ������.
/// </summary>
struct TreapNode
{
	/// <summary>
	/// ����.
	/// </summary>
	int Key;

	/// <summary>
	/// ���������.
	/// </summary>
	int Priority;

	/// <summary>
	/// ������ �� ������ ����.
	/// </summary>
	TreapNode* Right = nullptr;

	/// <summary>
	/// ������ �� ����� ����.
	/// </summary>
	TreapNode* Left = nullptr;
};

/// <summary>
/// �������� ����.
/// </summary>
/// <param name="key">����.</param>
/// <returns>��������� ����.</returns>
TreapNode* CreateTreapNode(int key);

/// <summary>
/// ������� ���� �������� � ����.
/// </summary>
/// <param name="left">����� ������.</param>
/// <param name="right">������ ������.</param>
/// <returns>������������ ������.</returns>
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// <summary>
/// ���������� ������ �� ��� �����.
/// </summary>
/// <param name="node">��������� ����.</param>
/// <param name="key">���� ��� ����������.</param>
/// <param name="left">������ �� ����� ������.</param>
/// <param name="right">������ �� ������ ������.</param>
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// <summary>
/// ���������� �������� � ������.
/// </summary>
/// <param name="node">��������� ����.</param>
/// <param name="key">����.</param>
/// <returns>������ � ����� ���������.</returns>
TreapNode* Add(TreapNode* node, int key);

/// <summary>
/// �������� �������� �� ������.
/// </summary>
/// <param name="node">��������� ����.</param>
/// <param name="key">����.</param>
/// <returns>������ ��� ��������.</returns>
TreapNode* Remove(TreapNode* node, int key);

/// <summary>
/// ���������� �������� � ������ ���������������� ��������.
/// </summary>
/// <param name="node">��������� ����.</param>
/// <param name="newNode">��������� ������ ����.</param>
/// <returns>���� � ����� ���������.</returns>
TreapNode* AddOptimized(TreapNode* node, TreapNode* newNode);

/// <summary>
/// �������� �������� �� ������ ���������������� ��������.
/// </summary>
/// <param name="node">��������� ����.</param>
/// <param name="key">����.</param>
/// <returns>���� ��� ��������.</returns>
TreapNode* RemoveOptimized(TreapNode* node, int key);

/// <summary>
/// ����� �������� � ������.
/// </summary>
/// <param name="node">��������� ����.</param>
/// <param name="key">����.</param>
/// <returns>��������� �������.</returns>
TreapNode* Search(TreapNode* node, int key);

/// <summary>
/// �������� ����.
/// </summary>
/// <param name="node">��������� ����.</param>
void DeleteTreapNode(TreapNode* node);
