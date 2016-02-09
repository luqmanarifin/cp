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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL a[35], t[35][35], tmp[35][35];
int m;

void ttmp() {
	int i, j, k;
	LL ret[m][m];
	reset(ret, 0);
	FORS(i, m) FORS(j, m) FORS(k, m) {
		ret[i][j] = (ret[i][j] + t[i][k] * tmp[k][j]) % mod;
	}
	FORS(i, m) FORS(j, m) tmp[i][j] = ret[i][j];
}

void tmptmp() {
	int i, j, k;
	LL ret[m][m];
	reset(ret, 0);
	FORS(i, m) FORS(j, m) FORS(k, m) {
		ret[i][j] = (ret[i][j] + tmp[i][k] * tmp[k][j]) % mod;
	}
	FORS(i, m) FORS(j, m) tmp[i][j] = ret[i][j];
}

void atmp() {
	int i, j, k;
	LL ret[m];
	reset(ret, 0);
	FORS(i, 1) FORS(j, m) FORS(k, m) {
		ret[j] = (ret[j] + a[k] * tmp[k][j]) % mod;
	}
	FORS(j, m) a[j] = ret[j];
}

void power(int p) {
	if(p == 0) return;
	power(p/2);
	tmptmp();
	if(p & 1) ttmp();
}

int main(void)
{
	int tt;
	sf("%d", &tt);
	while(tt--) {
		int n, k, i, j;
		reset(a, 0);
		reset(t, 0);
		sf("%d %d", &n, &k);
		bool c[35];
		int d[35];
		reset(c, 0);
		m = 0;
		FORS(i, n) {
			sf("%d", d + i);
			m = max(m, d[i]);
			c[d[i]] = 1;
		}
		FORS(i, m) FORS(j, m) tmp[i][j] = (i == j);
		a[0] = 1;
		FOR(i, 1, m-1)
			FORS(j, n) {
				if(d[j] > i) continue;
				a[i] += a[i-d[j]];
				if(a[i] >= mod) a[i] -= mod;
			}
		FORS(i, m) FORS(j, m) {
			if(j != m - 1) {
				if(i == j + 1)
					t[i][j] = 1;
			} else {
				if(c[m - i])
					t[i][j] = 1;
			}
		}
		power(k);
		atmp();
		pf("%d\n", (int) a[0]);
	}
	return 0;
}
