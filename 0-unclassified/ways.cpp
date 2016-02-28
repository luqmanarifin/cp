#include <bits/stdc++.h>

/**
 * Codeforces Round #266 (Div. 2) 
 * Problem : C
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
const int N = 5e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N], back[N];
LL sum;

int main(void)
{
	int i, n;
	sf("%d", &n);
	FOR(i, 1, n) {
		sf("%d", a + i);
		sum += a[i];
	}
	LL cur = 0;
	FORD(i, n, 1) {
		cur += a[i];
		if(cur*3 == sum)
			back[i] = 1;
		back[i] += back[i+1];
	}
	LL ans = 0; cur = 0;
	FOR(i, 1, n) {
		cur += a[i];
		if(cur*3 == sum)
			ans += back[i+2];
	}
	cout << ans << endl;
	return 0;
}
