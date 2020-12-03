#pragma once

#ifndef Common_Map
#define Common_Map

#include"Value.h"

using namespace std;

/**************************图的邻接矩阵及操作开始*****************/

//typedef struct MGraph {
//	string vexs[MaxSize];
//	int arcs[MaxSize][MaxSize];
//	int vexnum, arcnum;//vertx:顶点，arc:弧
//}mg;


class MGraph
{
	private:
		string vexs[MaxSize];
		int arcs[MaxSize][MaxSize];
		int vexnum, arcnum;//vertx:顶点，arc:弧

	private:
		//定位
		int LocatVex(string in) {
			int res = -1;
			for (int i = 0; i < vexnum; i++)
				if (vexs[i] == in)
					res = i;
			return res;
		}

		//输入顶点和弧数、顶点名字 
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

		//有向图DG，无向图UDG，有向网DN,无向网UDN
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
		//表
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
		//判断是否有<x,y>||(x,y)
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
				cout << "与该点邻接的边: ";
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




/**************************图的邻接矩阵及操作结束*****************/






/**************************图的邻接表及操作开始*****************/

typedef struct ArcNode {
	int adjvex;
	ArcNode* next;
}arn;
/**************************图的邻接表及操作结束*****************/
#endif // !Common_Map

