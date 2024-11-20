#pragma once
#include "HashNode.h"
#include "LinkedList.h"
#include <iostream>

/// <summary>
/// Структура хеш-таблицы.
/// </summary>
struct HashTable
{
	/// <summary>
	/// Массив узлов.
	/// </summary>
	HashNode** Items;

	/// <summary>
	/// Массив указателей.
	/// </summary>
	LinkedList** OverflowBuckets;

	/// <summary>
	/// Размер таблицы.
	/// </summary>
	int Size;

	/// <summary>
	/// Количество элементов.
	/// </summary>
	int Count;
};

/// <summary>
/// Фактор роста для хеш-таблицы.
/// </summary>
const int growthFactor = 2;

/// <summary>
/// Коэфициент заполнения.
/// </summary>
const double limitLoadFactor = 0.75;

/// <summary>
/// Создание хеш-таблицы.
/// </summary>
/// <param name="size">Размер.</param>
/// <returns>Созданная хеш-таблица.</returns>
HashTable* CreateHashTable(int size);

/// <summary>
/// Добавление в хеш-таблицу.
/// </summary>
/// <param name="hashTable">Структура хеш-таблицы.</param>
/// <param name="key">Ключ.</param>
/// <param name="value">Значение.</param>
void InsertHashTable(HashTable* hashTable, std::string key, std::string value);

/// <summary>
/// Поиск в хеш-таблице.
/// </summary>
/// <param name="hashTable">Структура хеш-таблицы.</param>
/// <param name="key">Ключ.</param>
/// <returns>Найденное значение, иначе пустая строка.</returns>
std::string SearchHashTable(HashTable* hashTable, std::string key);

/// <summary>
/// Удаление из хеш-таблицы.
/// </summary>
/// <param name="hashTable">Структура хеш-таблицы.</param>
/// <param name="key">Ключ.</param>
void RemoveHashTable(HashTable* hashTable, std::string key);

/// <summary>
/// Перешеширование хеш-таблицы.
/// </summary>
/// <param name="hashTable">Структура хеш-таблицы.</param>
void Rehashing(HashTable* hashTable);

/// <summary>
/// Вывод поиска в хеш-таблице.
/// </summary>
/// <param name="hashTable">Структура хеш-таблицы.</param>
/// <param name="key">Ключ.</param>
void PrintSearch(HashTable* hashTable, std::string key);

/// <summary>
/// Вывод хеш-таблицы.
/// </summary>
/// <param name="hashTable">Структура хеш-таблицы.</param>
void PrintTable(HashTable* hashTable);

/// <summary>
/// Удаление хеш-таблицы.
/// </summary>
/// <param name="hashTable">Структура хеш-таблицы.</param>
void DeletetHashTable(HashTable* hashTable);