#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
double pi = acos(-1);
int main() {
	double s, luasS,luasLD,luasLL, jariLD,jariLL;
	double a, b, c;
	while (cin>>a>>b>>c) {
		s = (a + b + c) / 2.0;
		luasS = sqrt(s*(s - a)*(s - b)*(s - c));
		jariLD = luasS / s;
		jariLL = (a*b*c) / (4 * luasS);
		luasLD = jariLD * jariLD * pi;
		luasLL = jariLL * jariLL * pi;
		luasLL -= luasS;
		luasS -= luasLD;
		printf("%.4lf %.4lf %.4lf\n", luasLL, luasS, luasLD);
	}
	return 0;
}
