#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct suffix
{
	int index;
	int color;
	int rank[2];	
};

int compare(struct suffix a, struct suffix b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
}

char inputText[110005];
char tempText[1024];
//suffix array
struct suffix suffixes[110005];
int nextSuffix[110005];
//kasai
int lcp[110005];
int invSuffix[110005];

int n;
int hashColor[105];

void buildSuffixArray() {
	int coloring = 0;
	for (int i = 0; i < n; i++) {
		suffixes[i].index = i;
		if (inputText[i] < 'a') {
			coloring++;
			suffixes[i].color = -1;
		}
		else {
			suffixes[i].color = coloring;
		}
		suffixes[i].rank[0] = inputText[i];
		suffixes[i].rank[1] = ((i+1) < n)? (inputText[i + 1]): -1; 
	}
	
	sort(suffixes, suffixes + n, compare);
	
	for (int i = 4; i < 2 * n; i *= 2) {
		int rank = 0;
		int prev = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		nextSuffix[suffixes[0].index] = 0;
		
		for (int j = 1; j < n; j++) {
			if (suffixes[j].rank[0] == prev &&
				suffixes[j].rank[1] == suffixes[j - 1].rank[1])
			{
				prev = suffixes[j].rank[0];
				suffixes[j].rank[0] = rank;
			}
			else {
				prev = suffixes[j].rank[0];
				suffixes[j].rank[0] = ++rank;
			}
			nextSuffix[suffixes[j].index] = i;
		}
		
		for (int j = 0; j < n; j++) {
			int nextIndex = suffixes[j].index + i / 2;
			suffixes[j].rank[1] = (nextIndex < n) ? suffixes[nextSuffix[nextIndex]].rank[0] : -1;
		}
		sort(suffixes, suffixes + n, compare);
	}
}

void kasai() {
	for (int i = 0; i < n; i++) {
		invSuffix[suffixes[i].index] = i;
	}
	
	int k = 0;
	
	for (int i = 0; i < n; i++, k?k--:0) {
		if (invSuffix[i] == n - 1) {
			k = 0;
			continue;
		}
		
		int j = suffixes[invSuffix[i] + 1].index;
		
		while (i + k < n && j + k < n && inputText[i + k] == inputText[j + k]) {
			k++;
		}
		
		lcp[invSuffix[i] + 1] = k;
	}
}


int main() {
	int nc;
	int pref;
	int ncStat = 0;
	while (scanf("%d", &nc) == 1 && nc) {
		if (ncStat > 0) printf("\n");
		ncStat++; 
		n = -1;
		pref = '#';
		for (int i = 0; i < nc; i++) {
			if (n != -1) {
				inputText[n] = pref++;
				scanf("%s", tempText);
				int l = strlen(tempText);
				for (int j = 0; j < l; j++) {
					inputText[n + 1 + j] = tempText[j];
				}
				n += strlen(tempText) + 1;
			}
			else {
				scanf("%s", inputText);
				n = strlen(inputText);
			}
		}
		inputText[n] = pref;
		inputText[n + 1] = '\0';
		n = strlen(inputText);
//		printf("%s\n", inputText);
		buildSuffixArray();
		kasai();
		for (int i = 0; i < n; i++) {
			printf("%d ", lcp[i]);
			printf("%s ", &inputText[suffixes[i].index]);
			printf("%d\n", suffixes[i].color);
		}
		// sliding windows
		int maxLength = 0;
		vector<int> result;
		for (int i = 0; i < nc; i++) {
			hashColor[i] = 0;
		}
		int top = 0;
		int bottom = 0;
		while (top != n - 1 && bottom != n - 1) {
			if (top == bottom) {
				bottom += 1;
				if (bottom != n - 1) {
					hashColor[suffixes[bottom].color]++;
				}
				continue;
			}
			int ct = 0;
			for (int i = 0; i < nc; i++) {
				if (hashColor[i] > 0) {
					ct++;
				}
			}
			if (ct <= nc / 2) {
				bottom += 1;
				if (bottom != n - 1) {
					hashColor[suffixes[bottom].color]++;
				}
			}
			else {
				int temp = lcp[top + 1];
				for (int i = top + 2; i <= bottom; i++) {
					if (lcp[i] < temp) {
						temp = lcp[i];
						break;
					}
				}
				if (maxLength < temp) {
					maxLength = temp;
					result.clear();
					result.push_back(top + 1);
				}
				else if (maxLength == temp) {
					result.push_back(top + 1);
				}
				hashColor[suffixes[top].color]--;
				top++;
				hashColor[suffixes[top].color]++;
			}
		}
//		printf("max length : %d\n", maxLength);
		if (maxLength > 0) {
			for (auto it : result) {
				for (int i = 0; i < maxLength; i++) {
					printf("%c", inputText[suffixes[it].index + i]);
				}
				printf("\n");
			}
		}
		else {
			printf("?\n");
		}
	} 
	return 0;
}
