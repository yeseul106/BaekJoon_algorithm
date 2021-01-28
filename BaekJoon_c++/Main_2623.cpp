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
	int	id;	// ��� ������	
	Node* link;	// ��� ��ũ
public:
	Node(int i, Node* l = NULL) : id(i), link(l) { }
	~Node(void) { if (link != NULL) delete link; }

	int      getId() { return id; }		// id�� ��ȯ
	Node* getLink() { return link; }		// link�� ��ȯ
	void setLink(Node* l) { link = l; }	// link�� l�� ����
};
class AdjListGraph  // ���� ����Ʈ Ŭ����
{
protected:
	int	size;	// ��� ����			
	int	vertices[MAX_VTXS];	// ��� ������ A,B,C,D	
	Node* adj[MAX_VTXS];		// ���Ḯ��Ʈ ��� ����

public:
	AdjListGraph(void) : size(0) { }
	~AdjListGraph(void) { reset(); }

	void reset(void) { 	// adj ���Ḯ��Ʈ ����
		for (int i = 0; i < size; i++)
			if (adj != NULL) delete adj[i];
		size = 0;
	}
	bool isEmpty() { return (size == 0); }
	bool isFull() { return (size >= MAX_VTXS); }
	int getVertex(int i) { return vertices[i]; }  // ith ��� ��ȯ,A,B.C��

	void insertVertex(int val) {	// ��� 1�� �߰� : char val
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;  // �ش� adj[] �ʱ�ȭ
		}
		else printf("Error: �׷��� ���� ���� �ʰ�\n");
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
				if (p->getId() > v) //�����Ϸ��� ��� id�� �� ������ �տ� �ֱ�
				{
					adj[u] = new Node(v, NULL);
					adj[u]->setLink(p);
					break;
				}
				p = p->getLink();
			}
		}

		// insert (v,u)
		if (adj[v] == NULL) adj[v] = new Node(u, NULL); // ���Ḯ��Ʈ�� ��尡 ���� ���� ���
		else {  // ���Ḯ��Ʈ ��ũ�� ���󰡼� �� �������� ��� u ����
			Node* p = adj[v];
			while (p != NULL) {
				if (p->getId() <= u && p->getLink() == NULL)
				{
					p->setLink(new Node(u, NULL));
					break;
				}
				if (p->getId() > u) //�����Ϸ��� ��� id�� �� ������ �տ� �ֱ�
				{
					adj[v] = new Node(u, NULL);
					adj[v]->setLink(p);
					break;
				}
				p = p->getLink();
			}
		}
	}
	void display() {  // �׷��� ���� ���� ���÷���
		printf("%d\n", size);
		for (int i = 0; i < size; i++) { // ��� ������ŭ	
			printf("%d  ", getVertex(i));	 // �� ��忡 ����
			// ���Ḯ��Ʈ ���󰡸鼭 ������ ���� ��� 
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

	if (n != resultSize) //����Ŭ ����
		printf("%d", 0);
	else
		for (int i = 0; i < resultSize; i++)
			printf("%d\n", result[i]);
	return 0;
}