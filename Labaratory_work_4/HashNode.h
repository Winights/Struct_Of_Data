#pragma once
#include <string>
/// <summary>
/// ��������� ����.
/// </summary>
struct HashNode
{
	/// <summary>
	/// ��������.
	/// </summary>
	const char* Value;

	/// <summary>
	/// ����.
	/// </summary>
	const char* Key;
};

/// <summary>
/// �������� ���� ��� ���-�������.
/// </summary>
/// <returns>��������� ����.</returns>
HashNode* CreateHashNode();

/// <summary>
/// �������� ����.
/// </summary>
/// <param name="hashNode">��������� ���� ���-�������.</param>
void DeletetHashNode(HashNode* hashNode);
