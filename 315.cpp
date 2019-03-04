#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

vector<int> edges[105];
int disc[105];
int low[105];
int tick;
bool visited[105];
int parent[105];
bool isAp[105];

void ap(int u) {
	int children = 0;
	visited[u] = true;
	
	disc[u] = low[u] = tick++;
	
	for (auto v : edges[u]) {
		if (!visited[v]) {
			children++;
			parent[v] = u;
			ap(v);
			
			low[u] = min(low[u], low[v]);
			
			if (parent[u] == -1 && children > 1) isAp[u] = true;
			if (parent[u] != -1 && low[v] >= disc[u]) isAp[u] = true;
		}
		else if (v != parent[u]){
			low[u] = min(low[u], disc[v]);
		}
	}
}

int main() {
	int n, x, y;
	string str;
	while (scanf("%d", &n) == 1 && n) {
		getchar();
		for (int i = 0; i < n; i++) {
			edges[i].clear();
			visited[i] = false;
			parent[i] = -1;
			isAp[i] = false;
		}
		tick = 1;
		while (getline(cin, str)) {
			stringstream s(str);
			s >> x;
			if (x == 0) break;
			while (s >> y) {
				edges[x - 1].push_back(y - 1);
				edges[y - 1].push_back(x - 1);
			}
		}
		ap(0);
		int ct = 0;
		for (int i = 0; i < n; i++) {
			if (isAp[i]) {
				ct++;
			}
		}
		printf("%d\n", ct);
	}
	return 0;
}
