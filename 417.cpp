#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

map<string, int> memo;
void generate() {
	int count = 1;
	char s[6];
	for (s[0] = 'a'; s[0] <= 'z'; s[0]++) {
		s[1] = '\0';
		memo[string(s)] = count++;
	}
	for (s[0] = 'a'; s[0] <= 'z' - 1; s[0]++)
		for (s[1] = s[0] + 1; s[1] <= 'z'; s[1]++) {
			s[2] = '\0';
			memo[string(s)] = count++;
		}

	for (s[0] = 'a'; s[0] <= 'z' - 2; s[0]++)
		for (s[1] = s[0] + 1; s[1] <= 'z' - 1; s[1]++)
			for (s[2] = s[1] + 1; s[2] <= 'z'; s[2]++) {
				s[3] = '\0';
				memo[string(s)] = count++;
			}

	for (s[0] = 'a'; s[0] <= 'z' - 3; s[0]++)
		for (s[1] = s[0] + 1; s[1] <= 'z' - 2; s[1]++)
			for (s[2] = s[1] + 1; s[2] <= 'z' - 1; s[2]++)
				for (s[3] = s[2] + 1; s[3] <= 'z'; s[3]++) {
					s[4] = '\0';
					memo[string(s)] = count++;
				}

	for (s[0] = 'a'; s[0] <= 'z' - 4; s[0]++)
		for (s[1] = s[0] + 1; s[1] <= 'z' - 3; s[1]++)
			for (s[2] = s[1] + 1; s[2] <= 'z' - 2; s[2]++)
				for (s[3] = s[2] + 1; s[3] <= 'z' - 1; s[3]++)
					for (s[4] = s[3] + 1; s[4] <= 'z'; s[4]++) {
						s[5] = '\0';
						memo[string(s)] = count++;
					}
}

int main() {
	generate();
	string input;
	while (cin >> input) {
		if (memo.count(input)) {
			cout << memo[input] << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
