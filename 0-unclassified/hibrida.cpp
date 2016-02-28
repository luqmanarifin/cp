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
const LL INF = 9e18;
const int inf = 2e9;
const int N = 5e4 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<int,int> pii;
#define x first
#define y second

bool by_x(pii a, pii b) {
	return a.x < b.x;
}
bool by_y(pii a, pii b) {
	return a.y < b.y;
}
unsigned int dist(pii a) {
	return a.x + a.y;
}
bool by_o(pii a, pii b) {
	return dist(a) < dist(b);
} 

pii sorted[N];

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FORS(i, n) {
		sf("%d %d", &sorted[i].x, &sorted[i].y);
	}
	sort(sorted, sorted + n, by_o);
	int magic = min(1000, n);
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		LL ans = INF;
		FORS(i, magic) {
			LL cur = 1LL*sorted[i].x*a + 1LL*sorted[i].y*b;
			if(cur < ans) ans = cur;
		}
		pf("%lld\n", ans);
	}
	return 0;
}
