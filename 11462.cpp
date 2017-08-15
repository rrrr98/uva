// Date : 15 August 2017
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int x;
	int *arr;
	while (scanf("%d", &x) == 1, x != 0) {
		arr = new int[x];
		for (int i = 0; i < x; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + x);
		for (int i = 0; i < x; i++) {
			printf("%d", arr[i]);
			if (i != x - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
