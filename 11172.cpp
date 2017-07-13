#include <iostream>

using namespace std;

int main() {
	int num, a, b;
	cin >> num;
	while (num--) {
		cin >> a >> b;
		if (a < b) {
			cout << "<\n";
		}
		else if (a > b) {
			cout << ">\n";
		}
		else {
			cout << "=\n";
		}
	}
	return 0;
}
