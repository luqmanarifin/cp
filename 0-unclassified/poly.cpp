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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<int,int> Point;
int len;

#define x first
#define y second

bool valid (vector<Point> a) {
	sort(a.begin(), a.end());
	int i;
	FOR(i, 1, 3) if(a[i] == a[i-1]) return 0;
	FORS(i, 4) if(a[i].x < 0 || a[i].y < 0) return 0;
	return 1;
}

int dis(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int dist(vector<Point> a) {
	int i, temp = 0;
	FOR(i, 1, 3) temp += dis(a[i], a[i-1]);
	return temp;
}

int main(void)
{
	int n, m, i, j;
	vector<Point> ans[10];
	sf("%d %d", &n, &m);
	ans[0].push_back(mp(0 , 0));
	ans[0].push_back(mp(n , m));
	ans[0].push_back(mp(n , 0));
	ans[0].push_back(mp(0 , m));
	
	ans[1].push_back(mp(0 , 0));
	ans[1].push_back(mp(n , m));
	ans[1].push_back(mp(0 , m));
	ans[1].push_back(mp(n , 0));
	
	ans[2].push_back(mp(n , m-1));
	ans[2].push_back(mp(0 , 0));
	ans[2].push_back(mp(n , m));
	ans[2].push_back(mp(0 , 1));
	
	ans[3].push_back(mp(n-1 , m));
	ans[3].push_back(mp(0 , 0));
	ans[3].push_back(mp(n , m));
	ans[3].push_back(mp(1 , 0));
	
	vector<Point> res;
	FORS(i, 4) {
		if(!valid(ans[i])) continue;
		int now = dist(ans[i]);
		if(now > len) {
			len = now;
			res = ans[i];
		}
	}
	FORS(i, 4) pf("%d %d\n", res[i].x, res[i].y);
	return 0;
}
