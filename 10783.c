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
		for (i = a; i <= b; i += 2) {
			res += i;
		}
		printf("Case %d: %d\n", ncase++, res);
		ncase++;
	}
	return 0;
}
