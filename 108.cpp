#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int n, i, j, k;
	int memo[101];
	int arr[100][100];
	int sum[100][101];
	int res;
	while (scanf("%d", &n) == 1) {
		res = INT_MIN;
		for (i = 0; i < n; i++) {
			sum[i][0] = 0;
			for (j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				if (j != 0) {
					sum[i][j] = sum[i][j - 1] + arr[i][j - 1];
				}
			}
			sum[i][j] = sum[i][j - 1] + arr[i][j - 1];
		}
		for (i = 0; i < n; i++) {
			for (j = i + 1; j <= n; j++) {
				memo[0] = 0;
				for (k = 0; k < n; k++) {
					memo[k + 1] = max(sum[k][j] - sum[k][i] + memo[k], sum[k][j] - sum[k][i]);
					res = max(memo[k + 1], res);
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
