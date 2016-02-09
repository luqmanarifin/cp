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

typedef pair<int,int> pii;

int row[101], col[105], a[55][55];
vector<pair<pii, pii> > ans;

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FOR(i, 1, n) sf("%d", row + i);
	FOR(i, 1, n) FOR(j, 1, row[i]) sf("%d", &a[i][j]);
	
	int now = 0;
	FOR(i, 1, n) FOR(j, 1, row[i]) {
		now++;
		int ii = i, jj = j;
		while(a[ii][jj] != now) {
			if(jj < row[ii]) jj++;
			else ii++, jj = 1;
		}
		if(ii != i || jj != j) {
			swap(a[i][j], a[ii][jj]);
			ans.push_back(mp(mp(i, j), mp(ii, jj)));
		}
	}
	
	cout << ans.size() << endl;
	FORS(i, ans.size()) {
		#define x first
		#define y second
		pf("%d %d %d %d\n", ans[i].x.x, ans[i].x.y, ans[i].y.x, ans[i].y.y);
	}
	return 0;
}
