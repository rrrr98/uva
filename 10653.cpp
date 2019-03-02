#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define ii pair<int, int>
#define iii pair<int, ii>

using namespace std;

int r, c;
int n, nRow, nCol, x;
int beginX, beginY, endX, endY;
bool field[1005][1005];

iii make_node(int x, int y, int cost) {
	return make_pair(cost, make_pair(x, y));
}

int bfs() {
	queue<iii> q;
	q.push(make_node(beginX, beginY, 0));
	
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cost = q.front().first;
		q.pop();
		if (field[x][y]) continue;
		field[x][y] = true;
		if (x == endX && y == endY) return cost;
		if (x + 1 < r) q.push(make_node(x + 1, y, cost + 1));
		if (x - 1 >= 0) q.push(make_node(x - 1, y, cost + 1));
		if (y + 1 < c) q.push(make_node(x, y + 1, cost + 1));
		if (y - 1 >= 0) q.push(make_node(x, y - 1, cost + 1));
	}
	return 0;
}

int main() {
	while (scanf("%d %d", &r, &c) == 2 && (r || c)) {
		scanf("%d", &n);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				field[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &nRow, &nCol);
			for (int j = 0; j < nCol; j++) {
				scanf("%d", &x);
				field[nRow][x] = true;
			}
		}
		scanf("%d %d %d %d", &beginX, &beginY, &endX, &endY);
		printf("%d\n", bfs());
	}
	return 0;
}
