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
	//将元素入栈
	bool Push(const Type& element) {
		if (top_Index >= max_Size - 1)
			return false;

		++top_Index;
		urls[top_Index] = element;
		return true;
	}

	//pop只用于弹出栈顶元素，不能返回栈顶元素，因为遇上cout右结合会破坏栈的先进后出。
	bool Pop() {
		if (top_Index < 0)
			return false;
		--top_Index;
		return true;
	}
	//获取栈顶元素 可选择配合pop将已获取的弹出
	Type GetTop() {
		if (top_Index < 0)
			exit(0);
		return urls[top_Index];
	}

	bool IsEmpty() {
		return top_Index == -1;
	}

	//获取栈已使用大小
	int Size() {
		if (top_Index = -1)
			return -1;
		return top_Index+1;
	}
	//获取栈顶元素下标
	int GetTop_Index() {
		return top_Index;
	}
};


#endif // !Common_Stack
