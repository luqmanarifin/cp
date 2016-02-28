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
const double eps = 1e-13;
const int N = 1005;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

pair<int,int> pos[N];
vector<pair<int,pair<int,int> > > ans;
bool done[N];
int row[N], col[N];

#define x first
#define y second

int main(void)
{
	int i, j, n, m;
	sf("%d", &n);
	FORS(i, n - 1) sf("%d %d", &pos[i].x, &pos[i].y);
	FORD(m, n, 2) {
		reset(row, 0);
		reset(col, 0);
		FORS(i, n - 1) {
			if(done[i]) continue;
			row[pos[i].x]++;
			col[pos[i].y]++;
		}
		if(col[m]) {
			int poscol = -1;
			FOR(i, 1, m) {
				if(col[i] == 0) {
					poscol = i;
					break;
				}
			}
			if(poscol == -1) break;
			ans.push_back(mp(2, mp(poscol, m)));
			FORS(i, n - 1) {
				if(done[i]) continue;
				if(pos[i].y == poscol) pos[i].y = m;
				else if(pos[i].y == m) pos[i].y = poscol;
			}
		}
		if(row[m] == 0) {
			int posrow = -1;
			FOR(i, 1, m) {
				if(row[i]) {
					posrow = i;
					break;
				}
			}
			if(posrow == -1) break;
			ans.push_back(mp(1, mp(posrow, m)));
			FORS(i, n - 1) {
				if(done[i]) continue;
				if(pos[i].x == posrow) pos[i].x = m;
				else if(pos[i].x == m) pos[i].x = posrow;
			}
		}
		FORS(i, n - 1) {
			if(done[i]) continue;
			if(pos[i].x == m) done[i] = 1;
		}
	}
	int sz = (int) ans.size();
	pf("%d\n", sz);
	FORS(i, sz) pf("%d %d %d\n", ans[i].x, ans[i].y.x, ans[i].y.y);
	
	return 0;
}
