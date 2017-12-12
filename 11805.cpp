#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
int main() {
	int nc, n, k, p;
	int i = 1;
	cin >> nc;
	while (nc--) {
		cin >> n >> k >> p;
		int res = (k + p % n) % n;
		printf("Case %d: ", i);
		if (res == 0) {
			cout << n << endl;
		}
		else {
			cout << res << endl;
		}
		i++;
	}
	return 0;
}
