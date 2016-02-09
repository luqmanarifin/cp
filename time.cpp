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

LL a[N], b[N], ta[N], aa[N];

int main(void)
{
	int i, j, n, m;
	sf("%d %d", &n, &m);
	FORS(i, n) {
		sf("%I64d", a + i);
		aa[i] = a[i];
	}
	FORS(i, m) {
		sf("%I64d", b + i);
	}
	
	FORS(i, m) {
		int r = lower_bound(a, a + n, b[i]) - a, l = r - 1;
		if(r == 0) l = inf;
		if(r == n) l = inf, r--;
		if(l == inf) ta[r] += abs(a[r] - b[i]), a[r] = b[i];
		else {
			if(ta[l] + abs(a[l] - b[i]) > ta[r] + abs(a[r] - b[i]))
				ta[r] += abs(a[r] - b[i]), a[r] = b[i];
			else
				ta[l] += abs(a[l] - b[i]), a[l] = b[i];
		}
	}
	LL ans1 = -1;
	FORS(i, n) if(ta[i] > ans1) ans1 = ta[i];
	reset(ta, 0);
	FORS(i, n) a[i] = aa[i];
	
	FORM(i, m) {
		int r = lower_bound(a, a + n, b[i]) - a, l = r - 1;
		if(r == 0) l = inf;
		if(r == n) l = inf, r--;
		if(l == inf) ta[r] += abs(a[r] - b[i]), a[r] = b[i];
		else {
			if(ta[l] + abs(a[l] - b[i]) < ta[r] + abs(a[r] - b[i]))
				ta[l] += abs(a[l] - b[i]), a[l] = b[i];
			else
				ta[r] += abs(a[r] - b[i]), a[r] = b[i];
		}
	}
	LL ans2 = -1;
	FORS(i, n) if(ta[i] > ans2) ans2 = ta[i];
	cout << min(ans1, ans2) << endl;
	return 0;
}
