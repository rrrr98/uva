#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

#define MAX_N 100010

using namespace std;

char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
int Phi[MAX_N], PLCP[MAX_N], LCP[MAX_N];
int color[MAX_N], tempColor[MAX_N];
int ctColor;

void countingSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++) 
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++){
		int t = c[i]; c[i] = sum; sum += t;	}
	for (i = 0; i < n; i++) {
		tempColor[c[SA[i] + k < n ? RA[SA[i] + k] : 0]] = color[i];
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	}
	for (i = 0; i < n; i++) {
		SA[i] = tempSA[i];
		color[i] = tempColor[i];	
	}
}

void contructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];
	for (i = 0; i < n; i++) {
		SA[i] = i;
		if (T[i] < 'a') {
			ctColor++;
			color[i] = -1;
			continue;
		}
		color[i] = ctColor;
	}
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
		if (RA[SA[n - 1]] == n - 1) break;
	}
}

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1;
	for (i = 1; i < n; i++)
		Phi[SA[i]] = SA[i - 1];
	for (i = L = 0; i < n; i++) {
		if (Phi[i] == -1) {
			PLCP[i] = 0;
			continue;
		}
		while (T[i + L] == T[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	for (i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

int main() {
	int nc;
	int tempLength, padding;
	char tempStr[1024];
	int low, high;
	while (scanf("%d", &nc) == 1 && nc) {
		padding = 0;
		for (int i = 0; i < nc; i++) {
			scanf("%s", tempStr);
			strcpy(&T[padding], tempStr);
			padding += strlen(tempStr);
			T[padding++] = '#' + i;
		}
		T[++padding] = '\0';
		n = strlen(T);
		contructSA();
		computeLCP();
//		for (int i = 0; i < n; i++) {
//			printf("%d %s %d\n", LCP[i], &T[SA[i]], color[i]);
//		}
		low = high = 0;
		int hashColor[ctColor];
		if (color[low] != -1) hashColor[color[low]] = 1;
		memset(hashColor, 0, sizeof(hashColor));
		int result = 0;
		while (low != n - 1 && high != n - 1) {
			if (low == high) {
				high++;
				if (high != n - 1) {
					hashColor[color[high]]++;
				}
				continue;
			}
			int ct = 0;
			for (int i = 0; i < ctColor; i++) {
				if (hashColor[i] > 0) {
					ct++;
				}
			}
			
			if (ct > nc / 2) {
				int ct = LCP[low + 1];
				for (int i = low + 2; i <= high; i++) {
					ct = min(ct, LCP[i]);
				}
				printf("ct : %d\n", ct);
				result = max(result, ct);
				
				hashColor[color[low]]--;
				low++;
			}
			else {
				high++;
				if (high != n - 1) {
					hashColor[color[high]]++;
				}
			}
		}
		printf("%d", result);
	}
	return 0;
}
