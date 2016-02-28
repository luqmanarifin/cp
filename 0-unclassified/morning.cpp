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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> num;
int done[20000005];
int a[5][5];

void dfs(int i, int j, int v) {
	//pf("%d %d %d\n", i, j, v);
	if(j > 2) return;
	if(i > 2 && j != 1) return;
	if(i > 3) return;
	int x;
	dfs(i, j + 1, v);
	dfs(i + 1, j, v);
	int now = v;
	FORS(x, 3) {
		now = now*10 + a[i][j];
		if(now > 200) return;
		if(!done[now]) num.push_back(now), done[now] = 1;
		dfs(i, j + 1, now);
		dfs(i + 1, j, now);
	}
}

int main(void)
{
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
	a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
	a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;
	a[3][1] = 0;
	int i, t, k;
	dfs(0, 0, 0);
	sort(num.begin(), num.end());
	sf("%d", &t);
	while(t--) {
		sf("%d", &k);
		int pos = lower_bound(num.begin(), num.end(), k) - num.begin();
		int ans = num[pos];
		if(pos - 1 >= 0)
			if(abs(num[pos - 1] - k) < abs(k - ans))
				ans = num[pos - 1];
		pf("%d\n", ans);
	}
	
	return 0;
}
