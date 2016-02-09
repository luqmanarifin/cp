#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	long long n, m, a;
	cin >> n >> m >> a;
	long long ans = (n % a? n/a + 1 : n/a) * (m % a? m/a + 1 : m/a);
	cout << ans << endl;
	return 0;
}