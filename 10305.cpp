// Date : 28 August 2017
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;

int mark[101];
vector<vector<int>> arr;
stack<int> s;

void topologicalSortIn(int v) {
	mark[v] = 1;
	for (auto it = arr[v].begin(); it != arr[v].end(); it++) {
		if (mark[*it] == 0) {
			topologicalSortIn(*it);
		}
	}
	s.push(v);
}

void topologicalSort(int m) {
	for (int i = 1; i <= m; i++) {
		if (mark[i] == 0) {
			topologicalSortIn(i);
		}
	}
	while (!s.empty()) {
		if (s.top() == 0) break;
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}

int main() {
	int m, n;
	int a, b;
	int value;
	int x;
	while (scanf("%d %d", &m, &n) == 2) {
		if (m == 0 && n == 0) {
			break;
		}
		arr.clear();
		arr.resize(m + 1);
		for (int i = 0; i < m + 1; i++) {
			arr[i].resize(m + 1);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			arr[a].push_back(b);
			sort(arr[a].begin(), arr[a].end());
		}
		memset(mark, 0, sizeof(mark));
		topologicalSort(m);
	}
	return 0;
}
