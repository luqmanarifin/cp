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

int mask, e[20], p[20];
bool win[20];
LL ans = INF;

int main(void)
{
	int i, j, n, k;
	sf("%d %d", &n, &k);
	FORS(i, n) sf("%d %d", p + i, e + i);
	FORS(mask, (1 << n)) {
		LL cur = 0;
		int point = 0;
		reset(win, 0);
		FORS(i, n) {
			if(mask & (1 << i)) cur += e[i], ++point, win[i] = 1;
		}
		int atas = 0;
		FORS(i, n) {
			if(p[i] + 1 < point) continue;
			if(p[i] <= point && win[i]) continue;
			atas++;
		}
		if(atas < k) ans = min(ans, cur);
	}
	cout << (ans == INF? -1 : ans) << endl;
	return 0;
}
