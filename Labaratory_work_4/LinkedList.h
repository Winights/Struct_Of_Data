#pragma once
#include "HashNode.h"

struct LinkedList
{
	HashNode* Node;
	LinkedList* Next = nullptr;
};

LinkedList* CreateLinkedList();

LinkedList* LinkedListInsert(LinkedList* linkedList, HashNode* hashNode);

HashNode* LinkedListRemove(LinkedList* linkedList);

void DeleteLinkedList(LinkedList* linkedList);
