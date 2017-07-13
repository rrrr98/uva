#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str = (char *)malloc(sizeof(char) * 1000);
	int status = 1;
	char *ptr = "``";
	char *optr = "''";
	char *pointer;
	while (fgets(str,998,stdin)) {
		pointer = str;
		while (*pointer != '\n') {
			if (*pointer == '"') {
				if (status) {
					printf("%s", ptr);
					status = 0;
				}
				else {
					printf("%s", optr);
					status = 1;
				}
			}
			else {
				printf("%c", *pointer);
			}
			pointer += 1;
		}
		printf("\n");
	}
	return 0;
}
