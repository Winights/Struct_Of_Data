// Labaratory_work_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

/// <summary>
/// Проверяет является ли строка числом.
/// </summary>
/// <param name="prompt">Введенные значения.</param>
/// <returns>True, если является числом, иначе false.</returns>
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
/// <returns>Целое число</returns>
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

/// <summary>
/// Получение значения от пользователя для размеров.
/// </summary>
/// <param name="prompt">Введенные значения.</param>
/// <returns>Положительное число</returns>
int PositiveSize(const string& prompt)
{
    string input;
    cout << prompt;
    cin >> input;

    if (!isNumber(input) || stoi(input) <= 0)
    {
        cout << endl;
        std::cout << "Size must be positive or not be zero." << std::endl;
        cout << endl;
        return PositiveSize(prompt);
    }
    else
    {
        return stoi(input);
    }
}

int main()
{
    int sizeOfHashTable = PositiveSize("Enter size of hash table: ");
    HashTable* harshTable = CreateHashTable(sizeOfHashTable);
    unsigned char* pearsonTable = CreateTablePearson();

    cout << endl;

    while (true)
    {
        cout << "Select the action you want to do: \n";
        cout << "1. Insert in harsh table \n";
        cout << "2. Search in harsh table \n";

        int choice = GetInput("Your input: ");

        switch (choice)
        {
            case 1:
            {
                string value;
                cout <<"Enter the value to insert: ";
                cin >> value;

                string key;
                cout << "Enter the key to insert: ";
                cin >> key;

                Insert(harshTable, pearsonTable, key.c_str(), value.c_str());
                PrintTable(harshTable);
                break;
            }
            case 2:
            {
           
            }
            case 3:
            {
            
            }
            case 4:
            {
           
            }
            case 5:
            {
            
            }
            case 6:
            {
           
            }
            case 7:
            {
            
            }
            case 8:
            {
            
            }
            case 9:
            {
            
            }
            case 10:
            {
            
            }
            case 11:
            {
            
            }
            case 12:
            {
            
            }
            case 13:
            {
            
            }
            case 14:
            {
            
            }
            case 15:
            {
            
            }
            case 16:
            {
               
            }
            default:
            {
                cout << endl;
                cout << "Unknown command. Try entering the command again";
                cout << endl;
            }
        }
    }
    
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
