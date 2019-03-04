#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

int ct[10];

int main() {
	long long n, a, b;
	while (scanf("%lld", &n) == 1) {
		for (int i = 0; i < 10; i++) {
			ct[i] = 0;
		}
		while (n != 0) {
			ct[n % 10]++;
			n /= 10;
		}
		a = 0;
		b = 0;
		for (int i = 9; i >= 0; i--) {
			if (ct[i]) {
				for (int j = 0; j < ct[i]; j++) {
					a = (a * 10) + i;
				}
			}
		}
		bool isFirst = true;
		for (int i = 1; i < 10; i++) {
			if (ct[i]) {
				for (int j = 0; j < ct[i]; j++) {
					b = (b * 10) + i;
					if (isFirst) {
						isFirst = false;
						if (ct[0]) {
							for (int j = 0; j < ct[0]; j++) {
								b *= 10;
							}
						}
					}
				}
			}
		}
		printf("%lld - %lld = %lld = 9 * %lld\n", a, b, (a - b), (a - b) / 9);
	}
	return 0;
}
