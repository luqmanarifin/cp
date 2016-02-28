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
const LL INF = 4e18;
const int inf = 5000000;
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

typedef pair<int, int> point;
#define x first
#define y second

point p[N];

int dist(point a, point b) {
	return max(abs(a.x - b.x), abs(a.y - b.y));
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	//open;
	int i, j, n;
	while(cin >> n) {
		FORS(i, n) cin >> p[i].x >> p[i].y;
		sort(p, p + n);
		set<pair<int,int> > temp;
		int ans = inf;
		int tail = 0;
		FORS(i, n) {
			while(tail < i && abs(p[tail].x - p[i].x) > ans) {
				temp.erase(temp.find(mp(p[tail].y, p[tail].x)));
				tail++;
			}
			set<pair<int,int> >::iterator it = temp.lower_bound(mp(p[i].y - ans, -inf));
			set<pair<int,int> >::iterator end = temp.upper_bound(mp(p[i].y + ans, inf));
			while(it != end) {
				//pf("%d %d\n", it->y, it->x);
				ans = min(ans, dist(p[i], mp(it->y, it->x)));
				it++;
			}
			
			temp.insert(mp(p[i].y, p[i].x));
		}
		pf("%d\n", ans);
	}
	
	//close;
	return 0;
}