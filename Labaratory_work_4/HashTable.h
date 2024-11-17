#pragma once
#include "HashNode.h"
#include <iostream>
#include <vector>


/// <summary>
/// ��������� ����.
/// </summary>
struct HashTable
{
	/// <summary>
	/// ������ �����.
	/// </summary>
	HashNode** Items;

	/// <summary>
	/// ������ �������.
	/// </summary>
	int Size;

	/// <summary>
	/// ���������� ���������.
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

