#include "DynamicList.h"
#include <string>
#include <iostream>

using namespace std;

LinkedList* CreateDynamicList()
{
	LinkedList* list = new LinkedList;

	return list;
}

void AddToBegin(LinkedList* list, int value)
{
    Node* node = new Node;
    node->Data = value;

    node->Next = list->Head;

    if (list->Head != NULL)
    {
        list->Head->Prev = node;
    }

    if (list->Tail == NULL)
    {
        list->Tail = node;
    }

    list->Head = node;
    
}

void AddToEnd(LinkedList* list, int value)
{
    Node* node = new Node;
    node->Data = value;

    node->Prev = list->Tail;

    if (list->Tail != NULL)
    {
        list->Tail->Next = node;
    } 

    if (list->Head == NULL)
    {
        list->Head = node;
    }

    list->Tail = node;

}

Node* GetElement(LinkedList* list, int index)
{
    Node* node = new Node;
    node->Data = list->Head->Data;

    int n = 0;

    while (n != index) 
    {
        if (node == NULL)
        {
            return node;
        }
        node = node->Next;
        n++;
    }

    return node;
}

void RemoveToBegin(LinkedList* list)
{
    if (list->Head == NULL) return;

    Node* node = list->Head->Next;
    if (node != NULL)
    {
        node->Prev = NULL;
    }
    else
    {
        list->Tail = NULL;
    }

    delete list->Head;
    list->Head = node;

}


void RemoveToEnd(LinkedList* list) 
{
    if (list->Tail == NULL)
    {
        return;
    }

    Node* node = list->Tail->Prev;
    if (node != NULL)
    {
        node->Next = NULL;
    }
    else
    {
        list->Head = NULL;
    }

    delete list->Tail;
    list->Tail = node;

}

int InsertByIndex(LinkedList* list, int index, int value)
{
    Node* right = GetElement(list, index);
    if (right == NULL)
    {
        return 1;
    }       

    Node* left = right->Prev;
    if (left == NULL)
    {
        return 2;
    }

    Node* node = new Node;
    node->Data = value;

    node->Prev = left;
    node->Next = right;
    left->Next = node;
    right->Prev = node;

}

void RemoveByIndex(LinkedList* list, int index)
{
    Node* node = GetElement(list, index);
    if (node == NULL)
    {
        return;
    }

    if (node->Prev == NULL) 
    {
        RemoveToBegin(list);
        return;
    }

    if (node->Next == NULL) 
    {
        RemoveToEnd(list);
        return;
    }

    Node* left = node->Prev;
    Node* right = node->Next;
    left->Next = right;
    right->Prev = left;

    delete node;
}

/// <summary>
/// Объединяет две части в один список.
/// </summary>
/// <param name="left">Указатель на левую часть списка.</param>
/// <param name="right">Указатель на правую часть списка.</param>
/// <returns>Возвращает указатель на узел, который является головой объединенного отсортированного списка.</returns>
Node* Merge(Node* left, Node* right) 
{
    if (!left)
    {
        return right;
    }
    
    if (!right)
    {
        return left;
    }

    if (left->Data < right->Data) 
    {
        left->Next = Merge(left->Next, right);
        left->Next->Prev = left;
        left->Prev = nullptr;
        return left;
    }
    else 
    {
        right->Next = Merge(left, right->Next);
        right->Next->Prev = right;
        right->Prev = nullptr;
        return right;
    }
}

/// <summary>
/// Делит список на две части.
/// </summary>
/// <param name="head">Указатель на узел, который является головой в списке.</param>
/// <returns>Возвращает указатель на вторую половину списка, разделенного по середине.</returns>
Node* Split(Node* head) 
{
    Node* slow = head;
    Node* fast = head->Next;

    while (fast && fast->Next)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    Node* temp = slow->Next;
    slow->Next = nullptr;
    if (temp)
    {
        temp->Prev = nullptr;
    }
    return temp;
}

/// <summary>
/// Рекурсивно сортирует список.
/// </summary>
/// <param name="head">Узел начального элемента в списке.</param>
/// <returns>Возвращает указатель на отсортированный список.</returns>
Node* MergeSort(Node* head) 
{
    if (!head || !head->Next)
    {
        return head;
    }

    Node* secondHalf = Split(head);
    head = MergeSort(head);
    secondHalf = MergeSort(secondHalf);

    return Merge(head, secondHalf);
}

void SortList(LinkedList* list)
{
    list->Head = MergeSort(list->Head);
}

void LinerSearch(LinkedList* list, int value)
{
    bool flag = false;
    int index = 0;
    for (Node* node = list->Head; node != NULL; node = node->Next)
    {
        if (node->Data == value)
        {
            flag = true;
            cout << "Needed element is at the index : " << index << "\n" << endl;
        }
        index++;
    }
    if (flag == false)
    {
        cout << "Element not found.\n";
    }
}

void PrintList(LinkedList* list)
{
    for (Node* ptr = list->Head; ptr != NULL; ptr = ptr->Next)
    {
        std::cout << ptr->Data << " ";
    }
    cout << endl;
}


void FreeList(LinkedList* list)
{
    while (list->Head != NULL)
    {
        RemoveToBegin(list);
    }
    delete list;
}