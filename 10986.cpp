#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <functional>
#define ii pair<int, int>
#define iii pair<int, ii>

using namespace std;

bool visited[20005];
int totalCost[20005];

int main() {
	int nc, n, m, s, t;
	int x, y, cost;
	scanf("%d", &nc);
	for (int c = 1; c <= nc; c++) {
		printf("Case #%d: ", c);
		scanf("%d %d %d %d", &n, &m, &s, &t);
		vector<ii> edges[n];
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		for (int i = 0; i < n; i++) {
			visited[i] = false;
			totalCost[i] = INT_MAX;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &cost);
			edges[x].push_back(make_pair(cost, y));
			edges[y].push_back(make_pair(cost, x));
		}
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			ii f = pq.top();
			int node = f.second;
			int cost = f.first;
			pq.pop();
			if (visited[node]) continue;
			visited[node] = true;
			totalCost[node] = cost;
			if (node == t) {
				break;
			}
			for (auto it : edges[node]) {
				if (!visited[it.second]) {
					if (cost + it.first < totalCost[it.second]) {
						pq.push(make_pair(cost + it.first, it.second));
					}
				}
			}
		}
		if (visited[t]) {
			printf("%d\n", totalCost[t]);
		}
		else {
			printf("unreachable\n");
		}
	}
	return 0;
}
