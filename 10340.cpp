#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;
bool containsString(char *s1, char *s2) {
	int x = strlen(s1);
	int y = strlen(s2);
	int idx = 1;
	if (x > y) {
		return false;
	}
	int ct = 0;
	for (int i = 0; i < y; i++) {
		if (s2[i] == s1[0]) {
			ct++;
			for (int j = i+1; j < y; j++) {
				if (idx < x && s2[j] == s1[idx]) {
					ct++;
					idx++;
				}
			}
			if (ct == x) {
				break;
			}
			else {
				ct = 0;
				idx = 1;
			}
		}
	}
	return ct == x;
}

int main() {
	char *a = new char[500];
	char *b = new char[500];
	while (cin>>a>>b) {
		if (containsString(a, b)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
