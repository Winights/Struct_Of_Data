#include "QueueCircularBuffer.h"
#include "CircularBuffer.h"
#include <iostream>

QueueCircularBuffer* CreateQueueCircularBuffer(int capacity)
{
    QueueCircularBuffer* queueCircularBuffer = new QueueCircularBuffer;
    queueCircularBuffer->CircularBuffer = CreateCircularBuffer(capacity);
    return queueCircularBuffer;
}

void Enqueue(QueueCircularBuffer* queueCircularBuffer, int value)
{
    AddElement(queueCircularBuffer->CircularBuffer, value);;
}

int Dequeue(QueueCircularBuffer* queueCircularBuffer)
{
    return GetElement(queueCircularBuffer->CircularBuffer);
}

void ResizeQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int newCapacity)
{
    ResizeBuffer(queueCircularBuffer->CircularBuffer, newCapacity);
}

void PrintQueue(QueueCircularBuffer* queueCircularBuffer)
{
    int index = queueCircularBuffer->CircularBuffer->Read;
    for (int i = 0; i < queueCircularBuffer->CircularBuffer->Size; i++) 
    {
        std::cout << queueCircularBuffer->CircularBuffer->Buffer[index] << " ";
        index = (index + 1) % queueCircularBuffer->CircularBuffer->Capacity;
    }
    std::cout << std::endl;
}

void DeleteBuffer(QueueCircularBuffer* queueCircularBuffer)
{
    delete[] queueCircularBuffer->CircularBuffer->Buffer;
    delete queueCircularBuffer->CircularBuffer;
    delete queueCircularBuffer;
}