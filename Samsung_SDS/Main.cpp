#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int T;
	//vector<int> result;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int start = 0; int end = 0;
		int N;
		int totalTime = 0;
		int before_camp_idx = 0;
		vector<int> map;
		queue<int> campingspace;
		int before_camp = 0;

		cin >> N;

		//���� ���� �Է� �ޱ�
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			map.push_back(num);

			if (num == 3) {
				end = j;
				campingspace.push(j);
			}
		}

		//0: �����, 1: ����, 2: �ްԼ�, 3: ķ����
		while (start <= end && !campingspace.empty()) {
			bool isvalid = false;
			int current_camp_idx = campingspace.front();
			//cout << "���� ��ǥ ķ����: " << current_camp_idx << endl;
			int time = current_camp_idx - start;
			
			if (end - start <= 6) {
				totalTime += end - start;
				break;
			}

			if (current_camp_idx - before_camp <= 15) { // ķ���� ���� �Ÿ��� 15�ð� �̳�
				if (time <= 6) { // ķ���� ���� �Ÿ��� 6�ð� �̳�
					before_camp_idx = current_camp_idx;
					campingspace.pop();
					//cout << "���� ķ���� Ȯ��, ������� �ð�: " << totalTime << endl;
				}
				else { // ķ���� �Ÿ��� 6�ð� �̳��� �ƴ� ��
					int max_2 = start;
					for (int k = start+1; k < current_camp_idx; k++) {
						if (map.at(k) == 2) {
							if (max_2 < k) {
								max_2 = k;
							}
						}
					}
					if (isvalid) {
						totalTime += 1; //�ްԼ� 1�ð� �޽�
						isvalid = true;
						totalTime += max_2 - start;
						start = max_2;
						//cout << "�ްԼ� ���� ! ���� ��ġ: " << start << endl;
						before_camp_idx = current_camp_idx;
						campingspace.pop();
					}
					else { //�ްԼҰ� ��� ������ ���ٸ� ���� ķ���忡 �ӹ�������.
						before_camp = before_camp_idx;
						totalTime += before_camp_idx - start;
						start = before_camp_idx;
						//cout << "ķ���� ���� ! ���� ��ġ: " << start << endl;
					}
					
				}
			}
			else {
				before_camp = before_camp_idx;
				totalTime += before_camp_idx-start;
				start = before_camp_idx;
				//cout << "ķ���� ���� ! ���� ��ġ: " << start << endl;
			}
			//cout << "��������� �ð�: " << totalTime << endl;
			//cout << "---------------------------------" << endl;

		}

		if (totalTime == 0)
			totalTime = -1;

		cout << "#" << i + 1 << " " << totalTime << endl;
	}
}