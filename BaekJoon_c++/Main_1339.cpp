/*
문제: 민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.
단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다. 이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다. 같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.
예를 들어, GCF + ACDEB를 계산한다고 할 때, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 두 수의 합은 99437이 되어서 최대가 될 것이다.
N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.

- 입력: 첫째 줄에 단어의 개수 N(1 ≤ N ≤ 10)이 주어진다. 둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다. 단어는 알파벳 대문자로만 이루어져있다. 
        모든 단어에 포함되어 있는 알파벳은 최대 10개이고, 수의 최대 길이는 8이다. 서로 다른 문자는 서로 다른 숫자를 나타낸다.

- 출력: 첫째 줄에 주어진 단어의 합의 최댓값을 출력한다.
*/

//그리디 알고리즘 => 1) 자릿수를 먼저 비교 (높은자리수 부터 큰수를 배정) 2) 자릿수가 같다면 순서대로 수를 배정

//내가 틀린 부분 -> 자릿수가 높다고 무조건 큰수 아님! 알파벳의 빈도가 더 높다면 그게 더 큰 수여야 결과값이 최대
//100의 자리->알파벳 100개 있다고 생각, 10의 자리-> 알파벳 10개있다고 생각
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

        //알파벳 자리수 저장
        for (int j = 0; j < arr[i].length(); j++) {
            int num = arr[i].length() - j;
            int ch = arr[i].at(j);
            alphaNum[ch - 'A']+=pow(10,num-1); //알파벳 몇번 나왔는지

            if (alpha.find(ch) == alpha.end()) //없는 알파벳이라면
                alpha.insert(pair<char, int>(ch, num));
            else
                if (alpha.at(ch) < num)
                    alpha.at(ch) = num;
        }
    }
    
        //map을 value값 기준으로 정렬하기 위해 vector 이용하기
        vector<pair<char, int>> vec(alpha.begin(), alpha.end());
        sort(vec.begin(), vec.end(), cmp);

        
        int result=0;
       
        //알파벳에 숫자 할당하기
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