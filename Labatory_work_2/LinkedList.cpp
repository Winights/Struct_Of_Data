#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

LinkedList* CreateDynamicList()
{
	LinkedList* list = new LinkedList;

	return list;
}

void InitializationLinkedList(LinkedList* list)
{
    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        int value = rand() % 21;
        AddToEnd(list, value);
    }
}

void AddToBegin(LinkedList* list, int value)
{
    Node* node = new Node;
    node->Data = value;

    node->Next = list->Head;

    if (list->Head != nullptr)
    {
        list->Head->Prev = node;
    }

    if (list->Tail == nullptr)
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

    if (list->Tail != nullptr)
    {
        list->Tail->Next = node;
    } 

    if (list->Head == nullptr)
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
        if (node == nullptr)
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
    if (list->Head == nullptr) return;

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

}


void RemoveToEnd(LinkedList* list) 
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

}

int InsertByIndex(LinkedList* list, int index, int value)
{
    Node* right = GetElement(list, index);
    if (right == nullptr)
    {
        return 1;
    }       

    Node* left = right->Prev;
    if (left == nullptr)
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
    if (list->Head == nullptr || index < 0) 
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    Node* current = list->Head;
    for (int i = 0; i < index; ++i) 
    {
        if (current == nullptr) 
        {
            std::cout << "Index out of bounds" << std::endl;
            return;
        }
        current = current->Next;
    }

    // Если нашли нужный узел
    if (current) 
    {
        if (current->Prev) 
        {
            current->Prev->Next = current->Next;
        }
        else 
        {
            // Обработка случая, если это голова
            list->Head = current->Next;
        }

        if (current->Next) 
        {
            current->Next->Prev = current->Prev;
        }
        else 
        {
            // Обработка случая, если это хвост
            list->Tail = current->Prev;
        }

        delete current; // Освобождаем память
    }
    else 
    {
        std::cout << "Index out of bounds" << std::endl;
    }
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
    for (Node* ptr = list->Head; ptr != nullptr; ptr = ptr->Next)
    {
        std::cout << ptr->Data << " ";
    }
    cout << endl;
}


void FreeList(LinkedList* list)
{
    while (list->Head != nullptr)
    {
        RemoveToBegin(list);
    }
    delete list;
}