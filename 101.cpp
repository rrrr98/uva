#include <cstdio>
#include <iostream>
#include <stack>
#include <map>

using namespace std;
map<int, stack<int>> m;
stack<int> stk;
int block[25];
void moveOnto(int a, int b) {
	int blk1 = block[a];
	int blk2 = block[b];
	if (blk1 == blk2 || a == b)return;
	while (!m[blk1].empty()){
		if (m[blk1].top() == a) {
			m[blk1].pop();
			break;
		}
		int temp = m[blk1].top();
		block[temp] = temp;
		m[temp].push(temp);
		m[blk1].pop();
	}
	while (!m[blk2].empty()) {
		if (m[blk2].top() == b) {
			m[blk2].push(a);
			break;
		}
		int temp = m[blk2].top();
		block[temp] = temp;
		m[temp].push(temp);
		m[blk2].pop();
	}
	block[a] = block[b];
}
void moveOver(int a, int b) {
	int blk1 = block[a];
	int blk2 = block[b];
	if (blk1 == blk2 || a == b)return;
	while (!m[blk1].empty()) {
		if (m[blk1].top() == a) {
			m[blk1].pop();
			break;
		}
		int temp = m[blk1].top();
		block[temp] = temp;
		m[temp].push(temp);
		m[blk1].pop();
	}
	m[blk2].push(a);
	block[a] = block[b];
}
void pileOnto(int a, int b) {
	int blk1 = block[a];
	int blk2 = block[b];
	if (blk1 == blk2 || a == b)return;
	while (!m[blk1].empty()) {
		if (m[blk1].top() == a) {
			int t = m[blk1].top();
			stk.push(t);
			block[t] = block[b];
			m[blk1].pop();
			break;
		}
		int temp = m[blk1].top();
		stk.push(temp);
		block[temp] = block[b];
		m[blk1].pop();
	}
	while (!m[blk2].empty()) {
		if (m[blk2].top() == b) {
			break;
		}
		int temp = m[blk2].top();
		block[temp] = temp;
		m[temp].push(temp);
		m[blk2].pop();
	}
	while (!stk.empty()) {
		m[blk2].push(stk.top());
		stk.pop();
	}
}
void pileOver(int a, int b) {
	int blk1 = block[a];
	int blk2 = block[b];
	if (blk1 == blk2 || a == b)return;
	while (!m[blk1].empty()) {
		if (m[blk1].top() == a) {
			int t = m[blk1].top();
			stk.push(t);
			block[t] = block[b];
			m[blk1].pop();
			break;
		}
		int temp = m[blk1].top();
		stk.push(temp);
		block[temp] = block[b];
		m[blk1].pop();
	}
	while (!stk.empty()) {
		m[blk2].push(stk.top());
		stk.pop();
	}
}
int main() {
	int num;
	char input[10];
	int a, b;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		m[i].push(i);
		block[i] = i;
	}
	while (cin >> input) {
		if (input[0] == 'm') {
			cin >> a;
			cin >> input;
			cin >> b;
			if (input[1] == 'v') {
				moveOver(a, b);
			}
			else {
				moveOnto(a, b);
			}
		}
		else if (input[0] == 'p') {
			cin >> a;
			cin >> input;
			cin >> b;
			if (input[1] == 'v') {
				pileOver(a, b);
			}
			else {
				pileOnto(a, b);
			}
		}
		else {
			break;
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%d:",i);
		while (!m[i].empty()) {
			stk.push(m[i].top());
			m[i].pop();
		}
		while (!stk.empty()) {
			printf(" %d", stk.top());
			stk.pop();
		}
		printf("\n");
	}
	return 0;
}
