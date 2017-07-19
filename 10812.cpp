#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int ncases, a, b;
	int r1, r2;
	scanf("%d", &ncases);
	while (ncases--) {
		scanf("%d %d", &a, &b);
		r1 = (a * 1.0) / (2 * 1.0) + (b * 1.0) / (2 * 1.0);
		r2 = (a * 1.0) / (2 * 1.0) - (b * 1.0) / (2 * 1.0);
		if (a < b || r1 + r2 != a || abs(r1-r2)!=b) {
			printf("impossible\n");
		}
		else {
			printf("%d %d\n", r1, r2);
		}
	}
	return 0;
}
