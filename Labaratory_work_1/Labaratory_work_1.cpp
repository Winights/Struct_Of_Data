// Labaratory_work_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "DynamicArray.h"

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
        std::cout << "Unknown command. Try entering the command again." << std::endl;
        return GetInput(prompt);
    }
}

int main()
{
    DynamicArray* dynamicArray = CreateDynamicArray();

    cout << "Current array \n";

    InitializationDynamicArray(dynamicArray);
    cout << endl;
    PrintArray(dynamicArray);
    cout << endl;

    while (true)
    {
        cout << "Select the action you want to do: \n";
        cout << "1. Remove an element by index from an array \n";
        cout << "2. Remove an element by value from an array \n";
        cout << "3. Insert an element at the beginning \n";
        cout << "4. Insert an element at the end \n";
        cout << "5. Insert after a certain element \n";
        cout << "6. Sort array \n";
        cout << "7. Linear search for an element in an array \n";
        cout << "8. Binary search for an element in an array \n";

        int choice = GetInput("Your input: ");

        switch (choice)
        {
            case 1:
            {
                int index = GetInput("Enter the index to delete: ");
                cout << endl;
                RemoveByIndex(dynamicArray, index);
                PrintArray(dynamicArray);
                cout << endl;
                break;
            }
            case 2:
            {
                int value = GetInput("Enter the value to delete: ");
                cout << endl;
                RemoveByValue(dynamicArray, value);
                PrintArray(dynamicArray);
                cout << endl;
                break;
            }
            case 3:
            {
                int value = GetInput("Enter the element to insert it at the beginning: ");
                cout << endl;
                AddElement(dynamicArray, 0, value);
                PrintArray(dynamicArray);
                cout << endl;
                break;
            }
            case 4:
            {
                int value = GetInput("Enter the element to inset it at the end: ");
                cout << endl;;
                AddElement(dynamicArray, dynamicArray->Size, value);
                PrintArray(dynamicArray);
                cout << endl;
                break;
            }
            case 5:
            {
                int index = GetInput("Enter the index where you want to insert the value : ");
                int value = GetInput("Enter the value you want to insert: ");
                cout << endl;
                AddElement(dynamicArray, index, value);
                PrintArray(dynamicArray);
                cout << endl;
                break;
            }
            case 6:
            {
                SortArray(dynamicArray);
                cout << "Array is sorted " << endl;
                cout << endl;
                PrintArray(dynamicArray);
                cout << endl;
                break;
            }
            case 7:
            {
                int value = GetInput("Enter the value you want to find in the array: ");
                cout << endl;
                LinerSearch(dynamicArray, value);
                PrintArray(dynamicArray);
                cout << endl;
                break;
            }
            case 8:
            {
                int value = GetInput("Enter the value you want to find in the array: ");
                cout << endl;
                BinarySearch(dynamicArray, value);
                PrintArray(dynamicArray);
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
    FreeArray(dynamicArray);
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
