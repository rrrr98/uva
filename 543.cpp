#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <cstring>

using namespace std;

int arr[1000000];

bool isPrime(int num,int div) {
	if (div == 1) {
		return true;
	}
	else if (num % div) {
		return isPrime(num, div - 1);
	}
	else {
		return false;
	}
}
int main() {
	memset(arr, -1, sizeof(arr));
	int input, s, b;
	int nowA, nowB;
	while (scanf("%d", &input) == 1) {
		if (input == 0) {
			break;
		}
		for (int i = 2; i <= input / 2; i++) {
			if (arr[i] != -1 || isPrime(i,sqrt(i))) {
				b = input - i;
				arr[i] = 1;
				if (arr[b] != -1 || isPrime(b, sqrt(b))) {
					arr[b] = 1;
					nowA = i;
					nowB = b;
					break;
				}
			}
		}
		printf("%d = %d + %d\n", input, nowA, nowB);
	}
	return 0;
}
