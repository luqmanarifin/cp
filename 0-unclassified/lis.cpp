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

int pos[5][1005], a[1005], lis[1005];

int main(void)
{
	int i, j, n, k, tc;
	sf("%d %d", &n, &k);
	FOR(i, 1, n) sf("%d", a + i);
	FORS(i, k-1) {
		int x;
		FOR(j, 1, n) {
			sf("%d", &x);
			pos[i][x] = j;
		}
	}
	FOR(i, 1, n) FOR(j, 1, n) lis[i] = 1;
	FOR(i, 1, n) FORD(j, i-1, 1) {
		bool valid = 1;
		FORS(tc, k-1) if(pos[tc][a[i]] < pos[tc][a[j]]) {
			valid = 0;
			break;
		}
		if(valid) lis[a[i]] = max(lis[a[i]], lis[a[j]] + 1);
	}
	int ans = -1;
	FOR(i, 1, n) ans = max(ans, lis[i]);
	cout << ans << endl;
	return 0;
}
