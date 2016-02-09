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
const int N10 = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int bit[N10], n;

void add(int a) {
	for(; a < N10; a |= a + 1) {
		bit[a]++;
	}
}

int find(int a) {
	int ret = 0;
	for(; a >= 0; a = (a & (a + 1)) - 1) {
		ret += bit[a];
	}
	return ret;
}

int main(void)
{
	int i, j, k;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", &k);
		add(k);
	}
	int ans = n;
	FOR(i, 0, 1000000) {
		ans = min(ans, i + n - find(i));
	}
	cout << ans << endl;
	return 0;
}
