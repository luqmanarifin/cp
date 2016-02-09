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

int win[2005][2005];
int los[2005][2005];

void norm(int &a) {
	if(a >= mod) a -= mod;
}

int main(void)
{
	int i, j, n;
	win[0][0] = los[0][0] = 1;
	FOR(i, 1, 4000) {
		FOR(j, 0, i) if(j <= 2000 && i - j <= 2000) {
			if(j > i - j) {
				if((j - 1 > i - j && j - 1 >= 0 && i - j >= 0) || (j - 1 == 0 && i - j == 0)) {
					win[j][i - j] += win[j - 1][i - j];
					norm(win[j][i - j]);
				}
				if((j > i - j - 1 && j >= 0 && i - j - 1 >= 0) || (j == 0 && i - j - 1 == 0)) {
					win[j][i - j] += win[j][i - j - 1];
					norm(win[j][i - j]);
				}
			}
			if(j <= i - j) {
				if(j - 1 <= i - j && j - 1 >= 0 && i - j >= 0) {
					los[j][i - j] += los[j - 1][i - j];
					norm(los[j][i - j]);
				}
				if(j <= i - j - 1 && j >= 0 && i - j - 1 >= 0) {
					los[j][i - j] += los[j][i - j - 1];
					norm(los[j][i - j]);
				}
			}
		}
	}
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		int a, b;
		sf("%d-%d", &a, &b);
		pf("Case #%d: %d %d\n", tt, win[a][b], los[b][b]);
	}
	
	return 0;
}
