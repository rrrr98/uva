#include <stdio.h>

int main() {
	int x, a, b, c;
	int num;
	int res;
	scanf("%d", &x);
	while (x--) {
		res = 0;
		scanf("%d", &num);
		while (num--) {
			scanf("%d %d %d", &a, &b, &c);
			res += (a * c);
		}
		printf("%d\n", res);
	}
	return 0;
}
