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
const int N = 2005;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<int,int> pii;
#define x first
#define y second

LL a[N][N], b[N][N], c[N][N], d[N][N];
int num[N][N], n;
vector<pair<LL, pii> > will[2];

bool valid(int i, int j) {
	return (1 <= i && i <= n && 1 <= j && j <= n);
}

int main(void)
{
	int i, j;
	sf("%d", &n);
	FOR(i, 1, n) FOR(j, 1, n) sf("%d", &num[i][j]);
	for(i = n, j = 1; valid(i, j);) {
		int ii = i, jj = j;
		while(valid(ii, jj)) {
			a[ii][jj] = a[ii-1][jj-1] + num[ii][jj];
			ii++, jj++;
		}
		if(i > 1) i--;
		else j++;
	}
	for(i = 1, j = 1; valid(i, j); ) {
		int ii = i, jj = j;
		while(valid(ii, jj)) {
			b[ii][jj] = b[ii-1][jj+1] + num[ii][jj];
			ii++, jj--;
		}
		if(j < n) j++;
		else i++;
	}
	for(i = 1, j = 1; valid(i, j); ) {
		int ii = i, jj = j;
		while(valid(ii, jj)) {
			c[ii][jj] = c[ii+1][jj-1] + num[ii][jj];
			ii--, jj++;
		}
		if(i < n) i++;
		else j++;
	}
	for(i = n, j = 1; valid(i, j); ) {
		int ii = i, jj = j;
		while(valid(ii, jj)) {
			d[ii][jj] = d[ii+1][jj+1] + num[ii][jj];
			ii--, jj--;
		}
		if(j < n) j++;
		else i--;
	}
	
	FOR(i, 1, n) FOR(j, 1, n) {
		LL cur = a[i][j] + b[i][j] + c[i][j] + d[i][j] - 3LL*num[i][j];
		will[i % 2 == j % 2].push_back(mp(cur, mp(i, j)));
	}
	FORS(i, 2) {
		sort(will[i].begin(), will[i].end());
		reverse(will[i].begin(), will[i].end());	
	}
	LL res = will[0][0].x + will[1][0].x;
	cout << res << endl;
	pf("%d %d %d %d\n", will[0][0].y.x, will[0][0].y.y, will[1][0].y.x, will[1][0].y.y);
	/*
	FORS(i, will[1].size()) {
		pf("%I64d %d %d\n", will[1][i].x, will[1][i].y.x, will[1][i].y.y);
	}
	*/
	return 0;
}
