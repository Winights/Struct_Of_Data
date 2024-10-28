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
/// �������� ���� ������������ ������.
/// </summary>
/// <returns>���������� ��������� ����.</returns>
Node* CreateLinkedListItem();
