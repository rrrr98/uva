#include <cstdio>

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) == 2) {
		printf("%d\n", a + ((a-1) / (b-1)) );
	}
	return 0;
}
