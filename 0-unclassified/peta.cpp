#include <bits/stdc++.h>

/**
 * Penyisihan Lomba Programming Gemastik 7 UGM
 * Gajah Wangi
 * Problem : E
 */

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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int a, b, c, d;
		sf("%d %d %d %d", &a, &b, &c, &d);
		double l = (double) a / c;
		double r = (double) b / d;
		double scale = (DB) a / b;
		//pf("%.3lf %.3lf\n", l, r);
		DB ansa, ansb;
		if(r < l) {
			ansa = scale * d;
			ansb = d;
		} else {
			ansb = c / scale;
			ansa = c;
		}
		pf("%d %d\n", (int) (ansa + 0.5), (int) (ansb + 0.5));
	}
	
	return 0;
}
