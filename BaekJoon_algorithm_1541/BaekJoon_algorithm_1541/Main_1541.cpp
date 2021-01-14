/*
-문제: 세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

-입력: 첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
	   그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 
	   수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.
*/

//문자열 수식 계산 -> stack을 이용 (원래는 괄호 케이스까지 고려해줘야함!)
//하지만 이 문제는 괄호 안에 + 밖에 들어갈 수 없으므로 괄호 고려 안해도 됨
//따라서 +가 나오면 괄호를 묶은 것이므로 무조건 계산하고, -는 stack에 push

#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

int main() {
	string input;
	cin >> input;

	stack<string>all;//문자열에 요소를 stack으로 저장해야 뒤에서부터 요소를 계산할 수 있음 -> 그것을 정리하기 위한 stack
	stack<int>number; //피연산자 저장 stack
	stack<string>oper; //연산자 저장 stack

	string num="";
	string tmp = "";

	//all 스택에 모든 요소 집어넣기
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != '-' && input[i] != '+') //연산자 앞까지 잘라서 숫자로 인식
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

	/*확인
	while (!all.empty()) {
		string tmp = all.top();
		cout << tmp <<" ";
		all.pop();
	}*/

	//피연산자와 연산자 스택에 나눠서 넣기
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

	//나머지 - 계산하기
	while (!oper.empty()) {
		oper.pop();
		int num1 = number.top(); number.pop();
		int num2 = number.top(); number.pop();

		number.push(num1 - num2);
	}

	if(!number.empty())
		cout << number.top();
}