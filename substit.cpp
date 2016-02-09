#include <bits/stdc++.h>

/**
 * Codeforces Round #265 (Div. 2)
 * Problem : E
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int mul(int a, int b) {
	return (int)((LL) a*b % mod);
}

int add(int a, int b) {
	int ret = a + b;
	if(ret >= mod) ret -= mod;
	return ret;
}

char s[N];
vector<char> q[N];
int dig[N], val[10], po[10];

int main(void)
{
	int i, j, tt;
	sf("%s %d", s, &tt);
	FORS(i, tt) {
		char junk[N];
		sf("%s", junk);
		int len = strlen(junk);
		dig[i] = junk[0] - '0';
		FOR(j, 3, len-1) q[i].push_back(junk[j]);
	}
	FORS(i, 10) {
		val[i] = i;
		po[i] = 10;
	}
	FORM(i, tt) {
		int sz = (int) q[i].size();
		int nval = 0;
		int npow = 1;
		FORS(j, sz) {
			int d = q[i][j] - '0';
			nval = mul(nval, po[d]);
			nval = add(nval, val[d]);
			npow = mul(npow, po[d]);
		}
		val[dig[i]] = nval;
		po[dig[i]] = npow;
	}
	int ans = 0, n = strlen(s);
	FORS(i, n) {
		int d = s[i] - '0';
		ans = mul(ans, po[d]);
		ans = add(ans, val[d]);
	}
	cout << ans << endl;
	return 0;
}
