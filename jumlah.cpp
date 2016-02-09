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
const int N = 1000;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int m, kam[15];
LL ans, fact[N], ifact[N];

LL power(LL a, LL b) {
	if(b == 0) return 1LL;
	LL temp = power(a, b/2);
	temp *= temp;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

LL inv(LL a) {
	return power(a, mod - 2);
}

void find(int pos, int sisa, int prev) {
	int i, j;
	//pf("%d %d %d\n", pos, sisa, prev);
	if(pos == m) {
		if(sisa > 9) return;
		kam[sisa]++;
		LL cur = fact[m];
		FOR(i, 1, 9) {
			cur *= ifact[kam[i]];
			cur %= mod;
			//pf("%d ", kam[i]);
		}
		kam[sisa]--;
		ans += cur;
		if(ans >= mod) ans -= mod;
		return;
	}
	FOR(i, prev, 9) {
		if(9*(m - pos) < sisa - i) continue;
		if(i*(m - pos) > sisa - i) break;
		kam[i]++;
		find(pos+1, sisa - i, i);
		kam[i]--;
	}
}

int main(void)
{
	int t, i, j;
	fact[0] = ifact[0] = 1;
	FOR(i, 1, N-1) {
		fact[i] = fact[i-1]*i;
		fact[i] %= mod;
		ifact[i] = inv(fact[i]);
	}
	sf("%d", &t);
	while(t--) {
		int n;
		ans = 0;
		reset(kam, 0);
		sf("%d %d", &n, &m);
		find(1, n, 1);
		pf("%d\n", (int) ans);
	}
	return 0;
}
