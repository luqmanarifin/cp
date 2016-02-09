#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, m, pos[105], sor[105], ans[105];

int main(void)
{
	sf("%d %d", &n, &m); int i;
	FORS(i,n) sf("%d", &pos[i]), sor[i] = pos[i];
	sort(sor, sor+n);
	FORS(i,n) ans[sor[i]] = i % 2;
	FORS(i,n) pf("%d ",ans[pos[i]]);
	
	return 0;
}
