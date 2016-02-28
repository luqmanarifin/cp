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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a[3005], pos[3005];

int main(void)
{
	int n, i, j, naik = 0;
	sf("%d", &n);
	FOR(i, 1, n) {
		sf("%d", a + i);
		pos[a[i]] = i;
	}
	int ans = 0;
	FOR(i, 1, n) {
		while(pos[i] > i) {
			swap(a[pos[i]], a[pos[i]-1]);
			swap(pos[a[pos[i]]], pos[a[pos[i]-1]]);
			ans++;
		}
	}
	ans = ((ans >> 1) << 2) + (ans & 1);
	pf("%.9f\n", (double) ans);
	return 0;
}
