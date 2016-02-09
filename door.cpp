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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

inline long long get(int a) {
	return (long long)(a + 1)*(a + 2)/2;
}

int main(void)
{
	int tt, t, n, i, j;
	LL m;
	sf("%d", &t);
	FOR(tt, 1, t) {
		sf("%d %I64d", &n, &m);
		int l = 0, r = n - 1;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(get(mid) < m) l = mid + 1;
			else r = mid;
		}
		pf("Case %d: %d %d\n", tt, l, (int)(m - get(l - 1) - 1));
	}
	
	return 0;
}
