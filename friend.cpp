#include <bits/stdc++.h>

using namespace std;

#define LL long long

int main() {
	LL a, b, x, y;
	cin >> a >> b >> x >> y;
	LL l = 0, r = 2e9;
	while(l < r) {
		LL m = (l + r) >> 1;
		//printf("%d %d %d\n", l, m, r);
		LL f1 = m / x;
		LL f2 = m / y;
		LL both = m / (x * y);
		if(max(0LL, b - f1 + both) + max(0LL, a - f2 + both) <= m - f1 - f2 + both)
			r = m;
		else
			l = m + 1;
	}
	cout << l << endl;
}