#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define dd pair<double,double>
#define idd pair<int, dd>
#define dpp pair<double, pair<idd, idd>>

using namespace std;

vector<idd> v;
vector<dpp> edges;
int parent[105];
int ranks[105];

idd make_point(int num, double x, double y) {
	return make_pair(num, make_pair(x, y));
}

dpp make_edge(idd p1, idd p2) {
	dd pt1 = p1.second;
	dd pt2 = p2.second;
	double distance = sqrt(pow(pt1.first - pt2.first, 2) + pow(pt1.second - pt2.second, 2));
	return make_pair(distance, make_pair(p1, p2));
}

int find(int i) {
	if (parent[i] != i) {
		parent[i] = find(parent[i]);
	}
	return parent[i];
}

void Union(int x, int y){
	int xroot = find(x);
	int yroot = find(y);
	
	if (ranks[xroot] < ranks[yroot]) {
		parent[xroot] = yroot;
	}
	else if (ranks[xroot] > ranks[yroot]) {
		parent[yroot] = xroot;
	}
	else {
		parent[yroot] = xroot;
		ranks[xroot]++;
	}
}

int main() {
	int nc, n;
	double x, y;
	scanf("%d", &nc);
	for (int a = 0; a < nc; a++) {
		scanf("%d", &n);
		v.clear();
		edges.clear();
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &x, &y);
			v.push_back(make_point(i, x, y));
		}
		for (auto it = v.begin(); it != v.end(); it++) {
			for (auto it2 = it + 1; it2 != v.end(); it2++) {
				edges.push_back(make_edge(*it, *it2));
			}
		}
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			ranks[i] = 0;
		}
		sort(edges.begin(), edges.end());
		double sum = 0;
		for (auto it : edges) {
			idd p1 = it.second.first;
			idd p2 = it.second.second;
			int x = find(p1.first);
			int y = find(p2.first);
			if (x != y) {
				sum += it.first;
				Union(x, y);
			}
		}
		if (a != 0) {
			printf("\n");
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}
