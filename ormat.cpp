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

int a[105][105], nol[105][105];
vector<pair<int,int> > must, check;

int main(void)
{
	int i, j, n, m, k;
	sf("%d %d", &n, &m);
	FORS(i, n) FORS(j, m) {
		sf("%d", &a[i][j]);
		if(a[i][j] == 0) must.push_back(mp(i, j));
		else check.push_back(mp(i, j));
	}
	FORS(k, must.size()) {
		int x = must[k].first;
		int y = must[k].second;
		FORS(i, n) nol[i][y] = 1;
		FORS(j, m) nol[x][j] = 1;
	}
	FORS(k, check.size()) {
		int x = check[k].first;
		int y = check[k].second;
		int valid = 0;
		FORS(i, n) if(nol[i][y] == 0) valid = 1;
		FORS(j, m) if(nol[x][j] == 0) valid = 1;
		if(!valid) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	FORS(i, n) { FORS(j, m) pf(nol[i][j]? "0 " : "1 "); nl; }
	
	return 0;
}
