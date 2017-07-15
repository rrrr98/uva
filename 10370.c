#include <stdio.h>
#include <stdlib.h>

int main() {
	int ncases;
	int nnum, num, i;
	int r, ct;
	double res;
	int *arr = (int *)malloc(sizeof(int) * 1000);
	scanf("%d", &ncases);
	while (ncases--) {
		r = 0;
		ct = 0;
		scanf("%d", &nnum);
		for (i = 0; i < nnum; i++) {
			scanf("%d", &arr[i]);
			r += arr[i];
		}
		r /= nnum;
		for (i = 0; i < nnum; i++) {
			if (arr[i] > r) {
				ct++;
			}
		}
		res = (ct*1.0) / (nnum*1.0) * 100.0;
		printf("%.3lf%c\n", res,'%');
	}
	return 0;
}
