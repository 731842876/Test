#pragma once

#ifndef Common_Map
#define Common_Map

#include"Value.h"
#include"Stack.h"
#include"Squeue.h"

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
		bool Visited[MaxSize];//������ȱ�����Ƿ���
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

		//DFS
		void DFS(int i) {
			Visited[i] = true;

			cout << vexs[i] << " ";
			for (int j = 0; j < vexnum; j++)
				if (arcs[i][j] != 0 && !Visited[j])
					DFS(j);
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
				cout << vexs[pos] << " ��õ��ڽӵı�: ";
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


		//���ض���v�ĵ�һ���ڽӵ�
		int FirstNeighbor(string v) {

			int pos = LocatVex(v);
			for (int i = 0; i < vexnum; i++)
				if (arcs[pos][i] != 0)
					return i;
			//cout << vexs[i] << endl;
			return -1;		
		}

		//���ض���v�������w����һ���ڽӵ�
		int NextNeighbor(string v, string w) {
			int pos = LocatVex(v);
			int st = LocatVex(w);
			for (int i = st+1; i < vexnum; i++) {
				if (arcs[pos][i] != 0)
					return i;
			}
			return -1;
		}
		
		
		//�����������
		void DFS_func() {
			cout << "DFS: ";
			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;

			for (int i = 0; i < vexnum; i++)
				if (!Visited[i])
					DFS(i);
			cout << endl;
		}
		
		//�����������
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




/**************************ͼ���ڽӾ��󼰲�������*****************/






/**************************ͼ���ڽӱ�������ʼ*****************/



//
//typedef struct {
//	Vnode vexs[MaxSize];
//	int vexnum, arcnum;
//};

class ALGraph
{

	private:

		//��ڵ�
		typedef struct ArcNode {
			int adjvex;
			ArcNode* next;
		}Arn,*pArc;

		//ͷ�ڵ�
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
					//ͷ�巨
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
					//ͷ�巨
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
		
		//���ض���v�ĵ�һ���ڽӵ�
		int FirstNeighbor(int pos) {
			pArc p = vexs[pos].firstArc;
			if (p)
				return p->adjvex;
			else
				return -1;
		}

		//���ض���v�������w����һ���ڽӵ�
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

		//�����������
		void DFS_func() {

			cout << "DFS: ";

			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;

			for (int i = 0; i < vexnum; i++)
				if (!Visited[i])
					DFS(i);
			cout << endl;
		}


		//�����������
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


		
		//�Ӷ���start��end���м�·��
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


		//����ͼ��������ж�����start��end����·�� 
		void DFS_to_FindPath(string start, string end) {
			
			if (Type != "DG") {
				cout << "��������ͼ";
				exit(0);
			}

			int s = LocatVex(start);
			int e = LocatVex(end);
			if (s == -1 || e == -1)
				exit(0);

			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;
			
			if (DFS_Finding(s, e))
				cout << vexs[s].data << " ���� " << vexs[e].data << " ����·�� " << endl;
			else
				cout << vexs[s].data << " ���� " << vexs[e].data << " ������·�� " << endl;
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
		//����ͼ��������ж�����start��end����·��
		void BFS_to_FindPath(string start, string end) {
			if (Type != "DG") {
				cout << "��������ͼ";
				exit(0);
			}

			int s = LocatVex(start);
			int e = LocatVex(end);
			if (s == -1 || e == -1)
				exit(0);

			for (int i = 0; i < vexnum; i++)
				Visited[i] = false;

			if (BFS_Finding(s, e))
				cout << vexs[s].data << " ���� " << vexs[e].data << " ����·�� " << endl;
			else
				cout << vexs[s].data << " ���� " << vexs[e].data << " ������·�� " << endl;

		}


		~ALGraph() {

		}

};




/**************************ͼ���ڽӱ���������*****************/
#endif // !Common_Map

