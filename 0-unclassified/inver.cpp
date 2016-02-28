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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int bit[N], n;

void add(int a) {
	for(; a <= n; a |= a + 1) {
		bit[a]++;
	}
}

int find(int a) {
	int temp = 0;
	for(; a >= 0; a = (a & (a + 1)) - 1) {
		temp += bit[a];
	}
	return temp;
}

int main(void)
{
	int t, tt, i, j, k, a;
	sf("%d", &t);
	FOR(tt, 1, t) {
		reset(bit, 0);
		sf("%d %d", &n, &k);
		LL inv = 0;
		FORS(i, n) {
			sf("%d", &a);
			inv += find(n - a);
			add(n - a);
		}
		cout << "inv " << inv << endl;
		inv -= k;
		if(inv < 0) {
			if(inv % 2) inv = 1;
			else inv = 0;
		}
		pf("Case %d: %lld\n", tt, inv);
	}
	
	return 0;
}
