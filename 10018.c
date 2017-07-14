#include <stdio.h>
int counter;
long long reverseNum(long long num) {
	long long temp = 0;
	while (num != 0) {
		temp *= 10;
		temp += num % 10;
		num /= 10;
	}
	return temp;
}

long long plusUltra(long long num) {
	long long reversed;
	while (1) {
		reversed = reverseNum(num);
		if (reversed == num) {
			break;
		}
		num += reversed;
		counter++;
	}
	return num;
}

int main() {
	long long num;
	int ncases;
	scanf("%d", &ncases);
	while (ncases--) {
		counter = 0;
		scanf("%lld", &num);
		num = plusUltra(num);
		printf("%d %lld\n", counter, num);
	}
	return 0;
}
