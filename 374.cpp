#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

long long bigMod(long long b, long long p, long long m) {
	if (p == 0) {
		return 1;
	}
	else if (p % 2) {
		return ((b % m) * bigMod(b, p - 1, m)) % m;
	}
	else {
		long long c = bigMod(b, p / 2, m);
		return ((c % m) * (c % m)) % m;
	}
}

int main() {
	long long b, p, m;
	long long res;
	while (cin >> b >> p >> m) {
		res = bigMod(b, p, m);
		cout << res << "\n";
	}
	return 0;
}
