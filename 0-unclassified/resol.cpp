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
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int p[25], c[25], f[25];

int main(void)
{
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		int n, i, j, mask;
		int gp, gc, gf;
		sf("%d %d %d %d", &gp, &gc, &gf, &n);
		FORS(i, n) sf("%d %d %d", p + i, c + i, f + i);
		int pol = (1 << n);
		bool found = 0;
		FORS(mask, pol) {
			int np = 0, nc = 0, nf = 0;
			FORS(i, n) if(mask & (1 << i)) {
				np += p[i];
				nc += c[i];
				nf += f[i];
				if(np > gp || nc > gc || nf > gf) goto NEXT;
			}
			NEXT:;
			if(np == gp && nc == gc && nf == gf) {
				found = 1;
				break;
			}
		}
		pf("Case #%d: ", tt);
		puts(found? "yes" : "no");
		cerr << "Case " << tt << " done!\n";
	}
	
	return 0;
}
