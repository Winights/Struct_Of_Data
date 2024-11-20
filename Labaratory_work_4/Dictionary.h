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
/// Добавление элемента в словарь.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
/// <param name="key">Ключ.</param>
/// <param name="value">Значение.</param>
void InsertDictionary(Dictionary* dictionary, std::string key, std::string value);

/// <summary>
/// Удаление элемента из словаря.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
/// <param name="key">Ключ.</param>
void RemoveDictionary(Dictionary* dictionary, std::string key);

/// <summary>
/// Поиск элемента в словаре.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
/// <param name="key">Ключ.</param>
/// <returns>Найденное значение, иначе пустая строка.</returns>
std::string SearchDictionary(Dictionary* dictionary, std::string key);

/// <summary>
/// Вывод поиска в словаре.
/// </summary>
/// <param name="dictionary">Структура словаря.</param>
/// <param name="key">Ключ.</param>
void PrintSearch(Dictionary* dictionary, std::string key);

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