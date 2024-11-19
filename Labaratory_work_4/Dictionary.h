#pragma once
#include "HashTable.h"

/// <summary>
/// Структура словаря.
/// </summary>
struct Dictionary
{
	/// <summary>
	/// Хеш-таблица.
	/// </summary>
	HashTable* Table;
};

/// <summary>
/// Создание словаря.
/// </summary>
/// <param name="size">Размер.</param>
/// <returns>Созданный словарь.</returns>
Dictionary* CreateDictionary(int size);

/// <summary>
/// Добавление в словарь.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
/// <param name="key">Ключ.</param>
/// <param name="value">Значение.</param>
void InsertInDictionary(Dictionary* dictionary, std::string key, std::string value);

/// <summary>
/// Удаление из словаря.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
/// <param name="key">Ключ.</param>
void RemoveInDictionary(Dictionary* dictionary, std::string key);

/// <summary>
/// Поиск в словаре.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
/// <param name="key">Ключ.</param>
/// <returns>Найденное значение, иначе пустая строка.</returns>
std::string SearchInDictionary(Dictionary* dictionary, std::string key);

/// <summary>
/// Вывод поиска в словаре.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
/// <param name="key">Ключ.</param>
void PrintSearchInDictionary(Dictionary* dictionary, std::string key);

/// <summary>
/// Вывод словаря.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
void PrintDictionary(Dictionary* dictionary);

/// <summary>
/// Удаление словаря.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
void DeletetDictionary(Dictionary* dictionary);