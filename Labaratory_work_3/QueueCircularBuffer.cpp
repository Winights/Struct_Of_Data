#include "QueueCircularBuffer.h"
#include "CircularBuffer.h"
#include <iostream>

QueueCircularBuffer* CreateQueueCircularBuffer(int capacity)
{
    QueueCircularBuffer* queueCircularBuffer = new QueueCircularBuffer;
    queueCircularBuffer->CircularBuffer = CreateCircularBuffer(capacity);
    return queueCircularBuffer;
}

void EnqueueQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int value)
{
    Enqueue(queueCircularBuffer->CircularBuffer, value);;
}

int DequeueQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer)
{
    return Dequeue(queueCircularBuffer->CircularBuffer);
}

void ResizeQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int newCapacity)
{
    ResizeCircularBuffer(queueCircularBuffer->CircularBuffer, newCapacity);
}

void PrintQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer)
{
    int index = queueCircularBuffer->CircularBuffer->Read;
    for (int i = 0; i < queueCircularBuffer->CircularBuffer->Size; i++) 
    {
        std::cout << queueCircularBuffer->CircularBuffer->Buffer[index] << " ";
        index = (index + 1) % queueCircularBuffer->CircularBuffer->Capacity;
    }
    std::cout << std::endl;
}

void DeleteQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer)
{
    DeleteCircularBuffer(queueCircularBuffer->CircularBuffer);
    delete queueCircularBuffer;
}