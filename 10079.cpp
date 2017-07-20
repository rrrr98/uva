#include <cstdio>
#include <string.h>

using namespace std;

int main() {
	long long slice;
	while (scanf("%lld", &slice) == 1) {
		if (slice < 0) {
			break;
		}
		printf("%lld\n", slice * (slice+1)/2+1);
	}
}
