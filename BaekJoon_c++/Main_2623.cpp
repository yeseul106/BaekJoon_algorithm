#pragma once
#include <cstdlib>
#include<cstdio>
#define MAX_VTXS 1001
#include <stack>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int n;
int result[1000];
int resultSize = 0;
class Node
{
protected:
	int	id;	// 노드 데이터	
	Node* link;	// 노드 링크
public:
	Node(int i, Node* l = NULL) : id(i), link(l) { }
	~Node(void) { if (link != NULL) delete link; }

	int      getId() { return id; }		// id를 반환
	Node* getLink() { return link; }		// link를 반환
	void setLink(Node* l) { link = l; }	// link를 l로 설정
};
class AdjListGraph  // 인접 리스트 클래스
{
protected:
	int	size;	// 노드 개수			
	int	vertices[MAX_VTXS];	// 노드 데이터 A,B,C,D	
	Node* adj[MAX_VTXS];		// 연결리스트 헤드 정보

public:
	AdjListGraph(void) : size(0) { }
	~AdjListGraph(void) { reset(); }

	void reset(void) { 	// adj 연결리스트 해제
		for (int i = 0; i < size; i++)
			if (adj != NULL) delete adj[i];
		size = 0;
	}
	bool isEmpty() { return (size == 0); }
	bool isFull() { return (size >= MAX_VTXS); }
	int getVertex(int i) { return vertices[i]; }  // ith 노드 반환,A,B.C…

	void insertVertex(int val) {	// 노드 1개 추가 : char val
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;  // 해당 adj[] 초기화
		}
		else printf("Error: 그래프 정점 개수 초과\n");
	}
	void insertEdge(int u, int v) {
		if (adj[u] == NULL) adj[u] = new Node(v, NULL);  // insert (u,v)
		else {
			Node* p = adj[u];
			while (p != NULL) {
				if (p->getId() <= v && p->getLink() == NULL)
				{
					p->setLink(new Node(v, NULL));
					break;
				}
				if (p->getId() > v) //삽입하려는 노드 id가 더 작으면 앞에 넣기
				{
					adj[u] = new Node(v, NULL);
					adj[u]->setLink(p);
					break;
				}
				p = p->getLink();
			}
		}

		// insert (v,u)
		if (adj[v] == NULL) adj[v] = new Node(u, NULL); // 연결리스트에 노드가 아직 없는 경우
		else {  // 연결리스트 링크를 따라가서 맨 마지막에 노드 u 삽입
			Node* p = adj[v];
			while (p != NULL) {
				if (p->getId() <= u && p->getLink() == NULL)
				{
					p->setLink(new Node(u, NULL));
					break;
				}
				if (p->getId() > u) //삽입하려는 노드 id가 더 작으면 앞에 넣기
				{
					adj[v] = new Node(u, NULL);
					adj[v]->setLink(p);
					break;
				}
				p = p->getLink();
			}
		}
	}
	void display() {  // 그래프 연결 정보 디스플레이
		printf("%d\n", size);
		for (int i = 0; i < size; i++) { // 노드 갯수만큼	
			printf("%d  ", getVertex(i));	 // 각 노드에 대해
			// 연결리스트 따라가면서 인접한 노드들 출력 
			for (Node* v = adj[i]; v != NULL; v = v->getLink())
				printf("   %d", getVertex(v->getId()));
			printf("\n");
		}
	}
};
inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

class TopoSortGraph : public AdjListGraph {
public:
	TopoSortGraph(void) {}
	~TopoSortGraph(void) {}

	void insertDirEdge(int u, int v) {
		adj[u] = new Node(v, adj[u]);
	}

	void TopoSort() {
		stack<int> stack;

		int* inDeg = new int[size];

		for (int i = 0; i < size; i++)
			inDeg[i] = 0;

		for (int i = 0; i < size; i++) {
			Node* node = adj[i];
			while (node != NULL) {
				inDeg[node->getId()]++;
				node = node->getLink();
			}
		}

		for (int i = 0; i < size; i++)
			if (inDeg[i] == 0) stack.push(i);

		while (!stack.empty()) {
			int w = stack.top(); stack.pop();
			result[resultSize++] = getVertex(w);
			Node* node = adj[w];
			while (node != NULL) {
				int u = node->getId();
				inDeg[u]--;
				if (inDeg[u] == 0) stack.push(u);
				node = node->getLink();
			}
		}
		delete[] inDeg;
	}
};
int main() {
	TopoSortGraph g;
	int m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		g.insertVertex(i + 1);
	}

	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		int arr[1000];

		for (int j = 0; j < num; j++)
			scanf("%d", &arr[j]);

		for (int j = 0; j < num - 1; j++)
			g.insertDirEdge(arr[j] - 1, arr[j + 1] - 1);

		//g.display();
		//printf("\n");
	}
	//g.display();
	g.TopoSort();

	if (n != resultSize) //사이클 존재
		printf("%d", 0);
	else
		for (int i = 0; i < resultSize; i++)
			printf("%d\n", result[i]);
	return 0;
}