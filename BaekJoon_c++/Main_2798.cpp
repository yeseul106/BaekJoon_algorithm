//���� �Ǽ��� �κе�
// 1) ������������ ������ ���� �պ��� ���ʴ�� Ž���ص� ���̸� ���ؾ���
// EX --- 10 8 4 2 1 , M�� 14�� ��, ������ 14(8+4+2)�ε� ���� �ڵ�� 13(10+2+1)�� ���� �ȴ�.

// 2) �ݵ�� 3���� �̾ƾ� �ϴ� ���� ������� ����.



#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int main() {
	vector<int> arr;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		arr.push_back(k);
	}

	int result=300000;

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int temp = arr[i] + arr[j] + arr[k];

				if (temp < M) {
					if (abs(result-M) >= abs(temp-M))
					{
						result = temp;
					}
				}
				else if (temp == M)
				{
					result = temp;
					i = N-1;
				}
			}
		}
	}
	cout << result;
} 