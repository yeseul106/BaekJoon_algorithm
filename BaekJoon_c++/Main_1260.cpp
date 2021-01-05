//BaekJoon_1260_ys

#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 1010
#define MAX_QUEUE_SIZE	1010
#pragma warning (disable:4996)

class CircularQueue
{
    int	front;
    int	rear;
    int	data[MAX_QUEUE_SIZE];

public:
    CircularQueue() { front = rear = 0; }
    ~CircularQueue() { }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
    int getSize() {
        int max = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        return (max - front);
    }

    void enqueue(int val) {
        if (isFull()) {
            printf("  error: ť ��ȭ���� \n");
            system("pause");
        }
        else {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            printf("  Error: ť �������\n");
            system("wait");
        }
        else {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
        return 0;
    }

    int peek() {
        if (isEmpty()) {
            printf("  Error: ť �������\n");
            system("wait");
        }
        else
            return data[(front + 1) % MAX_QUEUE_SIZE];
    }

    void display() {
        printf("ť ���� : ");
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++)
            printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
        printf("\n");
    }

};

class Node {
protected:
    int id; 	    // ������ id
    Node* link; 	// ���� ����� ������
public:
    Node(int i, Node* l = NULL) : id(i), link(l) { }
    ~Node() {
        if (link != NULL) delete link;
    }
    int   getId() { return id; }
    Node* getLink() { return link; }
    void  setLink(Node* l) { link = l; }
};

class AdjListGraph {
protected:
    int size;                // ������ ����
    int vertices[MAX_VTXS]; // ���� ���� (���뿡 ���� Ȯ�� �ʿ�)
    Node* adj[MAX_VTXS];     // �� ������ ���� ����Ʈ
    int t[100][100];
public:
    int p, q;

    AdjListGraph() : size(0) { }
    ~AdjListGraph() { reset(); }
    void reset(void) {
        for (int i = 0; i < size; i++)
            if (adj[i] != NULL) delete adj[i];
    }

    bool isEmpty() { return (size == 0); }
    bool isFull() { return (size >= MAX_VTXS); }
    int getVertex(int i) { return vertices[i]; }

    void insertVertex(int val) {      // ���� ���� ����
        if (!isFull()) {
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else printf("Error: �׷��� ���� ���� �ʰ�\n");
    }

    void insertEdge(int u, int v) {    // ���� ���� ����       
        if (adj[u] == NULL) adj[u] = new Node(v, NULL);
        else {
            Node* p = adj[u];
            Node* q = p;
            while (p != NULL && p->getId() < v) {
                q = p;
                p = p->getLink();
            }
            if (p == q) adj[u] = new Node(v, adj[u]);
            else q->setLink(new Node(v, p));
        }

        if (adj[v] == NULL) adj[v] = new Node(u, NULL);
        else {
            Node* p = adj[v];
            Node* q = p;
            while (p != NULL && p->getId() < u) {
                q = p;
                p = p->getLink();
            }
            if (p == q) adj[v] = new Node(u, adj[v]);
            else q->setLink(new Node(u, p));
        }
    }

    void display() {
        printf("%d\n", size);                // ������ ���� ���
        for (int i = 0; i < size; i++) {      // �� ���� ���� ���
            printf("%d ", getVertex(i));         // ������ �̸� ���
            for (Node* v = adj[i]; v != NULL; v = v->getLink())
                printf(" %d", getVertex(v->getId()));
            printf("\n");
        }
    }
    Node* adjacent(int v) { return adj[v]; }
};

class SrchALGraph : public AdjListGraph
{
    bool	visited[MAX_VTXS];
public:
    void resetVisited() {
        for (int i = 0; i < size; i++)
            visited[i] = false;
    }

    bool isLinked(int u, int v) {
        for (Node* p = adj[u]; p != NULL; p = p->getLink())
            if (p->getId() == v) return true;
        return false;
    }

    // ���� �켱 Ž�� 
    void DFS(int v) {
        visited[v] = true;
        printf("%d ", getVertex(v));

        for (Node* p = adj[v]; p != NULL; p = p->getLink())
            if (visited[p->getId()] == false)
                DFS(p->getId());
    }

    // �ʺ� �켱 Ž��
    void BFS(int v) {
        visited[v] = true;
        printf("%d ", getVertex(v));

        CircularQueue que;
        que.enqueue(v);

        while (!que.isEmpty()) {
            int v = que.dequeue();
            for (Node* w = adj[v]; w != NULL; w = w->getLink()) {
                int id = w->getId();
                if (!visited[id]) {
                    visited[id] = true;
                    printf("%d ", getVertex(id));
                    que.enqueue(id);
                }
            }
        }
        printf("\n");
    }
};

int main()

{
    SrchALGraph graph;
    int n, m, v, a, b;
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < n; i++)
        graph.insertVertex(i + 1);

    for (int j = 0; j < m; j++) {
        scanf("%d %d", &a, &b);
        graph.insertEdge(a - 1, b - 1);
    }

    graph.resetVisited();
    graph.DFS(v - 1); printf("\n");
    graph.resetVisited();
    graph.BFS(v - 1); printf("\n");

    return 0;
}
