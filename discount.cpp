#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL inf = 4e18;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int cost[N], discount = N;

int main(void)
{
	int m; sf("%d", &m);
	while(m--) {
		int x; sf("%d", &x);
		if(x < discount) discount = x;
	}
	int i, n; sf("%d", &n);
	FORS(i,n) {
		sf("%d", cost + i);
	}
	sort(cost, cost + n);
	reverse(cost, cost + n);
	int ans = 0, j; i = 0;
	while(i < n) {
		j = 1;
		while(j <= discount && i < n) {
			ans += cost[i];
			i++; j++;
		}
		i += 2;
	}
	pf("%d\n", ans);
	return 0;
}
