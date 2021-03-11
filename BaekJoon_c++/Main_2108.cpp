/*
* merge sort
* : ����Ʈ �� ���� �κ� ����Ʈ�� �����ϰ� ���� ����
* => ���ĵ� �κ� ����Ʈ�� ���ؼ� ��ü ����Ʈ�� ����
* 
* ���� ��Ʈ�� �ð��ʰ�....
* ���ͷ� �迭 ���� ������ STL ���� sort �Լ��� ����غ��Ҵ�.
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
		sorted[k++] = (list[i] <= list[j] ? list[i++] : list[j++]); //i��°�� j��° �� �� ���� ���� �ֱ�

	if (i > mid)  //left �迭�� ���� �������Ƿ� right �������� sorted�� �����ϱ�
		for (l = j; l <= right; l++, k++)
			sorted[k] = list[l];
	else //right �迭�� ���� �������Ƿ� left �������� sorted�� �����ϱ�
		for (l = i ; l<= mid; l++, k++)
			sorted[k] = list[l];

	for (l = left; l <= right; l++) //���ĵ� sorted �迭�� list�� �����ؼ� ����
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
* �� �Լ� ���� �ð��ʰ�......
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
	int arr[8001] = { 0 }; //�ֺ��� ���ϱ� ����
	double sum = 0;
	int temp = 0;

	for (int i = 0; i < N; i++)
	{
		int k;
		scanf("%d", &k);
		v.push_back(k);
		sum += k;

		temp = (k <= 0) ? abs(k) : k + 4000;
		//�־����� ���� -4000~4000 ���̰�
		//���� �迭�� 0~8000���� �ε��� �̹Ƿ� �־����� ���� ������ �����, ����� +4000�ؼ� �����ϱ�
		arr[temp]++;
	}
		
	//merge_sort(list, 0, N-1);
	sort(v.begin(), v.end());

	//��� ���
    double before = sum / N;

	int average = round(sum / N);
	//�߾Ӱ�
	int middle = v.at(N / 2);

	//�ֺ� 
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

			if (i <= 4000) {  //���� ���� ����
				max =  -beforeindex;  //������ �������ϱ� �ٷ� ���� ���� �ι����� �� 
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
	//����
	int range = v[N - 1] - v[0];

	printf("%d\n", average);
	printf("%d\n", middle);
	printf("%d\n", max);
	printf("%d\n", range);
}