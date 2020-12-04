#pragma once

#ifndef Common_Map
#define Common_Map

#include"Value.h"

using namespace std;

/**************************ͼ���ڽӾ��󼰲�����ʼ*****************/

//typedef struct MGraph {
//	string vexs[MaxSize];
//	int arcs[MaxSize][MaxSize];
//	int vexnum, arcnum;//vertx:���㣬arc:��
//}mg;


class MGraph
{
	private:
		string Type;//����ͼDG������ͼUDG��������DN,������UDN
		string vexs[MaxSize];
		int arcs[MaxSize][MaxSize];
		int vexnum, arcnum;//vertx:���㣬arc:��

	private:
		//��λ
		int LocatVex(string in) {
			int res = -1;
			for (int i = 0; i < vexnum; i++)
				if (vexs[i] == in)
					res = i;
			return res;
		}

		//���붥��ͻ������������� 
		void Input() {

			cout << "vexnum and arcnum: " << endl;
			cin >> vexnum >> arcnum;

			cout << "input vertx name: " << endl;
			for (int i = 0; i < vexnum; i++) 
				cin >> vexs[i];
			
			for (int i = 0; i < vexnum; i++)
				for (int j = 0; j < vexnum; j++)
					arcs[i][j] = 0;

		}

	public:

		//���ع���
		MGraph(string op="DG") {

			string v1, v2;
			int ip, jp;
			Type = op;

			if (op == "DG") {
				Input();
				cout << "input arcs: " << endl;
				for (int i = 0; i < arcnum; i++)
				{	
					cin >> v1 >> v2;
					ip = LocatVex(v1);
					jp = LocatVex(v2);
					if (ip != -1 && jp != -1)
						arcs[ip][jp] = 1;
				}
			}
			else if (op=="UDG")
			{
				Input();
				cout << "input arcs: " << endl;
				for (int i = 0; i < arcnum; i++)
				{
					cin >> v1 >> v2;
					ip = LocatVex(v1);
					jp = LocatVex(v2);
					if (ip != -1 && jp != -1)
						arcs[ip][jp] = arcs[jp][ip] = 1;
				}
			}
			else if (op == "DN") {
				int w;
				Input();
				cout << "input arcs: " << endl;
				for (int i = 0; i < arcnum; i++)
				{
					cin >> v1 >> v2 >> w;
					ip = LocatVex(v1);
					jp = LocatVex(v2);
					if (ip != -1 && jp != -1)
						arcs[ip][jp] = w;
						//arcs[ip][jp] = arcs[jp][ip] = 1;
				}
			}
			else if (op=="UDN")
			{
				int w;
				Input();
				cout << "input arcs: " << endl;
				for (int i = 0; i < arcnum; i++)
				{
					cin >> v1 >> v2 >> w;
					ip = LocatVex(v1);
					jp = LocatVex(v2);
					if (ip != -1 && jp != -1)
						arcs[ip][jp] = arcs[jp][ip] = w;
				}
			}
			else {
				cout << "fuck" << endl;
			}
	

		}
		//��
		void Visit() {
			cout << endl;
			

			cout << setw(4) << "*" << '\t';
			for (int i = 0; i < vexnum; i++) {
				cout << setiosflags(ios::right);
				cout << vexs[i] << "\t";
			}
			cout << endl;

			for (int i = 0; i < vexnum; i++) {
				cout << setiosflags(ios::right);
				cout << setw(4) << vexs[i] << '\t';

				for (int j = 0; j < vexnum; j++) {
					if (arcs[i][j]!=-404) {
						cout << setiosflags(ios::right);
						cout << arcs[i][j] << "|" << '\t';
					}
					else
					{
						cout << setiosflags(ios::right);
						cout << "-" << "|" << '\t';
					}
				}
				cout << endl;
			}
			cout << endl;
		}
		//�ж��Ƿ���<x,y>||(x,y)
		bool Adjacent(string v1,string v2) {
			int ip, jp;
			ip = LocatVex(v1);
			jp = LocatVex(v2);
			if (ip != -1 && jp != -1)
				return arcs[ip][jp] != 0 ? true : false;
			else
				exit(0);
		}
		//��ڵ�x�ڽӵı�
		void Neighbors(string v) {
			int pos = LocatVex(v);
			if (pos != -1) {
				cout << "��õ��ڽӵı�: ";
				for (int i = 0; i < vexnum; i++)
					if (arcs[pos][i] != 0)
						cout << vexs[i] << " ";
				cout << endl;
			}
		}
		//����ڵ�
		bool InsertVertex(string in) {
			if (vexnum > MaxSize - 1) {
				cout << "�Ѵ洢���ڵ���" << endl;
				return false;
			}
			else
			{
				vexs[vexnum] = in;
				vexnum++;
				for (int i = 0; i < vexnum; i++) 
					arcs[vexnum-1][i] = arcs[i][vexnum-1] = 0;
				
				return true;
			}	
		}
		//ɾ���ڵ�
		bool DeteleVertex(string in) {

			int pos = LocatVex(in);
			if (pos == -1)
				return false;
			else
			{
				for (int i = 0; i < vexnum; i++)
					arcs[pos][i] = arcs[i][pos] = -404;
				
				return true;
			}
		}

		//û�иñ߱����
		void AddEdge(string v1,string v2) {
			
			if (Adjacent(v1, v2))
				cout << "�Ѵ���" << endl;
			else
			{
				int i = LocatVex(v1);
				int j = LocatVex(v2);
				if (Type == "DG") {
					arcs[i][j] = 1;
				}
				else if (Type == "DN")
				{
					int w;
					cin >> w;
					arcs[i][j] = w;
				}
				else if (Type == "UDG")
					arcs[i][j] = arcs[j][i] = 1;
				else
				{
					int w;
					cin >> w;
					arcs[i][j] = arcs[j][i] = w;
				}
				cout << "�����" << endl;
			}

		}

		//����Ȩ��
		bool Set_Weight(string v1, string v2, int w) {

			if (!Adjacent(v1, v2))
				return false;
			else
			{
				int i = LocatVex(v1);
				int j = LocatVex(v2);
				if (Type == "DN")
					arcs[i][j] = w;
				else
					arcs[i][j] = arcs[j][i] = w;
			}
		}
		//���Ȩ��
		int Get_Weight(string v1, string v2) {
			int res = -1;
			if (!Adjacent(v1, v2))
				return res;
			else
			{
				int i = LocatVex(v1);
				int j = LocatVex(v2);
				if (Type == "DN")
					res = arcs[i][j];
				return res;
			}
		}	

		~MGraph() {
			//delete[]arcs;
		}

};




/**************************ͼ���ڽӾ��󼰲�������*****************/






/**************************ͼ���ڽӱ�������ʼ*****************/

typedef struct ArcNode {
	int adjvex;
	ArcNode* next;
}arn;
/**************************ͼ���ڽӱ���������*****************/
#endif // !Common_Map

