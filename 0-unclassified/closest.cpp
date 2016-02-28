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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const double INF = 99999;
const int inf = 2e9;
const int N = 1e4 + 5;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

typedef pair<DB, DB> point;
#define x first
#define y second

point p[N];

double dist(point a, point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double ans;

void solve(int l, int r) {
	if(l == r) return;
	int mid = (l + r) >> 1, i, j;
	solve(l, mid);
	solve(mid+1, r);
	double line = (p[mid].x + p[mid+1].x)/2;
	for(j = mid+1; p[j].x < line + ans && j <= r; j++){
		for(i = mid; line - ans < p[i].x && i >= l; i--) {
			if(abs(p[i].y - p[j].y) > ans) continue;
			ans = min(ans, dist(p[i], p[j]));
		}
	}
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	int i, j, n;
	sf("%d", &n);
	while(n) {
		FORS(i, n) sf("%lf %lf", &p[i].x, &p[i].y);
		sort(p, p + n);
		ans = INF;
		solve(0, n - 1);
		if(ans >= 10000.0) puts("INFINITY");
		else pf("%.4lf\n", ans);
		sf("%d", &n);
	}
	
	//close;
	return 0;
}