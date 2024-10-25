// Struct_Of_Data_Labaratory0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

// 1.2
//i = 0, sum = 0
//i = 1, sum = 1,1
//i = 2, sum = 3,52
//i = 3, sum = 7,513
//i = 4, sum = 13,3694
//i = 5, sum = 21,42195
//i = 6, sum = 32,051316
//i = 7, sum = 45,6923357
//i = 8, sum = 62,84104618
//i = 9, sum = 84,062575399
void BreakpointsOfFirstTask()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        sum += add * i;
        add *= 1.1;
    }
    cout << "Total sum is " << sum << endl;
}
// 1.2
//i = 776, sum = 3,2624579394327844
void BreakpointsOfSecondTask()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 1000; i++)
    {
        sum += add * i; // Поставьте условную точку останова здесь
        if (i % 3 == 0)
        {
        add *= 1.1;
        }
        else
        {
        add /= 3.0;
        }
    }
    cout << "Total sum is " << sum << endl;
}

// 3.1
double GetPower(double base, int exponent)
{
    if (exponent < 0) 
    {
        base = 1.0 / base;
        exponent = -exponent; // Делаем степень положительной
    }

    double result = 1.0;
    for (int i = 0; i < exponent; ++i) 
    {
        result *= base; // Умножаем значение на base exponent раз
    }

    return result;
}

// 3.2
void DemoGetPower(double base, int exponent)
{
    if (exponent < 0)
    {
        base = 1.0 / base;
        exponent = -exponent; // Делаем степень положительной
    }

    double result = 1.0;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base; // Умножаем значение на base exponent раз
    }

    std::cout <<  base << "^"<< exponent<< "= " << result;
    std::cout << std::endl;
}

// 3.3
void RoundToTens(int& value)
{
    int remainder = value % 10;
    if (remainder < 5) 
    {
        value = (value / 10) * 10; // Округление вниз
    }
    else 
    {
        value = (value / 10 + 1) * 10; // Округление вверх
    }
}

// 4.4 и 4.5
void FooFirst(double a)
{
    cout << "Address of a in Foo(): " << &a << endl;
    cout << "Value of a in Foo(): " << a << endl;

    a = 15.0;
    cout << "New value of a in Foo(): " << a << endl;
}

// 4.7
void Foo(double* a)
{
    cout << "Address in pointer: " << a << endl;
    cout << "Address of pointer: " << &a << endl;
    cout << "Value in pointer address: " << *a << endl;

    * a = 15.0;
    cout << "New value in pointer address: " << *a << endl;
}

// 5.4
void Sort(double * arr, int size) 
{
    for (int i = 0; i < 9; i++) 
    {
    for (int j = 0; j < 9 - i; j++) 
    {
   	    if (arr[j] > arr[j+1]) 
            {
  			int temp = arr[j];
  			arr[j] = arr[j + 1];
  			arr[j + 1] = temp;
   		    }
   	    }
    }
}

// 5.5
int Search(int* arr, int s)
{
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] >= s)
        {
            k++;
        }
    }
    return k;
}

// 5.6
void Letters(char* arr) 
{
    for (int i = 0; i < 15; i++) 
    {
        if (arr[i] >= 'a' && arr[i] <= 'z') 
        {
            cout << arr[i] << " ";
        }
    }
}

// 5.7
int* MakeRandomArray(int arraySize)
{
    int* arr = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        arr[i] = rand() % 101; // numbers from 0 to 100
    }
    return arr;
}

