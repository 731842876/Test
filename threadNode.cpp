//https://blog.csdn.net/out_of_memory_error/article/details/102332332?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.control
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>
using namespace std;

#define MaxSize 100
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
		//popֻ���ڵ���ջ��Ԫ�أ����ܷ���ջ��Ԫ�أ���Ϊ����cout�ҽ�ϻ��ƻ�ջ���Ƚ������
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

		//������β�ƥ��const String& str
		size_t size() const {
			return length;
		}
		
		
};


//void CoolCoding(bool code = true) {
//
//	string fools[MaxSize];
//	while (code)
//		//eat(fools);
//}



/******************************************������ʼ******************************************/

typedef struct SinglyLinkedList {
	ElemType data;
	struct SinglyLinkedList* next;
}SLnode, * pSLnode;

void InitSLnode(pSLnode p) {
	p->next = NULL;
}

//ͷ�巨
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

//β�巨
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

//����
void VisitSL(pSLnode head) {

	pSLnode p = head;

	while (p->next!=NULL)
	{
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}

//ɾ����Сֵ
void DelMinValue(pSLnode head) {
	
	pSLnode pre = head, p = head->next, m = p, mp = pre;

	while (p)
	{
		if (p->data < m->data) {
			mp = pre;
			m = p;
		}
		pre = p;
		p = p->next;
	}
	mp->next = m->next;
	free(m);
}

//ɾ��target
bool Delx(pSLnode head,int target) {

	pSLnode p = head;

	while (p->next)
	{
		if (p->next->data == target) {
			
			pSLnode del = p->next;
			p->next = p->next->next;
			free(del);
			return true;
		}
		else
			p = p->next;
	}
	return false;
}

//ԭ������
void ReverseList(pSLnode head) {

	pSLnode p = head->next, q;
	head->next = NULL;

	while (p)
	{
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
}

//���ҵ�����k����
bool FindLastK(pSLnode head, int k) {

	pSLnode p = head, q = head->next;
	int i = 1;

	while (q) {

		q = q->next;
		i++;
		if (i > k)
			p = p->next;
	}
	if (k >= i)
		return false;
	else
	{
		cout << p->data << endl;
		return true;
	}
}

/******************************************���������******************************************/


/******************************************˫����ʼ******************************************/

typedef struct DoubleLinkedList {
	ElemType data;
	struct DoubleLinkedList* next;
	struct DoubleLinkedList* pre;

	
}DLnode,*pDLnode;

void InitDLnode(pDLnode head) {
	head->next = NULL;
	head->pre = NULL;
}

//β�巨
void CreateDLLbyTail(pDLnode&head,int nums[],int n) {

	pDLnode p, q;

	head = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	InitDLnode(head);

	p = head;
	for (int i = 0; i < n; i++) {

		q = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
		q->data = nums[i];

		p->next = q;
		q->pre = p;
		p = q;
	}
	p->next = NULL;
}

//����
void VisitDLL(pDLnode head) {
	
	pDLnode p = head->next;

	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//���ҽڵ�
pDLnode findTarget(pDLnode head,ElemType target) {

	pDLnode p = head->next;
	while (p)
	{
		if (p->data == target)
			return p;
		p = p->next;
	}
	return 0;
}


//����ڵ�
bool InsertNodeToDLL(pDLnode& head, ElemType value, int index) {

	int i;
	pDLnode p = head;

	if (index < 0)
		return false;
	for (i = 1; i < index; i++) {
		if (p->next)
			p = p->next;
		else
			break;
	}
	if (i < index - 2)
		return false;
	else
	{
		pDLnode s;
		s = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
		s->data = value;

		s->next = p->next;
		s->pre = p;
		p->next = s;
		if (s->next)
			s->next->pre = s;
		return true;
	}
}

//ɾ���ڵ�
bool Delx(pDLnode* head, int target) {

	return false;
}

/******************************************˫�������******************************************/

/******************************************˳����к������п�ʼ******************************************/

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

typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode;
typedef struct Queue {
	QNode* front;
	QNode* rear;
}Que, * pQue;

/******************************************˳����к������н���******************************************/




/**************************����������&&�������Ĵ���*****************/

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

	//char��������ע���жϿսڵ� 
	if (NullNode(in))
		p = NULL;
	else
	{
		//p = (threadNode*)malloc(sizeof(threadNode));
		//����ʹ��mallocһ��ռ佫�ᶪʧltag��rtag�ĳ�ʼֵ��
		p = new tN;
		p->data = in;
		p->left = CreateTree();
		p->right = CreateTree();
	}
	return p;
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
/**************************����������&&�������Ĵ���*****************/


/**************************����������*******************************/
void NLR(threadNode* p) {

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

	while (p || !s.IsEmpty())
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
/**************************����������*******************************/


/**************************��������������****************************/
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
/**************************��������������****************************/


/**************************������������ʼ*******************************/

//�ݹ�������
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

//�ǵݹ�ͨ����α���������
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

//ͨ��ջ��α�����ʵ�ִ��µ��ϣ��ҵ������
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

//�ж��Ƿ�Ϊ��ȫ������
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

//����������ʾ�ĺ�׺���ʽת��Ϊ��׺���ʽ
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

//���������WPL������Ҷ�ӽ���Ȩ��*���֮��
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

//����
void DelNode(tNp p) {
	if (p) {
		DelNode(p->left);
		DelNode(p->right);
		free(p);
	}
}

//ɾȥÿ����targetΪ����Ҷ�ӽڵ�
void DelxRoot(tNp p,int target) {

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

/**************************��������������*******************************/


/**************************����������������ʼ*******************************/

//��������������
tNp Target_In_BST(tNp p, ElemType target) {
	if (p == NULL)
		return NULL;
	if (p->data == target)
		return p;
	else if (target < p->data)
		Target_In_BST(p->left, target);
	else
		Target_In_BST(p->right, target);
}

//��������������
bool Insert_BTS(tNp& p, ElemType x) {
	if (p == NULL) {

		p = new tN;
		p->left = p->right = NULL;
		p->data = x;
		return true;
	}
	else
	{
		if (x == p->data)	return false;
		else if (x > p->data) return Insert_BTS(p->right, x);
		else return Insert_BTS(p->left, x);
	}
}

//�������������
void Create_BTS(tNp& p,ElemType nums[],int n) {
	p = NULL;
	for (int i = 0; i < n; i++)
		Insert_BTS(p, nums[i]);

}

//�ж��Ƿ�Ϊ����������
int Is_BST(tNp p) {

	static int PreNum = -999;
	int l, r;
	if (!p)
		return 1;
	else
	{
		l=Is_BST(p->left);
		if (l == 0 || PreNum >= p->data)
			return 0;
		PreNum = p->data;

		r = Is_BST(p->right);
		return r;

	}

}

//�ж��Ƿ�Ϊƽ�����������
void Is_Balance_BST(tNp p, int& h, int& balance) {

	int hl, bl, hr, br;
	if (!p) {
		balance = 1;
		h = 0;
	}
	else if (p->left == NULL && p->right == NULL) {
		balance = 1;
		h = 1;
	}
	else
	{
		Is_Balance_BST(p->left, hl, bl);
		Is_Balance_BST(p->right, hr, br);

		h = (hl > hr ? hl : hr) + 1;
		if (abs(hl - hr) < 2)
			balance = bl && br;
		else
			balance = 0;
	}
}

//�����ڵ��ڶ����������еĲ��
int Target_In_Level(tNp p, int target) {
	int n = 0;

	if (p) {
		n++;
		while (p->data != target)
		{
			if (p->data > target)
				p = p->left;
			else
				p = p->right;
			n++;
		}
	}
	return n;

}


/**************************������������������*******************************/

/******************************************����ɭ�ִ洢�ṹ��ʼ******************************************/

//˫�ױ�ʾ��
typedef struct {
	char data;
	int parent;
}PTnode;

typedef struct {
	PTnode nodes[MaxSize];
	int n, r;
}PTtree;

void InitPTtree(PTtree& p, int n) {

	for (int i = 0; i < n; i++) {
		p.nodes[i].parent = -1;
		p.nodes[i].data = '#';
	}
	p.n = 0;
}

bool InsertNode(PTtree& p,char node) {
	
	if (node != '#') {
		p.nodes[p.n++].data = node;
		return true;
	}
	return false;
}

bool InsertParent(PTtree &t,char son,char father){

	int son_pos = -1, father_pos = -1;

	for (int i = 0; i < t.n; i++) {
		if (t.nodes[i].data == son)	son_pos = i;
		if (t.nodes[i].data == father)	father_pos = i;
	}

	if (son_pos != -1 && father_pos != -1) {
		t.nodes[son_pos].parent = father_pos;
		return true;
	}

	return false;
}

void CreateByPTtree(PTtree& t) {
	//10 R A B C D E F G H K A R B R C R D A E A F C G F H F K F
	
	int n = 0;
	int par;

	char node, son, father;
	cin >> n;
	InitPTtree(t, n);
	par = n - 1;
	while (n--)
	{
		cin >> node;
		InsertNode(t, node);
	}
	while (par--)
	{
		cin >> son >> father;
		InsertParent(t, son, father);
	}
}

void VisitPTtree(PTtree t) {
	for (int i = 0; i < t.n; i++)
		cout << "data: " << t.nodes[i].data << "  parent: " << t.nodes[i].parent << endl;
}
//�ֵܱ�ʾ��

typedef struct CSnode {
	char data;
	struct CSnode* firstChild, * nextSibling;
}CSnode, * pCSnode, ** ppCSnode;

void CreateByCStree(pCSnode& p) {
	//R ABC DE # F # # GHK # # #
	char input[20], root;
	cin >> root;

	SqQueue<pCSnode> qu(20);

	if (root != '#') {

		p = (CSnode*)malloc(sizeof(CSnode));
		p->nextSibling = NULL;
		p->data = root;

		qu.EnQueue(p);

		pCSnode father, son;
		while (!qu.QueueIsEmpty())
		{
			qu.GetQueueTop(father);
			qu.DeQueue();

			cin >> input;
			if (input[0] != '#') {

				father->firstChild = (CSnode*)malloc(sizeof(CSnode));
				father->firstChild->data = input[0];
				son = father->firstChild;

			/*	son = father->firstChild;
				son->data = input[0];*/

				for (int i = 1; i < strlen(input); i++) {
					son->nextSibling = (CSnode*)malloc(sizeof(CSnode));
					son->nextSibling->data = input[i];
					
					qu.EnQueue(son);
					son = son->nextSibling;
				}
				qu.EnQueue(son);
				son->nextSibling = NULL;
			}
			else
				father->firstChild = NULL;
		}


	}
	else
		p = NULL;

}

//�������
void VistiCStree(pCSnode p) {

	if (p) {
		cout << p->data << " ";
		VistiCStree(p->firstChild);
		VistiCStree(p->nextSibling);
	}
}
//�������
void MinVisitCStree(pCSnode p) {

	if (p) {
		MinVisitCStree(p->firstChild);
		cout << p->data << " ";
		MinVisitCStree(p->nextSibling);
	}
}

//ͳ��Ҷ�ӽڵ�
int CountCStreeLeaf(pCSnode p){

	if (!p)
		return 0;
	if (!p->firstChild)
		return 1 + CountCStreeLeaf(p->nextSibling);
	else
		return CountCStreeLeaf(p->firstChild) + CountCStreeLeaf(p->nextSibling);
}

//�߶�
int getHeight(pCSnode p) {

	if (!p)
		return 0;
	else
	{
		int hChild, hSibling;

		hChild = getHeight(p->firstChild);
		hSibling = getHeight(p->nextSibling);

		return hChild + 1 > hSibling ? hChild + 1 : hSibling;
	}
}

//����ÿ�����Ķ��Լ�������й����ֵܱ�ʾ
void CreateCStree_By_Degree(pCSnode& t, char e[], int degree[], int n) {

	pCSnode* p = (pCSnode*)malloc(sizeof(CSnode) * n);
	for (int i = 0; i < n; i++) {
		p[i] = (CSnode*)malloc(sizeof(CSnode));
		p[i]->data = e[i];
		p[i]->firstChild = p[i]->nextSibling = NULL;
	}

	int de, kid = 0;

	for (int i = 0; i < n; i++) {
		
		de = degree[i];
		if (de) {
			
			kid++;
			p[i]->firstChild = p[kid];
			for (int j = 2; j <= de; j++) {
				kid++;
				p[kid - 1]->nextSibling = p[kid];
			}
		}
	}
	t = p[0];
	free(p);
}

//���Ϊh��ƽ�������ٽڵ�
int NodesTo_Height(int height) {

	if (height == 0)
		return 0;
	if (height == 1)
		return 1;
	if (height == 2)
		return 2;
	if (height > 2)
		return NodesTo_Height(height - 1) + NodesTo_Height(height - 2) + 1;
}

/******************************************����ɭ�ִ洢�ṹ����******************************************/

void test(int*& p) {
	int a = 4;
	p = &a;
}

int main() {


	//BST����,BST:��������������ƽ�������
	tNp p, res;
	int nums[10] = { 9,23,12,43 };
	Create_BTS(p, nums, 10);
	LNR(p);
	cout << endl;
	res = Target_In_BST(p, 23);
	cout << res->data << endl;
	cout << NodesTo_Height(40) << endl;
	cout << Is_BST(p) << endl;
	cout << Target_In_Level(p, 9) << endl;

	int height, balance;
	Is_Balance_BST(p, height, balance);
	cout << height << " " << balance << endl;



	//˫�ױ�ʾ����
	/*PTtree t;
	CreateByPTtree(t);
	VisitPTtree(t);*/



	//�����ֵܱ�ʾ
	//pCSnode p;
	//CreateByCStree(p);
	//VistiCStree(p);
	//cout << endl;
	//MinVisitCStree(p);
	//cout << endl;

	//cout << CountCStreeLeaf(p) << endl;
	//cout << getHeight(p) << endl;

	//pCSnode q;
	//char e[11] = "RABCDEFGHK";
	//int n = 10;
	//int degree[10] = { 3,2,0,1,0,0,3,0,0,0 };
	//CreateCStree_By_Degree(q, e, degree, n);
	//VistiCStree(q);


	//ָ����ָ���ָ��
	//int* p;
	//p = (int*)malloc(sizeof(int) * 4);

	//int** q;
	//for (int i = 0; i < 4; i++) {
	//	*(p + i) = (int)malloc(sizeof(int));
	//	cin >> *(p + i);
	//	cout << *(p + i) << endl;
	//}

	
		
		
	

	//���������
	//int nums[5] = { 1,2,3,4,5 };
	//pSLnode head;

	////CreateListByHead(head, nums, 5);
	//CreateListByTail(head, nums, 5);
	//VisitSL(head);

	//ReverseList(head);
	//VisitSL(head);

	//Delx(head, 3);
	//VisitSL(head);

	//DelMinValue(head);
	//VisitSL(head);

	//FindLastK(head, 2);

	//˫�������
	/*int nums[5] = { 1,2,3,4,5 };
	pDLnode head;
	CreateDLLbyTail(head, nums, 5);
	VisitDLL(head);

	InsertNodeToDLL(head, 10, 8);
	VisitDLL(head);*/

	//ջ����
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


	//����������
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
//Ctrl + M + O: �۵����з���
//
//Ctrl + M + M : �۵�����չ����ǰ����
//
//Ctrl + M + L : չ�����з���

