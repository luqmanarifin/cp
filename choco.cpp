#include <bits/stdc++.h>

/**
 * Codeforces Round #257 (Div. 2)
 * Problem : C
 * Luqman Arifin (kadalbonek)
 */

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL solve(LL sq, LL line) {
	LL cur = 1LL*sq/(line + 1);
	if(!cur) cur = 1;
	return cur;
}

int main(void)
{
	LL n, m, k;
	sf("%I64d %I64d %I64d", &n, &m, &k);
	if(k > n + m - 2) {
		puts("-1");
		return 0;
	}
	LL ans1 = 0, ans2 = 0, kk = k;
	ans1 = solve(n, kk);
	if(kk > n - 1) {
		kk -= n - 1;
		ans1 *= solve(m, kk);
	} else
		ans1 *= m;
	
	kk = k;
	ans2 = solve(m, kk);
	if(kk > m - 1) {
		kk -= m - 1;
		ans2 *= solve(n, kk);
	} else
		ans2 *= n;
	
	cout << max(ans1, ans2) << endl;
	return 0;
}
