#pragma once
#ifndef Common_Singly_Linked_List
#define Common_Singly_Linked_List

#include<iostream>
#include"Value.h"
using namespace std;


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

	while (p->next != NULL)
	{
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}

//删除最小值
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

//删除target
bool Delx(pSLnode head, int target) {

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

//原地逆置
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

//查找倒数第k个点
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


#endif // !Common_Singly_Linked_List
