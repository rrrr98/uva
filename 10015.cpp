#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> prime;
bool isPrime(int n) {
	for (int i = 3; i <= sqrt(n); i+=2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void makePrime() {
	prime.push_back(2);
	for (int i = 3; i < 100000; i+=2) {
		if (isPrime(i)) {
			prime.push_back(i);
		}
	}
}

int savedPeople(int x) {
	int pos = 0;
	for (int i = 1; i <= x; i++) {
		pos = (pos + prime[x - i]) % i;
	}
	return pos + 1;
}

int main() {
	makePrime();
	int x;
	while (cin >> x) {
		if (x == 0) break;
		cout << savedPeople(x) << endl;
	}
	return 0;
}
