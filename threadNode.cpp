#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>
using namespace std;

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

		Type GetTop() {
			if (top_Index < 0)
				exit(0);
			return urls[top_Index];
		}

		bool IsEmpty() {
			if (top_Index == -1)
				return true;
			return false;
		}

		int Size() {
			return max_Size;
		}

		int GetTop_Index() {
			return top_Index;
		}
};


class String
{
	private:
		char* data;
		int length;
	
	public:
		String(const char* str = NULL) {
			
			if (str) {
				length = strlen(str);
				data = new char[length + 1];
				strcpy(data, str);
			}
			else
			{
				length = 0;
				data = new char[1];
				*data = '\0';
			}
		}
		

		/*String(const String& str) {
			length = str.size();
			data = new char[length + 1];
			strcpy(data, str);
		}*/



		~String() {
			delete[]data;
			length = 0;
		}

		//与调用形参匹配const String& str
		size_t size() const {
			return length;
		}
		
		
};




typedef int ElemType;
typedef struct threadNode{

	ElemType data;
	struct threadNode* left, * right;
	int ltag = 0, rtag = 0;
}tN,*tNp;

tNp CreateTree() {

	tNp p;
	ElemType in;
	cin >> in;

	if (in == -1)
		p = NULL;
	else
	{
		//p = (threadNode*)malloc(sizeof(threadNode));
		//不能使用malloc一块空间将会丢失ltag和rtag的初始值。
		p = new tN;
		p->data = in;
		p->left = CreateTree();
		p->right = CreateTree();
	}
	return p;
}

void NLR(threadNode *p) {

	if (p) {
		cout << p->data << " ";
		NLR(p->left);
		NLR(p->right);
	}
}

void LNR(threadNode* p) {

	if (p) {
		LNR(p->left);
		cout << p->data << " ";
		LNR(p->right);
	}
}

void LRN(threadNode* p) {
	if (p) {
		LRN(p->left);
		LRN(p->right);
		cout << p->data << " ";
	}
}


void StackToNLR(tNp p) {

	Stack<tNp> s(10);
	tNp t = p;

	while (p || !s.IsEmpty())
	{
		if (p) {
			cout << p->data << " ";
			s.Push(p);
			p = p->left;
		}
		else
		{
			p = s.GetTop();
			s.Pop();
			p = p->right;
		}
	}

	
}
void StackToLNR(tNp p) {
	Stack<tNp> s(10);
	tNp t = p;

	while (p || !s.IsEmpty())
	{
		if (p) {
			s.Push(p);
			p = p->left;
		}
		else
		{
			p = s.GetTop();
			cout << p->data << " ";
			s.Pop();
			p = p->right;
		}
	}
}
void StackToLRN(tNp p) {

	Stack<tNp> s(10);
	tNp t = p, r = NULL;

	while (p||!s.IsEmpty())
	{
		if (p) {
			s.Push(p);
			p = p->left;
		}
		else
		{
			p = s.GetTop();
			if (p->right && p->right != r) {
				p = p->right;
				s.Push(p);
				p = p->left;
			}
			else
			{
				cout << p->data << " ";
				s.Pop();
				r = p;
				p = NULL;
			}
		}
	}
}

void InThread(tNp &p,tNp &pre) {
	
	if (p) {		
		InThread(p->left,pre);

		if (p->left == NULL) {
			p->left = pre;
			p->ltag = 1;
		}

		if (pre != NULL && pre->right == NULL) {
			pre->right = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->right,pre);
	}
}

void CreateThreadtree(tNp T) {

	tNp pre = NULL;
	if (T) {
		InThread(T, pre);
		pre->right = NULL;
		pre->rtag = 1;
	}
	
}

tNp firstNode(tNp p) {

	while (p->ltag == 0) 
		p = p->left;
	return p;
}

tNp nextNode(tNp p) {

	if (p->rtag == 0)
		return firstNode(p->right);
	else
		return p->right;
}

void inOrder(tNp t) {
	for (tNp tmp = firstNode(t); tmp != NULL; tmp = nextNode(tmp))
		cout << tmp->data << " ";
	cout << endl;
}

//递归求树高
int getHeightbyRec(tNp p) {
	int h = 0;
	if (p) {
		int l, r;
		l = getHeightbyRec(p->left);
		r = getHeightbyRec(p->right);
		if (l > r)
			return h = l + 1;
		else
			return h = r + 1;
	}
	return h;
}

//非递归通过层次遍历求树高
int getHeight(tNp p) {

	if (!p)	return 0;

	int front = -1, rear = -1;
	int last = 0, h = 0;
	tNp Q[100];

	Q[++rear] = p;
	tNp t;

	while (front<rear)
	{
		t = Q[++front];

		if (t->left)
			Q[++rear] = t->left;
		if (t->right)
			Q[++rear] = t->right;

		if (front == last) {
			h++;
			last = rear;
		}

	}

}
void test(int*& p) {
	int a = 4;
	p = &a;
}


int main() {



	//栈测试
	/*string in;
	int size = 4;
	Stack<string> s(size);
	while (cin>>in&&size!=0)
	{
		size--;

		if (s.Push(in))
			cout << "Ok!" << endl;
		else
			cout << "fail!" << endl;	
			
	}
	
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;

	if (s.IsEmpty())
		cout << "is empty" << endl;
	else
		cout << " not empty" << endl;

	cout << s.GetTop() << endl;*/


	//二叉树遍历
	//3 4 -1 6 -1 -1 2 5 -1 -1 7 -1 -1
	//1 2 -1 4 6 -1 -1 -1 3 -1 5 -1 -1
	//6 2 1 -1 -1 4 3 -1 -1 -1 8 -1 -1
	//1 2 -1 -1 3 -1 -1

	tNp p = NULL;
	p = CreateTree();

	StackToNLR(p);
	cout << endl;
	StackToLNR(p);
	cout << endl;
	StackToLRN(p);
	cout << endl;
	cout << getHeightbyRec(p) << endl;
	


	//NLR(p);
	//cout << endl;
	//LNR(p);
	//cout << endl;
	/*LRN(p);
	cout << endl;*/

	//CreateThreadtree(p);
	//inOrder(p);
	
	

}