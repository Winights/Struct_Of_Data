#include "HashNode.h"
#include "HashTable.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <cstring>
#include <string>

HashTable* CreateHashTable(int size)
{
	HashTable* hashTable = new HashTable;
	hashTable->Size = size;
	hashTable->Count = 0;
	hashTable->Items = new HashNode*[hashTable->Size];
	for (int i = 0; i < hashTable->Size; i++)
	{
		hashTable->Items[i] = NULL;
	}
	return hashTable;
}

unsigned char* CreateTablePearson()
{
	unsigned char* table = new unsigned char[256];

	// Заполнение массива значениями от 0 до 255
	for (size_t i = 0; i < 256; ++i)
	{
		table[i] = i;
	}
	//// Создание генератора случайных чисел
	//// получить случайное число для задания начального значения
	//std::random_device randomDevice;
	//// инициализация генератора
	//std::mt19937 generator(randomDevice());
	//std::shuffle(table, table + 256, generator);

	// Перемешивание таблицы
	for (unsigned char i = 255; i > 0; --i) 
	{
		unsigned char j = rand() % (i + 1);
		std::swap(table[i], table[j]);
	}

	return table;
}

int HashPearson(const std::string& key, unsigned char* table)
{
	//unsigned char hash = static_cast<unsigned char>(key.length() % 256);
	int hashValue = 0;
	for (char i : key) 
	{
		/*hash = table[(hash + static_cast<unsigned char>(i)) % 256];*/
		hashValue = table[hashValue ^ static_cast<unsigned char>(i)];
	}
	return hashValue;
}

void HandleCollision(HashTable* hashTable, int index, HashNode* hashNode)
{

}

void Insert(HashTable* hashTable, unsigned char* table, const char* key, const char* value)
{
	if (hashTable->Count == hashTable->Size)
	{
		std::cout << "Hash table is full" << std::endl;
	}
	HashNode* hashNode = new HashNode();
	hashNode->Key = key;
	hashNode->Value = value;

	int index = HashPearson(key, table);

	HashNode* currentNode = hashTable->Items[index];

	if (currentNode == NULL)
	{
		hashTable->Items[index] = hashNode;
		hashTable->Count++;
	}
	//else
	//{
	//	if (strcmp(currentNode->Key, key) == 0)
	//	{
	//		/*strcpy_s(value, hashTable->Items[index]->Value);*/
	//		return;
	//	}
	//	else
	//	{
	//		HandleCollision(hashTable, index, hashNode);
	//		return;
	//	}
	//}
}

const char* Search(HashTable* hashTable, unsigned char* table, const char* key)
{
	// Searches the key in the hashtable
	// and returns NULL if it doesn't exist
	int index = HashPearson(key, table);
	HashNode* item = hashTable->Items[index];

	// Ensure that we move to a non NULL item
	if (item != NULL) 
	{
		if (strcmp(item->Key, key) == 0)
		{
			return item->Value;
		}
	}
	return NULL;
}

void PrintSearch(HashTable* hashTable, unsigned char* table, const char* key)
{
	const char* val;
	if ((val = Search(hashTable, table, key)) == NULL)
	{
		printf("Key:%s does not exist\n", key);
		return;
	}
	else 
	{
		printf("Key:%s, Value:%s\n", key, val);
	}
}

void PrintTable(HashTable* hashTable) 
{
	for (int i = 0; i < hashTable->Size; i++) 
	{
		if (hashTable->Items[i]) 
		{
			std::cout << "Index: " << i << " " <<
				"Key: " << hashTable->Items[i]->Key << " "
				<< "Value: " << hashTable->Items[i]->Value << "\n";
		}
	}
	std::cout << std::endl;
}

void DeletetHashTable(HashTable* hashTable)
{
	for (int i = 0; i < hashTable->Size; i++)
	{
		if (hashTable->Items[i] != nullptr)
		{
			DeletetHashNode(hashTable->Items[i]);
		}
	}
	delete[] hashTable->Items;
	delete hashTable;
}

