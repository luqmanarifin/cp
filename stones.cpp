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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n;
LL cost[N], sorted[N];

int main(void)
{
	sf("%d", &n);
	int i;
	reset(cost, 0);
	reset(sorted, 0);
	FOR(i, 1, n) {
		sf("%I64d", &cost[i]);
		sorted[i] = cost[i];
	}
	sort(sorted+1, sorted+1+n);
	FOR(i,2,n) {
		cost[i] += cost[i-1];
		sorted[i] += sorted[i-1];
	}
	int m; sf("%d", &m);
	while(m--) {
		int type, l, r;
		sf("%d %d %d", &type, &l, &r);
		if(type == 1) {
			pf("%I64d\n", cost[r] - cost[l-1]);
		} else
			pf("%I64d\n", sorted[r] - sorted[l-1]);
	}
	
	return 0;
}
