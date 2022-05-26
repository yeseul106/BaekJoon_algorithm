#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int size;
	int cnt = 0;

	unordered_map<string, int> in_tunnel; // �ͳο� �� ������ �ؽø����� �����س���
	vector<string> out_tunnel; // �ͳο��� ���� ���� ����

	cin >> size;

	// �ͳο� �� ���� �Է� �ޱ�
	for (int i = 0; i < size; i++) {
		string s;
		cin >> s;
		in_tunnel[s] = i;
	}

	// �ͳο��� ���� ������� �Է� �ޱ�
	for (int i = 0; i < size; i++) {
		string temp;
		cin >> temp;
		out_tunnel.push_back(temp);
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			
			// �ͳο��� ���� �� �ڿ� �ִ� ����� �� => ���� ������ �ٸ��� �߿��� ��  
			if (in_tunnel[out_tunnel[i]] > in_tunnel[out_tunnel[j]]) {
				cnt += 1;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}