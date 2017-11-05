#include <cstdio>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int count(int N) {
	int res = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			res += gcd(i, j);
		}
	}
	return res;
}
int main() {
	int num;
	while (scanf("%d", &num), num) {
		printf("%d\n", count(num));
	}
	return 0;
}
