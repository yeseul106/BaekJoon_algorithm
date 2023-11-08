#include <iostream>
using namespace std;

pair<char, char> arr[26]; //알파벳 노드를 기준으로 first에는 left, second에는 right
int N;

void preorder(char ch) { //전위 순회 : 루트 - left - right
    if (ch!='.') {
        cout << ch;
        preorder(arr[ch-'A'].first);
        preorder(arr[ch-'A'].second);
    }
}

void inorder(char ch) { //중위 순회 : left - 루트 - right
    if (ch!='.') {
        inorder(arr[ch-'A'].first);
        cout << ch;
        inorder(arr[ch-'A'].second);
    }
}

void postorder(char ch) { //후위 순회 : left - right - 루트
    if (ch!='.') {
        postorder(arr[ch-'A'].first);
        postorder(arr[ch-'A'].second);
        cout << ch;
    }
}

int main() {
    cin >> N;

    for (int i=0; i<N; i++) {
        char root, left, right;
        cin >> root >> left >> right;

        arr[root-'A'] = pair(left, right);
    }

    preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
}
