#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int N;

	// 오른쪽으로 90도씩 바꾼다고 생각했을 때
	// 남(0) 서(1) 북(2) 동(3)
	int direction = 0; 
	string s;
	
	// 미로의 시작점이 주어지지 않아서 50X50이 아니라,
	// 100X100으로 설정하고 시작점을 (50,50)으로 해야함.
	char map[101][101];

	cin >> N;
	cin >> s;

	// 현재 좌표
	int now_r, now_c;
	now_r = now_c = 50;

	for (int i = 0; i < s.length(); i++) {
		char ch = s[i] - '0';


	}


}