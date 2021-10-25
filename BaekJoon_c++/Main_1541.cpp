/*
-����: �����̴� ����� +, -, �׸��� ��ȣ�� ������ ���� �������. �׸��� ���� �����̴� ��ȣ�� ��� ������.
�׸��� ���� �����̴� ��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ������� �Ѵ�.
��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ����� ���α׷��� �ۼ��Ͻÿ�.

-�Է�: ù° �ٿ� ���� �־�����. ���� ��0��~��9��, ��+��, �׸��� ��-�������� �̷���� �ְ�, ���� ó���� ������ ���ڴ� �����̴�. 
	   �׸��� �����ؼ� �� �� �̻��� �����ڰ� ��Ÿ���� �ʰ�, 5�ڸ����� ���� ���ӵǴ� ���ڴ� ����. 
	   ���� 0���� ������ �� �ִ�. �Է����� �־����� ���� ���̴� 50���� �۰ų� ����.
*/

//���ڿ� ���� ��� -> stack�� �̿� (������ ��ȣ ���̽����� ����������!)
//������ �� ������ ��ȣ �ȿ� + �ۿ� �� �� �����Ƿ� ��ȣ ��� ���ص� ��
//���� +�� ������ ��ȣ�� ���� ���̹Ƿ� ������ ����ϰ�, -�� stack�� push

#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

int main() {
	string input;
	cin >> input;

	stack<string>all;//���ڿ��� ��Ҹ� stack���� �����ؾ� �ڿ������� ��Ҹ� ����� �� ���� -> �װ��� �����ϱ� ���� stack
	stack<int>number; //�ǿ����� ���� stack
	stack<string>oper; //������ ���� stack

	string num="";
	string tmp = "";

	//all ���ÿ� ��� ��� ����ֱ�
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != '-' && input[i] != '+') //������ �ձ��� �߶� ���ڷ� �ν�
		{
			num += input[i];
			if (i == input.length() - 1)
				all.push(num);
		}
		else if (input[i] == '+') {
			all.push(num);
			num.clear();

			all.push("+");
		}
		else if (input[i] == '-') {
			all.push(num);
			num.clear();

			all.push("-");
		}
	}

	/*Ȯ��
	while (!all.empty()) {
		string tmp = all.top();
		cout << tmp <<" ";
		all.pop();
	}*/

	//�ǿ����ڿ� ������ ���ÿ� ������ �ֱ�
	while (!all.empty()) {
		string ss = all.top(); all.pop();
		if (ss.compare("+") == 0) {
			int ttmp = number.top() + stoi(all.top());
			number.pop(); all.pop();
			number.push(ttmp);
		}
		else if (ss.compare("-") == 0) {
			oper.push(all.top());
		}
		else {
			number.push(stoi(ss));
		}
	}

	//������ - ����ϱ�
	while (!oper.empty()) {
		oper.pop();
		int num1 = number.top(); number.pop();
		int num2 = number.top(); number.pop();

		number.push(num1 - num2);
	}

	if(!number.empty())
		cout << number.top();
}