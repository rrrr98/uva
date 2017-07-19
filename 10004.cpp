#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

int main() {
	int n, edges, a, b;
	int sign[200];
	bool status;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		status = true;
		memset(sign, -1, sizeof(sign));
		scanf("%d", &edges);
		sign[0] = 0;
		while (edges--) {
			scanf("%d", &a);
			scanf("%d", &b);
			if (sign[a] == -1) {
				if (sign[b] == 1) {
					sign[a] = 0;
				}
				else if (sign[b] == 0) {
					sign[a] = 1;
				}
			}
			else if (sign[a] == 1) {
				if (sign[b] == -1) {
					sign[b] = 0;
				}
				else if(sign[b] == 1) {
					status = false;
				}
			}
			else {
				if (sign[b] == -1) {
					sign[b] = 1;
				}
				else if (sign[b] == 0) {
					status = false;
				}
			}
		}
		if (status) {
			printf("BICOLORABLE.\n");
		}
		else {
			printf("NOT BICOLORABLE.\n");
		}
	}
	return 0;
}
