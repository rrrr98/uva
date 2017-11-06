#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
int nextSeed(int z, int i, int m,int l) {
	return (z * l + i) % m;
}
int main () {
	int cycle;
	int z,i,m,l;
	int x,y,idxX,idxY;
	int cases = 1;
	while (scanf("%d %d %d %d", &z, &i, &m, &l),z,i,m,l) {
		idxX = 1;
		idxY = 2;
		x = nextSeed(z,i,m,l);
		y = nextSeed(z,i,m,x);
		while (x != y) {
			idxX += 1;
			idxY += 2;
			x = nextSeed(z,i,m,x);
			y = nextSeed(z,i,m,nextSeed(z,i,m,y));
		}
		printf("Case %d: %d\n", cases++, idxY-idxX);
	}
	return 0;
}
