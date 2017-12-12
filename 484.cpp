#include <cstdio>
#include <iostream>
#include <vector>
#include <map>


using namespace std;

vector<int> v;
map<int, long long> memo;

int main() {
	int x;
	while (cin >> x) {
		if (!memo.count(x)) {
			memo[x] = 1;
			v.push_back(x);
		}
		else {
			memo[x] += 1;
		}
	}
	for (auto it : v) {
		cout << it << " " << memo[it] << endl;
	}

	return 0;
}
