#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m;
	map<int, vector<int>> memo;
	while (cin >> n >> m) {
		memo.clear();
		for (int i = 0; i < n; i++) {
			int in;
			cin >> in;
			memo[in].push_back(i);
		}
		for (int i = 0; i < m; i++) {
			int k, v;
			cin >> k >> v;
			if (memo.count(v) && memo[v].size() >= k) {
				cout << memo[v][k - 1] + 1<< endl;
			}
			else {
				cout << '0' << endl;
			}
		}
	}
	return 0;
}
