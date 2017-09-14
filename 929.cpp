#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <map>
#include <functional>

using namespace std;

int maze[999][999];
int cost[999][999];
int posI[4] = { -1,0,1,0 };
int posJ[4] = { 0,1,0,-1 };
int nc, row, column;
bool validPos(int x, int y) {
	return ((x >= 0 && x < row) && (y >= 0 && y < column));
}

int main() {
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	scanf("%d", &nc);
	while (nc--) {
		scanf("%d", &row);
		scanf("%d", &column);

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				scanf("%d", &maze[i][j]);
				cost[i][j] = INT_MAX;
			}
		}
		cost[0][0] = maze[0][0];
		pq.push(make_pair(0, make_pair(0,0)));
		int x = 0;
		while (!pq.empty()) {
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			for (int j = 0; j < 4; j++) {
				int newI = x + posI[j];
				int newJ= y + posJ[j];
				if (validPos(newI, newJ)) {
					int v = maze[newI][newJ];
					if (cost[x][y] + v < cost[newI][newJ]) {
						cost[newI][newJ] = cost[x][y] + v;
						pq.push(make_pair(cost[newI][newJ],make_pair(newI,newJ)));
					}
				}
			}
		}
		printf("%d\n", cost[row - 1][column - 1]);
	}
	return 0;
}
