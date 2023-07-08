#include<iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
 
int main(void) {
    int N, M;
    string temp;
    int count =0;
    map<string, bool> str_map;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        str_map[temp] = true;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        if(str_map[temp]) count++;
    }

    cout << count << endl;

}