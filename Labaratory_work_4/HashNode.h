#pragma once
#include <string>

/// <summary>
/// Структура узла.
/// </summary>
struct HashNode
{
	/// <summary>
	/// Значение.
	/// </summary>
	std::string Value;

	/// <summary>
	/// Ключ.
	/// </summary>
	std::string Key;

};

/// <summary>
/// Создание узла хеш-таблицы.
/// </summary>
/// <returns>Созданный узел.</returns>
HashNode* CreateHashNode();

/// <summary>
/// Удаление узла.
/// </summary>
/// <param name="hashNode">Структура узла хеш-таблицы.</param>
void DeletetHashNode(HashNode* hashNode);