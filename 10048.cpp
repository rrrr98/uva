#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#define ii pair<int, int>
#define iii pair<int, ii>

using namespace std;

int parent[105];
int ranks[105];
int maxCost[105][105];
bool visited[105];
int conn[105][105];

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
	else {
		parent[aRoot] = bRoot;
		ranks[bRoot]++;
	}
}

iii make_edge(int a, int b, int c) {
	return make_pair(c, make_pair(a, b));
}

int dfs(int source, int dest, int c) {
	if (source == dest) return 0;
	visited[source] = true;
	for (int j = 0; j < c; j++) {
		if (conn[source][j] != -1 && !visited[j]) {
			int res = dfs(j, dest, c);
			if (res != -1) {
				return max(conn[source][j], res);	
			}
		}
	}
	return -1;
}

int main() {
	int c, s, q, c1, c2, d;
	int nc = 1;
	while (scanf("%d %d %d", &c, &s, &q) == 3 && (c || s || q)) {
		vector<iii> edges;
		if (nc > 1) printf("\n");
		printf("Case #%d\n", nc++);
		for (int i = 0; i < c; i++) {
			parent[i] = i;
			ranks[i] = 0;
		}
		for (int i = 0; i < s; i++) {
			scanf("%d %d %d", &c1, &c2, &d);
			edges.push_back(make_edge(c1 - 1, c2 - 1, d));
		}
		sort(edges.begin(), edges.end());
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < c; j++) {
				conn[i][j] = -1;
				maxCost[i][j] = -1;
			}
		}
		for (int i = 0; i < s; i++) {
			ii e = edges[i].second;
			int x = find(e.first);
			int y = find(e.second);
			
			if (x != y) {
				conn[x][y] = edges[i].first;
				conn[y][x] = edges[i].first;
				Union(x, y);
			}
		}
		
		for (int i = 0; i < q; i++) {
			scanf("%d %d", &c1, &c2);
			if (maxCost[c1 - 1][c2 - 1] == -1) {
				for (int i = 0; i < c; i++) {
					visited[i] = false;
				}
				maxCost[c1 - 1][c2 - 1] = dfs(c1 - 1, c2 - 1, c);
			}
			if (maxCost[c1 - 1][c2 - 1] == -1) {
				printf("no path\n");
			}
			else {
				printf("%d\n", maxCost[c1 - 1][c2 - 1]);	
			}
		}
	} 
	return 0;
}
