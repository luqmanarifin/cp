#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

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
#define open freopen("marathon.in","r",stdin); freopen("marathon.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int x[N], y[N];

int dist(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	open;
	int ans = inf;
	int i, j, n;
	sf("%d", &n);
	FORS(i, n) sf("%d %d", &x[i], &y[i]);
	int tot = 0;
	FORS(i, n-1) tot += dist(i, i + 1);
	FOR(i, 1, n-2) {
		ans = min(ans, tot - dist(i, i - 1) - dist(i, i + 1) + dist(i - 1, i + 1));
	}
	cout << ans << endl;
	close;
	return 0;
}