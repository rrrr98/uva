#include <cstdio>
#include <functional>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void makeNull(int arr[102][102], int i, int j) {
	if (arr[i][j - 1] == 1) {
		arr[i][j - 1] = 0;
		makeNull(arr, i, j - 1);
	}
	if (arr[i - 1][j - 1] == 1) {
		arr[i - 1][j - 1] = 0;
		makeNull(arr, i - 1, j - 1);
	}
	if (arr[i - 1][j] == 1) {
		arr[i - 1][j] = 0;
		makeNull(arr, i - 1, j);
	}
	if (arr[i - 1][j + 1] == 1) {
		arr[i - 1][j + 1] = 0;
		makeNull(arr, i - 1, j + 1);
	}
	if (arr[i][j + 1] == 1) {
		arr[i][j + 1] = 0;
		makeNull(arr, i, j + 1);
	}
	if (arr[i + 1][j + 1] == 1) {
		arr[i + 1][j + 1] = 0;
		makeNull(arr, i + 1, j + 1);
	}
	if (arr[i + 1][j] == 1) {
		arr[i + 1][j] = 0;
		makeNull(arr, i + 1, j);
	}
	if (arr[i + 1][j - 1] == 1) {
		arr[i + 1][j - 1] = 0;
		makeNull(arr, i + 1, j - 1);
	}
}

int howManyOil(int arr[102][102], int m, int n) {
	int ct = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1) {
				ct++;
				makeNull(arr, i, j);
			}
		}
	}
	return ct;
}

int main() {
	int m, n;
	int i, j;
	char input[102];
	int arr[102][102];
	int result;
	while (scanf("%d %d", &m, &n) == 2) {
		if (m == 0) {
			break;
		}
		getc(stdin);
		memset(arr, 0, sizeof(arr));
		for (i = 1; i <= m; i++) {
			fgets(input, 102, stdin);
			for (j = 1; j <= n; j++) {
				if (input[j-1] == '@') {
					arr[i][j] = 1;
				}
			}
		}
		result = howManyOil(arr, m, n);
		printf("%d\n", result);
	}
	return 0;
}
