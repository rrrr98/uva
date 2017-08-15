// Date : 15 August 2017
#include <cstdio>
#include <iostream>

using namespace std;

long long sequence(long long a,long long l) {
	if (a == 1) {
		return 1;
	}
	else if (a > l) {
		return 0;
	}
	else if (a % 2 == 0) {
		return 1 + sequence(a / 2, l);
	}
	else {
		return 1 + sequence(3 * a + 1, l);
	}
}

int main() {
	int nc = 1;
	long long a, l;
	while (scanf("%lld %lld", &a, &l) == 2) {
		if (a < 0 && l < 0) {
			break;
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n", nc++, a, l, sequence(a, l));
	}
	return 0;
}
