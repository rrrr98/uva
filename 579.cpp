#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

double convertToDeg(int h, int m) {
	int temp = h * 60 + m;
	double a, b;
	a = (temp * 1.0) / 60.0 * 30.0;
	b = (m * 1.0) * 6.0;
	if (a > b) {
		return min(a - b,360.0 - a + b);
	}
	else {
		return min(b - a, 360.0 - b + a);
	}
}

int main() {
	char str[10];
	char *tok;
	int h, m;
	double res;
	while (scanf("%d:%d",&h,&m) == 2) {
		if (h == 0 && m == 0) {
			break;
		}
		res = convertToDeg(h, m);
		printf("%.3f\n", res);
	}
	return 0;
}
