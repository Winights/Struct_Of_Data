// Labaratory_work_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Stack.h"
#include "CircularBuffer.h"
#include "QueueCircularBuffer.h"
#include "QueueStacks.h"

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
    int sizeOfStack = PositiveSize("Enter size of stack: ");
    cout << endl;
    Stack* stack = CreateStack(sizeOfStack);
    InitializationStack(stack, sizeOfStack - 1);
    int sizeOfCircular = PositiveSize("Enter size of circular buffer: ");
    cout << endl;
    CircularBuffer* circularBuffer = CreateCircularBuffer(sizeOfCircular);
    InitializationCircularBuffer(circularBuffer, sizeOfCircular - 1);
    int sizeOfQueueCircularBuffer = PositiveSize("Enter size of queue based on circular buffer: ");
    cout << endl;
    QueueCircularBuffer* queueCircularBuffer = CreateQueueCircularBuffer(sizeOfQueueCircularBuffer);
    InitializationQueueCircularBuffer(queueCircularBuffer, sizeOfQueueCircularBuffer - 1);
    int sizeOfQueueStacks = PositiveSize("Enter size of queue based on 2 stacks: ");
    cout << endl;
    QueueStacks* queueStacks = CreateQueueStacks(sizeOfQueueStacks);
    InitializationQueueStacks(queueStacks, sizeOfQueueStacks - 1);

    cout << endl;

    while (true)
    {
        cout << "Select the action you want to do: \n";
        cout << "1. Print stack \n";
        cout << "2. Push the value to stack \n";
        cout << "3. Pop the value from stack \n";
        cout << "4. Resize stack \n";
        cout << "5. Print circular buffer \n";
        cout << "6. Add element to circular buffer \n";
        cout << "7. Get element from circular buffer \n";
        cout << "8. Resize circular buffer \n";
        cout << "9. Print queue based on circular buffer \n";
        cout << "10. Add element to queue based on circular buffer \n";
        cout << "11. Get element from queue based on circular buffer \n";
        cout << "12. Resize queue based on circular buffer \n";
        cout << "13. Print queue based on two stacks \n";
        cout << "14. Add element to queue based on two stacks \n";
        cout << "15. Get element from queue based on two stacks \n";
        cout << "16. Resize queue based on two stacks \n";

        int choice = GetInput("Your input: ");

        switch (choice)
        {
            case 1:
            {
                cout << endl;
                PrintStack(stack);
                cout << endl;
                break;
            }
            case 2:
            {
                int value = GetInput("Enter the value to push: ");
                cout << endl;
                Push(stack, value);
                PrintStack(stack);
                cout << endl;
                break;
            }
            case 3:
            {
                int value = Pop(stack);
                cout << endl;
                cout << "Element received " << value << endl;
                cout << endl;
                PrintStack(stack);
                cout << endl;
                break;
            }
            case 4:
            {
                int size = PositiveSize("Enter new size of stack: ");
                ResizeStack(stack, size);
                cout << endl;
                cout << "Resize was complete" << endl;
                cout << endl;
                PrintStack(stack);
                cout << endl;
                break;
            }
            case 5:
            {
                cout << endl;
                PrintCircularBuffer(circularBuffer);
                cout << endl;
                break;
            }
            case 6:
            {
                int value = GetInput("Enter the value to add: ");
                cout << endl;
                Enqueue(circularBuffer, value);
                PrintCircularBuffer(circularBuffer);
                cout << endl;
                break;
            }
            case 7:
            {
                int value = Dequeue(circularBuffer);
                cout << endl;
                cout << "Element received " << value << endl;
                cout << endl;
                PrintCircularBuffer(circularBuffer);
                cout << endl;
                break;
            }
            case 8:
            {
                int size = PositiveSize("Enter new size of circular buffer: ");
                ResizeCircularBuffer(circularBuffer, size);
                cout << endl;
                cout << "Resize was complete" << endl;
                cout << endl;
                PrintCircularBuffer(circularBuffer);
                cout << endl;
                break;
            }
            case 9:
            {
                cout << endl;
                PrintQueueCircularBuffer(queueCircularBuffer);
                cout << endl;
                break;
            }
            case 10:
            {
                int value = GetInput("Enter the value to add: ");
                cout << endl;
                EnqueueQueueCircularBuffer(queueCircularBuffer, value);
                PrintQueueCircularBuffer(queueCircularBuffer);
                cout << endl;
                break;
            }
            case 11:
            {
                int value = DequeueQueueCircularBuffer(queueCircularBuffer);
                cout << endl;
                cout << "Element received " << value << endl;
                cout << endl;
                PrintQueueCircularBuffer(queueCircularBuffer);
                cout << endl;
                break;
            }
            case 12:
            {
                int size = PositiveSize("Enter new size of queue based on circular buffer: ");
                ResizeQueueCircularBuffer(queueCircularBuffer, size);
                cout << endl;
                cout << "Resize was complete" << endl;
                cout << endl;
                PrintQueueCircularBuffer(queueCircularBuffer);
                cout << endl;
                break;
            }
            case 13:
            {
                cout << endl;
                PrintQueueStacks(queueStacks);
                cout << endl;
                break;
            }
            case 14:
            {
                int value = GetInput("Enter the value to add: ");
                cout << endl;
                EnqueueQueueStacks(queueStacks, value);
                PrintQueueStacks(queueStacks);
                cout << endl;
                break;
            }
            case 15:
            {
                int value = DequeueQueueStacks(queueStacks);
                cout << endl;
                cout << "Element received " << value << endl;
                cout << endl;
                PrintQueueStacks(queueStacks);
                cout << endl;
                break;
            }
            case 16:
            {
                int size = PositiveSize("Enter new size of queue based on 2 stacks: ");
                ResizeQueueStacks(queueStacks, size);
                cout << endl;
                cout << "Resize was complete" << endl;
                cout << endl;
                PrintQueueStacks(queueStacks);
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
    DeleteStack(stack);
    DeleteCircularBuffer(circularBuffer);
    DeleteQueueCircularBuffer(queueCircularBuffer);
    DeleteQueueStacks(queueStacks);
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
