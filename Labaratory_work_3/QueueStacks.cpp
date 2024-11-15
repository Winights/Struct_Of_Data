#include "QueueStacks.h"
#include <iostream>

QueueStacks* CreateQueueStacks(int capacity)
{
    QueueStacks* queueStacks = new QueueStacks;
    queueStacks->TopStack = CreateStack(capacity);
    queueStacks->TailStack = CreateStack(capacity);
    return queueStacks;
}

void InitializationQueueStacks(QueueStacks* queueStacks, int size)
{
    InitializationStack(queueStacks->TopStack, size);
}

int IsFull(Stack* stack)
{
    return stack->BufferSize - stack->Count;
}

void EnqueueQueueStacks(QueueStacks* queueStacks, int value)
{
    if (IsFull(queueStacks->TopStack) == 0)
    {
        std::cout << std::endl;
        std::cout << "Queue is filled" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        Push(queueStacks->TopStack, value);
    }
}

int DequeueQueueStacks(QueueStacks* queueStacks)
{
    if (!IsEmpty(queueStacks->TailStack))
    {
       return Pop(queueStacks->TailStack);
    }

    while (!IsEmpty(queueStacks->TopStack))
    {
        Push(queueStacks->TailStack, Pop(queueStacks->TopStack));
    }

    return Pop(queueStacks->TailStack);
}

void ResizeQueueStacks(QueueStacks* queueStacks, int newCapacity)
{
    ResizeStack(queueStacks->TopStack, newCapacity);
    ResizeStack(queueStacks->TailStack, newCapacity);
}

void PrintQueueStacks(QueueStacks* queueStacks)
{
    Stack* tempStack = CreateStack(queueStacks->TailStack->BufferSize);
    int index = 0;

    for (int i = queueStacks->TailStack->Count - 1; i > -1; i--)
    {
        tempStack->Buffer[index] = queueStacks->TailStack->Buffer[i];
        index++;
        tempStack->Count++;
    }

    for (int i = 0; i < queueStacks->TopStack->Count; i++)
    {
        tempStack->Buffer[index] = queueStacks->TopStack->Buffer[i];
        index++;
        tempStack->Count++;
    }

    for (int j = 0; j < tempStack->Count; j++)
    {
        std::cout << tempStack->Buffer[j] << " ";
    }
    std::cout << std::endl;
    
}

void DeleteQueueStacks(QueueStacks* queueStacks)
{
    DeleteStack(queueStacks->TopStack);
    DeleteStack(queueStacks->TailStack);
    delete queueStacks;
}