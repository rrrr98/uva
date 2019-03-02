#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
	int nc, l, m, x, ct;
	bool stat;
	char s[20];
	scanf("%d", &nc);
	while (nc--) {
		queue<int> ql, qr;
		scanf("%d %d", &l, &m);
		l *= 100;
		for (int i = 0; i < m; i++) {
			scanf("%d %s", &x, &s);
			if (s[0] == 'l') {
				ql.push(x);
			}
			else {
				qr.push(x);
			}
		}
		ct = 0;
		stat = true;
		while (!ql.empty() || !qr.empty()) {
			if (stat) {
				int w = 0;
				while (!ql.empty() && w + ql.front() <= l) {
					w += ql.front();
					ql.pop();
				}
				stat = false;
				ct++;
			}
			else {
				int w = 0;
				while (!qr.empty() && w + qr.front() <= l) {
					w += qr.front();
					qr.pop();
				}
				stat = true;
				ct++;
			}
		}
		cout << ct << endl;
	}
	return 0;
}
