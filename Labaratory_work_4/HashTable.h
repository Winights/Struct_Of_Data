#pragma once
#include "HashNode.h"
#include <iostream>
#include <vector>


/// <summary>
/// Структура узла.
/// </summary>
struct HashTable
{
	/// <summary>
	/// Массив узлов.
	/// </summary>
	HashNode** Items;

	/// <summary>
	/// Размер таблицы.
	/// </summary>
	int Size;

	/// <summary>
	/// Количество элементов.
	/// </summary>
	int Count;
};

HashTable* CreateHashTable(int size);

unsigned char* CreateTablePearson();

void Insert(HashTable* hashTable, unsigned char* table, const char* key, const char* value);

const char* Search(HashTable* hashTable, unsigned char* table, const char* key);

void PrintSearch(HashTable* hashTable, unsigned char* table, const char* key);

void PrintTable(HashTable* hashTable);

void DeletetHashTable(HashTable* hashTable);

