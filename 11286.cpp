#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int main() {
	int n, x;
	while (scanf("%d", &n) == 1 && n != 0) {
		map<string, int> memo;
		string arr[5];
		int m = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> arr[j];
			}
			sort(arr, arr + 5);
			string str = "";
			for (int j = 0; j < 5; j++) {
				str += arr[j];
			}
			if (!memo.count(str)) {
				memo[str] = 1;
				m = max(m, 1);
			}
			else {
				memo[str]++;
				m = max(m, memo[str]);
			}
		}
		int ct = 0;
		for (auto it : memo) {
			if (it.second == m) ct += it.second;
		}
		printf("%d\n", ct);
	}
	return 0;
}
