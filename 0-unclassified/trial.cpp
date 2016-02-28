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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

pair<LL, int> a[N], b[N];

#define x first
#define y second

int main(void)
{
	int n, i;
	sf("%d", &n);
	FORS(i, n) {
		sf("%I64d", &a[i].x);
		a[i].y = i;
	}
	FORS(i, n) {
		sf("%I64d", &b[i].x);
		b[i].y = i;
	}
	sort(b, b + n);
	FOR(i, 1, n-1)
		b[i].x += b[i-1].x;
		
	i = 0;
	while(a[b[i].y].x > b[i].x && i < n) i++;
	if(i < n) puts("Redemption");
	else puts("Dire victory");
	return 0;
}
