#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	char arr[102][102];
	char input[102];
	int i = 0;
	int longest = 0;
	int temp;
	while (fgets(arr[i], 102, stdin)) {
		temp = strlen(arr[i]) - 1;
		arr[i][temp] = 0;
		if (temp > longest) {
			longest = temp;
		}
		i++;
	}
	i--;
	for (int x = 0; x < longest; x++) {
		for (int y = i; y >= 0; y--) {
			if (strlen(arr[y]) > x) {
				printf("%c", arr[y][x]);
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
