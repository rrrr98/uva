#include <cstdio>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	int input;
	int res;
	int size = 0;
	int arr[10000];
	while (cin >> input) {
		arr[size] = input;
		sort(arr,arr+size+1);
		if (size % 2) {
			res = (arr[size / 2] + arr[size / 2 + 1]) / 2;
		}
		else {
			res = arr[size / 2];
		}
		cout << res << endl;
		size++;
	}
	return 0;
}
