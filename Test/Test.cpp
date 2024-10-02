// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

int* ReadArray(int count) 
{
    int* values = new int[count];
    for (int i = 0; i < count; i++) 
    {
        std::cin >> values[i];
    }
    return values;
}

int CountPositiveValues(int* values, int count) 
{
    int result = 0;
    for (int i = 0; i < count; i++) 
    {
        if (values[i] > 0) 
        {
            result++;
        }
    }
       return result;
}

int main() 
{
    int count = 15;
    int* values = ReadArray(count);
    std::cout << "Count is: " << CountPositiveValues(values, count) << std::endl;
    delete[] values; // we need to clear the heap 2 times

    count = 20;
    values = ReadArray(count);
    std::cout << "Count is: " << CountPositiveValues(values, count) << std::endl;
    delete[] values; 

    return 0;
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
