#include "CircularBuffer.h"
#include <iostream>
#include <stdexcept>

CircularBuffer* CreateCircularBuffer(int capacity)
{
    CircularBuffer* circularBuffer = new CircularBuffer;
    circularBuffer->Capacity = capacity;
    circularBuffer->Buffer = new int[circularBuffer->Capacity];
    circularBuffer->Read = 0;
    circularBuffer->Write = 0;
    circularBuffer->Size = 0;
    return circularBuffer;
}

void InitializationBuffer(CircularBuffer* circularBuffer, int size)
{
    circularBuffer->Size = size;
    for (int i = 0; i < circularBuffer->Size; i++)
    {
        circularBuffer->Buffer[i] = 0;
    }
}

void ResizeBuffer(CircularBuffer* circularBuffer, int newCapacity)
{
    circularBuffer->Capacity = newCapacity;
    int* newBuffer = new int[newCapacity];

    for (int i = 0; i < circularBuffer->Size; i++)
    {
        newBuffer[i] = circularBuffer->Buffer[i];
    }

    delete[] circularBuffer->Buffer;
    circularBuffer->Buffer = newBuffer;
}

int GetFreeSpace(CircularBuffer* circularBuffer)
{
    return circularBuffer->Capacity - circularBuffer->Size;
}

int GetOccupiedSpace(CircularBuffer* circularBuffer)
{
    return circularBuffer->Size;
}

void AddElement(CircularBuffer* circularBuffer, int value)
{
    if (GetFreeSpace(circularBuffer) == 0)
    {
        throw std::overflow_error("Кольцевой буфер заполнен");
    }

    if (circularBuffer->Write >= circularBuffer->Capacity)
    {
        circularBuffer->Write = 0;
    }

    circularBuffer->Buffer[circularBuffer->Write++] = value;
    ++circularBuffer->Size;
}

int GetElement(CircularBuffer* circularBuffer)
{
    if (circularBuffer->Size == 0)
    {
        throw std::overflow_error("Кольцевой буфер пустой");
    }

    if (circularBuffer->Read >= circularBuffer->Capacity)
    {
        circularBuffer->Read = 0;
    }

    int value = circularBuffer->Buffer[circularBuffer->Read++];
    --circularBuffer->Size;
    return value;
}

void DeleteBuffer(CircularBuffer* circularBuffer)
{
    delete[] circularBuffer->Buffer;
    delete circularBuffer;
}

void PrintCircularBuffer(CircularBuffer* circularBuffer)
{
    int index = circularBuffer->Read;

    for (int i = 0; i < circularBuffer->Size; i++)
    {
        std::cout << circularBuffer->Buffer[index] << " ";
        index = (index + 1) % circularBuffer->Capacity;
    }
    std::cout << std::endl;
}