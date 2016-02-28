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

int a[55], b[55], c[55], d[55];

bool pisah(int w, int x, int y, int z) {
	return (x < y || z < w);
}

int main(void)
{
	int t, ans = 0, i, j, p, q, l, r;
	sf("%d %d %d %d", &p, &q, &l, &r);
	FORS(i, p) sf("%d %d", a + i, b + i);
	FORS(i, q) sf("%d %d", c + i, d + i);
	FOR(t, l, r) {
		int bisa = 0;
		FORS(i, p) {
			FORS(j, q) {
				if(!pisah(a[i], b[i], c[j] + t, d[j] + t))
					bisa = 1;
			}
		}
		if(bisa) ans++;
	}
	cout << ans << endl;
	return 0;
}