void ShowArray(int* arr, int arraySize) 
{
    for (int i = 0; i < arraySize; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 5.8
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

// 6
struct Person
{
    string FirstName;
    string LastName;
    unsigned Age;
};

void WritePerson(const Person& person)
{
    cout << "First Name: " + person.FirstName
        + ";  Last Name: " + person.LastName
        + ";  Age: ";
    cout << person.Age << endl;
}
const int PeopleCount = 5;

Person** CreatePeopleArray()
{
    Person** people = new Person * [PeopleCount];
    people[0] = new Person();
    people[0]->FirstName = "Casey";
    people[0]->LastName = "Aguilar";
    people[0]->Age = 30;

    people[1] = new Person();
    people[1]->FirstName = "Brock";
    people[1]->LastName = "Curtis";
    people[1]->Age = 19;

    people[2] = new Person();
    people[2]->FirstName = "Blake";
    people[2]->LastName = "Diaz";
    people[2]->Age = 21;

    people[3] = new Person();
    people[3]->FirstName = "Cristian";
    people[3]->LastName = "Evans";
    people[3]->Age = 55;

    people[4] = new Person();
    people[4]->FirstName = "Les";
    people[4]->LastName = "Foss";
    people[4]->Age = 4;

    return people;
}


void ClearPerson(Person* person)
{
    delete person;
}

void ClearPeople(Person** people, int itemsCount)
{
    for (int i = 0; i < itemsCount; i++)
    {
        ClearPerson(people[i]);
    }
    delete[] people;
}

void Task1_FindPersonByLastName()
{
    Person * *people = CreatePeopleArray();
    for (int i = 0; i < PeopleCount; i++)
    {
        WritePerson(*people[i]);
    }

    std::string lastName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    int foundIndex = -1;

    for (int i = 0; i < PeopleCount; i++)
    {
        if (people[i]->LastName == lastName)
        {
            foundIndex = i;
            break; // Выходим из цикла после нахождения
        }
    }

    if (foundIndex == -1)
    {
        std::cout << "Could not find a person by last name: " << lastName << std::endl;
    }
    else
    {
        std::cout << "A person's last name "
        << lastName
        << " was found. Its index in the array is "
        << foundIndex
        << std::endl;
    }

    ClearPeople(people, PeopleCount);
}


int main()
{
    //// 2.1
    //int arrayOfInt[] = { 78, -9, 456, -34, 0, 12, 555, -678, 123, -1 };

    //std::cout << "Unsorted array: ";
    //for (int i = 0; i < 10; i++) 
    //{
    //    std::cout << arrayOfInt[i] << " ";
    //}
    //std::cout << std::endl;


    //for (int i = 0; i < 9; i++) 
    //{
    //    for (int j = 0; j < 9 - i; j++) 
    //    {
    //        if (arrayOfInt[j] > arrayOfInt[j + 1]) 
    //        {
    //            int temp = arrayOfInt[j];
    //            arrayOfInt[j] = arrayOfInt[j + 1];
    //            arrayOfInt[j + 1] = temp;
    //        }
    //    }
    //}

    //std::cout << "Sorted array: ";
    //for (int i = 0; i < 10; i++) 
    //{
    //    std::cout << arrayOfInt[i] << " ";
    //}
    //std::cout << std::endl;

    //// 2.2
    //double arrayOfDouble[12] = { 3.14, 2.71, 1.62, 0.57, 4.20, 6.66, 9.81, 1.41, 2.81, 5.12, 7.22, 8.33 };

    //std::cout << "Array of double: ";
    //for (int i = 0; i < 12; i++) 
    //{
    //    std::cout << arrayOfDouble[i] << " ";
    //}
    //std::cout << std::endl;

    //double searchingValue;
    //std::cout << "Enter value for searchingValue: ";
    //std::cin >> searchingValue;

    //int countOfArray = 0;
    //for (int i = 0; i < 12; i++) 
    //{
    //    if (arrayOfDouble[i] >= searchingValue) 
    //    {
    //        countOfArray++;
    //    }
    //}

    //std::cout << "Number of elements greater than or equal to " << searchingValue << ": " << countOfArray << std::endl;

    //// 2.3
    //char charArray[8];

    //std::cout << "Enter 8 of symbols: ";
    //for (int i = 0; i < 8; i++) 
    //{
    //    std::cin >> charArray[i];
    //}

    //std::cout << "Array: ";
    //for (int i = 0; i < 8; i++) 
    //{
    //    std::cout << charArray[i] << " ";
    //}
    //std::cout << std::endl;

    //std::cout << "Letters of 'a' to 'z' in array: ";
    //for (int i = 0; i < 8; i++) 
    //{
    //    if (islower(charArray[i]) | isupper(charArray[i])) 
    //    { 
    //        std::cout << charArray[i] << " ";
    //    }
    //}
    //std::cout << std::endl;

    //// 3.1
   

    //std::cout << "Result: " << GetPower(base, exponent);
    //std::cout << std::endl;

    // 3.2
    /*for (int i = 0; i < 3; i++)
    {
        double base;
        std::cout << "Enter number: ";
        std::cin >> base;

        int exponent;
        std::cout << "Enter exponent for number: ";
        std::cin >> exponent;

        DemoGetPower(base, exponent);
    }*/
   

    //// 3.3
    //int f;
    //int testValues[] = { 12, 187, 27, 85, 46, 99 };

    //for (int value : testValues)
    //{
    //    f = value;
    //    std::cout << "Исходное значение: " << f << std::endl;

    //    RoundToTens(f);
    //    std::cout << "Округленное значение: " << f << std::endl << std::endl;
    //}

    //// 4.1
    //int a = 5;
    //int b = 4;
    //cout << "Address of a: " << &a << endl;
    //cout << "Address of b: " << &b << endl;
    //
    //double c = 13.5;
    //cout << "Address of c: " << &c << endl;
 
    //bool d = true;
    //cout << "Address of d: " << &d << endl;

    //// 4.2
    //int g[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
    //cout << "Size of int type: " << sizeof(int) << endl;

    //for (int i = 0; i < 10; i++)
    //{
    //    cout << "Address of g[" << i << "]: " << &g[i] << endl;
    //}

    //cout << endl;
    //cout << "Size of double type: " << sizeof(double) << endl;
    //double j[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
    //for (int i = 0; i < 10; i++)
    //{
    //    cout << "Address of j[" << i << "]: " << &j[i] << endl;
    //}

    //// 4.3
    /*int n = 5;
    int& m = n;

    cout << "Address of n: " << &n << endl;
    cout << "Address of n: " << &m << endl;


    cout << endl;
    m = 7;
    cout << "Value of n: " << n << endl;*/

    //// 4.4
    //double q = 5.0;
    //cout << "Address of q in main(): " << &q << endl;
    //cout << "Value of q in main(): " << q << endl;
    //cout << endl;
   
    //FooFirst(q);

    //cout << endl;
    //cout << "Value of q in main(): " << q << endl;

    //// 4.5
    //double y = 5.0;
    //cout << "Address of y in main(): " << &y << endl;
    //cout << "Value of y in main(): " << y << endl;
    //cout << endl;
   
    //FooFirst(y);

    //cout << endl;
    //cout << "Value of y in main(): " << y << endl;

    //// 4.6
    //int i = 5;
    //int* newPointer = &i;

    //cout << "Address of i: " << &i << endl;
    //cout << "Address in newPointer: " << newPointer << endl;
    //cout << "Address of newPointer: " << &newPointer << endl;

    //cout << endl;
    //*newPointer = 7;
    //cout << "Value in i: " << a << endl;
    //cout << "Value by newPointer address: " << *newPointer << endl;

    //// 4.7
    //double value = 5.0;
    //double* pointer = &value;
    //cout << "Address of value in main(): " << &value << endl;
    //cout << "Address in pointer in main(): " << pointer << endl;
    //cout << "Address of pointer in main(): " << &pointer << endl;
    //cout << "Value of a in main(): " << value << endl;
    //cout << endl;

    //Foo(pointer);

    //cout << endl;
    //cout << "Value of a in main(): " << value << endl;

    //// 5.1
    //double* newArrayDouble = new double[8];
    //newArrayDouble[0] = 1.0;
    //newArrayDouble[1] = 15.0;
    //newArrayDouble[2] = -8.2;
    //newArrayDouble[3] = -3.5;
    //newArrayDouble[4] = 12.6;
    //newArrayDouble[5] = 38.4;
    //newArrayDouble[6] = -0.5;
    //newArrayDouble[7] = 4.5;
    //
    //cout << "Array of double:" << endl;
    //for (int i = 0; i < 8; i++) 
    //{
    //      cout << newArrayDouble[i] << " ";
    //}
    //cout << endl;

    //delete[] newArrayDouble;
    //
    //// 5.2
    //bool* arrayOfBool = new bool[8];
    //arrayOfBool[0] = true;
    //arrayOfBool[1] = false;
    //arrayOfBool[2] = true;
    //arrayOfBool[3] = true;
    //arrayOfBool[4] = false;
    //arrayOfBool[5] = true;
    //arrayOfBool[6] = false;
    //arrayOfBool[7] = false;

    //cout << "Array of bool:" << endl;
    //for (int i = 0; i < 8; i++) 
    //{
    //cout << boolalpha <<arrayOfBool[i] << " "; // ?
    //}
    //cout << endl;

    //delete[] arrayOfBool;

    //// 5.3
    //int p; cout << "enter n: "; cin >> p;
    //char* arrayOfChar = new char[p];
    //cout << "enter " << p << " characters: " << endl;
    //for (int i = 0; i < p; i++) 
    //{
    //	cin >> arrayOfChar[i];
    //}

    //cout << "array of characters: ";
    //for (int i = 0; i < p; i++) 
    //{
    //		cout << arrayOfChar [i] << " ";
    //}
    //delete[] arrayOfChar; 

    // 5.4
    //double* arrayOfDoublesForSort = new double[10];

    //arrayOfDoublesForSort[0] = 1.0;
    //arrayOfDoublesForSort[1] = 15.0;
    //arrayOfDoublesForSort[2] = -8.2;
    //arrayOfDoublesForSort[3] = -3.5;
    //arrayOfDoublesForSort[4] = 12.6;
    //arrayOfDoublesForSort[5] = 38.4;
    //arrayOfDoublesForSort[6] = -0.5;
    //arrayOfDoublesForSort[7] = 4.5;
    //arrayOfDoublesForSort[8] = 39.8;
    //arrayOfDoublesForSort[9] = -6.5;

    //cout << "Array of double:" << endl;
    //for (int i = 0; i < 10; i++)
    //{
    //    cout << arrayOfDoublesForSort[i] << " ";
    //}

    //cout << endl;
    //cout << "Sorted array: ";
    //Sort(arrayOfDoublesForSort, 10);
    //for (int i = 0; i < 10; i++) 
    //{
    //    cout << arrayOfDoublesForSort[i] << " ";
    //}

    //delete[] arrayOfDoublesForSort;

    //// 5.5
    //int* newArrayOfInt = new int[10];
    //newArrayOfInt[0] = 1;
    //newArrayOfInt[1] = 15;
    //newArrayOfInt[2] = -8;
    //newArrayOfInt[3] = -3;
    //newArrayOfInt[4] = 12;
    //newArrayOfInt[5] = 38;
    //newArrayOfInt[6] = 0;
    //newArrayOfInt[7] = 4;
    //newArrayOfInt[8] = 39;
    //newArrayOfInt[9] = -6;

    //cout << "Enter searching value: "; int s; cin >> s;
    //int k = Search(newArrayOfInt, s);
    //cout << k;
    //delete[] newArrayOfInt;

    //// 5.6
    //char* newArrayOfChar = new char[15];
    //newArrayOfChar[0] = 'd';
    //newArrayOfChar[1] = 'u';
    //newArrayOfChar[2] = 'f';
    //newArrayOfChar[3] = 'a';
    //newArrayOfChar[4] = '9';
    //newArrayOfChar[5] = '4';
    //newArrayOfChar[6] = ';';
    //newArrayOfChar[7] = 't';
    //newArrayOfChar[8] = 'e';
    //newArrayOfChar[9] = 'w';
    //newArrayOfChar[10] = '[';
    //newArrayOfChar[11] = '6';
    //newArrayOfChar[12] = '2';
    //newArrayOfChar[13] = '5';
    //newArrayOfChar[14] = '1';
    //cout << "your array: " << endl;
    //for (int i = 0; i < 15; i++) 
    //{
    //		cout << newArrayOfChar[i] << " ";
    //}
    //cout << endl << "letters in the array: " << endl;
    //Letters(newArrayOfChar);
    //delete[]newArrayOfChar;

    //// 5.7
    //srand(time(0));
    //int* arr5 = MakeRandomArray(5);
    //int* arr8 = MakeRandomArray(8);
    //int* arr13 = MakeRandomArray(13);
    //
    //cout << "Random array of 5: ";
    //ShowArray(arr5, 5);

    //cout << "Random array of 8: ";
    //ShowArray(arr8, 8);

    //cout << "Random array of 13: ";
    //ShowArray(arr13, 13);

    //delete[] arr5;
    //delete[] arr8;
    //delete[] arr13;

    //// 6
    //Task1_FindPersonByLastName();

    //// 5.8
    //int count = 15;
    //int* values = ReadArray(count);
    //std::cout << "Count is: " << CountPositiveValues(values, count) << std::endl;
    //delete[] values; // we need to clear the heap 2 times

    //count = 20;
    //values = ReadArray(count);
    //std::cout << "Count is: " << CountPositiveValues(values, count) << std::endl;
    //delete[] values;

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
