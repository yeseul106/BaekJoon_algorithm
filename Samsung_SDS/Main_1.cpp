#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {

    int T, N;
    vector<int> output;

    //테스트 케이스 수 입력 받기
        cin >> T;

        for (int i = 0; i < T; i++) {
            int result = 0;
            int count = 0;
            
            cin >> N;
            int j = N - 1;
            vector<int> nums;

            // 카드 수 입력 받기
            for (int j = 0; j < N; j++) {
                int tmp;
                cin >> tmp;
                nums.push_back(tmp);
            }

            // 오름차순으로 정렬
            sort(nums.begin(), nums.end());

            //가장 큰 숫자 뽑기 (N/2 만큼 반복)
            while (count < N/2) {
                int max = nums.at(j);
                nums[j] = 0;
                //cout <<"max " << max << endl;

                if (max != 0) {
                    //max가 마지막 숫자일 경우
                    if (count == N / 2) {
                        for (int k = 0; k < j; k++) {
                            int tmp = nums.at(k);

                            if (tmp != 0) {
                                if ((tmp + max) % 2 == 0) {
                                    result += max;
                                }
                                else if ((tmp + max) % 2 != 0) {
                                    result += tmp;
                                }
                            }
                        }
                    }
                    else {
                        //max가 짝수일 경우 -> 짝수를 뽑아야함
                        if (max % 2 == 0) {
                            bool isvalid = false;
                            int tmp2 = 0;
                            int idx_tmp = 0;
                            for (int k = 0; k < j; k++) {
                                int tmp = nums.at(k);
                                if (tmp2 < tmp) {
                                    tmp2 = tmp;
                                    idx_tmp = k;
                                }

                                if (tmp % 2 == 0 && tmp != 0) {
                                    nums[k] = 0;
                                    result += max;
                                    isvalid = true;
                                    break;
                                }
                                if (k == j - 1 && !isvalid) {
                                    result += tmp2;
                                    nums[idx_tmp] = 0;
                                    j = j - 1;
                                }
                            }
                        }
                        //max가 홀수일 경우 -> 홀수를 뽑아야함
                        else {
                            bool isvalid = false;
                            int tmp2 = 0;
                            int idx_tmp = 0;
                            for (int k = 0; k < j; k++) {
                                int tmp = nums.at(k);
                                if (tmp2 < tmp) {
                                    tmp2 = tmp;
                                    idx_tmp = k;
                                }
                              
                                if (tmp % 2 != 0 && tmp != 0) {
                                    nums[k] = 0;
                                    result += max;
                                    isvalid = true;
                                    break;
                                }
                                if (k == j - 1 && !isvalid) {
                                    result += tmp2;
                                    nums[idx_tmp] = 0;
                                    j = j - 1;
                                }
                            }
                        }
                    }
                    j = j - 1;
                }
                else {
                    j = j - 1;
                    count--;
                }
                count++;
                
                //cout << "#" << count<< " " << result << endl;
            }
            output.push_back(result);
        }

    for (int a = 0; a < output.size(); a++) {
        cout << "#" << a + 1 << " " << output.at(a) << endl;
    }
    return 0;
}