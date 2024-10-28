#include "DynamicArray.h"
#include <string>
#include <iostream>

using namespace std;

DynamicArray* CreateDynamicArray()
{
	DynamicArray* dynamicArray = new DynamicArray;

	dynamicArray->Size = 0;
	dynamicArray->Capacity = originalCapacity;
	dynamicArray->Array = new int[dynamicArray->Capacity];

	return dynamicArray;
}

void InitializationDynamicArray(DynamicArray* array)
{
	srand(time(0));

	array->Size = 3;

	for (int i = 0; i < array->Size; i++)
	{
		array->Array[i] = rand() % 21;
	}
}

void ResizeArray(DynamicArray* array, int capacity)
{
	int* newDynamicArray = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		newDynamicArray[i] = array->Array[i];
	}

	delete[] array->Array;
	array->Array = newDynamicArray;
}

bool CheckRange(DynamicArray* array, int index)
{
	if (index < 0 && index > array->Size)
	{
		cout << "Index out of range.\n";
		return false;
	}
	return true;
}

void AddElement(DynamicArray* array, int index, int value)
{
	bool flagCheckRange = CheckRange(array, index);

	if (flagCheckRange == false)
	{
		cout << "Index out of range. Reenter index.\n";
		return;
	}

	if (array->Size >= array->Capacity)
	{
		ResizeArray(array, array->Capacity * growthFactor);
	}

	for (int i = array->Size; i > index; i--)
	{
		array->Array[i] = array->Array[i - 1];
	}

	array->Array[index] = value;
	array->Size++;
}

void RemoveByIndex(DynamicArray* array, int index)
{
	bool flagCheckRange = CheckRange(array, index);
	if (flagCheckRange == false)
	{
		cout << "Index out of range. Reenter index.\n";
		return;
	}

	for (int i = index; i < array->Size - 1; i++)
	{
		array->Array[i] = array->Array[i + 1];
	}

	array->Size--;

	if (array->Size < array->Capacity / growthFactor)
	{
		ResizeArray(array, array->Capacity / growthFactor);
	}
}

void RemoveByValue(DynamicArray* array, int value)
{
	for (int i = 0; i < array->Size; ++i)
	{
		// Если найден элемент, который нужно удалить
		if (array->Array[i] == value)
		{
			// Сдвигаем все элементы влево
			for (int j = i; j < array->Size - 1; ++j)
			{
				array->Array[j] = array->Array[j + 1];
			}
			// Уменьшаем размер массива
			array->Size--;
			// Уменьшаем индекс, чтобы не пропустить следующий элемент
			i--;
		}
	}
	if (array->Size < array->Capacity / growthFactor)
	{
		ResizeArray(array, array->Capacity / growthFactor);
	}
	else
	{
		cout << "Element not found in array.\n";
	}
}

void SortArray(DynamicArray* array)
{
	int temp = 0;
	for (int i = 0; i < array->Size-1; i++)
	{
		for (int j = 0; j < array->Size-i-1; j++)
		{
			if (array->Array[j] > array->Array[j+1])
			{
				temp = array->Array[j];
				array->Array[j] = array->Array[j+1];
				array->Array[j+1] = temp;
			}
		}
	}
}

void LinerSearch(DynamicArray* array, int value)
{
	bool flag = false;
	for (int i = 0; i < array->Size; i++)
	{
		if (array->Array[i] == value)
		{
			flag = true;
			cout << "Needed element is at the index : " << i << "\n" << endl;
		}
	}
	if (flag == false)
	{
		cout << "Element not found.\n";
	}
}

void BinarySearch(DynamicArray* array, int value)
{
	SortArray(array);
	int left = 0;
	int right = array->Size - 1;
	bool flag = false;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (array->Array[middle] == value)
		{
			cout << "Needed element is at the index: " << middle << "\n" << endl;
			flag = true;
			break;
		}
		else if (value < array->Array[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	if (flag == false)
	{
		cout << "Element not found.\n";
	}
}

void PrintArray(DynamicArray* array)
{
	for (int i = 0; i < array->Size; i++)
	{
		cout << array->Array[i] << " ";
	}
	cout << endl;
}


void FreeArray(DynamicArray* array)
{
	delete[] array->Array;
	delete array;
}