#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cmath>
#define ii pair<int, int>

using namespace std;

vector<int> edges[105];
int disc[105];
int low[105];
int tick;
bool visited[105];
int parent[105];
vector<ii> bridges;
vector<ii> fb;

bool compare(ii a, ii b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

void make_bridges(int u) {
	visited[u] = true;
	
	disc[u] = low[u] = tick++;
	
	for (auto v : edges[u]) {
		if (!visited[v]) {
			parent[v] = u;
			make_bridges(v);
			
			low[u] = min(low[u], low[v]);
			
			if (low[v] > disc[u]) {
				bridges.push_back(make_pair(min(u, v), max(u, v)));
			}
		}
		else if (v != parent[u]){
			low[u] = min(low[u], disc[v]);
		}
	}
}

int main() {
	int n, x, nx, y;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			edges[i].clear();
			visited[i] = false;
			parent[i] = -1;
		}
		tick = 1;
		bridges.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d ", &x);
			scanf("(%d)", &nx);
			for (int j = 0; j < nx; j++) {
				scanf("%d", &y);
				edges[x].push_back(y);
				edges[y].push_back(x);
			}
		}
		for (int i = 0; i < n; i++) {
			make_bridges(i);
		}
		printf("%d critical links\n", bridges.size());
		sort(bridges.begin(), bridges.end(), compare);
		for (auto it : bridges) {
			printf("%d - %d\n", it.first, it.second);
		}
		printf("\n");
	}
	return 0;
}
