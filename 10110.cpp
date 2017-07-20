#include <cstdio>
#include <string>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long long num;
	while (scanf("%lld", &num) == 1) {
		if (num == 0) {
			break;
		}
		if (floor(sqrt(num)) == ceil(sqrt(num))) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}
