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
const int N = 9e6;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL a, ans;
char s[4005];
int sum[N], pre[4005];

int main(void)
{
	int i, j, n, cur = 0;
	sf("%d %s", &a, &s[1]);
	n = strlen(&s[1]);
	FOR(i, 1, n) pre[i] = s[i] - '0';
	FOR(i, 1, n) pre[i] += pre[i-1];
	FOR(i, 1, n) FOR(j, i, n)
		sum[cur++] = pre[j] - pre[i-1];
	sort(sum, sum + cur);
	if(!a) {
		int zero = upper_bound(sum, sum + cur, 0) - sum;
		int non = cur - zero;
		ans += 1LL*zero*(2*non + zero);
	}
	for(i = 1; i*i <= a; ++i) if(a % i == 0) {
		int fakt = a/i;
		int low = lower_bound(sum, sum + cur, i) - sum;
		int upp = upper_bound(sum, sum + cur, i) - sum;
		int lower = lower_bound(sum, sum + cur, fakt) - sum;
		int upper = upper_bound(sum, sum + cur, fakt) - sum;
		LL cur = 1LL*(upp - low)*(upper - lower);
		ans += cur;
		if(i*i != a) ans += cur;
	}
	cout << ans << endl;
	return 0;
}
