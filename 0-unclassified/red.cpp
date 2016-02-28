#include <bits/stdc++.h>

using namespace std;
const double PI = acos(-1), eps = 1e-7;
double a, b, r;

int main() {
	cin >> a >> b >> r;
	a += r;
	b += r;
	long long li = 2, ri = 1e18;
	while(li < ri) {
		long long mid = (li+ri) >> 1;
		double now = a*sin(PI/mid);
		if(r < now && !(abs(now-r) < eps))
			li = mid+1;
		else
			ri = mid;
	}
	long long ans = -li;
	ri = 1e18;
	li = 2;
	while(li < ri) {
		long long mid = (li+ri) >> 1;
		double now = b*sin(PI/mid);
		if(r < now || abs(now-r) < eps)
			li = mid+1;
		else
			ri = mid;
	}
	ans += li;
	ans = max(ans, 0LL);
	cout << ans << "\n";
	return 0;
}