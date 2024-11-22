// Labaratory_work_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include "Tree.h"
#include "TreeNode.h"
#include "TreapNode.h"
#include "Treap.h"

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

int main()
{
    int rootBinaryTree = GetInput("Enter root for binary tree: ");
    Tree* binaryTree = CreateTree(rootBinaryTree);

    int rootTreap = GetInput("Enter root for treap: ");
    Treap* treap = CreateTreap(rootTreap);

    cout << endl;

    while (true)
    {
        cout << "Select the action you want to do: \n";
        cout << "1. Insert in binary tree \n";
        cout << "2. Search in binary tree \n";
        cout << "3. Remove in binary tree \n";
        cout << "4. Find min value in binary tree \n";
        cout << "5. Find max value in binary tree \n";
        cout << "6. Insert in treap \n";
        cout << "7. Search in treap \n";
        cout << "8. Remove in treap \n";
        cout << "9. Insert in treap a optimized way \n";
        cout << "10. Remove in treap a optimized way \n";
        cout << "11. Split and merge a treap  \n";

        int choice = GetInput("Your input: ");

        switch (choice)
        {
            case 1:
            {
                int value = GetInput("Enter value to insert: ");
                Insert(binaryTree, value);
                cout << endl;
                PrintTree(binaryTree);
                cout << endl;
                break;
            }
            case 2:
            {
                int value = GetInput("Enter value to insert: ");
                TreeNode* result = Search(binaryTree, value);
                if (result != NULL)
                {
                    cout << endl;
                    cout << "Element is " << result->Value << endl;
                    cout << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Element not found " << endl;
                    cout << endl;
                }
                cout << endl;
                PrintTree(binaryTree);
                cout << endl;
                break;
            }
            case 3:
            {
                int value = GetInput("Enter value to remove: ");
                Remove(binaryTree, value);
                cout << endl;
                PrintTree(binaryTree);
                cout << endl;
                break;
            }
            case 4:
            {
                TreeNode* minResult = FindMin(binaryTree);
                cout << endl;
                cout << "Element is " << minResult->Value << endl;
                cout << endl;
            }
            case 5:
            {
                TreeNode* maxResult = FindMax(binaryTree);
                cout << endl;
                cout << "Element is " << maxResult->Value << endl;
                cout << endl;
            }
            case 6:
            {
                int key = GetInput("Enter key to insert: ");
                AddTreap(treap, key);
                cout << endl;
                PrintTreap(treap);
                cout << endl;
                break;
            }
            case 7:
            {
                int key = GetInput("Enter key to insert: ");
                TreapNode* result = SearchTreap(treap, key);
                if (result != NULL)
                {
                    cout << endl;
                    cout << "Element is " << result->Key << ":" << result->Priority << endl;
                    cout << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Element not found " << endl;
                    cout << endl;
                }
                cout << endl;
                PrintTreap(treap);
                cout << endl;
                break;
            }
            case 8:
            {
                int key = GetInput("Enter key to remove: ");
                RemoveTreap(treap, key);
                cout << endl;
                PrintTreap(treap);
                cout << endl;
                break;
            }
            case 9:
            {
                int key = GetInput("Enter key to insert: ");
                AddTreapOptimized(treap, key);
                cout << endl;
                PrintTreap(treap);
                cout << endl;
                break;
            }
            case 10:
            {
                int key = GetInput("Enter key to remove: ");
                RemoveTreapOptimized(treap, key);
                cout << endl;
                PrintTreap(treap);
                cout << endl;
                break;
            }
            case 11:
            {
                TreapNode* left;
                TreapNode* right;
                int key = GetInput("Enter key to split: ");
                Split(treap->Root, key, left, right);
                cout << "Split treap" << endl;
                cout << "Left part" << endl;
                cout << endl;
                PrintRoots(left, 0);
                cout << "Right part" << endl;
                cout << endl;
                PrintRoots(right, 0);
                TreapNode* mergeTreapNodes = Merge(left, right);
                cout << endl;
                cout << "Merge treap" << endl;
                PrintRoots(mergeTreapNodes, 0);
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
    DeleteTree(binaryTree);
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
