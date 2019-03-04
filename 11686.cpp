#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> edges[1000005];
int mark[1000005];
stack<int> result;

bool topo(int x) {
	mark[x] = 1;
	for (auto it : edges[x]) {
		if (mark[it] == 0) {
			if (!topo(it)) {
				return false;
			}
		}
		else if (mark[it] == 1) {
			return false;
		}
	}
	mark[x] = 2;
	result.push(x);
	return true;
}

int main() {
	int n, m, a, b;
	while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
		for (int i = 0; i < n; i++) {
			edges[i].clear();
			mark[i] = 0;
		}
		
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			edges[a - 1].push_back(b - 1);
		}
		
		bool status = true;
		for (int i = 0; i < n; i++) {
			if (mark[i] == 0) {
				if (!topo(i)) {
					status = false;
					break;
				}
			}
		}
		if (status) {
			while (!result.empty()) {
				printf("%d\n", result.top() + 1);
				result.pop();
			}
		}
		else {
			printf("IMPOSSIBLE\n");
			while (!result.empty()) result.pop();
		}
	}
	return 0;
}
