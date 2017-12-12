#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>

using namespace std;

vector<string> v;

bool comparator(char a, char b) {
	bool lowA = true, lowB = true;
	if (a >= 'A' && a <= 'Z') {
		lowA = false;
	}
	if (b >= 'A' && b <= 'Z') {
		lowB = false;
	}

	if ((lowA && lowB) || (!lowA && !lowB)) {
		return a < b;
	}

	if (lowA) {
		a -= ('a' - 'A');
		return a < b;
	}
	else {
		b -= ('a' - 'A');
		return a <= b;
	}
}
int main() {
	int nc;
	string input;
	cin >> nc;
	while (nc--) {
		cin >> input;
		string comparer = input;
		sort(input.begin(), input.end(), comparator);
		cout << input << endl;
		while (next_permutation(input.begin(), input.end(), comparator)) {
			cout << input << endl;
		}
	}
	return 0;
}
