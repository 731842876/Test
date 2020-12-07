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
		bool Visited[MaxSize];//深度优先遍历标记访问
		string Type;//有向图DG，无向图UDG，有向网DN,无向网UDN
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

		//DFS
		void DFS(int i) {
			Visited[i] = true;

			cout << vexs[i] << " ";
			for (int j = 0; j < vexnum; j++)
				if (arcs[i][j] != 0 && !Visited[j])
					DFS(j);
		}

	public:

		//重载构造
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
		//判断是否有<x,y>||(x,y)
		bool Adjacent(string v1,string v2) {
			int ip, jp;
			ip = LocatVex(v1);
			jp = LocatVex(v2);
			if (ip != -1 && jp != -1)
				return arcs[ip][jp] != 0 ? true : false;
			else
				exit(0);
		}
		//与节点x邻接的边
		void Neighbors(string v) {
			int pos = LocatVex(v);
			if (pos != -1) {
				cout << vexs[pos] << " 与该点邻接的边: ";
				for (int i = 0; i < vexnum; i++)
					if (arcs[pos][i] != 0)
						cout << vexs[i] << " ";
				cout << endl;
			}
		}
		//插入节点
		bool InsertVertex(string in) {
			if (vexnum > MaxSize - 1) {
				cout << "已存储最大节点数" << endl;
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
		//删除节点
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

		//没有该边便添加
		void AddEdge(string v1,string v2) {
			
			if (Adjacent(v1, v2))
				cout << "已存在" << endl;
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
				cout << "已添加" << endl;
			}

		}

		//设置权重
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
		//获得权重
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


		//返回顶点v的第一个邻接点
		int FirstNeighbor(string v) {

			int pos = LocatVex(v);
			for (int i = 0; i < vexnum; i++)
				if (arcs[pos][i] != 0)
					return i;
			//cout << vexs[i] << endl;
			return -1;		
		}

		//返回顶点v的相对于w的下一个邻接点
		int NextNeighbor(string v, string w) {
			int pos = LocatVex(v);
			int st = LocatVex(w);
			for (int i = st+1; i < vexnum; i++) {
				if (arcs[pos][i] != 0)
					return i;
			}
			return -1;
		}
		
		
		//深度优先搜索
		void DFS_func() {
			cout << "DFS: ";
			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;

			for (int i = 0; i < vexnum; i++)
				if (!Visited[i])
					DFS(i);
			cout << endl;
		}
		
		//广度优先搜索
		void BFS_func() {
			
			SqQueue<int> q(10);
			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;
			
			cout << "BFS: ";
			
			for (int i = 0; i < vexnum; i++)
			{
				if (!Visited[i]) {

					Visited[i] = true;
					q.EnQueue(i);
					cout << vexs[i] << " ";
					while (!q.QueueIsEmpty())
					{
						q.GetQueueTop(i);
						q.DeQueue();

						for (int j = 0; j < vexnum; j++) {

							if (arcs[i][j] != 0 && !Visited[j]) {
								cout << vexs[j] << " ";
								q.EnQueue(j);
								Visited[j] = true;
							}
						}
					}
				}

			}
			cout << endl;
		}
		
		
		
		
		
		~MGraph() {
			//delete[]arcs;
		}

};




/**************************图的邻接矩阵及操作结束*****************/






/**************************图的邻接表及操作开始*****************/



//
//typedef struct {
//	Vnode vexs[MaxSize];
//	int vexnum, arcnum;
//};

class ALGraph
{

	private:

		//表节点
		typedef struct ArcNode {
			int adjvex;
			ArcNode* next;
		}Arn,*pArc;

		//头节点
		typedef struct Vnode{
			string data;
			pArc firstArc;
		}Vnode;


		Vnode vexs[MaxSize];
		int vexnum, arcnum;
		bool Visited[MaxSize];

	private:

		int LocatVex(string in) {

			for (int i = 0; i < vexnum; i++)
				if (vexs[i].data == in)
					return i;
			return -1;
		}


	public:
		ALGraph() {

			//UDG
			cout << "vexnum and arcnum: " << endl;
			cin >> vexnum >> arcnum;

			cout << "input vertx name: " << endl;
			for (int i = 0; i < vexnum; i++) {
				cin >> vexs[i].data;
				vexs[i].firstArc = NULL;
			}

			int ip, jp;
			string v1, v2;

			cout << "input arcs: " << endl;
			for (int i = 0; i < arcnum; i++) {

				cin >> v1 >> v2;
				ip = LocatVex(v1);
				jp = LocatVex(v2);

				//头插法
				pArc a = new ArcNode;
				a->adjvex = jp;
				a->next = vexs[ip].firstArc;
				vexs[ip].firstArc = a;

				a = new ArcNode;
				a->adjvex = ip;
				a->next = vexs[jp].firstArc;
				vexs[jp].firstArc = a;
			}

				
			
		}



		void Visit() {
			cout << endl;
			for (int i = 0; i < vexnum; i++) {

				cout << vexs[i].data;
				pArc p = vexs[i].firstArc;
				while (p)
				{
					cout << " --> " << vexs[p->adjvex].data;
					p = p->next;
				}
				cout << endl;
			}
			cout << endl;
		}
		
		//返回顶点v的第一个邻接点
		int FirstNeighbor(int pos) {
			pArc p = vexs[pos].firstArc;
			if (p)
				return p->adjvex;
			else
				return -1;
		}

		//返回顶点v的相对于w的下一个邻接点
		int NextNeighbor(int pos ,int t) {
			pArc p = vexs[pos].firstArc;
			while (p)
			{
				if (p->adjvex == t)
					break;
				p = p->next;
			}	
			if (!p->next || p->adjvex != t)
				return -1;
			return p->next->adjvex;
		}



		
		void DFS(int i) {

			Visited[i] = true;
			cout << vexs[i].data << " ";
			for (int j=FirstNeighbor(i);j>=0;j=NextNeighbor(i,j))
				if (!Visited[j])
					DFS(j);
			

		}

		//深度优先搜索
		void DFS_func() {

			cout << "DFS: ";

			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;

			for (int i = 0; i < vexnum; i++)
				if (!Visited[i])
					DFS(i);
			cout << endl;
		}


		//广度优先搜索
		void BFS_func(){

			SqQueue<int> q(10);
			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;

			cout << "BFS: ";
			for (int i = 0; i < vexnum; i++)
			{

				if (!Visited[i])
				{
					Visited[i] = true;
					q.EnQueue(i);
					
					while (!q.QueueIsEmpty())
					{
						int pos;
						q.GetQueueTop(pos);
						q.DeQueue();
						cout << vexs[pos].data << " ";

						for (int j = FirstNeighbor(pos); j >=0; j=NextNeighbor(pos,j))
						{
							if (!Visited[j]) {
								q.EnQueue(j);
								Visited[j] = true;
							}
						}
					}
				}

			}
			cout << endl;
		}



		~ALGraph() {

		}



};




/**************************图的邻接表及操作结束*****************/
#endif // !Common_Map

