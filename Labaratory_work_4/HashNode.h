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
	std::string Value;

	/// <summary>
	/// ����.
	/// </summary>
	std::string Key;

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
