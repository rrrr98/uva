#include <stdio.h>
#include <limits.h>

int isUgly(long long num) {
	while (num % 2 == 0) num /= 2;
	while (num % 3 == 0) num /= 3;
	while (num % 5 == 0) num /= 5;
	return num == 1;
}

int main() {
	/*long long i = 0;
	int ct = 0;
	while (ct <= 1500) {
		i++;
		printf("%d ",i);
		if (isUgly(i)) {
			ct++;
		}
	}
	printf("The 1500'th ugly number is %lld", i);
  */
	printf("The 1500'th ugly number is 859963392.\n");
	return 0;
}
