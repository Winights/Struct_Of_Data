﻿#include "LinkedList.h"
#include "LinkedListItem.h"
#include <string>
#include <iostream>

using namespace std;

LinkedList* CreateLinkedList()
{
	LinkedList* linkedList = new LinkedList;

    linkedList->Size = 0;

	return linkedList;
}

void InitializationLinkedList(LinkedList* list, int size)
{
    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 21;
        InsertEnd(list, value);
    }
}

void InsertBegin(LinkedList* list, int value)
{
    Node* NewNode = CreateLinkedListItem();
    NewNode->Data = value;

    NewNode->Next = list->Head;

    if (list->Head != nullptr)
    {
        list->Head->Prev = NewNode;
    }

    if (list->Tail == nullptr)
    {
        list->Tail = NewNode;
    }

    list->Head = NewNode;
    list->Size++;
    
}

void InsertEnd(LinkedList* list, int value)
{
    Node* NewNode = CreateLinkedListItem();
    NewNode->Data = value;

    NewNode->Prev = list->Tail;

    if (list->Tail != nullptr)
    {
        list->Tail->Next = NewNode;
    } 

    if (list->Head == nullptr)
    {
        list->Head = NewNode;
    }

    list->Tail = NewNode;
    list->Size++;

}

Node* GetElement(LinkedList* list, int index)
{
    Node* currentNode = list->Head;
    for (int i = 0; i < index; ++i)
    {
        if (currentNode == nullptr)
        {
            return currentNode;
        }
        currentNode = currentNode->Next;
    }

    return currentNode;
}

void RemoveBegin(LinkedList* list)
{
    if (list->Head == nullptr)
    {
        return;
    }

    Node* node = list->Head->Next;
    if (node != nullptr)
    {
        node->Prev = nullptr;
    }
    else
    {
        list->Tail = nullptr;
    }

    delete list->Head;
    list->Head = node;
    list->Size--;

}


void RemoveEnd(LinkedList* list) 
{
    if (list->Tail == nullptr)
    {
        return;
    }

    Node* node = list->Tail->Prev;
    if (node != nullptr)
    {
        node->Next = nullptr;
    }
    else
    {
        list->Head = nullptr;
    }

    delete list->Tail;
    list->Tail = node;
    list->Size--;

}

void RemoveByIndex(LinkedList* list, int index)
{
    if (list->Head == nullptr || index < 0)
    {
        cout << "Invalid index" << endl;
        return;
    }

    Node* currentNode = GetElement(list, index);

    // Если нашли нужный узел
    if (currentNode)
    {
        if (currentNode->Prev)
        {
            currentNode->Prev->Next = currentNode->Next;
        }
        else
        {
            // Обработка случая, если это голова
            list->Head = currentNode->Next;
        }

        if (currentNode->Next)
        {
            currentNode->Next->Prev = currentNode->Prev;
        }
        else
        {
            // Обработка случая, если это хвост
            list->Tail = currentNode->Prev;
        }

        delete currentNode;
        list->Size--;
    }
    else
    {
        cout << "Index out of bounds" << endl;
    }
}

void RemoveByValue(LinkedList* list, int value)
{
    Node* currentNode = list->Head;

    while (currentNode != nullptr)
    {
        if (currentNode->Data == value)
        {
            if (currentNode->Prev)
            {
                currentNode->Prev->Next = currentNode->Next;
            }
            else
            {
                // Обработка случая, если это голова
                list->Head = currentNode->Next;
            }

            if (currentNode->Next)
            {
                currentNode->Next->Prev = currentNode->Prev;
            }
            else
            {
                // Обработка случая, если это хвост
                list->Tail = currentNode->Prev;
            }
            list->Size--;
        }
        currentNode = currentNode->Next;
    }
    delete currentNode;
}

void InsertByIndex(LinkedList* list, int index, int value)
{
    Node* right = GetElement(list, index);
    if (right->Next == nullptr)
    {
        InsertEnd(list, value);
        return;
    }       

    Node* left = right->Prev;
    if (left == nullptr)
    {
        InsertBegin(list, value);
        return;
    }

    Node* newNode = CreateLinkedListItem();
    newNode->Data = value;

    newNode->Prev = left;
    newNode->Next = right;
    left->Next = newNode;
    right->Prev = newNode;
    list->Size++;

}

void InsertByValueAfter(LinkedList* list, int value, int target)
{
    Node* current = list->Head;

    while (current != nullptr)
    {
        if (current->Data == target)
        {
            Node* newNode = CreateLinkedListItem();
            newNode->Data = value;
            newNode->Next = current->Next;
            newNode->Prev = current;

            if (current->Next != nullptr)
            {
                current->Next->Prev = newNode;
            }
            current->Next = newNode;

            if (current == nullptr)
            { 
                list->Head = newNode;
            }
            list->Size++;
        }
        current = current->Next;
    }
}

void InsertByValueBefore(LinkedList* list, int value, int target)
{
    Node* current = list->Head;

    while (current != nullptr) 
    {
        if (current->Data == target) 
        {
            Node* newNode = CreateLinkedListItem();
            newNode->Data = value;
            newNode->Prev = current->Prev;
            newNode->Next = current;

            if (current->Prev != nullptr) 
            {
                current->Prev->Next = newNode;
            }
            else 
            {
                list->Head = newNode;
            }
            current->Prev = newNode;
            list->Size++;
        }
        current = current->Next;
    }
}

/// <summary>
/// Объединяет две части в один список.
/// </summary>
/// <param name="left">Указатель на левую часть списка.</param>
/// <param name="right">Указатель на правую часть списка.</param>
/// <returns>Возвращает указатель на узел, который является 
/// головой объединенного отсортированного списка.</returns>
Node* Merge(Node* left, Node* right) 
{
    //Если один из списков пустой
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
/// <returns>Возвращает указатель на вторую половину списка, 
/// разделенного по середине.</returns>
Node* Split(Node* head) 
{
    Node* slow = head;
    Node* fast = head->Next;

    //Находим середину спика
    while (fast && fast->Next)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    //Разделяем список на две половины
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

    ///Делит список на две части.
    Node* secondHalf = Split(head);
    //Отсоединяет ссылки у половины.
    head = MergeSort(head);
    secondHalf = MergeSort(secondHalf);

    //Объединенные половины списка.
    return Merge(head, secondHalf);
}

void SortList(LinkedList* list)
{
    list->Head = MergeSort(list->Head);
}

void BubbleSort(LinkedList* list)
{
    if (!list->Head)
    {
        return;
    }

    bool swapped;
    do 
    {
        swapped = false;
        Node* current = list->Head;
        while (current->Next) 
        {
            if (current->Data > current->Next->Data) 
            {
                int temp = current->Data;
                current->Data = current->Next->Data;
                current->Next->Data = temp;
                swapped = true;
            }
            current = current->Next;
        }
    }
    while (swapped);
}

void LinerSearch(LinkedList* list, int value)
{
    bool flag = false;
    int index = 0;
    for (Node* node = list->Head; node != nullptr; node = node->Next)
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
    for (Node* node = list->Head; node != nullptr; node = node->Next)
    {
        cout << node->Data << " ";
    }
    cout << endl;
}

void FreeList(LinkedList* list)
{
    while (list->Head != nullptr)
    {
        RemoveBegin(list);
    }
    delete list;
}