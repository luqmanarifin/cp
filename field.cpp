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
const double eps = 1e-13;
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n, m, dx, dy;
LL at[N];
vector<pair<int,int> > apple[N];

int main(void)
{
	int i, j;
	reset(at, -1);
	sf("%d %d %d %d", &n, &m, &dx, &dy);
	at[0] = 0;
	int now = dy;
	i = 0;
	while(now) {
		at[now] = ++i;
		now += dy;
		now %= n;
	}
	int pol = 0;
	FORS(i, m) {
		int x, y;
		sf("%d %d", &x, &y);
		LL id = x - at[y] * dx;
		id %= n;
		if(id < 0) id += n;
		apple[id].push_back(mp(x, y));
		pol = max(pol, (int) apple[id].size());
	}
	FORS(i, n) if(apple[i].size() == pol) {
		pf("%d %d\n", apple[i][0].first, apple[i][0].second);
		return 0;
	}
}
