#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char str[1002];
int m[1002][1002];

int howManyPalindrome(int l,int r) {
	if (l == r) {
		return 1;
	}
	else if (l + 1 == r) {
		if (str[l] == str[r]) {
			return 2;
		}
		else {
			return 1;
		}
	}
	if (m[l][r] != -1) {
		return m[l][r];
	}
	if (str[l] == str[r]) {
		m[l][r] = 2 + howManyPalindrome(l + 1, r - 1);
	}
	else {
		m[l][r] = max(howManyPalindrome(l, r - 1), howManyPalindrome(l + 1, r));
	}
	return m[l][r];
}

int main() {
	int ncases, res, len;
	scanf("%d", &ncases);
	getc(stdin);
	while (ncases--) {
		fgets(str, 1000, stdin);
		if (str[0] == '\n') {
			printf("0\n");
		}
		else {
			memset(m, -1, sizeof(m));
			len = strlen(str);
			res = howManyPalindrome(0, len - 1);
			printf("%d\n", res);
		}
	}
	return 0;
}
