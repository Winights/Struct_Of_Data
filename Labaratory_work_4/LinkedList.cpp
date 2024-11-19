#include "LinkedList.h"
#include "HashNode.h"

LinkedList* CreateLinkedList()
{
	LinkedList* linkedList = new LinkedList;

	return linkedList;
}

LinkedList* LinkedListInsert(LinkedList* linkedList, HashNode* hashNode)
{
	if (!linkedList)
	{
		LinkedList* head = CreateLinkedList();
		head->Node = hashNode;
		linkedList = head;
		return linkedList;
	}
	else if (linkedList->Next == nullptr)
	{
		LinkedList* head = CreateLinkedList();
		head->Node = hashNode;
		linkedList->Next = head;
		return linkedList;
	}

	LinkedList* temp = linkedList;
	while (temp->Next)
	{
		temp = temp->Next;
	}

	LinkedList* newNode = CreateLinkedList();
	newNode->Node = hashNode;
	temp->Next = newNode;

	return linkedList;
}

HashNode* LinkedListRemove(LinkedList* linkedList)
{
	if (!linkedList)
	{
		return NULL;
	}

	if (!linkedList->Next)
	{
		return NULL;
	}

	LinkedList* node = linkedList->Next;
	LinkedList* temp = linkedList;
	temp->Next = nullptr;
	linkedList = node;
	HashNode* memNode = temp->Node;
	memNode->Key = temp->Node->Key;
	memNode->Value = temp->Node->Value;
	delete temp;

	return memNode;
}

void DeleteLinkedList(LinkedList* linkedList)
{
	LinkedList* temp;
	while (linkedList)
	{
		temp = linkedList;
		linkedList = linkedList->Next;
		delete temp;
	}
}