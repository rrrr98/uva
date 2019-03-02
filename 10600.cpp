#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ii pair<int, int>
#define iii pair<int, ii>

using namespace std;

int ranks[105];
int parent[105];

int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void Union(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);
	
	if (ranks[aRoot] > ranks[bRoot]) {
		parent[bRoot] = aRoot;
	}
	else if (ranks[aRoot] < ranks[bRoot]) {
		parent[aRoot] = bRoot;
	}
	else  {
		parent[bRoot] = aRoot;
		ranks[aRoot] += 1;
	}
}

iii make_edge(int a, int b, int c) {
	return make_pair(c, make_pair(a, b));
}

int main() {
	int nc, n, m, a, b, c;
	scanf("%d", &nc);
	while (nc--) {
		scanf("%d %d", &n, &m);
		vector<iii> edges;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			edges.push_back(make_edge(a - 1, b - 1, c));
		}
		sort(edges.begin(), edges.end());
		
		int sum = 0;
		bool stEdges[m];
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			ranks[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			stEdges[i] = false;
			iii e = edges[i];
			ii edge = e.second;
			int x = find(edge.first);
			int y = find(edge.second);
			if (x != y) {
				sum += e.first;
				stEdges[i] = true;
				Union(x, y);
			}
		}
		int sum2 = INT_MAX;
		for (int i = 0; i < m; i++) {
			if (stEdges[i]) {
				int countEdges = 0;
				int temp = 0;
				for (int j = 0; j < n; j++) {
					parent[j] = j;
					ranks[j] = 0;
				}
				for (int j = 0; j < m; j++) {
					if (i == j) continue;
					iii e = edges[j];
					ii edge = e.second;
					int x = find(edge.first);
					int y = find(edge.second);
					if (x != y) {
						temp += e.first;
						countEdges++;
						Union(x, y);
					}
				}
				if (countEdges == n - 1) {
					sum2 = min(sum2, temp);
				}
			}
		}
		printf("%d %d\n", sum, sum2);
	}
	return 0;
}
