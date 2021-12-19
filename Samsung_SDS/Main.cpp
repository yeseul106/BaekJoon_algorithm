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

		//여행 지도 입력 받기
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			map.push_back(num);

			if (num == 3) {
				end = j;
				campingspace.push(j);
			}
		}

		//0: 출발지, 1: 도로, 2: 휴게소, 3: 캠핑장
		while (start <= end && !campingspace.empty()) {
			bool isvalid = false;
			int current_camp_idx = campingspace.front();
			//cout << "현재 목표 캠핑장: " << current_camp_idx << endl;
			int time = current_camp_idx - start;
			
			if (end - start <= 6) {
				totalTime += end - start;
				break;
			}

			if (current_camp_idx - before_camp <= 15) { // 캠핑장 사이 거리가 15시간 이내
				if (time <= 6) { // 캠핑장 사이 거리가 6시간 이내
					before_camp_idx = current_camp_idx;
					campingspace.pop();
					//cout << "다음 캠핑장 확인, 현재까지 시간: " << totalTime << endl;
				}
				else { // 캠핑장 거리가 6시간 이내가 아닐 때
					int max_2 = start;
					for (int k = start+1; k < current_camp_idx; k++) {
						if (map.at(k) == 2) {
							if (max_2 < k) {
								max_2 = k;
							}
						}
					}
					if (isvalid) {
						totalTime += 1; //휴게소 1시간 휴식
						isvalid = true;
						totalTime += max_2 - start;
						start = max_2;
						//cout << "휴게소 도착 ! 현재 위치: " << start << endl;
						before_camp_idx = current_camp_idx;
						campingspace.pop();
					}
					else { //휴게소가 없어서 갈수가 없다면 이전 캠핑장에 머물러야함.
						before_camp = before_camp_idx;
						totalTime += before_camp_idx - start;
						start = before_camp_idx;
						//cout << "캠핑장 도착 ! 현재 위치: " << start << endl;
					}
					
				}
			}
			else {
				before_camp = before_camp_idx;
				totalTime += before_camp_idx-start;
				start = before_camp_idx;
				//cout << "캠핑장 도착 ! 현재 위치: " << start << endl;
			}
			//cout << "현재까지의 시간: " << totalTime << endl;
			//cout << "---------------------------------" << endl;

		}

		if (totalTime == 0)
			totalTime = -1;

		cout << "#" << i + 1 << " " << totalTime << endl;
	}
}