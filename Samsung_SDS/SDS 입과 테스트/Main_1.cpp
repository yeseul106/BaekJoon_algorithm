#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {

    int T, N;
    vector<int> output;

    //�׽�Ʈ ���̽� �� �Է� �ޱ�
        cin >> T;

        for (int i = 0; i < T; i++) {
            int result = 0;
            int count = 0;
            
            cin >> N;
            int j = N - 1;
            vector<int> nums;

            // ī�� �� �Է� �ޱ�
            for (int j = 0; j < N; j++) {
                int tmp;
                cin >> tmp;
                nums.push_back(tmp);
            }

            // ������������ ����
            sort(nums.begin(), nums.end());

            //���� ū ���� �̱� (N/2 ��ŭ �ݺ�)
            while (count < N/2) {
                int max = nums.at(j);
                nums[j] = 0;
                //cout <<"max " << max << endl;

                if (max != 0) {
                    //max�� ������ ������ ���
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
                        //max�� ¦���� ��� -> ¦���� �̾ƾ���
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
                        //max�� Ȧ���� ��� -> Ȧ���� �̾ƾ���
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