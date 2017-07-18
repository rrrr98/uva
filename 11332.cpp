#include <cstdio>
#include <algorithm>

using namespace std;

long long g(long long num) {
	if (num < 10) {
		return num;
	}
	int temp = 0;
	while (num != 0) {
		temp += num % 10;
		num /= 10;
	}
	return g(temp);
}

int main() {
	long long num;
	int res;
	while (1) {
		scanf("%lld", &num);
		if (num == 0) {
			break;
		}
		res = g(num);
		printf("%d\n", res);
	}
	return 0;
}
