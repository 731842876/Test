#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


#include"Stack.h"
#include"Squeue.h"
#include "Value.h"
#include "Map.h"
using namespace std;



/**************************线索二叉树&&二叉树的创建*****************/

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
/**************************线索二叉树&&二叉树的创建*****************/


/**************************二叉树遍历*******************************/
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
/**************************二叉树遍历*******************************/


/**************************线索二叉树遍历****************************/
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
/**************************线索二叉树遍历****************************/


/**************************二叉树操作开始*******************************/

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

/**************************二叉树操作结束*******************************/


/**************************二叉排序树操作开始*******************************/

//二叉排序树查找
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

//二叉排序树插入
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

//构造二叉排序树
void Create_BTS(tNp& p,ElemType nums[],int n) {
	p = NULL;
	for (int i = 0; i < n; i++)
		Insert_BTS(p, nums[i]);

}

//判断是否为二叉排序树
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

//判断是否为平衡二叉排序树
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

//给定节点在二叉排序树中的层次
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


/**************************二叉排序树操作结束*******************************/

/******************************************树和森林存储结构开始******************************************/

//双亲表示法
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
//兄弟表示法

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

//先序遍历
void VistiCStree(pCSnode p) {

	if (p) {
		cout << p->data << " ";
		VistiCStree(p->firstChild);
		VistiCStree(p->nextSibling);
	}
}
//中序遍历
void MinVisitCStree(pCSnode p) {

	if (p) {
		MinVisitCStree(p->firstChild);
		cout << p->data << " ";
		MinVisitCStree(p->nextSibling);
	}
}

//统计叶子节点
int CountCStreeLeaf(pCSnode p){

	if (!p)
		return 0;
	if (!p->firstChild)
		return 1 + CountCStreeLeaf(p->nextSibling);
	else
		return CountCStreeLeaf(p->firstChild) + CountCStreeLeaf(p->nextSibling);
}

//高度
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

//根据每个结点的度以及层次序列构造兄弟表示
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

//深度为h的平衡树最少节点
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

/******************************************树和森林存储结构结束******************************************/

void test(int*& p) {
	int a = 4;
	p = &a;
}

int main() {


	//邻接表测试
	//UDG 4 5 A B C D A B A C B C B D C D
	//UDG 6 7 A B C D E F A B A C A E B F C D D E E F
	//DG 6 7 A B C D E F A B B C B F D B E B F A F E
	//ALGraph m("DG");
	//m.Visit();
	//m.DFS_func();
	//m.BFS_func();

	//m.Find_Path("A", "D");

	//m.DFS_to_FindPath("A", "F");
	//m.DFS_to_FindPath("A", "D");

	//m.BFS_to_FindPath("A", "F");
	//m.BFS_to_FindPath("A", "D");


	//邻接矩阵测试
	
	//UDG
	//6 10 A B C D E F A B 6 A C 1 A D 5 B C 5 B E 3 C D 5 C E 6 C F 4 D F 2 E F 6
	//DG
	//6 8 A B C D E F A B 3 A C 4 B F 1 C D 3 D A 7 D E 2 E B 2 F E 1
	MGraph m("DG",true);
	m.Visit();
	m.Neighbors("A");
	m.Neighbors("G");
	m.Prim_to_MST(0);
	//m.Kruskal_to_MST();


	//m.DFS_func();
	//m.BFS_func();
	

	/*if (m.Adjacent("A", "B"))
		cout << "1" << endl;

	m.InsertVertex("E");
	m.Visit();
	m.DeteleVertex("B");
	m.Visit();
	
	m.AddEdge("A", "E");
	m.Visit();

	cout << m.FirstNeighbor("A") << endl;
	cout << m.NextNeighbor("A", "B") << endl;*/


	//BST测试,BST:二叉排序树不是平衡二叉树
	/*tNp p, res;
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
	cout << height << " " << balance << endl;*/



	//双亲表示测试
	/*PTtree t;
	CreateByPTtree(t);
	VisitPTtree(t);*/



	//孩子兄弟表示
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


	//指针与指针的指针
	//int* p;
	//p = (int*)malloc(sizeof(int) * 4);

	//int** q;
	//for (int i = 0; i < 4; i++) {
	//	*(p + i) = (int)malloc(sizeof(int));
	//	cin >> *(p + i);
	//	cout << *(p + i) << endl;
	//}

	
		
		
	

	//单链表测试
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

	//双链表测试
	/*int nums[5] = { 1,2,3,4,5 };
	pDLnode head;
	CreateDLLbyTail(head, nums, 5);
	VisitDLL(head);

	InsertNodeToDLL(head, 10, 8);
	VisitDLL(head);*/

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
//Ctrl + M + O: 折叠所有方法
//
//Ctrl + M + M : 折叠或者展开当前方法
//
//Ctrl + M + L : 展开所有方法

