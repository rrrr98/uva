#include <cstdio>
#include <iostream>
#include <vector>
#define ii pair<int, int>
#define iii pair<int, ii>

using namespace std;

int parent[105];
int ranks[105];

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

int main() {
	int c, s, q, c1, c2, d;
	while (scanf("%d %d %d", &c, &s, &q) == 3) {
		vector<iii> edges;
		for (int i = 0; i < c; i++) {
			parent[i] = i;
			ranks[i] = 0;
		}
		for (int i = 0; i < s; i++) {
			scanf("%d %d %d", &c1, &c2, &d);
			edges
		}
	} 
	return 0;
}
