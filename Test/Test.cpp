// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Node {
public:
    double data;
    Node* prev, * next;

public:
    Node(double data) {
        this->data = data;
        this->prev = this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head, * tail;

public:
    LinkedList() {
        this->head = this->tail = NULL;
    }
    Node* push_back(double data)
    {
        Node* ptr = new Node(data);

        ptr->prev = tail;
        if (tail != NULL)
            tail->next = ptr;
        if (head == NULL)
            head = ptr;
        tail = ptr;

        return ptr;
    }
};



int main() 
{
    LinkedList list;
    list.push_back(3);
    list.push_back(3);
    list.push_back(3);

    for (Node* ptr = list.head; ptr != NULL; ptr = ptr->next)
        std::cout << ptr->data << " ";
    std::cout << std::endl;

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
