#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {
	char input[1002];
	char *tok;
	int i;
	while (fgets(input, 1000, stdin)) {
		i = 0;
		tok = strtok(input, " \n");
		while (tok != NULL) {
			if (i == 1) {
				printf(" ");
			}
			i = 1;
			reverse(tok, tok + strlen(tok));
			printf("%s", tok);
			tok = strtok(NULL, " \n");
		}
		printf("\n");
	}
	return 0;
}
