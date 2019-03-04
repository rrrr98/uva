#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ii pair<int, int>
#define iii pair<double, ii>

using namespace std;

ii towns[505];
int ranks[505];
int parent[505];

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
	double dist = sqrt((pow(towns[a].first - towns[b].first, 2) + pow(towns[a].second - towns[b].second, 2)) * 1.0);
	return make_pair(dist, make_pair(a, b));
}

int main() {
	int nc, s, p, a, b;
	scanf("%d", &nc);
	for (int i = 0; i < nc; i++) {
		scanf("%d %d", &s, &p);
		for (int j = 0; j < p; j++) {
			parent[j] = j;
			ranks[j] = 0;
		}
		for (int j = 0; j < p; j++) {
			scanf("%d %d", &a, &b);
			towns[j] = make_pair(a, b);
		}
		
		vector<iii> edges;
		for (int j = 0; j < p; j++) {
			for (int k = j + 1; k < p; k++) {
				edges.push_back(make_edge(j, k));
			}
		}
		
		sort(edges.begin(), edges.end());
		
		int ct = 0;
		for (int j = 0; j < edges.size(); j++) {
			int t1 = find(edges[j].second.first);
			int t2 = find(edges[j].second.second);
			if (t1 != t2) {
				ct++;
				Union(t1, t2);
				if (ct == p - s) {
					printf("%.2lf\n", edges[j].first);
					break;
				}
			}
		}
	}
	return 0;
}
