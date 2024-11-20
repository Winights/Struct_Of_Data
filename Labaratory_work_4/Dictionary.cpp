#include "HashTable.h"
#include "Dictionary.h"
#include <iostream>

Dictionary* CreateDictionary(int size)
{
	Dictionary* dictionary = new Dictionary;
	dictionary->Table = CreateHashTable(size);

	return dictionary;
}

void InsertDictionary(Dictionary* dictionary, std::string key, std::string value)
{
	InsertHashTable(dictionary->Table, key,value);
}

void RemoveDictionary(Dictionary* dictionary, std::string key)
{
	RemoveHashTable(dictionary->Table, key);
}

std::string SearchDictionary(Dictionary* dictionary, std::string key)
{
	return SearchHashTable(dictionary->Table, key);
}

void PrintSearch(Dictionary* dictionary, std::string key)
{
	std::string val = SearchDictionary(dictionary, key);
	if (val == "")
	{
		std::cout << "Key: " << key << " does not exist\n";
		return;
	}
	else
	{
		std::cout << "Key: " << key << " Value: " << val << "\n";
	}
}

void PrintDictionary(Dictionary* dictionary)
{
	printf(" => Dictionary => \n");
	for (int i = 0; i < dictionary->Table->Size; i++)
	{
		if (dictionary->Table->Items[i]->Key != ""
			&& dictionary->Table->Items[i]->Value != "")
		{
			std::cout << "Key: " << dictionary->Table->Items[i]->Key << " "
				<< "Value: " << dictionary->Table->Items[i]->Value << "\n";
			if (dictionary->Table->OverflowBuckets[i])
			{
				LinkedList* head = dictionary->Table->OverflowBuckets[i];

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
	PrintTable(dictionary->Table);
}

void DeletetDictionary(Dictionary* dictionary)
{
	DeletetHashTable(dictionary->Table);
	delete dictionary;
}