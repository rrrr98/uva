// Dynamic Programming Learn using 2 dimensional array
// Date : 14 August 2017
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int lcs(char *X, char *Y, int m, int n)
{
	int **L = new int*[m + 1];
	int i, j;

	for (i = 0; i <= m; i++) {
		L[i] = new int[n + 1];
		for (j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				L[i][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1]) {
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else {
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
		}
	}
	return L[m][n];
}

int main() {
	char *s1 = new char[1000];
	char *s2 = new char[1000];
	int m, n;
	while (fgets(s1, 1000, stdin)) {
		fgets(s2, 1000, stdin);
		if (strlen(s1) == 1 || strlen(s2) == 1) {
			printf("0\n");
			continue;
		}
		s1 = strtok(s1, "\n");
		s2 = strtok(s2, "\n");
		m = strlen(s1);
		n = strlen(s2);
		printf("%d\n", lcs(s1, s2, m, n));
	}
	return 0;
}
