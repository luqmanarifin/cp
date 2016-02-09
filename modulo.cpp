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

const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e4 + 7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool is[10010];

int power(int a, int b, int mod) {
	if(b == 0) return 1;
	int temp = power(a, b/2, mod);
	temp *= temp;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

int main(void)
{
	int i, j, t, tt, n;
	FOR(i, 2, N-1) {
		if(!is[i]) {
			for(j = i*i; j < N; j += i) {
				is[j] = 1;
			}
		}
	}
	sf("%d", &t);
	FOR(tt, 1, t) {
		sf("%d", &n);
		int ans;
		if(n == 1) ans = 1;
		else if(is[n]) ans = (n - 1)*(n - 1) % n;
		else ans = power(2, n-1, n);
		pf("Case #%d: %d\n", tt, ans);
	}
	
	return 0;
}
