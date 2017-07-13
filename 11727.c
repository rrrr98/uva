#include <stdio.h>

int main() {
	int a, b, c;
	int ncases;
	scanf("%d", &ncases);
	int res;
	int i = 1;
	while (ncases--) {
		res = 0;
		scanf("%d %d %d", &a, &b, &c);
		if ((a > b && a < c) || (a > c && a < b)) {
			res = a;
		}
		else if ((b > a && b < c) || (b > c && b < a)) {
			res = b;
		}
		else {
			res = c;
		}
		printf("Case %d: %d\n", i++, res);
	}
}
