#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

long long getSkew(int x) {
	return (1 << x) - 1;
}

int main() {
	long long res;
	string input;
	int size, value;
	while (cin >> input) {
		res = 0;
		size = input.size();
		for (int i = 0; i < input.size(); i++) {
			value = input.at(i) - 48;
			res += value * getSkew(size--);
			if (value == 2) {
				break;
			}
		}
		if (res == 0) {
			break;
		}
		printf("%lld\n", res);
	}
	return 0;
}
