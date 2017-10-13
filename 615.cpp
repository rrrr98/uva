#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;



int main() {
	int from, to, x, n, y;
	string root, sfrom, sto;
	int ncases = 1;
	bool status;
	map<string, vector<string>> memo;
	vector<string> v, vTo;
	vector<string> visited;
	queue<string> que;
	while (true) {
		status = true;
		n = -1; x = 0; y = 0;
		memo.clear();
		v.clear();
		vTo.clear();
		visited.clear();
		cin >> sfrom >> sto;
		if (sfrom[0] == '-') break;
		v.emplace_back(sfrom);
		memo[sfrom].emplace_back(sto);
		vTo.emplace_back(sto);
		sfrom[0] == '0' ? n = 0 : n = 1;
		if (sfrom[0] != '0' && sfrom == sto) status = false;
		if (n) x++;
		while (n && cin >> sfrom >> sto && sfrom[0] != '0') {
			if (sfrom == sto) status = false;
			v.emplace_back(sfrom);
			memo[sfrom].emplace_back(sto);
			vTo.emplace_back(sto);
			x++;
		}
		if (n && status) {
			for (auto it : vTo) {
				while (true) {
					auto pos = find(v.begin(), v.end(), it);
					if (pos != v.end()) {
						v.erase(pos);
					}
					else {
						break;
					}
				}
			}
		}
		if (n && v.size() == 0) status = false;
		if (n && status) {
			root = "bla";
			for (auto it : v) {
				if (root == "bla") {
					root = it;
				}
				else if (root != it) {
					status = false; break;
				}
			}
		}
		if (status && n) {
			que.push(root);
			while (!que.empty()) {
				string t = que.front();
				que.pop();
				if (memo.count(t)) {
					vector<string> a = memo[t];
					for (auto it : a) {
						if (find(visited.begin(), visited.end(), it) == visited.end()) {
							visited.emplace_back(it);
							que.push(it);
							y++;
						}
						else {
							status = false;
						}
					}
				}
			}
			if (y != x) {
				status = false;
			}
		}
		status ? printf("Case %d is a tree.\n", ncases) : printf("Case %d is not a tree.\n", ncases);
		ncases++;
	}
	return 0;
}
