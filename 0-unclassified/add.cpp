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

int a[N], ans;
LL total, pre[N];

LL get(int l, int r) {
	return pre[r] - pre[l-1] - 1LL*(a[r] - a[l-1])*(l-1);
}

int main(void)
{
	int n, i, j, k, elm, next;
	sf("%d %d", &n, &k);
	FOR(i, 1, n) sf("%d", a + i);
	sort(a + 1, a + 1 + n);
	FOR(i, 2, n)
		pre[i] = pre[i-1] + 1LL*(a[i] - a[i-1])*(i-1);
	for(i = 1; i <= n; i = next) {
		next = upper_bound(a + 1, a + 1 + n, a[i]) - a;
		int cur = next - i;
		int l = 1, r = i, mid = (l + r + 1) >> 1;
		LL now = 0;
		while(l < r) {
			mid = (l + r + 1) >> 1;
			now = get(mid, i);
			if(now < k) r = mid - 1;
			else l = mid;
		}
		while(now > k) {
			mid++;
			now = get(mid, i);
		}
		now = get(mid - 1, i);
		while(now <= k && mid > 1) {
			mid--;
			now = get(mid - 1, i);
		}
		cur += i - mid;
		if(cur > ans) {
			ans = cur;
			elm = a[i];
		}
	}
	pf("%d %d\n", ans, elm);
	return 0;
}
