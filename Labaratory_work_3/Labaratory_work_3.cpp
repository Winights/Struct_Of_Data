// Labaratory_work_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Stack.h""

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
    int size = GetInput("Enter size of stack: ");
    cout << endl;
    Stack* stack = CreateStack(size);
    InitializationStack(stack);
    PrintStack(stack);


    while (true)
    {
        cout << "Select the action you want to do: \n";
        cout << "1. Push the value to stack \n";
        cout << "2. Pop the value from stack \n";
        cout << "3. Resize stack \n";

        int choice = GetInput("Your input: ");

        switch (choice)
        {
            case 1:
            {
                int value = GetInput("Enter the value to push: ");
                cout << endl;
                Push(stack, value);
                PrintStack(stack);
                cout << endl;
                break;
            }
            case 2:
            {
                Pop(stack);
                PrintStack(stack);
                cout << endl;
                break;
            }
            case 3:
            {
                int size = GetInput("Enter new size of stack:: ");
                if (size < 0)
                {
                    cout << "Size must be positive number or not be zero" << endl;
                    break;
                }
                else
                {
                    ResizeStack(stack, size);
                    cout << "Resize was complete" << endl;
                    cout << endl;
                    PrintStack(stack);
                    cout << endl;
                    break;
                }         
            }
            default:
                cout << "Unknown command. Try entering the command again";
            }
    }
    Delete(stack);
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
