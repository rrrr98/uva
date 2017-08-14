// Edit : 14 August 2017
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int h, u, d, f;
	double speed = 0;
	double now = 0;
	bool status;
	double fatigue;
	int ct;
	while (scanf("%d %d %d %d", &h, &u, &d, &f) == 4) {
		if (h == 0) {
			break;
		}
		status = true;
		now = 0;
		speed = u + 0.0;
		fatigue = speed * f * 1.0 / 100.0;
		ct = 0;
		while (now <= h) {
			ct++;
			now += speed;
			if (now > h) break;
			speed -= fatigue;
			if (speed < 0) {
				speed = 0;
			}
			now -= d;
			if (now < 0) {
				status = false;
				break;
			}
		}
		if (status) {
			printf("success on day %d\n", ct);
		}
		else {
			printf("failure on day %d\n", ct);
		}
	}
	return 0;
}
