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

const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int mod;
int a[N];
int b[N];

void norm(int &x) {
	x %= mod;
	if(x < 0) x += mod;
}

int main(void)
{
	//open;
	int i, j, n, m;
	sf("%d %d %d", &n, &m, &mod);
	FOR(i, 1, n) sf("%d", &a[i]);
	FOR(i, 1, m) {
		sf("%d", &b[i]);
		b[i] += b[i-1];
	}
	FOR(i, 1, n) {
		int l = max(1, m - n + i);
		int r = min(m, i);
		//pf("%d %d %d\n", i, l, r);
		a[i] += b[r] - b[l - 1];
		norm(a[i]);
		pf("%d ", a[i]); //nl;
	}
	nl;
	//close;
	return 0;
}
