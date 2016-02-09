#include <bits/stdc++.h>

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
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a[1005];

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) sf("%d", a+i);
	FOR(i,0,n-2)
		FOR(j,i+1,n-2) {
			int q = min(a[i], a[i+1]);
			int b = max(a[i], a[i+1]);
			int c = min(a[j], a[j+1]);
			int d = max(a[j], a[j+1]);
			if((q < c && c < b && b < d) || (c < q && q < d && d < b)) {
				puts("yes");
				return 0;
			}
		}
	puts("no");
	return 0;
}
