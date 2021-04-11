#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	string input;
	getline(cin, input);

	
	
	for (int i = 0; i < input.length(); i++) {
		if (('a' <= input.at(i) && input.at(i) <= 'z')) {
			input.at(i) ='a'+ ((input.at(i)-'a') + 13) % 26;
		}
		else if('A' <= input.at(i) && input.at(i) <= 'Z') {
			input.at(i) ='A'+ (input.at(i)) % 26;
		}
	}

	cout << input;
}