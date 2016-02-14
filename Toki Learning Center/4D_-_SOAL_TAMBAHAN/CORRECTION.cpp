#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 3005;

char kamus[N][N];
char t[N];
pair<int,int> ans[N];

int main(void)
{
	int i, j, n;
	FORS(i, N) ans[i] = mp(inf, inf);
	sf("%d", &n);
	FORS(i, n) sf("%s", kamus[i]);
	sf("%s", t);
	int lent = strlen(t);
	FORS(i, n) {
		int len = strlen(kamus[i]);
		int dif = 0;
		FORS(j, len) {
			if(j >= lent) break;
			int temp = abs(kamus[i][j] - t[j]);
			temp = min(temp, 26 - temp);
			dif += temp;
			ans[j] = min(ans[j], mp(dif, i));
		}
	}
	FORS(i, lent) {
		int pos = ans[i].second;
		FOR(j, 0, i) pf("%c", kamus[pos][j]);
		nl;
	}
	
	return 0;
}
