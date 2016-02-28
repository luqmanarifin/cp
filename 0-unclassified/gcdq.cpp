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
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];
int lef[N], rig[N];
int n;

int main(void)
{
	//open;
	int t, i, j, n, q;
	sf("%d", &t);
	while(t--) {
		sf("%d %d", &n, &q);
		FORS(i, n) {
			sf("%d", &a[i]);
			lef[i] = rig[i] = a[i];
		}
		FOR(i, 1, n-1) lef[i] = gcd(lef[i], lef[i-1]);
		FORD(i, n-2, 0) rig[i] = gcd(rig[i], rig[i+1]);
		while(q--) {
			int l, r;
			sf("%d %d", &l, &r);
			l--, r--;
			if(0 < l && r < n-1) pf("%d\n", gcd(lef[l-1], rig[r+1]));
			else if(0 < l) pf("%d\n", lef[l-1]);
			else pf("%d\n", rig[r+1]);
		}
	}
	
	//close;
	return 0;
}
