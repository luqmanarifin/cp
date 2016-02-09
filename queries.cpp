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
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int ans[N];
char s[N];

int main(void)
{
	int i, j;
	sf("%s", &s[1]);
	int n = strlen(&s[1]), m;
	FOR(i, 1, n) {
		if(s[i] == s[i+1]) ans[i]++;
		ans[i] += ans[i - 1];
	}
	sf("%d", &m);
	while(m--) {
		int l, r;
		sf("%d %d", &l, &r);
		pf("%d\n", ans[r-1] - ans[l-1]);
	}
	return 0;
}
