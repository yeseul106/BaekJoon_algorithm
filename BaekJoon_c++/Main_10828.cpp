#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>  // ���ڿ��� �����س��� �۾��� ���� �Է� ��Ʈ��
#pragma warning (disable:4996)
using namespace std;

int N;
vector<int> stack;

void push(int n) {
	stack.push_back(n);
}

int size() {
	return stack.size();
}

int top() {
	int size = stack.size();

	if (stack.empty())
		return -1;
	else
		return stack.at(size - 1);
}

int pop() {
	int result = top();

	if (stack.empty())
		return result;
	else
	{
		stack.erase(stack.begin() + (size() - 1));
		return result;
	}
}


int empty() {
	if (stack.empty())
		return 1;
	else
		return 0;
}

int main() {
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);

		vector<string> s;

		//�����ڿ� ���� split (vector�� ����)
		istringstream ss(str);
		string tmp;

		while (getline(ss, tmp, ' ')) {
			s.push_back(tmp);
		}

		if (s[0].compare("push") == 0)
			push(stoi(s[1]));
		else if (s[0].compare("top") == 0)
			printf("%d\n", top());
		else if (s[0].compare("size") == 0)
			printf("%d\n", size());
		else if (s[0].compare("empty") == 0)
			printf("%d\n", empty());
		else if (s[0].compare("pop") == 0)
			printf("%d\n", pop());
	}

}