#include <bits/stdc++.h>

/**
 * Codeforces Round #265 (Div. 2)
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[1005], n, ans;

int dfs(int i) {
	if(a[i] == 0 || i >= n) return 0;
	a[i] = 0;
	return dfs(i + 1) + 1;
}

int main(void)
{
	int i, j;
	sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	FORS(i, n) {
		int now = dfs(i);
		if(now) ans += now + 1;
		//pf("%d %d\n", i, dfs(i));
	}
	pf("%d\n", ans? ans - 1 : 0);
	return 0;
}
