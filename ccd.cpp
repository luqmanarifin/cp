#include <bits/stdc++.h>

/** 
 * Bayan 2015 Contest Warm Up
 * Problem : D
 * بسم الله الرحمان الرحيم
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

map<int,LL> ans;
int a[N];

int main(void)
{
	int i, j, n, q;
	sf("%d", &n);
	FORS(i, n) sf("%d", &a[i]);
	FORS(i, n) {
		int cob = a[i];
		ans[cob]++;
		FOR(j, i + 1, n-1) {
			cob = gcd(cob, a[j]);
			ans[cob]++;
		}
	}
	sf("%d", &q);
	while(q--) {
		int a; sf("%d", &a);
		pf("%I64d\n", ans[a]);
	}
	
	return 0;
}
