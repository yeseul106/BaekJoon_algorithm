#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l, c;
vector<char> alpha;
char result[16];


bool check() {
	int vowel = 0;
	int consonant=0;

	for (int i = 0; i < l; i++) {
		char tmp = result[i];
		if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u')
			vowel++;
		else
			consonant++;
	}

	if (consonant >=2 && vowel >= 1)
		return true;
	else
		return false;
}

void DFS(int index, int count) {
	if (count == l) {
		if (check()) {
			for (int i = 0; i < l; i++) {
				cout << result[i];
			}
			cout << endl;
		}
		return;
	}

	for (int i = index; i < c; i++) {
		result[count] = (alpha.at(i));
		DFS(i+1, count+1);
	}
}

int main() {

	cin >> l >> c;


	for (int i = 0; i < c; i++) {
		char ch;
		cin >> ch;
		alpha.push_back(ch);
	}

	sort(alpha.begin(), alpha.end());

	DFS(0, 0);
}