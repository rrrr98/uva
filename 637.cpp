#include <cstdio>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

int main() {
	list<int> first;
	list<int> second;
	int a, b;
	int num;
	while (scanf("%d", &num) == 1) {
		if (num == 0) {
			break;
		}
		first.clear();
		second.clear();
		printf("Printing order for %d pages:\n", num);
		if (num == 1) {
			printf("Sheet 1, front: Blank, 1\n");
			continue;
		}
		for (int i = 1; i <= num;i++) {
			if (i % 2 != 0) {
				first.push_back(i);
			}
			else {
				second.push_back(i);
			}
		}
		int s1 = first.size();
		int s2 = second.size();
		if (s1 - s2 > 0) {
			second.push_back(0);
		}
		else if (s1 - s2 < 0) {
			first.push_back(0);
		}
		if (first.size() % 2 != 0) {
			first.push_back(0);
			second.push_back(0);
		}
		for (int i = 1; i <= num/4+1; i++) {
			if (!first.empty()) {
				a = second.back();
				second.pop_back();
				b = first.front();
				first.pop_front();
				if (a == 0 && b!= 0) {
					printf("Sheet %d, front: Blank, %d\n", i, b);
				}
				else if(a!= 0 && b==0){
					printf("Sheet %d, front: %d, Blank\n", i, a);
				}
				else if(a!=0 && b!=0){
					printf("Sheet %d, front: %d, %d\n", i,a, b);
				}
			}
			if (!first.empty()) {
				a = second.front();
				second.pop_front();
				b = first.back();
				first.pop_back();
				if (a == 0 && b != 0) {
					printf("Sheet %d, back : Blank, %d\n", i, b);
				}
				else if (a != 0 && b == 0) {
					printf("Sheet %d, back : %d, Blank\n", i, a);
				}
				else if (a != 0 && b != 0) {
					printf("Sheet %d, back : %d, %d\n", i, a, b);
				}
			}
		}
	}
	return 0;
}
