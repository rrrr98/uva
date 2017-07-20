#include <cstdio>
#include <bitset>

int main() {
	int num, t1, t2, temp;
	int memo, i;
	while (scanf("%d",&num) == 1) {
		if (num == 0) {
			break;
		}
		memo = 1;
		t1 = 0;
		t2 = 0;
		i = 0;
		while (num != 0) {
			if (num & 1 == 1) {
				if (memo) {
					t1 |= (1 << i);
					memo = 0;
				}
				else {
					t2 |= (1 << i);
					memo = 1;
				}
			}
			i++;
			num = num >> 1;
		}
		printf("%d %d\n", t1, t2);
	}
	return 0;
}
