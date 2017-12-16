#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int nc, a, b;
	int in, ct;
	vector<int> s1, s2;
	cin >> nc;
	while (nc--) {
		ct = 0;
		scanf("%d %d", &a, &b);
		s1.clear();
		s2.clear();
		while (a--) {
			scanf("%d", &in);
			s1.push_back(in);
		}
		while (b--) {
			scanf("%d", &in);
			s2.push_back(in);
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		auto i1 = s1.begin();
		auto i2 = s2.begin();
		while (i1 != s1.end() && i2 != s2.end()) {
			if (*i1 == *i2) {
				i1++;
				i2++;
			}
			else if (*i1 < *i2) {
				ct++;
				i1++;
			}
			else {
				ct++;
				i2++;
			}
		}
		while (i1 != s1.end()) {
			i1++;
			ct++;
		}
		while (i2 != s2.end()) {
			i2++;
			ct++;
		}
		
		cout << ct << endl;
	}
	return 0;
}
