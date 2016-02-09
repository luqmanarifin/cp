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

#define x first
#define y second

pair<int,int> snow[105];
int ans = -1, n;
bool done[105];

void dfs(int now) {
	int i;
	pair<int, int> cur = snow[now];
	FORS(i, n)
		if(cur.x == snow[i].x || cur.y == snow[i].y)
			if(!done[i]) {
				done[i] = 1;
				dfs(i);
			}
}

int main(void)
{
	int i; sf("%d", &n);
	FORS(i, n) {
		sf("%d %d", &snow[i].x, &snow[i].y);
	}
	FORS(i, n) if(!done[i]) {
		done[i] = 1;
		dfs(i);
		ans++;
	}
	cout << ans << endl;
	return 0;
}
