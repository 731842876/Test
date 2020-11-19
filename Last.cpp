#include<iostream>
using namespace std;


class Base
{
public:
	virtual void display() {
		cout << "here is base !" << endl;
	};

};


class FirstD:public Base
{
public:
	void display() {
		cout << "here is FirstD !" << endl;
	};

};


class SecondD:public Base
{
public:
	void display() {
		cout << "here is SecondD !" << endl;
	};

};

//int main() {
//
//	Base* ptr;
//
//	Base b1;
//	FirstD f1;
//	SecondD s1;
//
//	ptr = &b1;
//	ptr->display();
//
//	ptr = &f1;
//	ptr->display();
//
//	ptr = &s1;
//	ptr->display();
//
//}