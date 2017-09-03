#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

map<char, char> mapleft;
map<char, char> mapright;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
char arr[100][100];
int x, y;
int a, b, c, ct;

void cek(int x, int y) {
	if (arr[x][y] == '*') {
		ct += 1;
	}
}
void walk(char oldDir) {
	int d1, d2;
	if (oldDir == 'N') {
		d1 = dir[0][0];
		if (x + d1 >= 0 && arr[x + d1][y] != '#') {
			arr[x][y] = '.';
			x += d1;
			cek(x, y);
			arr[x][y] = oldDir;
		}
	}
	else if (oldDir == 'L') {
		d2 = dir[1][1];
		if (y + d2 < b && arr[x][y + d2] != '#') {
			arr[x][y] = '.';
			y += d2;
			cek(x, y);
			arr[x][y] = oldDir;
		}
	}
	else if (oldDir == 'S') {
		d1 = dir[2][0];
		if (x + d1 < a && arr[x + d1][y] != '#') {
			arr[x][y] = '.';
			x += d1;
			cek(x, y);
			arr[x][y] = oldDir;
		}
	}
	else {
		d2 = dir[3][1];
		if (y + d2 >= 0 && arr[x][y+d2] != '#') {
			arr[x][y] = '.';
			y += d2;
			cek(x,y);
			arr[x][y] = oldDir;
		}
	}
}

char getDirection(char oldDir, char command) {
	if (command == 'D') {
		return mapright[oldDir];
	}
	else if (command == 'E') {
		return mapleft[oldDir];
	}
	else {
		walk(oldDir);
		return oldDir;
	}
}


int main() {
	mapleft['N'] = 'O';
	mapleft['O'] = 'S';
	mapleft['S'] = 'L';
	mapleft['L'] = 'N';
	mapright['N'] = 'L';
	mapright['L'] = 'S';
	mapright['S'] = 'O';
	mapright['O'] = 'N';
	char temp[1000];
	int j;
	char chr;
	char *command;
	while (scanf("%d %d %d", &a, &b, &c) == 3) {
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		getc(stdin);
		for (int i = 0; i < a; i++) {
			fgets(temp, 1000, stdin);
			j = 0;
			while (temp[j] != '\n') {
				char c = temp[j];
				arr[i][j] = c;
				if (c == 'N' || c == 'S' || c == 'L' || c == 'O') {
					chr = c;
					x = i;
					y = j;
				}
				j++;
			}
		}
		command = new char[c + 2];
		fgets(command, c + 2, stdin);
		j = 0;
		ct = 0;
		while (command[j] != '\n') {
			chr = getDirection(chr, command[j]);
			j++;
		}
		cout << ct << endl;
		free(command);
	}
	return 0;
}
