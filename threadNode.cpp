//https://blog.csdn.net/out_of_memory_error/article/details/102332332?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.control
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>
using namespace std;

typedef int ElemType;

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

//单链表-----------------------------------开始

typedef struct SinglyLinkedList {
	ElemType data;
	struct SinglyLinkedList* next;
}SLnode, * pSLnode;

void InitSLnode(pSLnode p) {
	p->next = NULL;
}

//头插法
void CreateListByHead(pSLnode& head, int nums[], int n) {
	pSLnode s;
	head = (SLnode*)malloc(sizeof(SLnode));
	InitSLnode(head);

	for (int i = 0; i < n; i++) {

		s = (SLnode*)malloc(sizeof(SLnode));
		s->data = nums[i];
		s->next = head->next;
		head->next = s;
	}
}

//尾插法
void CreateListByTail(pSLnode& head, int nums[], int n) {
	

	pSLnode s, r;

	head = (SLnode*)malloc(sizeof(SLnode));
	InitSLnode(head);
	r = head;

	for (int i = 0; i < n; i++) {

		s = (SLnode*)malloc(sizeof(SLnode));
		s->data = nums[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

//遍历
void VisitSL(pSLnode head) {

	pSLnode p = head;

	while (p->next!=NULL)
	{
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}

//原地逆置



//单链表-----------------------------------结束

//-----------------------------顺序队列-----------------------------//

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
			 x = data[front+1];
			 return true;
		 }

		 int GetTopIndex() {
			 return rear;
		 }

		 int GetQueueSize() {
			 return Max_Size;
		 }

};

//-----------------------------顺序队列-----------------------------//

//-----------------------------链队列-----------------------------//

typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode;
typedef struct Queue {
	QNode* front;
	QNode* rear;
}Que, * pQue;

//-----------------------------链队列-----------------------------//


typedef struct threadNode {

	ElemType data;
	struct threadNode* left, * right;
	int ltag = 0, rtag = 0;
}tN, * tNp;


bool NullNode(ElemType in) {

	if (typeid(in) == typeid(int))
		return in == -1 ? true : false;
	if (typeid(in) == typeid(char))
		return in == '0' ? true : false;
	//if
	return true;
}
tNp CreateTree() {

	tNp p;
	ElemType in;
	cin >> in;

	//char类型输入注意判断空节点 
	if (NullNode(in))
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

//--------------------------二叉树遍历-----------------------------//
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

//--------------------------二叉树遍历-----------------------------//

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

	while (front < rear)
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
	return h;
}

//通过栈层次遍历并实现从下到上，右到左输出
void levelByStack(tNp p){

	Stack<tNp> s(10);
	SqQueue<tNp> qu(10);

	if (p) {

		qu.EnQueue(p);

		while (!qu.QueueIsEmpty())
		{
			qu.GetQueueTop(p);
			qu.DeQueue();

			s.Push(p);

			if (p->left)
				qu.EnQueue(p->left);
			if (p->right)
				qu.EnQueue(p->right);
		}

		while (!s.IsEmpty())
		{
			p = s.GetTop();
			s.Pop();
			cout << p->data << " ";
		}
	}
}

//判定是否为完全二叉树
bool IsCompleteBinaryTree(tNp p) {

	if (!p)
		return false;
	
	SqQueue<tNp> sq(10);
	sq.EnQueue(p);
	while (!sq.QueueIsEmpty())
	{
		sq.GetQueueTop(p);
		sq.DeQueue();

		if (p) {
			sq.EnQueue(p->left);
			sq.EnQueue(p->right);
		}
		else
		{
			while (!sq.QueueIsEmpty())
			{
				sq.GetQueueTop(p);
				sq.DeQueue();
				if (p)
					return false;
			}
		}
	}
	return true;
}

//将二叉树表示的后缀表达式转换为中缀表达式
void  ToInfixExpression(tNp p, int dep) {
	
	if (!p)
		return;
	else if (!p->left && !p->right)
		cout << " " << p->data << " ";
	else
	{	
		if (dep > 1)
			cout << "(";
		ToInfixExpression( p->left, dep + 1);
		cout << " " << p->data << " ";
		ToInfixExpression( p->right, dep + 1);
		if (dep > 1)
			cout << ")";
	}
}

//求二叉树的WPL：所有叶子结点的权重*深度之和
int WPL(tNp p,int dep) {
	
	static int wpl = 0;

	if (p->left == NULL && p->right == NULL)
		wpl = wpl + p->data * dep;
	if (p->left)
		WPL(p->left, dep + 1);
	if (p->right)
		WPL(p->right, dep + 1);
	return wpl;
}


//砍树
void DelNode(tNp p) {
	if (p) {
		DelNode(p->left);
		DelNode(p->right);
		free(p);
	}
}
//删去每个以target为根的叶子节点
void Delx(tNp p,int target) {

	if (p->data == target) {
		DelNode(p);
		exit(0);
	}
	SqQueue<tNp> s(20);
	s.EnQueue(p);

	while (!s.QueueIsEmpty())
	{
		s.GetQueueTop(p);
		s.DeQueue();

		if(p->left)
			if (p->left->data == target) {
				DelNode(p->left);
				p->left = NULL;
			}
			else
				s.EnQueue(p->left);
		if(p->right)
			if (p->right->data == target) {
				DelNode(p->right);
				p->right = NULL;
			}
			else
				s.EnQueue(p->right);

	}
}




void test(int*& p) {
	int a = 4;
	p = &a;
}

int main() {


	//单链表测试
	int nums[5] = { 1,2,3,4,5 };
	pSLnode head;

	//CreateListByHead(head, nums, 5);
	CreateListByTail(head, nums, 5);
	VisitSL(head);

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

	//19 10 5 3 1 -1 -1 2 -1 -1 2 -1 -1 5 -1 -1 9 -1 -1
	//* + a 0 0 b 0 0 * c 0 0 - 0 d 0 0

	//tNp p = NULL;
	//p = CreateTree();

	//StackToNLR(p);
	//cout << endl;
	//StackToLNR(p);
	//cout << endl;
	//StackToLRN(p);
	//cout << endl;

	//ToInfixExpression(p, 1);
	//cout << endl;
	//cout << WPL(p, 0) << endl;
	//
	//cout << getHeight(p) << endl;
	//Delx(p, 10);
	//cout << getHeight(p) << endl;


	//cout << getHeightbyRec(p) << endl;
	//cout << getHeight(p) << endl;
	//levelByStack(p);
	//cout << endl;


	//if (IsCompleteBinaryTree(p))
	//	cout << "yes" << endl;
	//else
	//	cout << "no" << endl;


	//SqQueue<int> q(10);
	//q.EnQueue(10);
	//q.EnQueue(1);
	//q.EnQueue(11);

	//if (q.QueueIsEmpty())
	//	cout << "null" << endl;
	//int x;
	//q.GetQueueTop(x);
	//q.DeQueue();
	//cout << x << endl;
	//cout << "::" << q.GetTopIndex() << endl;

	

	//NLR(p);
	//cout << endl;
	//LNR(p);
	//cout << endl;
	/*LRN(p);
	cout << endl;*/

	//CreateThreadtree(p);
	//inOrder(p);

}