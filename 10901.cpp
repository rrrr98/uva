#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>

using namespace std;

char str[20];
int nc, n, t, m, x;
bool loc, any;
int tx;

int main() {
	scanf("%d", &nc);
	while (nc--) {
		queue<int> l, r, nl, nr;
		queue<char> cargo;
		scanf("%d %d %d", &n, &t, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %s", &x, &str);
			if (str[0] == 'l') {
				l.push(x);
			}
			else {
				r.push(x);
			}
			cargo.push(str[0]);
		}
		//true means left
		loc = true;
		tx = 0;
		while (!l.empty() || !r.empty()) {
			if (loc) {
				any = false;
				for (int j = 0; j < n; j++) {
					if (l.empty()) break;
					int nt = l.front();
					if (tx >= nt) {
						l.pop();
						nl.push(tx + t);
						any = true;
					}
					else {
						break;
					}					
				}
				if (any) {
					loc = false;
					tx += t;
				}
				else {
					int a = INT_MAX;
					if (!l.empty()) {
						a = max(l.front(), tx);
						loc = true;
					}
					if (!r.empty()) {
						if (r.front() < a) {
							a = max(r.front(), tx) + t;
							loc = false;
						}
					}
					tx = a;
				}
			}
			else {
				any = false;
				for (int j = 0; j < n; j++) {
					if (r.empty()) break;
					int nt = r.front();
					if (tx >= nt) {
						r.pop();
						nr.push(tx + t);
						any = true;
					}
					else {
						break;
					}
				}
				if (any) {
					loc = true;
					tx += t;
				}
				else {
					int a = INT_MAX;
					if (!r.empty()) {
						a = max(r.front(), tx);
						loc = false;
					}
					if (!l.empty()) {
						if (l.front() < a) {
							a = max(l.front(), tx) + t;
							loc = true;
						}
					}
					tx = a;
				}
			}
			
		}
		while (!cargo.empty()) {
			char it = cargo.front();
			if (it == 'l') {
				cout << nl.front() << endl;
				nl.pop();
			}
			else {
				cout << nr.front() << endl;
				nr.pop();
			}
			cargo.pop();
		}
		if (nc != 0) printf("\n");
	}
	return 0;
}
