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

pair<int,int> num[N];

LL power(LL a, LL b) {
	if(b == 0) return 1;
	LL temp = power(a, b/2);
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
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		int p, i, j;
		sf("%d", &p);
		FORS(i, p) sf("%d %d", &num[i].first, &num[i].second);
		sort(num, num + p);
		unsigned long long ans = 0, temp = 0;
		FORS(i, p) {
			temp += num[i].second;
			ans += temp * num[i].second;
		}
		pf("Case %d: %ulld ", tt, ans); pf("%d\n", (int) power(2, p/2));
	}
	
	return 0;
}
