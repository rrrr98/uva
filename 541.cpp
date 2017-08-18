// Date : 18 August 2017
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int n;
	int **arr;
	int ctBaris;
	int ctKolom;
	int x, y;
	int status;
	while (scanf("%d", &n) == 1, n != 0) {
		arr = new int*[n];
		x = -1;
		y = -1;
		status = 1;
		for (int i = 0; i < n; i++) {
			arr[i] = new int[n];
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			ctBaris = 0;
			ctKolom = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j][i]) {
					ctKolom++;
				}
				if (arr[i][j]) {
					ctBaris++;
				}
			}
			if (ctBaris % 2 != 0) {
				if (x == -1) {
					x = i;
				}
				else {
					status = 0;
					break;
				}
			}
			if (ctKolom % 2 != 0) {
				if (y == -1) {
					y = i;
				}
				else {
					status = 0;
					break;
				}
			}
		}
		if (status == 0) {
			printf("Corrupt\n");
		}
		else if (x!= -1 && y != -1) {
			printf("Change bit (%d,%d)\n", x + 1, y + 1);
		}
		else {
			printf("OK\n");
		}
		free(arr);
	}
	return 0;
}
