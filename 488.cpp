#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int ncases, ampli, frec;
	int i, j, k;
	int x = 0;
	scanf("%d", &ncases);
	while (ncases--) {
		scanf("%d", &ampli);
		scanf("%d", &frec);
		for (i = 0; i < frec; i++) {
			if (x == 1) {
				printf("\n");
			}
			for (j = 1; j <= ampli; j++) {
				for (k = 0; k < j; k++) {
					printf("%d", j);
				}
				printf("\n");
			}
			for (j = ampli-1; j > 0; j--) {
				for (k = 0; k < j; k++) {
					printf("%d", j);
				}
				printf("\n");
			}
			x = 1;
		}
	}
	return 0;
}
