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

		//����ͼDG������ͼUDG��������DN,������UDN
		MGraph(string op="DG") {

			string v1, v2;
			int ip, jp;

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
					cout << setiosflags(ios::right);
					cout << arcs[i][j] << "|" << '\t';
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
				if (arcs[ip][jp] != 0 || arcs[jp][ip] != 0)
					return true;
			return false;
		}

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

