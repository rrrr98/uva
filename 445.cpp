// Date : 18 August 2017
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
char input[150];
int main() {
	char *pt;
	int count;
	char temp;
	while (fgets(input, 150, stdin)) {
		pt = input;
		count = 0;
		while (*pt != '\n') {
			if (*pt >= '0' && *pt <= '9') {
				count += (int)*pt - 48;
			}
			else if (*pt == '!') {
				printf("\n");
			}
			else {
				if (*pt == 'b') {
					temp = ' ';
				}
				else {
					temp = *pt;
				}
				for (int i = 0; i < count; i++) {
					printf("%c", temp);
				}
				count = 0;
			}
			pt++;
		}
		printf("\n");
	}
	return 0;
}
