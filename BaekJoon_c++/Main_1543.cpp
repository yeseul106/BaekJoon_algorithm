#include <iostream>
#include <string>
using namespace std;

int main() {
	string full_word;
	string search_word;

	getline(cin, full_word);
	getline(cin, search_word);

	int last_idx = 0;
	int count = 0;


	while (last_idx+search_word.length() <= full_word.length()) {
		string tmp = full_word.substr(last_idx, search_word.length());
		//cout << "tmp : " << tmp << endl;

		if (tmp.compare(search_word) == 0) {
			count++;
			last_idx += search_word.length();
		}
		else {
			last_idx++;
		}
		
	}

	cout << count << endl;
 }