#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str = (char *)malloc(1000);
	int ct;
	char *ptr;
	int status;
	while (fgets(str, 998, stdin)) {
		ct = 0;
		ptr = strtok(str," ");
		while (ptr != NULL) {
			status = 1;
			while (*ptr != '\0') {
				if (((int)*ptr >= 65 && (int)*ptr <= 90) || ((int)*ptr >= 97 && (int)*ptr <= 122)) {
					if (status) {
						ct += 1;
						status = 0;
					}
				}
				else {
					status = 1;
				}
				ptr += 1;
			}
			ptr = strtok(NULL, " ");
		}
		printf("%d\n", ct);
	}
	return 0;
}
