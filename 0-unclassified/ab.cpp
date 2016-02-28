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
	int tt, t, i, j;
	sf("%d", &t);
	FOR(tt, 1, t) {
		char a[10], b[10];
		sf("%s %s", a, b);
		int lena = strlen(a);
		int lenb = strlen(b);
		int basa = 0, basb = 0;
		FORM(i, lena) {
			a[i] -= '0';
			basa = max(basa, (int) a[i]);
		}
		FORM(i, lenb) {
			b[i] -= '0';
			basb = max(basb, (int) b[i]);
		}
		basa++; basb++;
		//cout << basa << ' ' << basb << endl;
		int aa = 0, bb = 0;
		FORS(i, lena) {
			aa = aa * basa + (int) a[i];
		}
		FORS(i, lenb) {
			bb = bb * basb + (int) b[i];
		}
		pf("Case #%d: %d\n", tt, aa + bb);
	}
	
	return 0;
}
