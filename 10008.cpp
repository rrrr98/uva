#include <cstdio>
#include <iostream>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <functional>
using namespace std;

int main() {
	int ncases;
	char input[1002];
	char *ptr;
	int arr[256];
	char c;
	int value;
	map<int, list<char>,greater<int>> m;
	scanf("%d", &ncases);
	getc(stdin);
	memset(arr, 0, sizeof(arr));
	while (ncases--) {
		fgets(input, 1002, stdin);
		ptr = input;
		while (*ptr != '\n') {
			if (*ptr >= 97) {
				arr[*ptr - 32] += 1;
			}
			else {
				arr[*ptr] += 1;
			}
			ptr += 1;
		}
	}
	for (int i = 65; i <= 90; i++) {
		c = i;
		value = arr[i];
		if (value != 0) {
			m[value].push_back(c);
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		while (!it->second.empty()) {
			cout << it->second.front() << " " << it->first << endl;
			it->second.pop_front();
		}
	}
	return 0;
}
