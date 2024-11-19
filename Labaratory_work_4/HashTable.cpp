#include "HashNode.h"
#include "HashTable.h"
#include <iostream>
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

void Rehashing(HashTable* hashTable)
{
	HashTable* newHashTable = CreateHashTable(hashTable->Size * growthFactor);

	/*PrintTable(newHashTable);*/

	for (int i = 0; i < hashTable->Size; i++)
	{
		if (hashTable->Items[i]->Key != "" && hashTable->Items[i]->Value != "")
		{
			Insert(newHashTable, hashTable->Items[i]->Key, hashTable->Items[i]->Value);
			if (hashTable->OverflowBuckets[i])
			{
				LinkedList* head = hashTable->OverflowBuckets[i];

				while (head)
				{
					Insert(newHashTable, head->Node->Key, head->Node->Value);
					head = head->Next;
				}
			}
		}
	}
	delete[] hashTable->Items;
	delete[] hashTable->OverflowBuckets;
	hashTable->Items = newHashTable->Items;
	hashTable->OverflowBuckets = newHashTable->OverflowBuckets;
	hashTable->Size = hashTable->Size * growthFactor;
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

void Insert(HashTable* hashTable, std::string key, std::string value)
{
	if (hashTable->Count == hashTable->Size)
	{
		std::cout << "Hash table is full" << std::endl;
		return;
	}
	HashNode* hashNode = new HashNode();
	hashNode->Key = key;
	hashNode->Value = value;
	int a = FindCompire(hashTable->Size - 1);

	int index = HashPearson(key, a, hashTable->Size-1);

	HashNode* currentNode = hashTable->Items[index];

	if (currentNode->Key == "" && currentNode->Value == "")
	{
		hashTable->Items[index] = hashNode;
		hashTable->Count++;
	}
	else
	{
		if (currentNode->Key == key && currentNode->Value == value)
		{
			std::cout << std::endl;
			std::cout << "Such a key and value are in the hash table" << std::endl;
			return;
		}
		else
		{
			HandleCollision(hashTable, index, hashNode);
			return;
		}
	}

	double loadFactor = (double)hashTable->Count / (double)hashTable->Size;

	if (loadFactor > limitLoadfactor)
	{
		Rehashing(hashTable);
	}
}

void Remove(HashTable* hashTable, std::string key)
{
	if (hashTable->Count == 0)
	{
		std::cout << "Hash table is empty" << std::endl;
	}

	int a = FindCompire(hashTable->Size - 1);

	int index = HashPearson(key, a, hashTable->Size - 1);

	HashNode* currentNode = hashTable->Items[index];

	LinkedList* head = hashTable->OverflowBuckets[index];

	if (currentNode->Key == "" && currentNode->Value == "")
	{
		return;
	}
	else
	{
		if (head == NULL && currentNode->Key == key)
		{
			currentNode->Key = "";
			currentNode->Value = "";
			hashTable->Count--;
			return;

		}
		else if (head != NULL)
		{
			if (currentNode->Key == key)
			{
				DeletetHashNode(currentNode);
				LinkedList* node = head;
				head = head->Next;
				node->Next = nullptr;
				hashTable->Items[index] = CreateHashNode();
				hashTable->Items[index]->Key = node->Node->Key;
				hashTable->Items[index]->Value = node->Node->Value;
				delete node;
				hashTable->OverflowBuckets[index] = head;
				return;
			}

			LinkedList* current = head;
			LinkedList* prev = nullptr;

			while (current)
			{
				if (current->Node->Key == key)
				{
					if (prev == NULL)
					{
						DeleteLinkedList(head);
						hashTable->OverflowBuckets[index] = NULL;
						return;
					}
					else
					{
						prev->Next = current->Next;
						current->Next = NULL;
						DeleteLinkedList(current);
						hashTable->OverflowBuckets[index] = head;
						return;
					}
				}
				current = current->Next;
				prev = current;		
			}
		}
	}

}

std::string Search(HashTable* hashTable, std::string key)
{
	int a = FindCompire(hashTable->Size - 1);
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

void PrintSearch(HashTable* hashTable, std::string key)
{
	std::string val = Search(hashTable, key);
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
	printf(" => Hash Table => \n");
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
					std::cout << " " << "Key: " << head->Node->Key << " "
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