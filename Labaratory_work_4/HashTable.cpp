#include "HashNode.h"
#include "HashTable.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <cstring>
#include <string>

LinkedList** CreateOverflowBuckets(HashTable* hashTable)
{
	LinkedList** buckets = new LinkedList*[hashTable->Size];
	for (int i = 0; i < hashTable->Size; i++)
	{
		buckets[i] = NULL;
	}
	return buckets;
}

HashTable* CreateHashTable(int size)
{
	HashTable* hashTable = new HashTable;
	hashTable->Size = size;
	hashTable->Count = 0;
	hashTable->Items = new HashNode*[hashTable->Size];
	for (int i = 0; i < hashTable->Size; i++)
	{
		hashTable->Items[i] = CreateHashNode();
	}
	hashTable->OverflowBuckets = CreateOverflowBuckets(hashTable);

	return hashTable;
}

// Функция для вычисления НОД
int Gsd(int a, int b) 
{
	while (b != 0) 
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int FindCompire(int size)
{
	int count = 0;

	for (int i = 1; i < size; ++i)
	{
		if (Gsd(i, size) == 1)
		{ 
			count = i;
		}
	}

	return count;
}

int HashPearson(std::string& key, int a, int size)
{
	int hashValue = 0;
	int power = 1;
	for (char i : key) 
	{
		hashValue += i * power;
		power *= a;
	}
	return abs(hashValue % size);
}

void HandleCollision(HashTable* hashTable, int index, HashNode* hashNode)
{
	LinkedList* head = hashTable->OverflowBuckets[index];

	if (head == NULL)
	{
		head = CreateLinkedList();
		head->Node = hashNode;
		hashTable->OverflowBuckets[index] = head;
		return;
	}
	else
	{
		hashTable->OverflowBuckets[index] = LinkedListInsert(head, hashNode);
		return;
	}
}

void Insert(HashTable* hashTable, std::string key, std::string value, int a)
{
	if (hashTable->Count == hashTable->Size)
	{
		std::cout << "Hash table is full" << std::endl;
	}
	HashNode* hashNode = new HashNode();
	hashNode->Key = key;
	hashNode->Value = value;

	int index = HashPearson(key, a, hashTable->Size-1);

	HashNode* currentNode = hashTable->Items[index];

	if (currentNode->Key == "" && currentNode->Value == "")
	{
		hashTable->Items[index] = hashNode;
		hashTable->Count++;
	}
	else
	{
		HandleCollision(hashTable, index, hashNode);
		return;
		/*if (currentNode->Key == key)
		{
			hashTable->Items[index]->Value = value;
			return;
		}*/
		/*else
		{
			HandleCollision(hashTable, index, hashNode);
			return;
		}*/
	}

	double loadFactor = (double)hashTable->Count / (double)hashTable->Size;

	if (loadFactor > limitLoadfactor)
	{

	}
}

void Remove(HashTable* hashTable, std::string key, int a)
{
	
}

std::string Search(HashTable* hashTable, std::string key, int a)
{
	int index = HashPearson(key, a, hashTable->Size - 1);
	HashNode* item = hashTable->Items[index];
	LinkedList* head = hashTable->OverflowBuckets[index];

	while (item->Key != "" && item->Value != "")
	{
		if (item->Key == key)
		{
			return item->Value;
		}
		if (head == NULL)
		{
			return "";
		}
		item = head->Node;
		head = head->Next;
	}
	return "";
}

void PrintSearch(HashTable* hashTable, std::string key, int a)
{
	std::string val = Search(hashTable, key, a);
	if (val == "")
	{
		std::cout << "Key: " << key <<" does not exist\n";
		return;
	}
	else 
	{
		std::cout << "Key: " << key << " Value: " << val << "\n";
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

			if (hashTable->OverflowBuckets[i])
			{
				printf(" => Overflow Bucket => \n");
				LinkedList* head = hashTable->OverflowBuckets[i];
				
				while (head)
				{
					std::cout << "Key: " << head->Node->Key << " "
						<< "Value: " << head->Node->Value << "\n";
					head = head->Next;
				}
			}
		}
	}
	std::cout << std::endl;
}

void DeletetOverflowBuckets(HashTable* hashTable)
{
	LinkedList** buckets = hashTable->OverflowBuckets;
	for (int i = 0; i < hashTable->Size; i++)
	{
		DeleteLinkedList(buckets[i]);
	}
	delete[] buckets;
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
	DeletetOverflowBuckets(hashTable);
	delete[] hashTable->Items;
	delete hashTable;
}

