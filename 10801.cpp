#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <climits>

using namespace std;

struct node {
	int value;
	int cost;
	list<node*> adjacent;
	list<pair<int, node*>> edges;
	node() {
		cost = INT_MAX;
	}
};

list<node*> visited;

void makeAdjacent(int cost, node* a, node *b) {
	a->adjacent.push_back(b);
	a->edges.push_back(make_pair(cost, b));
	b->adjacent.push_back(a);
	b->edges.push_back(make_pair(cost, a));
}


void dijkstra(node *head, node *now) {
	for (auto it = now->edges.begin(); it != now->edges.end(); it++) {
		int cost = it->first;
		node *target = it->second;
		if (cost + now->cost < target->cost) {
			target->cost = cost + now->cost;
			if (target != head) {
				dijkstra(head, target);
			}
		}
	}
}

int main() {
	int ne, target;
	int i, j;
	vector<pair<int,int>> index;
	int elev[5];
	map<int, map<int, node*>> map;
	char *temp;
	char input[1000];
	list<int> exist;
	node *head;
	node *t;
	node *abc;
	vector<int> arr[5];
	while (scanf("%d %d\n", &ne, &target) == 2) {
		index.clear();
		for (i = 0; i < ne; i++) {
			scanf("%d", &elev[i]);
		}
		getc(stdin);
		for (i = 0; i < ne; i++) {
			fgets(input, 1000, stdin);
			temp = strtok(input, " \n");
			while (temp != NULL) {
				arr[i].push_back(stoi(temp, nullptr));
				temp = strtok(NULL, " \n");
			}
		}
		head = new node();
		head->value = 0;
		head->cost = 0;
		exist.clear();
		exist.push_back(0);
		for (i = 0; i < ne; i++) {
			t = NULL;
			for (auto it = arr[i].begin(); it != arr[i].end(); it++) {
				if (t == NULL) {
					if (*it != 0) {
						t = new node();
						t->value = *it;
					}
					else {
						t = head;
					}
				}
				else {
					int cost = (*it - t->value) * elev[i];
					abc = new node();
					abc->value = *it;
					makeAdjacent(cost, abc, t);
					t = abc;
				}
				if (find(exist.begin(), exist.end(), *it) != exist.end()) {
					if (*it != 0) {
						for (j = 0; j < ne; j++) {
							if (j != i) {
								if (map[j][*it] != NULL) {
									makeAdjacent(60, map[j][*it], t);
								}
							}
						}
					}
				}
				else {
					exist.push_back(*it);
				}
				map[i][*it] = t;
				if (target == t->value) {
					index.push_back(make_pair(i, *it));
				}
			}
		}
		visited.clear();
		dijkstra(head, head);
		int ans = INT_MAX;
		for (auto it = index.begin(); it != index.end(); it++) {
			int cst = map[it->first][it->second]->cost;
			if (cst < ans) {
				ans = cst;
			}
		}
		if (ans == INT_MAX) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << ans << endl;
		}
		for (i = 0; i < 5; i++) arr[i].clear();
	}
	return 0;
}
