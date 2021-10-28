/*
����: �ν��̴� �����п����� �ܾ� ���� ������ Ǫ�� ������ �޾Ҵ�.
�ܾ� ���� ������ N���� �ܾ�� �̷���� ������, �� �ܾ�� ���ĺ� �빮�ڷθ� �̷���� �ִ�. �̶�, �� ���ĺ� �빮�ڸ� 0���� 9������ ���� �� �ϳ��� �ٲ㼭 N���� ���� ���ϴ� �����̴�. ���� ���ĺ��� ���� ���ڷ� �ٲ�� �ϸ�, �� �� �̻��� ���ĺ��� ���� ���ڷ� �ٲ������ �� �ȴ�.
���� ���, GCF + ACDEB�� ����Ѵٰ� �� ��, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7�� �����Ѵٸ�, �� ���� ���� 99437�� �Ǿ �ִ밡 �� ���̴�.
N���� �ܾ �־����� ��, �� ���� ���� �ִ�� ����� ���α׷��� �ۼ��Ͻÿ�.

- �Է�: ù° �ٿ� �ܾ��� ���� N(1 �� N �� 10)�� �־�����. ��° �ٺ��� N���� �ٿ� �ܾ �� �ٿ� �ϳ��� �־�����. �ܾ�� ���ĺ� �빮�ڷθ� �̷�����ִ�. 
        ��� �ܾ ���ԵǾ� �ִ� ���ĺ��� �ִ� 10���̰�, ���� �ִ� ���̴� 8�̴�. ���� �ٸ� ���ڴ� ���� �ٸ� ���ڸ� ��Ÿ����.

- ���: ù° �ٿ� �־��� �ܾ��� ���� �ִ��� ����Ѵ�.
*/

//�׸��� �˰��� => 1) �ڸ����� ���� �� (�����ڸ��� ���� ū���� ����) 2) �ڸ����� ���ٸ� ������� ���� ����

//���� Ʋ�� �κ� -> �ڸ����� ���ٰ� ������ ū�� �ƴ�! ���ĺ��� �󵵰� �� ���ٸ� �װ� �� ū ������ ������� �ִ�
//100�� �ڸ�->���ĺ� 100�� �ִٰ� ����, 10�� �ڸ�-> ���ĺ� 10���ִٰ� ����
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string arr[10];
map<char, int> alpha;
int alphaNum[26];
int alphaScore[26];
int n;

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
        char ch1 = a.first;
        char ch2 = b.first;

        if (alphaNum[ch1 - 'A'] > alphaNum[ch2 - 'A'])
            return true;
        else
            return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < 26; i++)
        alphaNum[i] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        //���ĺ� �ڸ��� ����
        for (int j = 0; j < arr[i].length(); j++) {
            int num = arr[i].length() - j;
            int ch = arr[i].at(j);
            alphaNum[ch - 'A']+=pow(10,num-1); //���ĺ� ��� ���Դ���

            if (alpha.find(ch) == alpha.end()) //���� ���ĺ��̶��
                alpha.insert(pair<char, int>(ch, num));
            else
                if (alpha.at(ch) < num)
                    alpha.at(ch) = num;
        }
    }
    
        //map�� value�� �������� �����ϱ� ���� vector �̿��ϱ�
        vector<pair<char, int>> vec(alpha.begin(), alpha.end());
        sort(vec.begin(), vec.end(), cmp);

        
        int result=0;
       
        //���ĺ��� ���� �Ҵ��ϱ�
        for (int i = 0; i<vec.size(); i++) {
            alphaScore[vec[i].first-'A'] = 9 - i;
        }
        
        for (int i = 0; i < n; i++) {
            string s = arr[i];

            for (int j = 0; j < s.length(); j++) {
                int r = s.length() - j - 1;
                result += alphaScore[s.at(j) - 'A'] * pow(10, r);
            }
        }
        cout << result << endl;
    
        return 0;
}