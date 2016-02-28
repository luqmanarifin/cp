#include <bits/stdc++.h>

/**
 * MemSQL Start[c]UP 2.0 - Round 2 - Online Round
 * Problem : B
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
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

pair<LL,int> pre[N];
int cnt[2];
#define x first
#define y second

int main(void)
{
	int n, m, i, j, t = 1, X;
	sf("%d %d", &m, &n);
	FOR(i, 1, m) {
		sf("%d", &X);
		pre[t++] = mp(1LL*X, 0);
	}
	FOR(i, 1, n) {
		sf("%d", &X);
		pre[t++] = mp(1LL*X, 1);
	}
	sort(pre + 1, pre + 1 + n + m);
	reverse(pre + 1, pre + 1 + n + m);
	FOR(i, 1, n+m) pre[i].x += pre[i-1].x;
	LL ans = INF;
	FOR(i, 1, n+m) {
		cnt[pre[i].y]++;
		if(cnt[0] == m && i > m) break;
		if(cnt[1] == n && i > n) break;
		LL cur = pre[n+m].x - pre[i].x;
		cur *= 1LL*i;
		if(cur < ans) ans = cur;
		pf("%I64d ", cur);
	}
	cout << ans << endl;
	return 0;
}
