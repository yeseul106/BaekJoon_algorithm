#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	string arrString[4] = {};
	double arrDouble[4];

	for (int i = 0; i < 4; i++) {
		cin >> arrDouble[i];
	}

	for (int i = 0; i < 4; i++) {
		string tmp = to_string(arrDouble[i]);
		int j = 0;

		while (true) {
			if (tmp.at(j) == '.')
				break;
			arrString[i] += tmp.at(j);
			j++;
		}
	}

	string ab = arrString[0] + arrString[1];
	string cd = arrString[2] + arrString[3];


	double ab_double = stod(ab);
	double cd_double = stod(cd);

	double result = ab_double + cd_double;

	string before = to_string(result);
	string after = "";

	for (int i = 0; i < before.length(); i++)
	{
		if (before.at(i) == '.')
			break;
		after += before.at(i);
	}
	
	cout << after;
}