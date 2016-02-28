#include <bits/stdc++.h>

/**
 * Codeforces Round #258 (Div. 2)
 * Problem : D
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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL ans[2], cnt[2][2];

int main(void)
{
	char s[N];
	sf("%s", s);
	int i, n = strlen(s);
	FORS(i, n) {
		int c = (s[i] == 'b');
		cnt[c][i&1]++;
		ans[0] += cnt[c][(i&1)^1];
		ans[1] += cnt[c][i&1];
	}
	pf("%I64d %I64d\n", ans[0], ans[1]);
	return 0;
}
