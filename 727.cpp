#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {
	int nc;
	char arr[3];
	stack<char> s;
	int i = 0;
	cin >> nc;
	getc(stdin);
	getc(stdin);
	while (nc--) {
		if (i == 1) {
			printf("\n");
		}
		while (fgets(arr, 3, stdin)) {
			if (arr[0] == '\n') {
				break;
			}
			if (arr[0] == '(' || arr[0] == ')' || arr[0] == '+' || arr[0] == '-' || arr[0] == '*' || arr[0] == '/') {
				if (arr[0] != ')') {
					if (arr[0] == '+' || arr[0] == '-') {
						if (!s.empty() && (s.top() == '*' || s.top() == '/')) {
							printf("%c", s.top());
							s.pop();
						}
						if (!s.empty() && s.top() != '(') {
							printf("%c", s.top());
							s.pop();
						}
						s.push(arr[0]);
					}
					else {
						if (arr[0] != '(' && !s.empty() && (s.top() == '*' || s.top() == '/')) {
							printf("%c", s.top());
							s.pop();
						}
						s.push(arr[0]);
					}
				}
				else {
					while (!s.empty() && s.top() != '(') {
						printf("%c", s.top());
						s.pop();
					}
					s.pop();
				}
			}
			else {
				printf("%c", arr[0]);
			}
		}
		while (!s.empty()) {
			printf("%c", s.top());
			s.pop();
		}
		printf("\n");
		i = 1;
	}
	return 0;
}
