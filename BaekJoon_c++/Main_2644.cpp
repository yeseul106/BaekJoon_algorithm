#include <iostream>
using namespace std;

int n; //전체 사람의 수
int family[101][101] = { 0 };//가족 관계도
int result = -1; //촌수
int visited[101] = { 0 }; //노드 방문했는지

void dfs(int parent, int child, int cnt) {
	if (parent == child) {
		result = cnt; //지금 탐색중인 노드(parent)와 목표인 child가 같아지면 종료 (목표 노드에 도달!)
		return;
	}
	visited[parent] = 1; //방문했다고 표시

	for (int i = 0; i < n; i++) {
		if (family[parent][i] == 1 && visited[i] == 0) {
			dfs(i, child, cnt+1); //현재 탐색 노드에서 연결된 노드를 탐색하기 위해 dfs 호출
		}
	}
}

int main() {
	cin >> n;
	int a, b; //촌수를 구해야하는 사람의 번호
	cin >> a >> b;
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;
		//인덱스는 1 작은거 주의!
		family[parent - 1][child - 1] = 1;
		family[child - 1][parent - 1] = 1;
	}
	dfs(a-1, b-1, 0); //인덱스를 넘겨야하므로 -1
	cout << result; //result를 -1로 초기화 했기 때문에 친척관계 없으면(연결 안되어있으면) -1

	return 0;
}