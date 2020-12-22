#pragma once
#ifndef Sort_Function
#define Sort_Function


#include"Value.h"
#define DataSize 200000



void generateRandomArray(int n, int rangeL, int rangeR) {
	

	fstream ofs;
	ofs.open("data.txt", ios::out);

	assert(rangeL <= rangeR);
	//int* arr = new int[n]; // 创建一个 n个元素的数组

	srand(time(NULL)); // 随机种子
	for (int i = 0; i < n; i++)
		ofs << rand() % (rangeR - rangeL + 1) + rangeL << endl;
	
}

void LoadData(int data[]) {
	ifstream ifs;
	ifs.open("data.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "打开失败，重新创建 " << endl;
		generateRandomArray(DataSize, 0, 300);
		exit(0);
	}
	else
	{
		string buf;
		int i = 0;
		while (getline(ifs,buf))
		{
			data[i++] = stoi(buf);
			//cout << stoi(buf) << " ";	
		}
		
	}
}


//插入排序
void InsertSort(int a[], int n) {

	clock_t start, end;
	start = clock();

	int i, j, temp;
	for (int i = 1; i < n; i++)
	{
		if(a[i]<a[i-1]){

			temp = a[i];
			for (j = i; temp < a[j - 1] && j >= 1; j--) {
				a[j] = a[j - 1];
			}
			a[j] = temp;

		}
	}
	end = clock();
	cout << "插入排序使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

void BinaryInsertSort(int a[],int len) {

}

//希尔排序
void ShellSort(int a[], int len) {
	
	clock_t start, end;
	start = clock();

	int j, temp;
	for (int group = len/2; group >0; group/=2)
	{
		for (int i = group; i < len; i++)
		{
			temp = a[i];
			for (j = i; j >= group && a[j - group] > temp; j -= group) {
				a[j] = a[j - group];
			}			
			a[j] = temp;
		}
	}
	end = clock();
	cout << "希尔排序使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

//冒泡排序
void BubbleSort(int a[],int len) {
	
	clock_t start, end;
	start = clock();

	int temp;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	end = clock();
	cout << "冒泡排序使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
//简单选择排序
void SelectSort(int a[], int len) {

	clock_t start, end;
	start = clock();

	int temp;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i + 1; j < len; j++) {
			if (a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	end = clock();
	cout << "简单选择排序使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << endl;

}

//选择插入排序
void SelectInsertSort(int a[],int len) {

	clock_t start, end;
	start = clock();

	for (int i = 1; i < len; i++)
	{
		int high = i - 1;
		int low = 0;
		int temp = a[i];
		while (low<=high)
		{
			int mid = (high + low) / 2;
			if (temp > a[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}

		int j;
		for (j = i - 1; j >= high + 1; j--)
			a[j + 1] = a[j];
		a[j+1] = temp;
	}
	end = clock();
	cout << "选择插入排序使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
void Print(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


//堆排序

void adjustHeap(int data[],int pos,int len) {

	int temp = data[pos];
	for (int i = 2*pos+1; i < len; i=i*2+1)
	{
		if (i + 1 < len && data[i] < data[i + 1])
			i++;

		if (data[i] > temp) {
			data[pos] = data[i];
			pos = i;
		}
		else
			break;
			
	}
	data[pos] = temp;
}

void Swap(int data[], int a, int b) {
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

void HeapSort(int data[], int len) {

	//创建大根堆
	clock_t start, end;
	start = clock();


	for (int i = len/2-1; i >= 0; i--)
	{
		adjustHeap(data, i, len);
	}

	for (int i = len - 1; i > 0; i--) {
		Swap(data, 0, i);
		adjustHeap(data, i, len);
	}

	end = clock();
	cout << "堆排序使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

//归并排序
template<typename Type>
void Merge_sort(Type data[], int len) {
	int* a = data;	
	int* b = new Type[len];

	clock_t start, end;
	start = clock();

	for (int seg = 1; seg < len; seg+=seg)
	{
		
		for (int start = 0; start < len; start+=seg+seg)
		{
			int pos = start;
			int low = start;	int mid = min(start + seg, len);	int high = min(start + seg + seg, len);
			
			int s1 = low, e1 = mid;	int	s2 = mid, e2 = high;
			while (s1 < e1 && s2 < e2)
				b[pos++] = a[s1] < a[s2] ? a[s1++] : a[s2++];
			while (s1 < e1)
				b[pos++] = a[s1++];
			while (s2 < e2)
				b[pos++] = a[s2++];


		}

		Type* temp = a;	a = b; b = temp;
	}

	if (a != data) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	
	end = clock();
	cout << "归并排序使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << endl;

	delete[]b;

}




void Timer() {

	int data[DataSize];

	LoadData(data);
	InsertSort(data, DataSize);//20.895
	LoadData(data);
	ShellSort(data, DataSize);//0.035
	LoadData(data);
	BubbleSort(data, DataSize);//92.875
	LoadData(data);
	SelectSort(data, DataSize);//32.069
	LoadData(data);
	SelectInsertSort(data, DataSize);
	LoadData(data);
	HeapSort(data, DataSize);//0.013
	LoadData(data);
	Merge_sort(data, DataSize);

	//Print(data, DataSize);

	
}

#endif // !Sort_Function
