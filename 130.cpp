#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

int arr[101];
int index(int a, int n) {
	a = a % n;
	if (a == 0) return n;
	return a;
}
int simulate(int n, int k, int start) {
	int x = start - 1;
	int alive = n;
	if (alive == 1) return 1;
	int dead;
	while (alive > 1) {
		int ct = 0;
		while (ct < k) {
			x++;
			x = index(x, n);
			if (arr[x] != 0) {
				ct++;
			}
		}
		arr[x] = 0;
		dead = x;
		ct = 0;
		while (ct < k) {
			dead++;
			dead = index(dead, n);
			if (arr[dead] != 0) {
				ct++;
			}
		}
		swap(arr[dead], arr[x]);
		alive--;
	}
	return arr[x];
}
int main() {
	int n, k;
	while (cin >> n >> k) {
		if (!n && !k) break;
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			iota(arr, arr + 101, 0);
			ans = simulate(n, k, i);
			if (ans == 1) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
