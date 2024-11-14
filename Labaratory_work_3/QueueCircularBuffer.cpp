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
    PrintCircularBuffer(queueCircularBuffer->CircularBuffer);
}

void DeleteQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer)
{
    DeleteCircularBuffer(queueCircularBuffer->CircularBuffer);
    delete queueCircularBuffer;
}