#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string.h>

using namespace std;

long long arr[101][101];
long long countCombination(long n, long m) {
	long long res = n;
	long nm = n - m;
	n--;
	while (n) {
		if (nm != 0) {
			if (res % nm == 0) {
				res /= nm;
				nm--;
			}
			else {
				res *= n;
				n--;
			}
		}
		if (m != 0) {
			if (res % m == 0) {
				res /= m;
				m--;
			}
			else {
				res *= n;
				n--;
			}
		}
		if (nm == 0 && m == 0) {
			break;
		}
	}
	while (n != 0) {
		res *= n;
		n--;
	}
	return res;
}
int main() {
	long n, m;
	long long res;
	memset(arr, -1, sizeof(arr));
	while (1) {
		scanf("%ld", &n);
		scanf("%ld", &m);
		if (n == 0 && m == 0) {
			break;
		}
		if (arr[n][m] != -1) {
			res = arr[n][m];
		}
		else {
			arr[n][m] = countCombination(n, m);
			res = arr[n][m];
		}
		printf("%ld things taken %ld at a time is %lld exactly.\n", n, m, res);
	}
	return 0;
}
