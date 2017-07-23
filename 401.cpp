#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
map<char, char> chara;

int stringJudge(string str) {
	int res = 0;
	string temp(str);
	reverse(temp.begin(), temp.end());
	if (temp == str) {
		res += 1;
	}
	string s;
	for (auto i = temp.begin(); i < temp.end(); i++) {
		if (chara[*i] != 0) {
			s.push_back(chara[*i]);
		}
	}
	if (s == str) {
		res += -2;
	}
	return res;
}

int main() {
	chara['A'] = 'A';
	chara['E'] = '3';
	chara['H'] = 'H';
	chara['I'] = 'I';
	chara['J'] = 'L';
	chara['L'] = 'J';
	chara['M'] = 'M';
	chara['O'] = 'O';
	chara['S'] = '2';
	chara['T'] = 'T';
	chara['U'] = 'U';
	chara['V'] = 'V';
	chara['W'] = 'W';
	chara['X'] = 'X';
	chara['Y'] = 'Y';
	chara['Z'] = '5';
	chara['1'] = '1';
	chara['2'] = 'S';
	chara['3'] = 'E';
	chara['5'] = 'Z';
	chara['8'] = '8';
	string input;
	int res;
	while (cin >> input) {
		res = stringJudge(input);
		cout << input;
		if (res == 0) {
			printf(" -- is not a palindrome.\n");
		}
		else if (res == 1) {
			printf(" -- is a regular palindrome.\n");
		}
		else if (res == -1) {
			printf(" -- is a mirrored palindrome.\n");
		}
		else {
			printf(" -- is a mirrored string.\n");
		}
		printf("\n");
	}
	return 0;
}
