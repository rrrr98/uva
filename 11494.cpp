#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int howMany(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) {
		return 0;
	}
	else if (abs(x1 - x2) == abs(y1 - y2)) {
		return 1;
	}
	else if (x1 == x2 || y1 == y2) {
		return 1;
	}
	else if (x1 != x2 && y1 != y2) {
		return 2;
	}
}

int main() {
	int x1, y1, x2, y2;
	int res;
	int temp;
	while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
		if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) {
			break;
		}
		if (x1 < x2) {
			swap(x1, x2);
		}
		if (y1 < y2) {
			swap(y1, y2);
		}
		res = howMany(x1, y1, x2, y2);
		printf("%d\n", res);
	}
	return 0;
}
