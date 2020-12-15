#pragma once

#ifndef Common_Map
#define Common_Map

#include"Value.h"
#include"Stack.h"
#include"Squeue.h"

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

		int gangster[MaxSize];//并查集

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
				for (int j = 0; j < vexnum; j++) {
					//arcs[i][j] = 1000;
					i == j ? arcs[i][j] = 0 : arcs[i][j] = 1000;
				}
				//999为最大权值
						

		}

		//DFS
		void DFS(int i) {
			Visited[i] = true;

			cout << vexs[i] << " ";
			for (int j = 0; j < vexnum; j++)
				if (arcs[i][j] != 0 && !Visited[j])
					DFS(j);
		}

		/**********kruskal算法辅助**********/
		typedef struct {
			int a, b;
			int w;
		}Road;

		bool static COM(const Road& a, const Road& b) {
			return a.w < b.w;
		}

		int GetBoss(int x) {
			while (x != gangster[x])
				x = gangster[x];
			return x;
		}
		/**********kruskal算法辅助**********/

	public:

		//重载构造
		MGraph(string op="DG",bool We=false):Type(op) {

			string v1, v2;
			int ip, jp, w;
			Type = op;

			if (op == "DG") {
				Input();
				cout << "input arcs: " << endl;
				for (int i = 0; i < arcnum; i++)
				{	
					if (We)
					{
						cin >> v1 >> v2 >> w;
						ip = LocatVex(v1);
						jp = LocatVex(v2);

						if (ip != -1 && jp != -1)
							arcs[ip][jp] = w;
					}
					else
					{
						cin >> v1 >> v2;

						ip = LocatVex(v1);
						jp = LocatVex(v2);

						if (ip != -1 && jp != -1)
							arcs[ip][jp] = 1;
					}
				}
			}
			else if (op=="UDG")
			{
				Input();
				cout << "input arcs: " << endl;
				for (int i = 0; i < arcnum; i++)
				{
					if (We)
						cin >> v1 >> v2 >> w;
					else
						cin >> v1 >> v2;

					ip = LocatVex(v1);
					jp = LocatVex(v2);
					if (We)
					{
						if (ip != -1 && jp != -1)
							arcs[ip][jp] = arcs[jp][ip] = w;
					}
					else {
						if (ip != -1 && jp != -1)
							arcs[ip][jp] = arcs[jp][ip] = 1;
					}

			
				}
			}
			else {
				cout << "fuck" << endl;
			}
	

		}
		//表
		void Visit() {
			cout << endl;
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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
					if (arcs[i][j]==-404) {
						cout << setiosflags(ios::right);
						cout << "-" << "|" << '\t';
					}
					else if (arcs[i][j] == 1000)
					{
						cout << setiosflags(ios::right);
						cout << "∞" << "|" << '\t';
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
						cout << setiosflags(ios::right);
						cout << arcs[i][j] << "|" << '\t';
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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
					if (arcs[pos][i] != 1000 && arcs[pos][i] != 0)
						cout << vexs[i] << " ";
				cout << endl;
			}
			else
				cout << "不存在该节点" << endl;
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
				for (int i = 0; i < vexnum; i++) {
					if (vexnum - 1 == i)
						arcs[vexnum - 1][i] = 0;
					else
						arcs[vexnum - 1][i] = arcs[i][vexnum - 1] = 1000;
				}
					
				
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
		
		//prim最小生成树
		void Prim_to_MST(int start, int sum = 0) {
			
			if (Type != "UDG")
				return;

			int min;//将每条最小路径加起来成最小生成树		
			int lowCost[MaxSize];
			int nextPost;

			for (int i = 0; i < vexnum; i++)
			{
				lowCost[i] = arcs[start][i];
				Visited[i] = false;
			}

			Visited[start] = true;

			for (int i = 0; i < vexnum - 1; i++)
			{
				int min = 99999;
				for (int j = 0; j < vexnum; j++)
					if (!Visited[j] && lowCost[j] < min) {
						nextPost = j;
						min = lowCost[j];
					}
				sum += min;
				Visited[nextPost] = true;
				start = nextPost;
				

				for (int j = 0; j < vexnum; j++)
					if (!Visited[j] && arcs[start][j] < lowCost[j])
						lowCost[j] = arcs[start][j];
			}

			cout << "Prim 最小生成路径总和： " << sum << endl;
		}
	
		

		//Kruskal最小生成树
		void Kruskal_to_MST() {

			if (Type != "UDG")
				return;
			Road road[MaxSize];
			int count = 0;

			for (int i = 0; i < vexnum; i++) {
				gangster[i] = i;
				for (int j = i + 1; j < vexnum; j++)
				{
					if (arcs[i][j] != 1000) {
						road[count].a = i;
						road[count].b = j;
						road[count].w = arcs[i][j];
						count++;
					}

				}
			}
				
			int a, b, sum = 0;
			sort(road, road + count, COM);
			for (int i = 0; i < arcnum; i++)
			{
				a = GetBoss(road[i].a);
				b = GetBoss(road[i].b);
				if (a != b) {
					sum += road[i].w;
					gangster[a] = b;
				}
			}
			cout << "Kruskal 最小生成路径总和： " << sum << endl;
			/*for (int i = 0; i < count; i++)
				cout << road[i].a << " " << road[i].b << " " << road[i].w << endl;*/
		}
		
		void Dijkatra(string start) {

			if (Type != "DG")
				return;


			int start_pos = LocatVex(start);

			int dist[MaxSize], path[MaxSize];

			for (int i = 0; i < vexnum; i++)
			{
				arcs[start_pos][i] < 1000 ? dist[i] = arcs[start_pos][i] : dist[i] = 1000;
				
				Visited[i] = false;

				arcs[start_pos][i] < 1000 ? path[i] = start_pos : path[i] = -1;
			}

		

			Visited[start_pos] = true;
			path[start_pos] = -1;
			
			int min, nextPos;
			for (int i = 0; i < vexnum - 1; i++) {

				min = 1000;

				for (int j = 0; j < vexnum; j++) {
					if (!Visited[j]&&dist[j]<min)
					{
						min = dist[j];
						nextPos = j;
					}
				}

				Visited[nextPos] = true;

				for (int j = 0; j < vexnum; j++)
				{
					if (!Visited[j] && dist[nextPos] + arcs[nextPos][j] < dist[j]) {
						dist[j] = dist[nextPos] + arcs[nextPos][j];
						path[j] = nextPos;
					}
				}

			}//for
			for (int i = 0; i < vexnum; i++)
				cout << dist[i] << " ";
			cout << endl;


		}

		void Floyd() {


			int map[MaxSize][MaxSize];
			int path[MaxSize][MaxSize];

			for (int i = 0; i < vexnum; i++)
				for (int j = 0; j < vexnum; j++) {
					map[i][j] = arcs[i][j];
					path[i][j] = -1;
				}
					

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

		string Type;
		bool Visited[MaxSize];

	private:

		int LocatVex(string in) {

			for (int i = 0; i < vexnum; i++)
				if (vexs[i].data == in)
					return i;
			return -1;
		}

		void Finding(int start, int end, int save_path[], int count) {

			count++;
			save_path[count] = start;
			Visited[start] = true;

			if (start == end)
			{
				cout << "Path: ";
				for (int i = 0; i <= count; i++)
					cout << vexs[save_path[i]].data << " ";
				cout << endl;
			}

			pArc p = vexs[start].firstArc;
			while (p)
			{
				if (!Visited[p->adjvex])
					Finding(p->adjvex, end, save_path, count);
				p = p->next;
			}
			Visited[start] = false;
		}

		bool DFS_Finding(int start, int end) {
			if (start == end)
				return true;
			else
			{
				Visited[start] = true;
				for (int i = FirstNeighbor(start); i >= 0; i = NextNeighbor(start, i))
				{
					if (!Visited[i] && DFS_Finding(i, end))
						return true;
				}
			}
			return false;
		}

	public:
		ALGraph(string type="UDG") {

			
			Type = type;
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

				if (Type=="UDG")//UDG
				{
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
				else
				{
					//DG
					//头插法
					pArc a = new ArcNode;
					a->adjvex = jp;
					a->next = vexs[ip].firstArc;
					vexs[ip].firstArc = a;
				}
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


		
		//从顶点start到end所有简单路径
		void Find_Path(string start, string end) {
			
			int s = LocatVex(start);
			int e = LocatVex(end);

			if (s == -1 || e == -1)
				exit(0);

			int save_path[MaxSize];
			for (int i = 0; i < vexnum; i++) {
				Visited[i] = false;
				save_path[i] = -1;
			}
			Finding(s, e, save_path, -1);
		}


		//有向图深度优先判定顶点start到end有无路径 
		void DFS_to_FindPath(string start, string end) {
			
			if (Type != "DG") {
				cout << "不是有向图";
				exit(0);
			}

			int s = LocatVex(start);
			int e = LocatVex(end);
			if (s == -1 || e == -1)
				exit(0);

			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;
			
			if (DFS_Finding(s, e))
				cout << vexs[s].data << " 到达 " << vexs[e].data << " 存在路径 " << endl;
			else
				cout << vexs[s].data << " 到达 " << vexs[e].data << " 不存在路径 " << endl;
		}

		bool BFS_Finding(int start,int end) {

			SqQueue<int> q(10);
			q.EnQueue(start);

			while (!q.QueueIsEmpty()) {
				int pos;
				q.GetQueueTop(pos);
				q.DeQueue();

				Visited[pos] = true;

				for (int i = FirstNeighbor(pos); i >= 0; i=NextNeighbor(pos,i))
				{
					if (i == end)
						return true;
					if (!Visited[i])
						q.EnQueue(i);
				}
			}
			return false;
		}
		//有向图广度优先判定顶点start到end有无路径
		void BFS_to_FindPath(string start, string end) {
			if (Type != "DG") {
				cout << "不是有向图";
				exit(0);
			}

			int s = LocatVex(start);
			int e = LocatVex(end);
			if (s == -1 || e == -1)
				exit(0);

			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;

			if (BFS_Finding(s, e))
				cout << vexs[s].data << " 到达 " << vexs[e].data << " 存在路径 " << endl;
			else
				cout << vexs[s].data << " 到达 " << vexs[e].data << " 不存在路径 " << endl;

		}


		~ALGraph() {

		}

};




/**************************图的邻接表及操作结束*****************/
#endif // !Common_Map

