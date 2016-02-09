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
int lcm(int a, int b) { return a*b / gcd(a, b); }

int ans[N], bef[N], cur;

int main(void)
{
	int i, n, x;
	reset(ans, -1);
	sf("%d", &n);
	FOR(i, 1, n) {
		sf("%d", &x);
		if(ans[x] == -1) {
			ans[x] = 0;
			cur++;
		} else if(!ans[x])
			ans[x] = i - bef[x];
		else if(ans[x] != inf) {
			if(bef[x] + ans[x] != i) {
				cur--;
				ans[x] = inf;
			}
		}
		bef[x] = i;
	}
	cout << cur << endl;
	FOR(i, 1, N - 5)
		if(ans[i] != inf && ans[i] != -1)
			pf("%d %d\n", i, ans[i]);
	
	return 0;
}
