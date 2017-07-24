#include <cstdio>
#include <iostream>
#include <functional>

using namespace std;

int main() {
	int n, num;
	int arr[1000];
	int counter;
	while (scanf("%d", &n) == 1) {
		counter = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[j] > arr[i]) {
					counter++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n", counter);
	}
	return 0;
}
