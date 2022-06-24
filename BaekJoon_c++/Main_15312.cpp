#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string input;
    for (int i = 0; i < 3; i++) {
        getline(cin, input);
        stringstream ss(input);

        string v;
        while ((ss >> v)) {
            cout << v << endl;
        }
        cout << endl;
    }
    return 0;
}