#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int num, a, b, x, y;
	while (1) {
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		scanf("%d %d", &a, &b);
		while (num--) {
			scanf("%d %d", &x, &y);
			if (x > a) {
				if (y < b) {
					printf("SE\n");
				}
				else if (y > b) {
					printf("NE\n");
				}
				else {
					printf("divisa\n");
				}
			}
			else if (x < a){
				if (y < b) {
					printf("SO\n");
				}
				else if (y > b) {
					printf("NO\n");
				}
				else {
					printf("divisa\n");
				}
			}
			else {
				printf("divisa\n");
			}
		}
	}
	return 0;
}
