#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

char input[105];
char output[105];
vector<int> fibo;
map<int, int> memo;
void makeFibo() {
	fibo.push_back(1);
	fibo.push_back(2);
	memo[1] = 1;
	memo[2] = 2;
	for (int i = 2; i < 45; i++) {
		int temp = fibo[i - 2] + fibo[i - 1];
		fibo.push_back(temp);
		memo[temp] = fibo.size();
	}
}

int main() {
	int nc, n, x;
	cin >> nc;
	makeFibo();
	vector<int> arr;
	int mx;
	for (int z = 0;z<nc;z++) {
		arr.clear();
		mx = 0;
		cin >> n;
		while (n--) {
			cin >> x;
			arr.push_back(x);
			mx = max(mx, x);
		}
		getchar();
		fgets(input, 100, stdin);
		strtok(input, "\n");
		int length = strlen(input);
		int idx = 0;
		int i = 0;
		for (int j = 0; j < memo[mx]; j++) {
			output[j] = ' ';
		}
		for (int j = 0; j < length; j++) {
			char read = input[j];
			if (read >= 65 && read <= 90) {
				if (memo.count(arr[i])) {
					int idx = memo[arr[i]] - 1;
					output[idx] = read;
				}
				i++;
				if (i > arr.size() - 1) {
					break;
				}
			}
		}
		output[memo[mx]] = '\0';
		cout << output << endl;
	}
	return 0;
}
