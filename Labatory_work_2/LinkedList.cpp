#include "LinkedList.h"
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
        AddToEnd(list, value);
    }
}

void AddToBegin(LinkedList* list, int value)
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

void AddToEnd(LinkedList* list, int value)
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

void RemoveToBegin(LinkedList* list)
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
    list->Size--;

}

void InsertByIndex(LinkedList* list, int index, int value)
{
    Node* right = GetElement(list, index);
    if (right->Next == nullptr)
    {
        AddToEnd(list, value);
        return;
    }       

    Node* left = right->Prev;
    if (left == nullptr)
    {
        AddToBegin(list, value);
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

void RemoveByIndex(LinkedList* list, int index)
{
    if (list->Head == nullptr || index < 0) 
    {
        std::cout << "Invalid index" << std::endl;
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
        std::cout << "Index out of bounds" << std::endl;
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
        std::cout << node->Data << " ";
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