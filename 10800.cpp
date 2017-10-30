#include <cstdio>
#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	int nc;
	string input;
	int cases;
	int h, l, hMax, hMin;
	char arr[150][150];
	cin >> nc;
	cases = 1;
	h = 0;
	while (nc--) {
		cin >> input;
		int x = 75;
		int y = 0;
		h = 0;
		hMax = 0;
		hMin = 0;
		int padding;
		int status[150];
		memset(status,0,sizeof(status));
		l = input.size();
		memset(arr,0, sizeof(arr));
		for (int i = 0; i < l; i++) {
			if (input[i] == 'R') {
				status[x] = 1;
				arr[x++][y++] = '/';
				h++;
				hMax = max(hMax,h);
			}
			else if (input[i] == 'F') {
				status[x - 1] = 1;
				arr[--x][y++] = '\\';
				h--;
				hMin = min(hMin,h);
			}
			else {
				arr[x][y++] = '_';
				status[x] = 1;
			}
		}
		printf("Case #%d:\n", cases++);
		for (int i = hMax; i >= hMin; i--) {
			if (!status[75 + i]) continue;
			printf("| ");
			padding = 0;
			for (int j = 0; j < l; j++) {
				char t = arr[75 + i][j];
				if (t == '/' || t == '\\' || t == '_') {
					for (int x = 0 ; x < padding; x++) {
						printf(" ");
					}
					padding = 0;
					printf("%c", t);
				}
				else {
					padding += 1;
				}
			}
			printf("\n");
		}
		printf("+");
		for (int i = 0 ; i <= l + 1;i++) {
			printf("-");
		}
		printf("\n\n");
	}
	return 0;
}
