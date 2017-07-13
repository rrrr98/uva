#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main() {
	int num;
	int i, x;
	int *arr;
	int status;
	int temp;
	int abc;
	arr = (int *)malloc(sizeof(int) * 3000);
	while (scanf("%d", &num) != EOF) {
		status = 1;
		temp = INT_MIN;
		for (i = 0; i < num; i++) {
			arr[i] = 0;
		}
		for (i = 0; i < num; i++) {
			scanf("%d", &x);
			if (temp == INT_MIN) {
				temp = x;
				continue;
			}
			abc = abs(x - temp);
			temp = x;
			if (abc > num) {
				status = 0;
				break;
			}
			arr[abc] += 1;
		}
		if (status == 1) {
			for (i = 1; i < num; i++) {
				if (arr[i] == 1) {
					continue;
				}
				else {
					status = 0;
					break;
				}
			}
		}
		if (status == 1) {
			printf("Jolly\n");
		}
		else {
			printf("Not jolly\n");
		}
	}
	return 0;
}
