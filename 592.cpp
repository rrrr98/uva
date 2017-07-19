#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	int num, res, i, temp, origin;
	while (scanf("%d", &num) == 1) {
		res = 0;
		origin = num;
		for (i = 0; i < 4; i++) {
			res = res << 8;
			temp = num & 255;
			res |= temp;
			num = num >> 8;
		}
		printf("%d converts to %d\n", origin, res);
	}
	return 0;
}
