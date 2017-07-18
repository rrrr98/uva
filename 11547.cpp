#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int ncases, num;
	int res;
	scanf("%d", &ncases);
	while (ncases--) {
		scanf("%d", &num);
		res = (num * 63 + 7492) * 5 - 498;
		res /= 10;
		res %= 10;
		res = abs(res);
		printf("%d\n", res);
	}
	return 0;
}
