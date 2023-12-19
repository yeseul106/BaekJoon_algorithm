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

	unordered_map<string, int> in_tunnel; // 터널에 들어간 순서를 해시맵으로 저장해놓기
	vector<string> out_tunnel; // 터널에서 나온 순서 저장

	cin >> size;

	// 터널에 들어간 순서 입력 받기
	for (int i = 0; i < size; i++) {
		string s;
		cin >> s;
		in_tunnel[s] = i;
	}

	// 터널에서 나온 순서대로 입력 받기
	for (int i = 0; i < size; i++) {
		string temp;
		cin >> temp;
		out_tunnel.push_back(temp);
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			
			// 터널에서 나올 때 뒤에 있는 차들과 비교 => 들어온 순서와 다르면 추월한 차  
			if (in_tunnel[out_tunnel[i]] > in_tunnel[out_tunnel[j]]) {
				cnt += 1;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}