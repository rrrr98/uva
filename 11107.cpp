#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <string>

#define MAX_N 101010

using namespace std;

char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
int Phi[MAX_N], PLCP[MAX_N], LCP[MAX_N];
int nc;
int lengths[105];
int owners[MAX_N];
int cts[105];
int maxLCS;

void countingSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++) 
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++){
		int t = c[i]; c[i] = sum; sum += t;	}
	for (i = 0; i < n; i++) {
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	}
	for (i = 0; i < n; i++) {
		SA[i] = tempSA[i];
	}
}

void contructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];
	int ctColor = 0;
	for (i = 0; i < n; i++) SA[i] = i;
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
		while (T[i + L] != '$' && T[i + L] == T[Phi[i] + L]) L++; // tambahin gk boleh T[i + L] == '$' krn $ adalah pembatas
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	for (i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

int owner(int idx) {
  for (int i = 0, length = lengths[i] + 1; ; i++, length += lengths[i] + 1) {
    if (idx < length - 1) // sebelum setiap $
      return i;
    else if (idx == length - 1) // nabrak $
      return -1;
  }
}

int main() {
	int ts = 0;
	while (scanf("%d", &nc) == 1 && nc) {
		if (ts > 0) printf("\n");
		ts++;
		if (nc == 1) { // kalau stringnya hanya 1, kembalikan string itu
			scanf("%s", T);
			printf("%s\n", T);
			continue;
		}
		n = 0;
		for (int i = 0; i < nc; i++) { // proses append string ke T, sebagai string seluruhnya
			scanf("%s", T + n);
			lengths[i] = strlen(T + n);
			n += lengths[i];
			T[n++] = '$';
		}
		T[n] = '\0';
		contructSA();
		computeLCP();
		for (int i = 0; i < n; i++) { // untuk tahu SA ke i itu milik string nomor berapa dalam string seluruhnya. (coloring)
			owners[i] = owner(SA[i]);
		}
		maxLCS = 0;
		memset(cts, 0, sizeof(cts)); // init counter sebagai hash untuk menghitung jumlah kepemilikan string (digunakan utk pengecekan dengan jumlah orang -> nc)
		int i = nc, j = nc, total = 0;
		vector<int> result;
		while (j < n) { // sliding windows i, j
			if (total <= nc / 2) {
				if (!cts[owners[j++]]++) {
					++total;
				}
			}
			if (total > nc / 2) {
				int k = min_element(LCP + i + 1, LCP + j) - LCP; // min element [x, y) | LCP + i + 1 karena yg pertama dalam LCP tidak di cek (bukan hasil)
				if (LCP[k] > maxLCS) { // kalau panjang LCP (yang minimum) ^ lebih besar dari maxLCS
					maxLCS = LCP[k];
					result.clear();
					result.push_back(SA[k]);
				}
				else if (maxLCS != 0 && LCP[k] == maxLCS) { // maxLCS == 0 tidak boleh dimasukkan ke dalam result
					result.push_back(SA[k]);
				}
				if (!--cts[owners[i++]]) {
					--total;
				}
			}
		}
		if (result.size() > 0) { // urutan lexicography jadi string yg sama pasti urutan. simpan di tSA utk temporary SA
			int tSA = -1;
			for (auto it : result) {
				if (tSA == -1 || strncmp(T + tSA, T + it, maxLCS)) { // cek supaya tidak berulang stringnya (unique result)
					tSA = it;
					char c = T[tSA + maxLCS];
					T[tSA + maxLCS] = '\0';
					printf("%s\n", T + tSA);
					T[tSA + maxLCS] = c;
				}
			}
		}
		else { // resultnya gk ada isi
			printf("?\n");
		}
	}
	return 0;
}
