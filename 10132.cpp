#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

set<string> s;

int main() {
	string input;
	while (cin >> input) {
		string other = "";
		for (int i = 0; i < input.length(); i++) {
			if (isalpha(input[i])) {
				other += tolower(input[i]);
			}
			else {
				if (other != "" && !s.count(other)) {
					s.insert(other);
				}
				other = "";
			}
		}
		if (other != "" && !s.count(other)) {
			s.insert(other);
		}
	}
	for (auto it : s) {
		cout << it << endl;
	}
	return 0;
}
