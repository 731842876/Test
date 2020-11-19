// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}

#include <iostream> 
#include <cstring>
#include <cstdio>
using namespace std;

class Base { 
	public: 
		virtual void vFn(void) 
		{ 
			cout << "Here is Base!\n"; 
		} 
};

class Derived :public Base {
	public:     
		void vFn(void) { 
			cout << "Here is Derived\n";
		}
	 
}; 

void fn(Base* p) { 
	p->vFn();  
	return;
}

int sub(char *s) { 
	char *p=s;  
	while(*p) p++;   
	return(p-s); 

} 

void sort(int* a, int n) { 
	
	for (int i = 1; i < n - 1; i++) { 
		int k = i - 1;            
		
		for (int j = i; j <= n - 1; j++) 
			if (a[j] < a[k]) 
				k = j;            
		
		if (k != i - 1) { 
			int x = a[i - 1]; 
			a[i - 1] = a[k]; 
			a[k] = x; 
		} 
	} 
}

//void main() {
//	char a[6] = "abcde";
//	int m;   
//	m=sub(a);   
//	cout << m << endl;
//}

//void main() { 
//	int i;    
//	char name[] = "book";
//	
//	for (i = 0; i < strlen(name); i++) 
//		cout << "name[" << i << "]:" << name[i] << endl; 
//
//}

//void main() { 
//
//	int a;   
//	int& ref = a;  
//
//	a = 10;   
//	cout << a << "-- - " << ref << endl;   
//	
//	int b = 20;   
//	ref = b;   
//	cout << a << "-- - " << ref << endl;   
//	
//	b--;   
//	cout << a << "-- - " << ref << endl; 
//}

//void main() { 
//	/*Base objB;   
//	Derived objD;   
//	
//	cout << "First call : ";
//	fn(&objB);   
//
//	cout << "Second call : ";
//	fn(&objD);*/
//
//	int n = 3 & 4;
//	cout << n << endl;
//
//}


