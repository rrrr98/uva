#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int edges[52][52];
int ct[52];
int mx, status;
vector<pair<int, int>> v;

void dfs(int from) {
	for (int i = 1; i <= mx; i++) {
		if (edges[from][i]) {
			edges[from][i]--;
			edges[i][from]--;
			dfs(i);
			v.push_back(make_pair(from, i));
		}
	}
}

int main() {
	int nc, n, a, b;
	scanf("%d", &nc);
	string fail = "some beads may be lost";
	for (int i = 1; i <= nc; i++) {
		if (i != 1) {
			cout << "\n";
		}
		printf("Case #%d\n", i);
		v.clear();
		memset(edges, 0, sizeof(edges));
		memset(ct, 0, sizeof(ct));
		mx = 0;
		cin >> n;
		int x = n;
		while (n--) {
			cin >> a >> b;
			edges[a][b]++;
			edges[b][a]++;
			ct[a]++;
			ct[b]++;
			mx = max(mx, max(a, b));
		}
		status = 0;
		for (int i = 1; i <= mx; i++) {
			if (ct[i] & 1) {
				status = 1;
				break;
			}
		}
		if (status) {
			cout << fail << "\n";
		}
		else {
			dfs(mx);
			if (v.size() != x || v[0].second != v[v.size() - 1].first) {
				cout << fail << "\n";
			}
			else {
				for (int i = v.size() - 1; i >= 0; i--) {
					printf("%d %d\n", v[i].first, v[i].second);
				}
			}
		}
	}
	return 0;
}
