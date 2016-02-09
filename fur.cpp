

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

// Abbrev
#define F first
#define S second
#define PB push_back
#define MP make_pair

// Macros
#define ALL(c) (c).begin(), (c).end()
#define SZ(a) (int)(a).size()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define FORIT(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

// Typedef
typedef long long ll;

// Const
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int INF = 2123123123;
const int MOD = 1e9+7;

// Functions
inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n,h;
int a[2100], vis[2100][2100];
ll memo[2100][2100];

ll dp(int p, int cacha) {
	if (p == n) return (cacha == 0);
	if (vis[p][cacha]) return memo[p][cacha];
	ll ret;
	if (cacha + a[p] + 1 == h) {
		ret = (dp(p+1, cacha + 1) % MOD + ((ll)(cacha+1) * dp(p+1, cacha)) % MOD ) % MOD;
	}
	else if (cacha + a[p] == h) {
		ret = (((ll)(cacha) * dp(p+1, cacha-1)) % MOD + dp(p+1, cacha)) % MOD;
	}
	else ret = 0;
	vis[p][cacha] = 1;
	return memo[p][cacha] = ret;
}

int main() {
	scanf("%d%d",&n,&h);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%I64d\n", dp(0,0));
	return 0;
}