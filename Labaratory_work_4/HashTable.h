#pragma once
#include "HashNode.h"
#include "LinkedList.h"
#include <iostream>


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
	/// ������ ����������.
	/// </summary>
	LinkedList** OverflowBuckets;

	/// <summary>
	/// ������ �������.
	/// </summary>
	int Size;

	/// <summary>
	/// ���������� ���������.
	/// </summary>
	int Count;
};

const double limitLoadfactor = 0.8;

HashTable* CreateHashTable(int size);

void Insert(HashTable* hashTable, std::string key, std::string value, int a);

std::string Search(HashTable* hashTable, std::string key, int a);

void PrintSearch(HashTable* hashTable, std::string key, int a);

void PrintTable(HashTable* hashTable);

void DeletetHashTable(HashTable* hashTable);

int FindCompire(int size);

int FindCompire(int size);

void Remove(HashTable* hashTable, std::string key, int a);

