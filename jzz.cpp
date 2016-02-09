#include <bits/stdc++.h>

/**
 * Codeforces Round #257 (Div. 2)
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
const int m = 2;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL tmp[2][2], t[2][2], a[2];

void ttmp() {
	int i, j, k;
	LL ret[m][m];
	reset(ret, 0);
	FORS(i, m) FORS(j, m) FORS(k, m) {
		ret[i][j] = (ret[i][j] + t[i][k] * tmp[k][j]) % mod;
		if(ret[i][j] < 0) ret[i][j] += mod;
	}
	FORS(i, m) FORS(j, m) tmp[i][j] = ret[i][j];
}

void tmptmp() {
	int i, j, k;
	LL ret[m][m];
	reset(ret, 0);
	FORS(i, m) FORS(j, m) FORS(k, m) {
		ret[i][j] = (ret[i][j] + tmp[i][k] * tmp[k][j]) % mod;
		if(ret[i][j] < 0) ret[i][j] += mod;
	}
	FORS(i, m) FORS(j, m) tmp[i][j] = ret[i][j];
}

void atmp() {
	int i, j, k;
	LL ret[m];
	reset(ret, 0);
	FORS(i, 1) FORS(j, m) FORS(k, m) {
		ret[j] = (ret[j] + a[k] * tmp[k][j]) % mod;
		if(ret[j] < 0) ret[j] += mod;
	}
	FORS(j, m) a[j] = ret[j];
}

void power(int p) {
	int i, j;
	if(p == 0) return;
	power(p/2);
	tmptmp();
	if(p & 1) ttmp();
	//pf("disini %d\n", p);
}

int main(void)
{
	LL x, y;
	int n, i, j;
	sf("%I64d %I64d %d", &x, &y, &n);
	a[0] = x; a[1] = y;
	FORS(i, 2) FORS(j, 2) tmp[i][j] = (i == j);
	t[0][0] = 0;
	t[0][1] = -1;
	t[1][0] = 1;
	t[1][1] = 1;
	power(n - 1);
	atmp();
	cout << a[0] << endl;
	return 0;
}
