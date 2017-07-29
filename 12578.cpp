#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double phi = acos(-1);
int main() {
	int nc, length;
	double width, radius, luasM, luasI;
	scanf("%d", &nc);
	while (nc--) {
		scanf("%d", &length);
		width = length * 1.0 / 10.0 * 6.0;
		radius = length * 1.0 / 5.0;
		luasM = phi * radius * radius;
		luasI = length * 1.0 * width - luasM;
		printf("%.2lf %.2lf\n", luasM, luasI);
	}
	return 0;
}
