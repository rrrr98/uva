#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
	int nc, target;
	int arr[10000];
	int fst, sec;
	int fres, sres;
	int temp;
	while (scanf("%d", &nc) != EOF) {
		fres = INT_MAX;
		sres = 0;
		for (int i = 0; i < nc; i++) {
			scanf("%d", &arr[i]);
		}
		scanf("%d", &target);
		for (int i = 0; i < nc - 1; i++) {
			for (int j = i + 1; j < nc; j++) {
				fst = arr[i];
				sec = arr[j];
				if ((fst + sec) == target) {
					if (abs(fst - sec) < abs(fres - sres)) {
						fres = fst;
						sres = sec;
					}
				}
			}
		}
		if (fres > sres) {
			temp = fres;
			fres = sres;
			sres = temp;
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",fres,sres);
	}
	return 0;
}
