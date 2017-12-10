#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <functional>

using namespace std;
int visited[200001];
vector<pair<int, int>> v[200001];
struct comparator {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		return a.second > b.second;
	}
};
int mst() {
	int index = 0;
	memset(visited, 0, sizeof(visited));

	pair<int, int> firstNode = make_pair(0, 0);
	priority_queue<pair<int,int> , vector<pair<int,int>>,comparator> pq;
	pq.push(firstNode);

	int totalCost = 0;

	while (!pq.empty()) {
		pair<int,int> n = pq.top(); pq.pop();
		if (visited[n.first]) continue;
		visited[n.first] = 1;
		totalCost += n.second;

		for (int i = 0; i<(int)v[n.first].size(); i++) {
			pq.push(make_pair(v[n.first][i].first, v[n.first][i].second));
		}
	}
	return totalCost;
}


int main() {
	int n, m;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) break;
		int originalCost = 0;
		for (int i = 0; i<200001; i++) {
			v[i].clear();
		}
		for (int i = 0; i<n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			v[x].push_back(pair<int, int>(y, z));
			v[y].push_back(pair<int, int>(x, z));
			originalCost += z;
		}
		int newCost = mst();
		cout << originalCost - newCost << endl;
	}
	return 0;
}
