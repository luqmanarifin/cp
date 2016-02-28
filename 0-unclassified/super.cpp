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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 50005;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<int,int> pii;
pair<int,pair<int,int> > ver[N], hor[N];
#define x first
#define y second

int intersect(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b) {
	pii a0 = a.y;
	pii a1 = mp(a.y.x, a.y.y + a.x);
	pii b0 = b.y;
	pii b1 = mp(b.y.x + b.x, b.y.y);
	if (!(b0.x <= a0.x && a0.x <= b1.x && a0.y <= b0.y && b0.y <= a1.y))
		return -1;
	pii fix = mp(a.y.x, b.y.y);
	//pf("%d %d\n", fix.x, fix.y);
	return min(min(fix.x - b0.x, b1.x - fix.x), min(fix.y - a0.y, a1.y - fix.y));
}

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FORS(i, n) sf("%d %d %d", &ver[i].y.x, &ver[i].y.y, &ver[i].x);
	FORS(i, m) sf("%d %d %d", &hor[i].y.x, &hor[i].y.y, &hor[i].x);
	int ans = 0;
	FORS(i, n) FORS(j, m) {
		ans = max(ans, intersect(ver[i], hor[j]));
	}
	cout << ans << endl;
	return 0;
}
