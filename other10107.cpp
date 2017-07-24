#include <cstdio>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int input;
	int res;
	int size = 0;
	vector<int> vec;
	while (cin >> input) {
		vec.push_back(input);
		sort(vec.begin(),vec.end());
		if (size % 2) {
			res = (vec[size / 2] + vec[size / 2 + 1]) / 2;
		}
		else {
			res = vec[size / 2];
		}
		cout << res << endl;
		size++;
	}
	return 0;
}
