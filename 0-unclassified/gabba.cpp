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

int main(void)
{
	int t, n, m, s, p, q, i, j;
	sf("%d", &t);
	while(t--) {
		sf("%d %d %d %d %d", &n, &m, &s, &p, &q);
		int non = 1, nom = 1;
		int ans = 0;
		FOR(i, 1, s) {
			non += p;
			nom += q;
			if(non > n) {
				non -= n + 1;
				non %= (n - m + 1);
				non += m;
			}
			if(nom > n) {
				nom -= n + 1;
				nom %= (n - m + 1);
				nom += m;
			}
			if(non == nom) ans++;
		}
		pf("%d\n", ans);
	}
	return 0;
}
