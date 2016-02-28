#include <bits/stdc++.h>

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
int lcm(int a, int b) { return a*b / gcd(a, b); }

int solve(int a, int b) {
	if(a < b) return a;
	return solve(a/b, b) + (a % b);
}

int main(void)
{
	int n, i, ans = 0;
	sf("%d", &n);
	FOR(i, 2, n-1)
		ans += solve(n, i);
	int dem = n-2;
	int fpb = gcd(dem, ans);
	dem /= fpb;
	ans /= fpb;
	cout << ans << '/' << dem << endl;
	
	return 0;
}
