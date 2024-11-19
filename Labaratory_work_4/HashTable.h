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

const double limitLoadfactor = 0.7;

const int growthFactor = 2;

HashTable* CreateHashTable(int size);

void Insert(HashTable* hashTable, std::string key, std::string value);

std::string Search(HashTable* hashTable, std::string key);

void PrintSearch(HashTable* hashTable, std::string key);

void PrintTable(HashTable* hashTable);

void DeletetHashTable(HashTable* hashTable);

int FindCompire(int size);

int FindCompire(int size);

void Remove(HashTable* hashTable, std::string key);

void Rehashing(HashTable* hashTable);

