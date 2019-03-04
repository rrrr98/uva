#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ii pair<int, int>
#define iii pair<int, ii>

using namespace std;

ii towns[755];
int ranks[755];
int parent[755];

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

iii make_edge(int a, int b) {
	int dist = pow(towns[a].first - towns[b].first, 2) + pow(towns[a].second - towns[b].second, 2);
	return make_pair(dist, make_pair(a, b));
}

int main() {
	int nc, n, m, x, y;
	scanf("%d", &nc);
	for (int i = 0; i < nc; i++) {
		if (i > 0) printf("\n");
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d %d", &x, &y);
			towns[j] = make_pair(x, y);
		}
		
		for (int j = 0; j < n; j++) {
			ranks[j] = 0;
			parent[j] = j;
		}
		
		scanf("%d", &m);
		int ctr = 0;
		for (int j = 0; j < m; j++) {
			scanf("%d %d", &x, &y);
			int t1 = find(x - 1);
			int t2 = find(y - 1);
			if (t1 != t2) {
				Union(x - 1, y - 1);
				ctr++;	
			}
		}
		if (ctr == n - 1) {
			printf("No new highways need\n");
		}
		else {
			vector<iii> edges;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					edges.push_back(make_edge(i, j));
				}
			}
			sort(edges.begin(), edges.end());
			
			for (int i = 0; i < edges.size(); i++) {
				int t1 = find(edges[i].second.first);
				int t2 = find(edges[i].second.second); 
				if (t1 != t2) {
					printf("%d %d\n", edges[i].second.first + 1, edges[i].second.second + 1);
					Union(t1, t2);
				}
			}
		}
	}
	return 0;
}
