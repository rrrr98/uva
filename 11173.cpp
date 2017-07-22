#include <cstdio>

using namespace std;

int main() {
	int ncases, n, k;
	scanf("%d", &ncases);
	while (ncases--) {
		scanf("%d %d", &n, &k);
		printf("%d\n", k ^ (k >> 1));
	}
	return 0;
}
