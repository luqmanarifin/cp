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

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL n, now;
vector<LL> ans;

int main(void)
{
	int i;
	sf("%I64d", &n);
	now = 1;
	while(now < n) now *= 3LL;
	while(n) {
		LL ping = n / now;
		//pf("%I64d %I64d %I64d\n", ping, now, n);
		FORS(i, ping) ans.push_back(now);
		n -= ping*now;
		now /= 3LL;
	}
	n = (int) ans.size();
	sort(ans.begin(), ans.end());
	cout << n << endl;
	pf("%d", ans[0]);
	FOR(i, 1, n-1) pf(" %d", ans[i]); nl;
	
	return 0;
}
