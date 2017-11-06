#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main() {
	int n, nc, nx, x, cases, maxDaily, dayMax;
	queue<pair<int,int>> q;
	vector<int> visited;
	int arr[5000];
	map<int, vector<int> > memo;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nx);
		memo[i];
		while (nx--) {
			scanf("%d", &x);
			memo[i].push_back(x);
		}
	}
	scanf("%d", &nc);
	while (nc--) {
		memset(arr,0,sizeof(arr));
		scanf("%d", &cases);
		q.push(make_pair(cases, 0));
		maxDaily = 0;
		dayMax = 0;
		int i = 0;
		visited.clear();
		visited.push_back(cases);
		while (!q.empty()) {
			i++;
			pair<int,int> p = q.front();
			int front = p.first;
			int day = p.second;
			q.pop();
			for (auto it : memo[front]) {
				if (find(visited.begin(), visited.end(), it) == visited.end()) {
					visited.push_back(it);
					q.push(make_pair(it, day + 1));
					arr[day + 1] += 1;
				}
			}
			if (arr[day + 1] > maxDaily) {
				maxDaily = arr[day + 1];
				dayMax = day + 1;
			}
		}
		if (maxDaily > 0) {
			printf("%d %d\n", maxDaily, dayMax);
		}
		else {
			printf("%d\n", maxDaily);
		}
	}
	return 0;
}
