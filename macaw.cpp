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

const int mod = 10007;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int m;
int temp[100][100], t[100][100], a[100];

void temptemp() {
	int i, j, k;
	int ret[m][m];
	FORS(i, m) FORS(j, m) {
		ret[i][j] = 0;
		FORS(k, m) {
			ret[i][j] += temp[i][k] * temp[k][j];
			ret[i][j] %= mod;
		}
	}
	FORS(i, m) FORS(j, m) temp[i][j] = ret[i][j];
}

void ttemp() {
	int i, j, k;
	int ret[m][m];
	FORS(i, m) FORS(j, m) {
		ret[i][j] = 0;
		FORS(k, m) {
			ret[i][j] += t[i][k] * temp[k][j];
			ret[i][j] %= mod;
		}
	}
	FORS(i, m) FORS(j, m) temp[i][j] = ret[i][j];
}

void atemp() {
	int i, j, k;
	int ret[m];
	FORS(j, m) {
		ret[j] = 0;
		FORS(k, m) {
			ret[j] += a[k] * temp[k][j];
			ret[j] %= mod;
		}
	}
	FORS(j, m) a[j] = ret[j];
}

void power(int n) {
	if(n == 0) return;
	power(n/2);
	temptemp();
	if(n & 1) {
		ttemp();
	}
}

int main(void)
{
	int test, tt, n, i, j;
	sf("%d", &test);
	FOR(tt, 1, test) {
		sf("%d %d", &n, &m);
		FORS(i, m) FORS(j, m) temp[i][j] = (i == j);
		a[0] = a[1] = 1;
		FOR(i, 2, m-1) {
			a[i] = a[i-1] + a[i-2];
			if(a[i] >= mod) a[i] -= mod;
		}
		reset(t, 0);
		FORS(j, m-1) {
			t[j+1][j] = 1;
			t[j][m-1] = 1;
		}
		power(n-1); atemp();
		pf("Case %d: %d\n", tt, (a[0] * 2) % mod);
	}
	
	return 0;
}
