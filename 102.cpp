#include <stdio.h>
#include <string>
#include <climits>

int arr[6][3] = { {0,2,1},{0,1,2}, {1,2,0}, {2, 1, 0}, {1, 0, 2}, {2,0,1} };
char *str[6] = {"BCG","BGC", "CBG", "CGB", "GBC", "GCB" };

int simulate(int x, int *b, int *g, int *c) {
	int b1 = arr[x][0];
	int b2 = arr[x][1];
	int b3 = arr[x][2];
	int box1 = 0;
	int box2 = 0;
	int box3 = 0;
	for (int i = 0; i < 3; i++) {
		if (i != b1) {
			box1 += b[i];
		}
		if (i != b2) {
			box2 += g[i];
		}
		if (i != b3) {
			box3 += c[i];
		}
	}
	return box1 + box2 + box3;
}


int main() {
	int *b = new int[3];
	int *g = new int[3];
	int *c = new int[3];
	int res;
	int boxRes;
	int temp;
	while (scanf("%d %d %d %d %d %d %d %d %d", &b[0], &g[0], &c[0], &b[1], &g[1], &c[1], &b[2], &g[2], &c[2]) != EOF) {
		temp = 0;
		boxRes = -1;
		res = INT_MAX;
		for (int x = 0; x < 6; x++) {
			temp = simulate(x, b, g, c);
			if (temp < res) {
				res = temp;
				boxRes = x;
			}
		}
		printf("%s %d\n", str[boxRes], res);
	}
	return 0;
}
