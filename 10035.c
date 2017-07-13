#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	int ct;
	int t1, t2, t3;
	int j;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) {
			break;
		}
		ct = 0;
		t3 = 0;
		j = a + b;
		while (a != 0 || b != 0) {
			t1 = a % 10;
			/*t2 = j % 10;*/
			t2 = b % 10;
			if (t3 == 1) {
				t1 += t3;
				t3 = 0;
			}
			if (t1 + t2 > 9) {
				ct++;
				t3 = 1;
			}
			a /= 10;
			b /= 10;
		}
		if (ct == 0) {
			printf("No carry operation.\n");
		}
		else if (ct == 1) {
			printf("1 carry operation.\n");
		}
		else {
			printf("%d carry operations.\n",ct);
		}
	}
	return 0;
}
