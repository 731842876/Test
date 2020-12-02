#pragma once



#ifndef Common_Queue
#define Common_Queue

#include<iostream>
#include"Value.h"

/******************************************顺序队列和链队列开始******************************************/

template<class Type>
class SqQueue
{
private:
	Type* data;
	int Max_Size;
	int front, rear;
public:
	SqQueue(int Size_input) {
		data = new Type[Size_input];
		Max_Size = Size_input;
		front = rear = 0;
	}

	~SqQueue() {
		delete[]data;
		front = rear = 0;
	}

	bool QueueIsEmpty() {
		return front == rear ? true : false;
	}
	bool EnQueue(Type x) {
		if ((rear + 1) % Max_Size == front)
			return false;

		rear = (rear + 1) % Max_Size;
		data[rear] = x;

		return true;
	}

	bool DeQueue() {

		if (QueueIsEmpty())
			return false;
		front = (front + 1) % Max_Size;
		return true;
	}

	bool GetQueueTop(Type& x) {
		if (QueueIsEmpty())
			return false;
		x = data[front + 1];
		return true;
	}

	int GetTopIndex() {
		return rear;
	}

	int GetQueueSize() {
		return Max_Size;
	}

};

typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode;
typedef struct Queue {
	QNode* front;
	QNode* rear;
}Que, * pQue;

/******************************************顺序队列和链队列结束******************************************/
#endif // !Common_Queue
