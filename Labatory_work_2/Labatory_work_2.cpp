// Labatory_work_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "LinkedList.h"
#include <string>
#include <chrono>
#include <cctype>
#include <fstream>

using namespace std;

/// <summary>
/// Проверяет является ли строка числом.
/// </summary>
/// <param name="prompt">Введенные значения.</param>
/// <returns>Возвращает true, если является числом, иначе false.</returns>
bool isNumber(const std::string& prompt) 
{
    if (prompt.empty())
    {
        return false;
    }

    // Проверяем, есть ли знак числа
    size_t start = 0;
    if (prompt[0] == '-' || prompt[0] == '+') 
    {
        start = 1;
    }

    for (size_t i = start; i < prompt.size(); ++i) 
    {
        if (!isdigit(prompt[i]))
        {
            return false;
        }
    }

    return true;
}

/// <summary>
/// Получение значения от пользователя.
/// </summary>
/// <param name="prompt">Введенные значения.</param>
/// <returns>Возвращает число</returns>
int GetInput(const string& prompt)
{
    string input;
    cout << prompt;
    cin >> input;

    if (isNumber(input)) 
    {
        return std::stoi(input);
    }
    else 
    {
        cout << endl;
        std::cout << "Unknown command. Try entering the command again." << std::endl;
        cout << endl;
        return GetInput(prompt);
    }
    
}

int main()
{
    /*int lists_count = 100;
        int step = 10000;
        int samples = 200;
        std::ofstream outfile("C:\\Users\\fgfgf\\Desktop\\mean_delete_from_center.csv");
        srand(time(0));
        outfile << "linked_list_size;mean_delete_from_center_time" << std::endl;
        for (int i = 0; i < lists_count; i++) {
            for (size_t j = 0; j < step; j++)
            {
                AddToBegin(linkedList, rand() % 21);
            }
            int res = 0;
            cout << i << endl;
            for (size_t sampl = 0; sampl < samples; sampl++)
            {
                auto start = std::chrono::high_resolution_clock::now();
                InsertByIndex(linkedList, int((i + 1) * step / 2), rand() % 21);
                AddToEnd(linkedList, rand() % 21);
                RemoveByIndex(linkedList, int((i + 1) * step / 2));
                RemoveToBegin(linkedList);
                RemoveToEnd(linkedList);
                auto end = std::chrono::high_resolution_clock::now();
                AddToBegin(linkedList, rand() % 21);
                RemoveToBegin(linkedList);
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                res += duration.count();
            }
            res /= samples;
            outfile << (i + 1) * step << ";" << res << std::endl;*/

            //cout << "List of size:\t" << (i + 1) * step << ".\tTime to delete "
            //    << int((i + 1) * step / 2) << "\titem:\t" << duration.count() << " microseconds" << endl;

    //Фигурная скобка
     /*   outfile.close();*/
    LinkedList* linkedList = CreateLinkedList();

    cout << "Current list \n";
    InitializationLinkedList(linkedList, 5);
    cout << endl;
    PrintList(linkedList);
    cout << endl;

    while (true)
    {
        cout << "Select the action you want to do: \n";
        cout << "1. Insert an element at the beginning \n";
        cout << "2. Insert an element at the end \n";
        cout << "3. Insert element after a certain element \n";
        cout << "4. Insert element before a certain element \n";
        cout << "5. Remove an element at the beginning \n";
        cout << "6. Remove an element at the end \n";
        cout << "8. Remove an element by value from an list \n";
        cout << "9. Sort array \n";
        cout << "10. Linear search for an element in an list \n";

        int choice = GetInput("Your input: ");

        switch (choice)
        {
            case 1:
            {
                int value = GetInput("Enter the element to insert it at the beginning: ");
                cout << endl;
                InsertBegin(linkedList, value);
                PrintList(linkedList);
                cout << endl;
                break;
            }
            case 2:
            {
                int value = GetInput("Enter the element to insert it at the end: ");
                cout << endl;
                InsertEnd(linkedList, value);
                cout << endl;
                PrintList(linkedList);
                cout << endl;
                break;
            }
            case 3:
            {
                int target = GetInput("Enter the value which after you want to insert the value: ");
                int value = GetInput("Enter the value you want to insert: ");
                cout << endl;
                InsertByValueAfter(linkedList, value, target);
                PrintList(linkedList);
                std::cout << std::endl;
                cout << endl;
                break;
            }
            case 4:
            {
                int target = GetInput("Enter the value which before you want to insert the value: ");
                int value = GetInput("Enter the value you want to insert: ");
                cout << endl;
                InsertByValueBefore(linkedList, value, target);
                PrintList(linkedList);
                std::cout << std::endl;
                cout << endl;
                break;
            }
            case 5:
            {
                cout << endl;
                RemoveBegin(linkedList);
                cout << "Element is deleted " << endl;
                PrintList(linkedList);
                cout << endl;
                break;
            }
            case 6:
            {
                cout << endl;
                RemoveEnd(linkedList);
                cout << "Element is deleted " << endl;
                PrintList(linkedList);
                cout << endl;
                break;
            }
            case 8:
            {
                int value = GetInput("Enter the value of element to delete: ");
                cout << endl;
                RemoveByValue(linkedList, value);
                PrintList(linkedList);
                cout << endl;
                break;
            }
            case 9:
            {
                BubbleSort(linkedList);
                cout << "List is sorted " << endl;
                cout << endl;
                PrintList(linkedList);
                cout << endl;
                break;
            }
            case 10:
            {
                int value = GetInput("Enter the value you want to find in the array: ");
                cout << endl;
                LinerSearch(linkedList, value);
                PrintList(linkedList);
                cout << endl;
                break;
            }
            default:
            {
                cout << endl;
                cout << "Unknown command. Try entering the command again";
                cout << endl;
            }
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
