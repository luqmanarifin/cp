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

int truk[105];

int main(void)
{
	int a, b, c, i, j;
	sf("%d %d %d", &a, &b, &c);
	FORS(i, 3) {
		int x, y;
		sf("%d %d", &x, &y);
		FOR(j, x, y-1)
			truk[j]++;
	}
	int ans = 0;
	FOR(i, 0, 100) {
		if(truk[i] == 1) ans += a;
		else if(truk[i] == 2) ans += 2*b;
		else if(truk[i] == 3) ans += 3*c;
	}
	cout << ans << endl;
	return 0;
}
