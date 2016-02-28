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

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a[3005];

int main(void)
{
	int n, m, i;
	sf("%d %d", &n, &m);
	FORS(i, m) sf("%d", a + i);
	sort(a, a + m);
	if(a[0] == 1 || a[m-1] == n) {
		puts("NO");
		return 0;
	}
	FOR(i, 2, m-1)
		if(a[i-2] + 2 == a[i]) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
