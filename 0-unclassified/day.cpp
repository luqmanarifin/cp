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
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int ans[N];

int main(void)
{
	int n, m, i;
	sf("%d %d", &n, &m);
	int a, b, c;
	sf("%d %d %d", &a, &b, &c);
	ans[a] = 1;
	ans[b] = 2;
	ans[c] = 3;
	while(--m) {
		sf("%d %d %d", &a, &b, &c);
		if(ans[a]) {
			ans[b] = ans[a] + 1;
			ans[c] = ans[a] + 2;
		} else if(ans[b]) {
			ans[c] = ans[b] + 1;
			ans[a] = ans[b] + 2;
		} else if(ans[c]) {
			ans[a] = ans[c] + 1;
			ans[b] = ans[c] + 2;
		} else {
			ans[a] = 1;
			ans[b] = 2;
			ans[c] = 3;
		}
	}
	FOR(i, 1, n)
		if(ans[i] % 3) pf("%d ", ans[i]%3);
		else pf("3 ");
		
	return 0;
}
