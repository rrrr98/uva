#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	int nc;
	char temp[32];
	map<string, int> memo;
	cin >> nc;
	getchar();
	int mark = 0;
	fgets(temp, 30, stdin);
	while (nc--) {
		if (mark) cout << "\n";
		memo.clear();
		int total = 0;
		while (fgets(temp, 32, stdin)) {
			if (strlen(temp) == 1) break;
			char *t = strtok(temp, "\n");
			string str = string(t);
			if (memo.count(str) == 0) {
				memo[str] = 1;
			}
			else {
				memo[str] += 1;
			}
			total += 1;
		}
		for (auto it : memo) {
			cout << it.first << " ";
			printf("%.4lf\n", it.second * 1.0 / total * 100.0);
		}
		mark = 1;
	}
	return 0;
}
