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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

pair<int,int> d[1005];

#define x first
#define y second

int main(void)
{
	int s, n, i;
	sf("%d %d", &s, &n);
	FORS(i, n) sf("%d %d", &d[i].x, &d[i].y);
	sort(d, d + n);
	FORS(i, n) {
		if(s <= d[i].x) {
			puts("NO");
			return 0;
		}
		s += d[i].y;
	}
	puts("YES");
	return 0;
}
