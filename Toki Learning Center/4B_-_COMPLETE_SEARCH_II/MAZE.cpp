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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[105][105];
bool vis[105][105];

int main(void)
{
	int n, m, i, j, x, y, ans = -1;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) FOR(j, 1, m) sf("%d", &a[i][j]);
	sf("%d %d", &x, &y);
	queue<pair<pair<int,int>,int> > q;
	q.push(mp(mp(x, y), 0));
	while(!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int step = q.front().second;
		
		q.pop();
		if(vis[x][y] || a[x][y] == -1) continue;
		//pf("%d %d %d\n", x, y, step);
		vis[x][y] = 1;
		if(x == 1 || x == n || y == 1 || y == m) {
			ans = step;
			break;
		}
		q.push(mp(mp(x + 1, y), step + 1));
		q.push(mp(mp(x - 1, y), step + 1));
		q.push(mp(mp(x, y + 1), step + 1));
		q.push(mp(mp(x, y - 1), step + 1));
	}
	cout << ans + 1 << endl;
	return 0;
}
