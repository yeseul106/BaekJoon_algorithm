#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int main() {
	stack<int> st;
	vector<int> vec;
	vector<char> printVec;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		vec.push_back(k);
	}

	int index = 0;
	for (int i = 1; i <= n; i++) {
		st.push(i);
		printVec.push_back('+');

		while (vec.at(index) <= i && !st.empty()) {
			if (st.top() == vec.at(index))
			{
				st.pop();
				printVec.push_back('-');
				index++;
			}
			else if (vec.at(index) < st.top())
				break;
			if (index >= n)
				break;
		}
		
	}

	if (!st.empty())
	{
		printf("NO");
	}
	else {
		int idx = 0;
		while (idx<printVec.size()) {
			printf("%c\n", printVec.at(idx));
			idx++;
		}
			
	}
}