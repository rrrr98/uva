#include <stdio.h>

int howManySwap(int *arr,int size) {
	int i, j;
	int temp;
	int ct = 0;
	int status = 1;
	for (i = 0; i < size; i++) {
		status = 1;
		for (j = 0; j < size-1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				ct++;
				status = 0;
			}
		}
		if (status) {
			break;
		}
	}
	return ct;
}

int main() {
	int ncases;
	int nnum;
	int *num;
	int i, res;
	scanf("%d", &ncases);
	while (ncases--) {
		scanf("%d", &nnum);
		num = (int *)malloc(sizeof(int) * nnum);
		for (i = 0; i < nnum; i++) {
			scanf("%d", &num[i]);
		}
		res = howManySwap(num, nnum);
		printf("Optimal train swapping takes %d swaps.\n", res);
	}
	return 0;
}
