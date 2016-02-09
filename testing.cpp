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

int a[505][505];
bool done[505][505];

int main(void)
{
	int i, j, n, m, k, t;
	sf("%d", &t);
	while(t--) {
		sf("%d %d %d", &n, &m, &k);
		reset(a, 0);
		reset(done, 0);
		FOR(i, 1, n) FOR(j, 1, m) sf("%d", &a[i][j]);
		bool valid = 0;
		stack<pair<int,int> > st;
		st.push(mp(1, 1));
		while(!st.empty()) {
			if(st.top() == mp(n, m)) {
				valid = 1;
				break;
			}
			int x = st.top().first;
			int y = st.top().second;
			//pf("haha %d %d\n", x, y);
			st.pop();
			done[x][y] = 1;
			if(x+1 <= n && !done[x+1][y] && a[x+1][y] - a[x][y] <= k) {
				st.push(mp(x+1, y));
				done[x+1][y] = 1;
			}
			if(x-1 >= 1 && !done[x-1][y] && a[x-1][y] - a[x][y] <= k) {
				st.push(mp(x-1, y));
				done[x-1][y] = 1;
			}
			if(y+1 <= m && !done[x][y+1] && a[x][y+1] - a[x][y] <= k) {
				st.push(mp(x, y+1));
				done[x][y+1] = 1;
			}
			if(y-1 >= 1 && !done[x][y-1] && a[x][y-1] - a[x][y] <= k) {
				st.push(mp(x, y-1));
				done[x][y-1] = 1;
			}
		}
		bool sip = 1;
		FOR(i, 1, n) FOR(j, 1, m) {
			if(i == n && j == m) continue;
			if(!done[i][j]) continue;
			bool all = 1;
			if(i+1 <= n && a[i+1][j] - a[i][j] <= k)
				all = 0;
			if(i-1 >= 1 && a[i-1][j] - a[i][j] <= k)
				all = 0;
			if(j+1 <= m && a[i][j+1] - a[i][j] <= k)
				all = 0;
			if(j-1 >= 1 && a[i][j-1] - a[i][j] <= k)
				all = 0;
			if(all) {
				sip = 0;
				goto CETAK;
			}
		}
		
		CETAK:;
		puts(valid && sip? "YES" : "NO");
	}
	
	return 0;
}
