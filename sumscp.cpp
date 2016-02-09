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

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int i, j, n;
		sf("%d", &n);
		bool hihi = 0;
		FORS(i, 31) {
			if(n == (1 << i)) {
				hihi = 1;
				puts("IMPOSSIBLE");
			}
		}
		if(hihi) continue;
		LL l = 2, r = 1e9;
		while(l < r) {
			LL mid = (l + r) >> 1;
			if(mid*(mid + 1)/2 < n) l = mid + 1;
			else r = mid;
		}
		int pol = (int) l;
		bool done = 0;
		FOR(i, 2, pol) {
			if(i & 1) {
				if(n % i == 0) {
					int awal = n/i - i/2;
					pf("%d = %d", n, awal);
					FOR(j, awal + 1, awal + i - 1) {
						pf(" + %d", j);
					}
					done = 1;
					nl;
					break;
				}
			} else {
				if(n % i == i/2) {
					int awal = n/i + 1 - i/2;
					pf("%d = %d", n, awal);
					FOR(j, awal + 1, awal + i - 1) {
						pf(" + %d", j);
					}
					done = 1;
					nl;
					break;
				}
			}
		}
		//cout << pol << endl;
		if(!done) puts("IMPOSSIBLE");
	}
	
	return 0;
}
