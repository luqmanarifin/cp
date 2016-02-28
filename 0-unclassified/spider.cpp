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

int ans[2005];

int main(void)
{
	int n, m, k, i, j;
	sf("%d %d %d", &n, &m, &k);
	FORS(i, n) {
		char s[2005];
		sf("%s", s);
		FORS(j, m) {
			if(s[j] == 'R') if(j+i < m) ans[j+i]++;
			if(s[j] == 'L') if(j-i >= 0) ans[j-i]++;
			if(s[j] == 'U') if(i%2 == 0) ans[j]++;
		}
	}
	FORS(i, m) pf("%d ", ans[i]); nl;
	return 0;
}
