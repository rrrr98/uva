#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int nc, a, b;
	scanf("%d", &nc);
	while (nc--) {
		scanf("%d %d", &a, &b);
		a /= 3;
		b /= 3;
		b = a * b;
		printf("%d\n", b);
	}
	return 0;
}
