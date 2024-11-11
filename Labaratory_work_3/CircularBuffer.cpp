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
        circularBuffer->Write = 0;
        circularBuffer->Size = 0;
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

    return value;
}

void DeleteBuffer(CircularBuffer* circularBuffer)
{
    delete[] circularBuffer->Buffer;
    delete circularBuffer;
}

void PrintCircularBuffer(CircularBuffer* circularBuffer)
{
    for (int i = 0; i < circularBuffer->Size; i++)
    {
        std::cout << circularBuffer->Buffer[i] << " ";
    }
    std::cout << std::endl;
}