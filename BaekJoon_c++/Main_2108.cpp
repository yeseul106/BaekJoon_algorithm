/*
* merge sort
* : 리스트 두 개의 부분 리스트로 분할하고 각각 정렬
* => 정렬된 부분 리스트를 합해서 전체 리스트를 정렬
* 
* 머지 소트도 시간초과....
* 벡터로 배열 값을 저장해 STL 내장 sort 함수를 사용해보았다.
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#pragma warning (disable:4996)
#define MAX_SIZE 500000
using namespace std;

/*
static void merge(int list[], int left, int mid, int right) {
	int i, j, k = left, l;
	static int sorted[MAX_SIZE];

	for (i = left, j = mid + 1; i <= mid && j <= right;)
		sorted[k++] = (list[i] <= list[j] ? list[i++] : list[j++]); //i번째와 j번째 중 더 작은 값을 넣기

	if (i > mid)  //left 배열이 먼저 끝났으므로 right 나머지를 sorted에 복사하기
		for (l = j; l <= right; l++, k++)
			sorted[k] = list[l];
	else //right 배열이 먼저 끝났으므로 left 나머지를 sorted에 복사하기
		for (l = i ; l<= mid; l++, k++)
			sorted[k] = list[l];

	for (l = left; l <= right; l++) //정렬된 sorted 배열을 list에 복사해서 전달
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
*/

/*
* 이 함수 마저 시간초과......
int findMode(vector<int> a, int size) {
	int mode,freq=1;
	int check = 0; int count = 0;
	for (int i = 0; i < size; i++) {
		freq = 1;
		for (int j = i + 1; j < size; j++) {
			if (a[i] == a[j])
				freq += 1;
		}
		if (freq > count){
			mode = a[i];
			count = freq;	
		}
		else if (freq == count) {
			check += 1;
			if (check < 2)
				mode = a[i];
			else
				mode = mode;
		}
	}

	return mode;
 }
 */

int main() {
	int N;
	scanf("%d", &N);

	vector<int> v;
	int arr[8001] = { 0 }; //최빈값을 구하기 위해
	double sum = 0;
	int temp = 0;

	for (int i = 0; i < N; i++)
	{
		int k;
		scanf("%d", &k);
		v.push_back(k);
		sum += k;

		temp = (k <= 0) ? abs(k) : k + 4000;
		//주어지는 수는 -4000~4000 사이값
		//지금 배열이 0~8000까지 인덱스 이므로 주어지는 수가 음수면 양수로, 양수면 +4000해서 저장하기
		arr[temp]++;
	}
		
	//merge_sort(list, 0, N-1);
	sort(v.begin(), v.end());

	//산술 평균
    double before = sum / N;

	int average = round(sum / N);
	//중앙값
	int middle = v.at(N / 2);

	//최빈값 
	int max = 0; int flag = 1; int cnt = 0;
	int beforeindex=0;
	for (int i = 0; i < 8001; i++) {
		if (cnt < arr[i])
		{
			cnt = arr[i];
			max = (i <= 4000) ? -i : i - 4000;
			flag = 1;
			beforeindex = i;
		}
		else if (cnt == arr[i]) {
			flag += 1;

			if (i <= 4000) {  //나온 값이 음수
				max =  -beforeindex;  //음수면 뒤집히니까 바로 이전 것이 두번쨰가 됨 
				beforeindex = i;
			}
			else {
				if (flag == 2)
				{
					max = (i <= 4000) ? -i : i - 4000;
				}
			}
		}
	}
	//범위
	int range = v[N - 1] - v[0];

	printf("%d\n", average);
	printf("%d\n", middle);
	printf("%d\n", max);
	printf("%d\n", range);
}