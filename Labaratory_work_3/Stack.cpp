#include "Stack.h""
#include <iostream>
#include <stdexcept>

Stack* CreateStack(int size) 
{
    Stack* stack = new Stack;  
    stack->BufferSize = size;
    stack->Buffer = new int[stack->BufferSize];
    stack->Count = 0;
    stack->Top = -1;                
    return stack;
}

//void InitializationStack(Stack* stack, int size)
//{
//    stack->BufferSize = size;
//    for (int i = stack->BufferSize; i > -1; i--)
//    {
//        stack->Buffer[i] = 0;
//    }
//}

void ResizeStack(Stack* stack, int newSize)
{
    stack->BufferSize = newSize;
    int* newBuffer = new int[newSize];

    for (int i = stack->BufferSize - 1; i > -1; i--)
    {
        newBuffer[i] = stack->Buffer[i];
    }

    delete[] stack->Buffer;
    stack->Buffer = newBuffer;
}

void Push(Stack* stack, int data) 
{
    if (stack->Top >= stack->BufferSize)
    {
        throw std::overflow_error("Стек переполнен");
    }
    stack->Buffer[++stack->Top] = data;
    ++stack->Count;
}


void Pop(Stack* stack) 
{
    if (IsEmpty(stack))
    {
        throw std::underflow_error("Стек пуст"); 
    }
    stack->Buffer[stack->Top--] = 0; 
    --stack->Count;
}


bool IsEmpty(Stack* stack) 
{
    return stack->Top < 0; 
}


void Delete(Stack* stack) 
{
    delete[] stack->Buffer; 
    delete stack;           
}

void PrintStack(Stack* stack)
{
	for (int i = stack->Count-1; i > -1 ; i--)
	{
		std::cout << stack->Buffer[i] << "\n" << std::endl;
	}
}