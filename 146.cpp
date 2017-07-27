#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string input;
	while (cin >> input) {
		if (input == "#") {
			break;
		}
		if (next_permutation(input.begin(), input.end())) {
			cout << input << "\n";
		}
		else {
			cout << "No Successor\n";
		}
	}
	return 0;
}
