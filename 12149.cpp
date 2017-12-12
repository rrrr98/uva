#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[101];

void generate() {
	arr[1] = 1;
	for (int i = 2; i <= 100; i++) {
		arr[i] = arr[i - 1] + pow(i, 2);
	}
}
int main() {
	int x;
	generate();
	while (cin >> x) {
		if (!x) break;
		cout << arr[x] << endl;
	}
	return 0;
}
