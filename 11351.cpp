#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int lastStanding(int n, int k)
{
	if (n == 1)
		return 1;
	else
		return (lastStanding(n - 1, k) + k - 1) % n + 1;
}
int main() {
	int nc;
	int n, k;
	cin >> nc;
	for (int i = 1; i <= nc; i++) {
		cin >> n >> k;
		cout << "Case " << i << ": ";
		cout << lastStanding(n, k) << endl;
	}
	return 0;
}
