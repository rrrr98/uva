#include <stdio.h>

int main() {
	int min, nnum, num, sum;
	int *arr = (int *)malloc(sizeof(int) * 50);
	int i;
	int x = 1;
	int ct;
	while (1) {
		scanf("%d", &nnum);
		if (nnum == 0)break;
		sum = 0;
		ct = 0;
		for (i = 0; i < nnum; i++) {
			scanf("%d", &num);
			sum += num;
			arr[i] = num;
		}
		sum /= nnum;
		for (i = 0; i < nnum; i++) {
			if (arr[i] > sum) {
				ct += arr[i] - sum;
			}
		}
		printf("Set #%d\n", x++);
		printf("The minimum number of moves is %d.\n\n", ct);
	}
	return 0;
}
