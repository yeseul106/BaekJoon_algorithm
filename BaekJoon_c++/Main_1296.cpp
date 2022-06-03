#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int y_L = 0;
	int y_O = 0;
	int y_V = 0;
	int y_E = 0;

	string answer;
	string yeondo;
	int max_num=-1;
	int N;

	cin >> yeondo;
	cin >> N;

	//���� �̸����� L,O.V,E ���� ���ϱ�
	for (int i = 0; i < yeondo.length(); i++) {
		char ch = yeondo.at(i);

		switch (ch)
		{
		case 'L':
			y_L++;
			break;
		case 'O':
			y_O++;
			break;
		case 'V':
			y_V++;
			break;
		case 'E':
			y_E++;
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		string tmp;
		int L = 0;
		int O = 0;
		int V = 0;
		int E = 0;

		cin >> tmp;

		for (int j = 0; j < tmp.length(); j++) {
			char ch = tmp.at(j);

			switch (ch)
			{
			case 'L':
				L++;
				break;
			case 'O':
				O++;
				break;
			case 'V':
				V++;
				break;
			case 'E':
				E++;
				break;
			default:
				break;
			}
		}

		// ���� �̸��� L,O,V,E ���� ���ϱ�
		L += y_L;
		O += y_O;
		V += y_V;
		E += y_E;

		int tmp_num = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
		//cout << "num: " << tmp_num << endl;

		if (tmp_num > max_num) {
			max_num = tmp_num;
			answer = tmp;
		}
		else if (tmp_num == max_num) {
			if (answer.compare(tmp) > 0) {
				answer = tmp;
			}
		}

	}

	cout << answer << endl;
}