// Date : 30 August 2017
#include <cstdio>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

char var[21];
char input[1000];
char *temp;
char order[301][3];

void makeNextPerm(int i,int j) {
	int count = 0;
	int output = 0;
	bool status;
	do {
		status = true;
		for (int x = 0; status, x < i - 1; x++) {
			for (int y = x + 1; status, y < i; y++) {
				char var1 = var[x];
				char var2 = var[y];
				for (int z = 0; status, z < j; z++) {
					char v1 = order[z][0];
					char e = order[z][1];
					char v2 = order[z][2];
					if (var1 == v1 && var2 == v2) {
						if (e == '>') {
							status = false;
							break;
						}
					}
					else if (var1 == v2 && var2 == v1) {
						if (e == '<') {
							status = false;
							break;
						}
					}
				}
			}
		}
		if (status) {
			if (output != 0) {
				cout << "\n";
			}
			for (int x = 0; x < i; x++) {
				if (x != 0) {
					cout << " ";
				}
				cout << var[x];
			}
			count++;
			output++;
		}
	} while (next_permutation(var, var + i));
	if (count == 0) {
		cout << "NO";
	}
	cout << "\n";
}

int main() {
	int nc, i, j;
	int xnc = 0;
	scanf("%d\n", &nc);
	while (nc--) {
		i = 0;
		j = 0;
		if (xnc != 0) {
			getc(stdin);
		}
		fgets(input, 1000, stdin);
		temp = strtok(input, " \n");
		while (temp != NULL) {
			var[i] = temp[0];
			i++;
			temp = strtok(NULL, " \n");
		}
		sort(var, var + i);
		fgets(input, 1000, stdin);
		temp = strtok(input, " \n");
		while (temp != NULL) {
			order[j][0] = temp[0];
			order[j][1] = temp[1];
			order[j][2] = temp[2];
			j++;
			temp = strtok(NULL, " \n");
		}
		if (xnc != 0) {
			cout << "\n";
		}
		makeNextPerm(i, j);
		xnc += 1;
	}
	return 0;
}
