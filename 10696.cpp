#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int f91(int num) {
	if (num >= 101) {
		return num - 10;
	}
	else {
		return f91(f91(num + 11));
	}
}

int main() {
	int num;
	int res;
	while (1) {
		scanf("%d", &num);
		if (num == 0) { break; }
		res = f91(num);
		printf("f91(%d) = %d\n", num, res);
	}
}
