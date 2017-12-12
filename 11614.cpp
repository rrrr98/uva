#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int nc;
	long long x;
	cin >> nc;
	while (nc--) {
		cin >> x;
		long long res = (-1.0 + sqrt(1 + 8.0 * x)) / 2.0;
		printf("%lld\n", res);
	}
	return 0;
}
