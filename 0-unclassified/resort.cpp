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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int type[N], from[N];
vector<int> ans[N], to[N];

void dfs(int obj, int source) {
	//pf("%d %d\n", obj, source);
	if((int) to[obj].size() > 1) return;
	ans[source].push_back(obj);
	if(from[obj]) dfs(from[obj], source);
}

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FOR(i, 1, n) sf("%d", type + i);
	FOR(i, 1, n) {
		sf("%d", &from[i]);
		to[from[i]].push_back(i);
	}
	int k = -1, ret;
	FOR(i, 1, n) if(type[i]) {
		dfs(i, i);
		if((int) ans[i].size() > k) {
			k = ans[i].size();
			ret = i;
		}
	}
	cout << k << endl;
	FORM(i, ans[ret].size()) pf("%d ", ans[ret][i]); nl;
	return 0;
}
