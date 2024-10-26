﻿// Labatory_work_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DynamicList.h"
#include <string>

using namespace std;

/// <summary>
/// Получение значения от пользователя.
/// </summary>
/// <param name="prompt">Введенные значения.</param>
/// <returns>Возвращает число</returns>
int GetInput(const string& prompt)
{
    int value;
    cout << prompt;
    cin >> value;
    return value;
}

int main()
{
    LinkedList* linkedList = CreateDynamicList();

    cout << "Current list \n";

    while (true)
    {
        cout << "Select the action you want to do: \n";
        cout << "1. Remove an element by index from an array \n";
        cout << "2. Insert an element at the beginning \n";
        cout << "3. Insert an element at the end \n";
        cout << "4. Insert after a certain element \n";
        cout << "5. Sort array \n";
        cout << "6. Linear search for an element in an array \n";

        int choice = GetInput("Your input: ");

        switch (choice)
        {
        case 1:
        {
            int index = GetInput("Enter the index to delete: ");
            cout << endl;
            RemoveByIndex(linkedList, index);
            PrintList(linkedList);
            cout << endl;
            break;
        }
        case 2:
        {
            int value = GetInput("Enter the element to insert it at the beginning: ");
            cout << endl;
            AddToBegin(linkedList, value);
            PrintList(linkedList);
            cout << endl;
            break;
        }
        case 3:
        {
            int value = GetInput("Enter the element to inset it at the end: ");
            cout << endl;
            AddToEnd(linkedList, value);
            PrintList(linkedList);
            cout << endl;
            break;
        }
        case 4:
        {
            int index = GetInput("Enter the index where you want to insert the value: ");
            int value = GetInput("Enter the value you want to insert: ");
            cout << endl;
            int result = InsertByIndex(linkedList, index, value);
            if (result == 1)
            {
                AddToEnd(linkedList, value);                    
            }
            if (result == 2)
            {
                AddToBegin(linkedList, value);
            }
            PrintList(linkedList);
            std::cout << std::endl;
            cout << endl;
            break;
        }
        case 5:
        {
            SortList(linkedList);
            cout << "List is sorted " << endl;
            cout << endl;
            PrintList(linkedList);
            cout << endl;
            break;
        }
        case 6:
        {
            int value = GetInput("Enter the value you want to find in the array: ");
            cout << endl;
            LinerSearch(linkedList, value);
            PrintList(linkedList);
            cout << endl;
            break;
        }
        default:
            cout << "Unknown command. Try entering the command again";
        }
    }
    FreeList(linkedList);
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
