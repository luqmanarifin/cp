#include <bits/stdc++.h>

/**
 * Good Bye 2014
 * Problem : A
 * Luqman Arifin (kadalbonek)
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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool ok[30005];
int a[30005];

int main(void)
{
	int n, t, i, j;
	sf("%d %d", &n, &t);
	FOR(i, 1, n-1) sf("%d", &a[i]);
	ok[1] = 1;
	FOR(i, 1, n-1) ok[i + a[i]] |= ok[i];
	puts(ok[t]? "YES" : "NO");
	
	return 0;
}
