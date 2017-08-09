#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int memo[7490];

void count(int S[], int m, int n) {
	memo[0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = S[i]; j <= n; j++) {
			memo[j] += memo[j - S[i]];
		}
	}
}
int main() {
	int max = 7489;
	int S[] = { 50,25,10,5,1 };
	int input;
	memset(memo, 0, sizeof(memo));
	count(S, 5, max);
	while (scanf("%d", &input) == 1) {
		printf("%d\n", memo[input]);
	}
	return 0;
}
