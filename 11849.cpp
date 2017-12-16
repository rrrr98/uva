#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main() {
	int a, b;
	set<int> s;
	int input;
	int ct;
	while (cin >> a >> b,a,b) {
		s.clear();
		ct = 0;
		while (a--) {
			cin >> input;
			s.insert(input);
		}
		while (b--) {
			cin >> input;
			auto it = s.find(input);
			if (it != s.end()) {
				ct++;
			}
		}
		printf("%d\n", ct);
	}
	return 0;
}
