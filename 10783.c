#include <stdio.h>

int main() {
	int x;
	int a, b;
	int i;
	int ncase = 1;
	int res;
	scanf("%d", &x);
	while (x--) {
		res = 0;
		scanf("%d %d", &a, &b);
		if (a % 2 == 0) {
			a += 1;
		}
		for (i = a; i <= b; i += 2) {
			res += i;
		}
		printf("Case %d: %d\n", ncase++, res);
	}
	return 0;
}
