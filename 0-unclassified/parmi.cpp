#include <bits/stdc++.h>

/**
 * Codeforces Round #261 (Div. 2)
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
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

map<int,int> cnt;
int a[N], fi[N], fj[N];

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	FORS(i, n) {
		cnt[a[i]]++;
		fi[i] = cnt[a[i]];
	}
	cnt.clear();
	FORM(i, n) {
		cnt[a[i]]++;
		fj[i] = cnt[a[i]];
	}
	
	LL ans = 0;
	FORS(i, n) {
		int pos = upper_bound(fi, fi + n, fj[i]) - fi;
		pos = n - pos;
		ans += 1LL*pos;
	}
	cout << ans << endl;
	return 0;
}
