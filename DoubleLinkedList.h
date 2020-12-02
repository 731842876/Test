#pragma once



#ifndef  Common_Double_Linked_List
#define Common_Double_Linked_List

#include<iostream>
#include"Value.h"

typedef struct DoubleLinkedList {
	ElemType data;
	struct DoubleLinkedList* next;
	struct DoubleLinkedList* pre;


}DLnode, * pDLnode;

void InitDLnode(pDLnode head) {
	head->next = NULL;
	head->pre = NULL;
}

//β�巨
void CreateDLLbyTail(pDLnode& head, int nums[], int n) {

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
pDLnode findTarget(pDLnode head, ElemType target) {

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



#endif // Common_Double_Linked_List
