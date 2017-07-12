#include <stdio.h>
#include <stdlib.h>

int main() {
	char *str = (char *)malloc(sizeof(char) * 10);
	char *ptr = "Hajj-e-Akbar";
	char *optr = "Hajj-e-Asghar";
	int i = 1;
	while (fgets(str, 8, stdin)) {
		if (*str == '*')break;
		if (*str == 'H') {
			printf("Case %d: %s\n", i, ptr);
		}
		else {
			printf("Case %d: %s\n", i, optr);
		}
		i++;
	}
	return 0;
}
