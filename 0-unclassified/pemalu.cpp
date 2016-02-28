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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int sapi[N];

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int n, m, k, i;
		sf("%d %d %d", &n, &m, &k);
		reset(sapi, 0);
		FORS(i, m) sf("%d", sapi + i);
		sort(sapi, sapi + m);
		int ans = m, pos = 1;
		FORS(i, m) {
			if(pos > sapi[i] || pos > n) continue;
			int add = (sapi[i] - pos)/k;
			if(pos % k == sapi[i] % k)
				pos += add*k + 1;
			else {
				add++;
				pos += add*k;
			}
			ans += add;
		}
		if(pos <= n) {
			ans += (n - pos)/k + 1;
		}
		pf("%d\n", ans);
	}
	
	return 0;
}
