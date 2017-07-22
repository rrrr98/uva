#include <cstdio>
#include <algorithm>
#include <cmath>

long long H(int n) {
	long long res = 0;
	long long root = floor(sqrt(n));
	for (int i = 1; i <= root; i++) {
		res += n / i;
	}
	return 2 * res - root*root;
}

int main() {
	int ncases, num;
	scanf("%d", &ncases);
	while (ncases--) {
		scanf("%d", &num);
		printf("%lld\n", H(num));
	}
	return 0;
}
