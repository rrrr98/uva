#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int input;
	long long male[1000];
	long long sum[1000];
	male[0] = 0;
	male[1] = 1;
	sum[0] = 1;
	sum[1] = 1;
	for (int i = 2; i < 1000; i++) {
		sum[i] = sum[i - 1] + sum[i - 2];
		male[i] = male[i - 1] + male[i - 2];
	}
	for (int i = 1; i < 1000; i++) {
		sum[i] += sum[i - 1];
		male[i] += male[i - 1];
	}
	while (scanf("%d", &input) == 1) {
		if (input == -1) {
			break;
		}
		printf("%lld %lld\n", male[input], sum[input]);
	}
	return 0;
}
