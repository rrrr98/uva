#include <cstdio>
#include <iostream>
#include <functional>
#include <cstring>

using namespace std;

int main() {
	int nc, day, nnum, num;
	int counter;
	int memo[3651];
	scanf("%d", &nc);
	while (nc--) {
		scanf("%d", &day);
		scanf("%d", &nnum);
		counter = 0;
		memset(memo, -1, (day + 1) * sizeof(int));
		while (nnum--) {
			scanf("%d", &num);
			for (int i = num; i <= day; i += num) {
				if (i % 7 == 6 || i % 7 == 0 || memo[i] == 1) {
					continue;
				}
				memo[i] = 1;
				counter++;
			}
		}
		printf("%d\n", counter);
	}
	return 0;
}
