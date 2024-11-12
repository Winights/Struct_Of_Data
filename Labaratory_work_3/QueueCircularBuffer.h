#pragma once
#include "CircularBuffer.h"

/// <summary>
/// ��������� ������� ����� ��������� �����.
/// </summary>
struct QueueCircularBuffer
{
	/// <summary>
	/// ��������� �����.
	/// </summary>
	CircularBuffer* CircularBuffer;
};

/// <summary>
/// �������� �������.
/// </summary>
/// <returns>��������� �������</returns>
QueueCircularBuffer* CreateQueueCircularBuffer(int capacity);

/// <summary>
/// ���������� �������� � �������.
/// </summary>
void Enqueue(QueueCircularBuffer* queueCircularBuffer, int value);

/// <summary>
/// ��������� �������� �� �������.
/// </summary>
/// <returns>������� �� �������</returns>
int Dequeue(QueueCircularBuffer* queueCircularBuffer);

/// <summary>
/// ��������� ����������� �������.
/// </summary>
void ResizeQueueCircularBuffer(QueueCircularBuffer* queueCircularBuffer, int newCapacity);

/// <summary>
/// ����� �������.
/// </summary>
void PrintQueue(QueueCircularBuffer* queueCircularBuffer);

/// <summary>
/// �������� �������.
/// </summary>
void DeleteBuffer(QueueCircularBuffer* queueCircularBuffer);


