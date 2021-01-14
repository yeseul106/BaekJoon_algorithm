#include <cstdio>
#define MAX_ELEMENT 100000
#pragma warning(disable:4996)

class HeapNode {
	int key;

public:
	HeapNode(int k = 0) : key(k) {}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
};

class MaxHeap {
	HeapNode node[MAX_ELEMENT]; 
	int size;

public:

	MaxHeap() :size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key) {
		if (isFull()) return;

		int i = ++size;

		while (i != 1 && key > getParent(i).getKey()) //부모 노드보다 키값이 크면 
		{
			node[i] = getParent(i);
			i = i / 2;

		}
		node[i].setKey(key);
	}

	HeapNode remove() {
		if (isEmpty()) return NULL;


		HeapNode root = node[1];
		HeapNode last = node[size--];;

		int parent = 1;
		int child = 2;

		while (child <= size) {
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
				child++;
			if (last.getKey() >= node[child].getKey())
				break; //마지막 노드가 더 큰 자식보다 크면 이동완료

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return root;
	}

	HeapNode& find() { return node[1]; }
};

class MinHeap {
	HeapNode node[MAX_ELEMENT];
	int size;

public:

	MinHeap() :size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key) {
		if (isFull()) return;

		int i = ++size;

		while (i != 1 && key < getParent(i).getKey()) //부모 노드보다 키값이 크면 
		{
			node[i] = getParent(i);
			i = i / 2;

		}
		node[i].setKey(key);
	}

	HeapNode remove() {
		if (isEmpty()) return NULL;


		HeapNode root = node[1];
		HeapNode last = node[size--];;

		int parent = 1;
		int child = 2;

		while (child <= size) {
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
				child++;
			if (last.getKey() <= node[child].getKey())
				break; //마지막 노드가 더 큰 자식보다 크면 이동완료

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return root;
	}

	HeapNode& find() { return node[1]; }
};

int main() {
	int n;
	scanf("%d", &n);

	MaxHeap maxheap;
	MinHeap minheap;

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);

		if (i % 2 == 0) maxheap.insert(k);
		else minheap.insert(k);

		HeapNode minNode = minheap.find();
		//printf("before min root 점검: %d\n", minNode.getKey());
		HeapNode maxNode = maxheap.find();
		//printf("before max root 점검: %d\n", maxNode.getKey());

		if (i >= 2 && (minNode.getKey() < maxNode.getKey()))
		{
			minheap.remove();
			maxheap.remove();
			minheap.insert(maxNode.getKey());
			//printf("min root 점검: %d\n", minheap.find().getKey());
			maxheap.insert(minNode.getKey());
			//printf("max root 점검: %d\n", maxheap.find().getKey());
		}

		if ((i == 1) & (minNode.getKey() < maxNode.getKey()))
			printf("%d\n", minheap.find().getKey());
		else
			printf("%d\n", maxheap.find().getKey());
	}
	return 0;
}