#include <bits/stdc++.h>

using namespace std;

int main() {
	int k, l, m, n, d, ans = 0;
	scanf("%d %d %d %d %d", &n, &k, &l, &m, &d);
	for(int i = 1; i <= d; i++) {
		ans += (i % k == 0) || (i % l == 0) || (i % m == 0) || (i % n == 0);
	}
	cout << ans << endl;
	return 0;
}