#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int L, N;
	string s1, s2;
	char t1, t2;
	cin >> L >> N;
	map<string, string> map;
	while (L--) {
		cin >> s1 >> s2;
		map[s1] = s2;
	}
	while (N--) {
		cin >> s1;
		if (map.find(s1) != map.end()) {
			cout << map[s1] << endl;
		}
		else {
			t1 = s1.at(s1.size() - 2);
			t2 = s1.at(s1.size() - 1);
			if (t1 != 'a' && t1 != 'i' && t1 != 'u' && 
				t1 != 'e' && t1 != 'o' && t2 == 'y') {
				s1.replace(s1.size() - 1, 1, "ies");
			}
			else if ((t1 == 's' && t2 == 'h') || (t1 == 'c' && t2 == 'h')
				|| t2 == 'o' || t2 == 's' || t2 == 'x') {
				s1.append("es");
			}
			else {
				s1.append("s");
			}
			cout << s1 << endl;
		}
	}
	return 0;
}
