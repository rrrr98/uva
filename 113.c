#include <stdio.h>
#include <math.h>

double searchRoot(double num, int n,double start,double end) {
	double mid = (start + end) / 2.0;
	double p = pow(mid, n);
	if (p == num) {
		return mid;
	}
	else if (p < num) {
		return searchRoot(num, n, mid + 1.0, end);
	}
	else {
		return searchRoot(num, n, start, mid - 1.0);
	}
}

int main() {
	double n;
	double p;
	while (scanf("%lf %lf", &n, &p) != EOF) {
		printf("%.0f\n", searchRoot(p, n, 1, p / n));
	}
	return 0;
}
