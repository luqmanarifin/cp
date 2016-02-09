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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n, m, rig[105], wro[105];

int main(void)
{
	int i, j;
	sf("%d %d", &n, &m);
	FORS(i, n) sf("%d", rig + i);
	FORS(i, m) sf("%d", wro + i);
	sort(rig, rig + n);
	sort(wro, wro + m);
	int ans = -1;
	FORD(i, wro[0]-1, 1) {
		if(i < max(rig[0]*2, rig[n-1])) break;
		//cout << max(rig[0]*2, rig[n-1]) << endl;
		ans = i;
	}
	cout << ans << endl;
	return 0;
}
