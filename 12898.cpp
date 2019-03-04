#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main () {
	int nc, a, b, x, y;
	scanf("%d", &nc);
	for (int i = 1; i <= nc; i++) {
		printf("Case  %d:", i);
		scanf("%d %d", &a, &b);
		x = a;
		y = a;
		for (int j = a + 1; j <= b; j++) {
			x |= j;
			y &= j;
		}
		printf(" %d %d\n", x, y);
	}
	return 0;
}
