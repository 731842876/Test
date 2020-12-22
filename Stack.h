#pragma

#ifndef Common_Stack

#define Common_Stack

#include<iostream>

template<class Type>
class Stack
{
private:
	Type* urls;
	int max_Size, top_Index;

public:
	Stack(int Size_input) {
		urls = new Type[Size_input];
		max_Size = Size_input;
		top_Index = -1;
	}

	~Stack() {
		delete[]urls;
	}
	//��Ԫ����ջ
	bool Push(const Type& element) {
		if (top_Index >= max_Size - 1)
			return false;

		++top_Index;
		urls[top_Index] = element;
		return true;
	}

	//popֻ���ڵ���ջ��Ԫ�أ����ܷ���ջ��Ԫ�أ���Ϊ����cout�ҽ�ϻ��ƻ�ջ���Ƚ������
	bool Pop() {
		if (top_Index < 0)
			return false;
		--top_Index;
		return true;
	}
	//��ȡջ��Ԫ�� ��ѡ�����pop���ѻ�ȡ�ĵ���
	Type GetTop() {
		if (top_Index < 0)
			exit(0);
		return urls[top_Index];
	}

	bool IsEmpty() {
		return top_Index == -1;
	}

	//��ȡջ��ʹ�ô�С
	int Size() {
		if (top_Index = -1)
			return -1;
		return top_Index+1;
	}
	//��ȡջ��Ԫ���±�
	int GetTop_Index() {
		return top_Index;
	}
};


#endif // !Common_Stack
