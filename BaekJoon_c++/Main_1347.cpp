#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int N;

	// ���������� 90���� �ٲ۴ٰ� �������� ��
	// ��(0) ��(1) ��(2) ��(3)
	int direction = 0; 
	string s;
	
	// �̷��� �������� �־����� �ʾƼ� 50X50�� �ƴ϶�,
	// 100X100���� �����ϰ� �������� (50,50)���� �ؾ���.
	char map[101][101];

	cin >> N;
	cin >> s;

	// ���� ��ǥ
	int now_r, now_c;
	now_r = now_c = 50;

	for (int i = 0; i < s.length(); i++) {
		char ch = s[i] - '0';


	}


}