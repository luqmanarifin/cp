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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<LL,LL> point;
#define x first
#define y second

LL cross(point a, point o, point b) {
	LL dxao = o.x - a.x;
	LL dyao = o.y - a.y;
	LL dxob = b.x - o.x;
	LL dyob = b.y - o.y;
	return dxao * dyob - dxob * dyao;
}

bool collinear(point a, point o, point b) {
	return cross(a, o, b) == 0;
}

bool ccw(point a, point o, point b) {
	return cross(a, o, b) > 0;
}

point pivot;
point dot[N];

LL dist(point a, point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angle_cmp(point a, point b) {
	if(collinear(a, pivot, b)) {
		//pf("coli %I64d %I64d %I64d %I64d\n", a.x, a.y, b.x, b.y);
		return dist(a, pivot) < dist(b, pivot);
	}
	LL xa = a.x - pivot.x;
	LL xb = b.x - pivot.x;
	LL ya = a.y - pivot.y;
	LL yb = b.y - pivot.y;
	return atan2(ya, xa) < atan2(yb, xb);
}

bool cmp(point a, point b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int main(void)
{
	//open;
	int t, i, j, n;
	sf("%d", &t);
	while(t--) {
		sf("%d", &n);
		j = 0;
		pivot = mp(INF, INF);
		point start = mp(INF, INF);
		FORS(i, n) {
			int xx, yy;
			LL X, Y;
			char c = ' ';
			sf("%d %d", &xx, &yy);
			X = xx, Y = yy;
			while(c != 'N' && c != 'Y') sf("%c", &c);
			if(c == 'Y') {
				dot[j++] = mp(X, Y);
				start = min(start, dot[j-1]);
			}
		}
		sort(dot, dot + j, cmp);
		pivot = dot[0];
		//pf("pivot %I64d %I64d\n", pivot.x, pivot.y);
		sort(dot + 1, dot + j, angle_cmp);
		int k = j - 1;
		while(k && collinear(dot[k-1], dot[k], dot[0])) k--;
		reverse(dot + k, dot + j);
		
		pf("%d\n", j);
		bool ok = 0;
		FORS(i, j) {
			if(dot[i] == start) ok = 1;
			if(ok) {
				pf("%d %d\n", (int) dot[i].x, (int) dot[i].y);
			}
		}
		FORS(i, j) {
			if(dot[i] == start) break;
			pf("%d %d\n", (int) dot[i].x, (int) dot[i].y);
		}
	}
	
	//close;
	return 0;
}
